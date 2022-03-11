/*
 * Author: Elecrow Keen
 * Date:4/21/2017
 * IDE V1.8.2 
 * Email:keen@elecrow.com
 * Function:
 */
#include <LiquidCrystal_I2C.h>
#include <dht11.h>    
LiquidCrystal_I2C lcd(0x3F,16,2); // set the LCD address to 0x3F for a 16 chars and 2 line display  
              
dht11 DHT;                          //Note:DHT on behalf of the temperature and humidity sensor 
const int dht11_data = 6;     
int temp=0;
int hum=0;

void setup(){
  lcd.init();     // initialize the lcd 
  lcd.backlight();
  lcd.print("  Welcome to ");
  lcd.setCursor(0,1);
  lcd.print("    Elecrow");
  delay(2000);
  lcd.clear();
}
void loop(){ 
  DHT.read(dht11_data);
  temp=DHT.temperature;
  hum=DHT.humidity;
  lcd.clear();                   //clear display
  lcd.print("Hum=%");            //display "Hum=%"
  lcd.print(hum);
  lcd.setCursor(10,0) ;
  lcd.print("Elecrow");           //display "Elecrow"
  lcd.setCursor(0,1) ;           //Display position
  lcd.print("Temp=");            //display"Temp="
  lcd.print(temp);
  lcd.write(0xDF);              //Display custom characters '°'
  lcd.print("C");
  delay(500);                   //After 500ms ,the screen will be refreshed
}

