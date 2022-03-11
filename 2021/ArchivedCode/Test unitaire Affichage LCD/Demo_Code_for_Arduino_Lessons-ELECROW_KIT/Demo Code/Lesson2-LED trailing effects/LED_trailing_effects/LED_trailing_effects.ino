/*
 * Author: Elecrow Keen
 * Date:4/21/2017
 * IDE V1.8.2 
 * Email:keen@elecrow.com
 * Function:
 */
const int BASE = 2;               
const int NUM = 6;             
void setup(){
  for (int i = BASE; i < BASE + NUM; i ++){
    pinMode(i, OUTPUT); //set port "i" as an output port 
  }
}
void loop(){
  for (int i = BASE; i < BASE + NUM; i ++){
    digitalWrite(i, LOW);      // Turn OFF the I/O board LED
    delay(200);             
  }
for (int i = BASE; i < BASE + NUM; i ++){
    digitalWrite(i, HIGH);    // Turn ON the I/O board LED
    delay(200);             
  }
}

