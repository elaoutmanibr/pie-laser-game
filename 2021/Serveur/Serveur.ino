
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display


void setup(){
  lcd.init();
  lcd.backlight();
  lcd.print("Bienvenue au");
  lcd.setCursor(0,1);         //Display position
  lcd.print(" PIE  LAZERGAME ");
}
void loop(){
  // Turn off the display:
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);
}