#include <IRremote.h>        //Using version 2.0.1
IRsend irsend;


const int gachette = 7;

void setup(){
  pinMode(gachette, OUTPUT);
}

void loop() {
  if (digitalRead(gachette)==HIGH){
    irsend.sendNEC(0xFFFFF, 32);
    delay(3000);
  }
}
