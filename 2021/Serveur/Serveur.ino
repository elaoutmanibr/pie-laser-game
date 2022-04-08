
#include <LiquidCrystal_I2C.h>
#include <VirtualWire.h>


LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
int RF_RX_PIN = 9;
int RF_TX_PIN = 11;
byte message[3];
byte size_msg =3;
byte response[3];

struct Shot{
    byte shooter;
    byte victim;
};

class Player
{
public:
    byte id;
    byte hits_emitted; //For score calculating
    byte hits_received;

    Player(byte _id) {
        this->id = _id;
        this->hits_emitted = 0;
        this->hits_received = 0;
    }
};


Player p1 = Player(0);
Player p2 = Player(1);

Player players[2] = {p1,p2};

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.print("Bienvenue au");
  lcd.setCursor(0,1);         //Display position
  lcd.print(" TEST RADIO V2 ");
  vw_set_rx_pin(RF_RX_PIN);
  vw_set_tx_pin(RF_TX_PIN);
  vw_setup(2000);
  vw_rx_start();
}
void loop(){
  // Turn off the display:
  //lcd.noDisplay();
  //delay(500);
  // Turn on the display:
  //lcd.display();
  //delay(500);
  //lcd.setCursor(0,0);
  //lcd.print("AWAITING MSSG   ");

  //vw_wait_rx_max(500);
  if (vw_get_message(message, &size_msg)) {
    Shot shot;
    //lcd.print("MSSG RECEIVED   ");
    if(message[0]==16){    // 16 => msg hit
      
      //Read what shot it is
      shot.shooter = message[1];
      shot.victim = message[2];
      
      //BDD update
      if(players[shot.shooter].hits_emitted<254){players[shot.shooter].hits_emitted++;}
      else{players[shot.shooter].hits_emitted=0;}
      if(players[shot.victim].hits_received<254){players[shot.victim].hits_received++;}
      else{players[shot.victim].hits_received=0;}
      
      //lcd quick update (debug)
      lcd.setCursor(0,0);
      lcd.print("SHOT            ");
      lcd.setCursor(6,0);
      lcd.print(players[shot.shooter].hits_emitted);
      lcd.setCursor(10,0);
      lcd.print(players[shot.victim].hits_received);
      lcd.setCursor(0,1);
      lcd.print(" TEST RADIO V2 ");
      delay(200);
      
      //Set outward message to victim has been shot
      response[0]=  shot.victim; // id du victim
      response[1]=20 ;// 20 => msg tir reçu/début paralysie
      response[2]=players[shot.victim].hits_received; //How many hits that makes, total
      
      //Attente de confirmation
      vw_send(response, 3);
      vw_wait_tx(); // attendre la fin de l'envoi
    }
  }

  //gere les display
  //On met un truc qui scroll
  //Score de tout les joueurs ordonnes

}
