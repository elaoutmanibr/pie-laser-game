/*
 * Author: Elecrow Keen
 * Date:4/21/2017
 * IDE V1.8.2 
 * Email:keen@elecrow.com
 * Function:
 */
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
const int water = A0;
int val=0;
int count=0;
void setup(){
  lcd.init();
  lcd.backlight();
  lcd.print("  Welcome to ");
  lcd.setCursor(0,1);
  lcd.print("    Elecrow");
  delay(2000);
  lcd.clear();
}
void loop(){ 
  val=analogRead(water);
  if(val>220)
  val=200;
  count=val/2.2;
  lcd.clear();                 //clear display
  lcd.print("Elecrow");
  lcd.setCursor(0, 1) ;       
  lcd.print("Water Level=%");            
  lcd.print(count);
  delay(150);   
}
