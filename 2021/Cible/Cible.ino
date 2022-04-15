#include <LiquidCrystal_I2C.h>
#include <VirtualWire.h>
#include <IRremote.h> // Referring to the IRRemote function library, the header file 
                        //has defined PIN 3 as the signal output, so it can only connect 
                        //to PIN 3. If change, please change it in the header file
                        //Using version 2.0.1
IRsend irsend;

int RECV_PIN = 11;
IRrecv irrecv (RECV_PIN);
decode_results irmsg;

int LED_PIN = 6;

void setup(){
  irrecv.enableIRIn();
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH); 
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);              
  digitalWrite(LED_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); 
  digitalWrite(LED_PIN, HIGH); 
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);              
  digitalWrite(LED_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); 
}

void loop() {
  if (irrecv.decode(&irmsg)) {
    Serial.println(irmsg.value, HEX);
    digitalWrite(LED_PIN, HIGH); 
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);              
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000); 
    irrecv.resume(); // Receive the next value
  }
}
