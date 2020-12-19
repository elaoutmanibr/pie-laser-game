int receiver = 7; //Relié au capteur IR
int emitter = 13; //Relié à la diode IR
int trigger = 4; //Relié à la gâchette

int receiverState = 0;
int lastReceiverState = 0;

int triggerState = 0;
int lastTriggerState = 0;

String id = "010100101";

unsigned long chrono;
unsigned long highTime; //durée du signal en position haute

//Durée des signaux (µs)
unsigned int zeroDuration = 600;
unsigned int oneDuration = 1200;
unsigned int headerDuration = 2400;
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
  else if (headerDuration - e < highTime && highTime < headerDuration + e) {
    Serial.print("Transmission start\n");
  }
  else if (endDuration - e < highTime && highTime < endDuration + e) {
    Serial.print("\nTransmission end\n\n");
  }
}



//Envoi du signal de début de message
void sendHeader(int pin) { 
  digitalWrite(pin, HIGH);
  delayMicroseconds(headerDuration);
  digitalWrite(pin, LOW);
  delayMicroseconds(zeroDuration);
}



//Envoi du signal de fin de message
void sendEnd(int pin) { 
  digitalWrite(pin, HIGH);
  delayMicroseconds(endDuration);
  digitalWrite(pin, LOW);
  delayMicroseconds(zeroDuration);
}



//Envoi de 1 ou 0
void sendBit(int pin, char bit) {
  if (bit == '0') { //Envoi du 0
    digitalWrite(pin, HIGH);
    delayMicroseconds(zeroDuration);
    digitalWrite(pin, LOW);
    delayMicroseconds(zeroDuration);
  }
  else if (bit == '1') { //Envoi du 1
    digitalWrite(pin, HIGH);
    delayMicroseconds(oneDuration);
    digitalWrite(pin, LOW);
    delayMicroseconds(zeroDuration);
  }
}



void sendPacket(int pin, String packet) {
  int len = packet.length();
  sendHeader(pin);
  for(int i = 0; i<len; i++) {
    sendBit(pin, packet[i]);
  }
  sendEnd(pin);
}



//Détecter l'appui sur la gâchette
void checkTrigger(int trigger) {
  triggerState = digitalRead(trigger);
  if (triggerState == 0) { //On n'appuie pas sur la gâchette
    if (lastTriggerState == 1) { //Front descendant (on a lâché la gâchette)
      lastTriggerState = 0;
    }
  }
  else if (triggerState == 1) { //On appuie sur la gâchette
    if (lastTriggerState == 0) { //Front montant (on vient d'appuyer sur la gâchette)
      sendPacket(emitter, id);
      lastTriggerState = 1;
    }
  }
}



void checkReceiver() {
  receiverState = digitalRead(receiver);
  if (receiverState == 1) { //On capte un signal
    if (lastReceiverState == 0) { //Front montant
      chrono = micros();
      lastReceiverState = 1;
    }
  }
  else if (receiverState == 0) { //On ne capte pas de signal
    if (lastReceiverState == 1) { //Front descendant
      highTime = micros() - chrono;
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
  checkTrigger(trigger);
}
