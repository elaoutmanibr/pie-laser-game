/*
 * Author: Elecrow Keen
 * Date:4/21/2017
 * IDE V1.8.2 
 * Email:keen@elecrow.com
 * Function:
 */
#include <IRremote.h> 
const int irReceiverPin = 2;   
IRrecv irrecv(irReceiverPin); 
decode_results results;   
 
void setup(){
  Serial.begin(9600);   
  irrecv.enableIRIn();   
}
void loop() {
  if (irrecv.decode(&results)){  
    Serial.print("IR_Code: ");            
    Serial.print(results.value, HEX); 
    Serial.print(",  Bits: ");           
    Serial.println(results.bits); 
    irrecv.resume();    
  }  
  delay(600); 
}

