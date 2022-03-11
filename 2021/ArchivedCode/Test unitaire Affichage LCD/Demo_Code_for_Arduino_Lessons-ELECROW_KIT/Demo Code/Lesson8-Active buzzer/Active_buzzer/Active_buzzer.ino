/*
 * Author: Elecrow Keen
 * Date:4/21/2017
 * IDE V1.8.2 
 * Email:keen@elecrow.com
 * Function:
 */
const int buzzer=5; 
void setup(){
  pinMode(buzzer,OUTPUT);
}
void loop(){
  digitalWrite(buzzer, HIGH); // produce sound
}

