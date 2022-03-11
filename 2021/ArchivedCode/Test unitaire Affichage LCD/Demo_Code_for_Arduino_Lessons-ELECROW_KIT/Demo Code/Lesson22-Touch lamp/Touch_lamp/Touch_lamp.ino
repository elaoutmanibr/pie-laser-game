/*
 * Author: Elecrow Keen
 * Date:4/21/2017
 * IDE V1.8.2 
 * Email:keen@elecrow.com
 * Function:
 */
const int touch = 2;
const int Bled = 3;
const int Rled = 5;
const int Gled = 6;
int lastime=0;
int val=0;
int count=0;
void setup() {
    analogWrite(Bled,0);
    analogWrite(Rled,0);
    analogWrite(Gled,0);
    attachInterrupt(0, swRGB, RISING);
}
void loop() {
  switch(count){
    case 1:
    analogWrite(Bled,255);
    analogWrite(Rled,0);
    analogWrite(Gled,0);
    delay(500);
    break;
    case 2:
    analogWrite(Bled,0);
    analogWrite(Rled,255);
    analogWrite(Gled,0);
    delay(500);
    break;
    case 3:
    analogWrite(Bled,0);
    analogWrite(Rled,0);
    analogWrite(Gled,255);
    delay(500);
    break;
    case 4:
    RGBflash();
    break;
    case 5:
    analogWrite(Bled,0);
    analogWrite(Rled,0);
    analogWrite(Gled,0);
    delay(500);
    break;
    }
}
void swRGB(){ 
  count++;
  if(count>5)
  count=0;  
 }
void RGBflash(){ 
 for (int c=0,b=255,a=0; c<=255,b>0,a<=255;c++,b--,a++){
    analogWrite(Bled,c);
    analogWrite(Rled,b);
    analogWrite(Gled,a);
    delay(5);                                    
  }
 for (int a=255,b=0,c=255; a>0,b<=255,c>0;a--,b++,c--){
    analogWrite(Bled,c);
    analogWrite(Rled,b);
    analogWrite(Gled,a);
    delay(5);                                     
  }
}

