/*
 * Author: Elecrow Keen
 * Date:4/21/2017
 * IDE V1.8.2 
 * Email:keen@elecrow.com
 * Function:
 */
 #include <dht11.h>                  
dht11 DHT;                  //Note: DHT on behalf of the DHT11 sensor 
const int dht11_data = 6;     //Please put the DH11`s dht11_data pin connect with arduino digital Port 6
int temp=0;
int hum=0;
void setup(){
  Serial.begin(9600);
}
void loop(){ 
  DHT.read(dht11_data);
  temp=DHT.temperature;
  hum=DHT.humidity;
  Serial.print("Hum=\t%");            
  Serial.print(hum);
  Serial.print("\tTemp=\t");            
  Serial.println(temp);
  delay(1000);
}

