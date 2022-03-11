const int ledPin=9;
String nom = "Arduino";
String msg;

void setup() {
 Serial.begin(9600);
}


void loop() {
 readSerialPort();
 if (msg == "is_killed") {
   digitalWrite(13 ,HIGH);
 }else if(msg=="is_paralysed"){
   digitalWrite(ledPin,HIGH);
 }else if (msg=="off"){
   digitalWrite(ledPin,LOW);
 }
 delay(500);
}

void readSerialPort() {
 msg = "";
 if (Serial.available()) {
   delay(10);
   while (Serial.available() > 0) {
     msg += (char)Serial.read();
   }
   Serial.flush();
 }
}
