/*
 * Author: Elecrow Keen
 * Date:4/21/2017
 * IDE V1.8.2 
 * Email:keen@elecrow.com
 * Function:
 */
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.print("  Welcome to ");
  lcd.setCursor(0,1);         //Display position
  lcd.print("       Elecrow");
}
void loop(){
  // Turn off the display:
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);
}

