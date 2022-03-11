/*
 * Author: Elecrow Keen
 * Date:4/21/2017
 * IDE V1.8.2 
 * Email:keen@elecrow.com
 * Function:
 */
const int flame_sensor =A0;
const int Buzzer=6;   
void setup(){
  pinMode(Buzzer,OUTPUT); 
  Serial.begin(9600);
}
void loop(){
  int val;
  val=analogRead(flame_sensor);
  Serial.println(val,DEC);
  // According to the serial data to adjust.
  while(val>500){
    digitalWrite(Buzzer,HIGH); 
    val=analogRead(0);   
    Serial.println(val,DEC);
  }
  digitalWrite(Buzzer,LOW); 
}

