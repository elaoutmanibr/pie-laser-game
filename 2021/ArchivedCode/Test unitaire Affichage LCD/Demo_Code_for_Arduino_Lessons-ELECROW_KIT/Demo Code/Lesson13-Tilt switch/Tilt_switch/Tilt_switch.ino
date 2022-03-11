/*
 * Author: Elecrow Keen
 * Date:4/21/2017
 * IDE V1.8.2 
 * Email:keen@elecrow.com
 * Function:
 */
const int led = 11;
int val;
void setup(){
  pinMode(led,OUTPUT);
}
void loop(){
  val=analogRead(0); 
  if(val<512){
    digitalWrite(led,HIGH);    
  }
  else
  digitalWrite(led,LOW);
}
