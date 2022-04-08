#include <LiquidCrystal_I2C.h>
#include <VirtualWire.h>
//#include <IRremote.h> // Referring to the IRRemote function library, the header file 
                        //has defined PIN 3 as the signal output, so it can only connect 
                        //to PIN 3. If change, please change it in the header file

byte ID = 0; // identifiant du pistolet
byte hits_recv =0 ;

LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
int RF_RX_PIN = 10;
int RF_TX_PIN = 12;
const int buttonPin = 4;   
byte message[3];
byte size_msg =3;
byte response[3];

void setup(){
  lcd.init();
  lcd.backlight();
  vw_set_rx_pin(RF_RX_PIN);
  vw_set_tx_pin(RF_TX_PIN);
  vw_setup(2000);
  vw_rx_start();

  lcd.print("Bienvenue au");
  lcd.setCursor(0,1);         //Display position
  lcd.print(" PIE  LAZERGAME ");
}

void loop() {
  if (vw_get_message(message, &size_msg) && message[0]==ID && message[1]==20) { // 20 : code paralysie
    // Affichage paralysie
    delay(15*1000);
    // Feu vert !!
    response[0]=17; // code fin paralysie
    response[1]=ID;
    response[2]=255; // null, ne vas être lu

    vw_send(response, 3);
    vw_wait_tx(); // attendre la fin de l'envoi

  }

  if (digitalRead(buttonPin) == HIGH) { // si le bouton hit recieved est appuyé dans la simulation
      response[0]=16; // code hit recieved
      response[1]=ID;
      response[2]=1; // id attaquant

      vw_send(response, 3);
      vw_wait_tx(); // attendre la fin de l'envoi

  }
}
