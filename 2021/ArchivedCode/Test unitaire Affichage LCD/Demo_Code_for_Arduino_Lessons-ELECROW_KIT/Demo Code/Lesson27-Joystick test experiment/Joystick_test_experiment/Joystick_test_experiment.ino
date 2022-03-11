/*
 * Author: Elecrow Keen
 * Date:4/21/2017
 * IDE V1.8.2 
 * Email:keen@elecrow.com
 * Function:
 */
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
const int xpotPin = A0;
const int ypotPin = A1;            
const int bpotPin = 6; 
int xval=0;       //Initialize a variable
int yval=0;
int bval=0;

void setup(){
  lcd.init();
  lcd.backlight();
  pinMode(xpotPin,INPUT);
  pinMode(ypotPin,INPUT);
  pinMode(bpotPin,INPUT); 
  lcd.print("  Welcome to ");
  lcd.setCursor(0,1);
  lcd.print("    Elecrow");
  delay(2000);
  lcd.clear();
}
void loop(){ 
  xval = analogRead(xpotPin);   //Read Values from the xpotPin
  yval = analogRead(ypotPin);   
  bval = digitalRead(bpotPin);   
  lcd.clear();                 //clear display
  lcd.setCursor(0, 0) ;       //Display position
  lcd.print("X=");            //Display "X="
  lcd.print(xval);
  lcd.setCursor(7, 0) ;  
  lcd.print("Y=");       
  lcd.print(yval);  
  if (bval==LOW){
    lcd.setCursor(0, 1) ;   
    lcd.print("Button ON"); 
  }
  else{
    lcd.setCursor(0, 1) ;
    lcd.print("Button OFF"); 
  }
  delay(150); //After 150ms the screen will be refreshed
}
