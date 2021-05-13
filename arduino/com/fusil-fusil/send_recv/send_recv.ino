/* #include <RH_ASK.h> */
/* #include <SPI.h> */

int receiver = 7; //Relié au capteur IR
int emitter = 12; //Relié à la diode IR
int trigger = 4; //Relié à la gâchette

int rc_receiver = 9;
int rc_emitter = 10;
RH_ASK rc;

int receiverState = 0; //État mesuré actuel de la gâchette
int lastReceiverState = 0; //Dernier état mesuré de la gâchette

int triggerState = 0; //État mesuré actuel de la gâchette
int lastTriggerState = 0; //Dernier état mesuré de la gâchette

bool isSendingPacket = false; //Si l'émetteur est en train d'envoyer un message
bool isSendingBit = false; //Si l'émetteur est en train d'envoyer un bit
int currentSendStep = 0; //Indice du bit en train d'être émis dans le message
bool currentSendState = 0; //Si l'émetteur est actuellement allumé

//Format standard message : "s******e", * = 0 ou 1
uint8_t id = 59;

String id_string;
id_string[0] = 's';
for (int8_t i = 7; i >= 0; i--) {
  id_string[8 - i] = ((id & 1 << i) >> i) + 48;
}
id_string[9] = 'e';

String msgBuffer = ""; //Buffer de réception

unsigned long recvChrono; //Chronomètre en réception
unsigned long sendChrono; //Chronomètre en envoi
unsigned long highRecvDuration; //Durée du signal mesuré en position haute

//Durée des signaux (µs)
unsigned int zeroDuration = 600;
unsigned int oneDuration = 1200;
unsigned int startDuration = 2400;
unsigned int endDuration = 1800;

//Fréquence des impulsions (56kHz)
unsigned int freq = 56000;

//Tolérance dans la durée des impulsions reçues (µs)
unsigned int e = 250;

typedef struct msg_t {
  uint8_t destination;
  uint8_t source;
  uint8_t type;
  uint8_t args[5];
} message;


//Interprétation du bit reçu en fonction de la durée du signal mesuré en position haute
void readBit(unsigned long highRecvDuration) {
  if (zeroDuration - e < highRecvDuration && highRecvDuration < zeroDuration + e) { //On reçoit un 0
    Serial.print("0");
  }
  else if (oneDuration - e < highRecvDuration && highRecvDuration < oneDuration + e) { //On reçoit un 1
    Serial.print("1");
  }
  else if (startDuration - e < highRecvDuration && highRecvDuration < startDuration + e) { //On reçoit un début de signal
    Serial.print("Transmission start\n");
  }
  else if (endDuration - e < highRecvDuration && highRecvDuration < endDuration + e) { //On reçoit une fin de signal
    Serial.print("\nTransmission end\n\n");
  }
}

void readBit2(unsigned long highRecvDuration, String &recvBuffer) {
  if (zeroDuration - e < highRecvDuration && highRecvDuration < zeroDuration + e) { //On reçoit un 0
    recvBuffer += "0";
  }
  else if (oneDuration - e < highRecvDuration && highRecvDuration < oneDuration + e) { //On reçoit un 1
    recvBuffer += "1";
  }
  else if (startDuration - e < highRecvDuration && highRecvDuration < startDuration + e) { //On reçoit un début de signal
    recvBuffer = "";
  }
  else if (endDuration - e < highRecvDuration && highRecvDuration < endDuration + e) { //On reçoit une fin de signal
    Serial.print(recvBuffer + "\nTransmission end\n\n");
  }
}


//Envoi de 0, 1, début de message, fin de message
void sendBit(int pin, char bit, int len) {
  unsigned int highDuration = 0;
  switch (bit) { //On définit la durée de la sortie haute
    case '0': //Le bit est un 0
      highDuration = zeroDuration;
      break;
    case '1': //Le bit est un 1
      highDuration = oneDuration;
      break;
    case 's': //Début de message
      highDuration = startDuration;
      break;
    case 'e': //Fin de message
      highDuration = endDuration;
      break;
  }

  if (!isSendingBit && !currentSendState) { //L'envoi du bit n'a pas encore commencé
    isSendingBit = true; //Début de l'envoi du bit
    currentSendState = true;
    //digitalWrite(emitter, HIGH); // Sortie haute
    tone(emitter, freq);
    sendChrono = micros(); //Réinitialisation du chronomètre
  }
  else if (currentSendState) { //L'envoi du bit a commencé, et la sortie est haute
    if (micros() - sendChrono >= highDuration) { //Fin de la sortie haute
      currentSendState = false;
      noTone(emitter);
      //digitalWrite(emitter, LOW); //Sortie basse
      sendChrono = micros(); //Réinitialisation du chronomètre
    }
  }
  else { //L'envoi du bit a commencé, et la sortie est basse
    if (micros() - sendChrono >= zeroDuration) { //Fin d'envoi du bit
      isSendingBit = false; //Fin de l'envoi du bit
      currentSendStep++; //On demande l'envoi du bit suivant
      if(currentSendStep == len) { //Tous les bits ont été envoyés
        isSendingPacket = false; //Arrêt de l'envoi du message
        currentSendStep = 0;
      }
    }
  }
}



//Envoi d'un message
void sendPacket(int pin, String packet) {
  int len = packet.length();
    sendBit(pin, packet[currentSendStep], len);
}



//Détecter l'appui sur la gâchette
void checkTrigger() {
  triggerState = digitalRead(trigger);
  if (triggerState == 0) { //On n'appuie pas sur la gâchette
    if (lastTriggerState == 1) { //Front descendant (on a lâché la gâchette)
      lastTriggerState = 0;
    }
  }
  else if (triggerState == 1 && !isSendingPacket) { //On appuie sur la gâchette
    if (lastTriggerState == 0) { //Front montant (on vient d'appuyer sur la gâchette)
      isSendingPacket = true; //On commence l'envoi du message
      lastTriggerState = 1;
    }
  }
}



//Détecter les tirs/messages entrants
void checkReceiver() {
  receiverState = 1 - digitalRead(receiver);
  if (receiverState == 1) { //On capte un signal
    if (lastReceiverState == 0) { //Front montant
      recvChrono = micros(); //Réinitialisation du chronomètre
      lastReceiverState = 1;
    }
  }
  else if (receiverState == 0) { //On ne capte pas de signal
    if (lastReceiverState == 1) { //Front descendant
      highRecvDuration = micros() - recvChrono; //Mesure du temps en signal haut
      readBit2(highRecvDuration, msgBuffer); //Interprétation du bit reçu
      lastReceiverState = 0;
    }
    else {
      if (micros() - recvChrono > 2e6) { //Si on ne capte rien pendant plus de 2 secondes
        msgBuffer = ""; //On réinitialise le buffer de réception
      }
    }
  }
}

// Renvoie un pointeur vers le message correspondant au signal. Si aucun message n'est reçu, il renvoie NULL.
message* checkRC() {
  uint8_t buflen = 8; // Format : destination_id (0-255), source_id (0-255), msg_type (0-255), up to 5 arguments (depending on the type of message)
  uint8_t buf[buflen];

  if (rc.recv(buf, &buflen)) {
    message* res = malloc(sizeof(message));
    res -> destination = buf[0],
    res -> source = buf[1],
    res -> type = buf[2]
    for (uint8_t i = 0; i < 5; i++) {
      res -> args[i] = buf[i + 3];
    }
    return res;
  }
  return NULL;
}

// Envoie le message correspondant
void sendRC(message* msg) {
  uint8_t buflen = 8;
  uint8_t buf[buflen];

  buf[0] = msg -> destination;
  buf[1] = id;
  buf[2] = msg -> type;
  for (uint8_t i = 0; i < 5; i++)
    buf[i + 3] = (msg -> args)[i];

  rc.send(buf, buflen);
}


//Initialisation
void setup() {
  pinMode(receiver, INPUT);
  pinMode(emitter, OUTPUT);
  pinMode(trigger, INPUT);
  // Initialisation de la partie radio
  if (!rc.init())
    Serial.print("Error: Module Radio non initialisé");
  Serial.begin(9600); //Initialisation de la communication texte
}



//Boucle d'exécution
void loop() {
  checkReceiver(); //Détection de tir/message entrant
  checkTrigger(); //Détection d'appui sur la gâchette
  if (isSendingPacket) {
    sendPacket(emitter, id_string); //Envoi de messages
  }
}
