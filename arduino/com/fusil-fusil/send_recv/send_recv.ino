int receiver = 7; //Relié au capteur IR
int emitter = 13; //Relié à la diode IR
int trigger = 4; //Relié à la gâchette

int receiverState = 0;
int lastReceiverState = 0;

int triggerState = 0;
int lastTriggerState = 0;

bool isSendingPacket = false; //Si l'émetteur est en train d'envoyer un message
bool isSendingBit = false;
int currentSendStep = 0; //Indice du bit en train d'être émis dans le message
bool currentSendState = 0; //Si l'émetteur est actuellement allumé

//Format standard message : "s******e", * = 0 ou 1
String id = "s1010e";

unsigned long recvChrono;
unsigned long sendChrono;
unsigned long highTime; //durée du signal en position haute

//Durée des signaux (µs)
unsigned int zeroDuration = 600;
unsigned int oneDuration = 1200;
unsigned int startDuration = 2400;
unsigned int endDuration = 1800;

//Tolérance dans la durée des impulsions reçues (µs)
unsigned int e = 50;



void readBit(unsigned long highTime) {
  if (zeroDuration - e < highTime && highTime < zeroDuration + e) {
    Serial.print("0");
  }
  else if (oneDuration - e < highTime && highTime < oneDuration + e) {
    Serial.print("1");
  }
  else if (startDuration - e < highTime && highTime < startDuration + e) {
    Serial.print("Transmission start\n");
  }
  else if (endDuration - e < highTime && highTime < endDuration + e) {
    Serial.print("\nTransmission end\n\n");
  }
}



//Envoi de 0, 1, début de message, fin de message
void sendBit(int pin, char bit, int len) {
  unsigned int highDuration = 0;
  switch (bit) {
    case '0':
      highDuration = zeroDuration;
      break;
    case '1':
      highDuration = oneDuration;
      break;
    case 's': //Début de message
      highDuration = startDuration;
      break;
    case 'e': //Fin de message
      highDuration = endDuration;
      break;
  }

  if (!isSendingBit && !currentSendState) {
    isSendingBit = true;
    currentSendState = true;
    digitalWrite(emitter, HIGH);
    sendChrono = micros();
  }
  else if (currentSendState) {
    if (micros() - sendChrono >= highDuration) { //Fin du signal haut
      currentSendState = false;
      digitalWrite(emitter, LOW);
      sendChrono = micros();
    }
  }
  else {
    if (micros() - sendChrono >= zeroDuration) { //Fin du signal bas et fin d'envoi du bit
      isSendingBit = false;
      currentSendStep++;
      if(currentSendStep == len) {
        isSendingPacket = false;
        currentSendStep = 0;
      }
    }
  }
}



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
      isSendingPacket = true;
      lastTriggerState = 1;
    }
  }
}



void checkReceiver() {
  receiverState = digitalRead(receiver);
  if (receiverState == 1) { //On capte un signal
    if (lastReceiverState == 0) { //Front montant
      recvChrono = micros();
      lastReceiverState = 1;
    }
  }
  else if (receiverState == 0) { //On ne capte pas de signal
    if (lastReceiverState == 1) { //Front descendant
      highTime = micros() - recvChrono;
      readBit(highTime);
      lastReceiverState = 0;
    }
  }
}



void setup() {
  pinMode(receiver, INPUT);
  pinMode(emitter, OUTPUT);
  pinMode(trigger, INPUT);
  Serial.begin(9600);
}

void loop() {
  checkReceiver();
  checkTrigger();
  if (isSendingPacket) {
    sendPacket(emitter, id);
  }
}
