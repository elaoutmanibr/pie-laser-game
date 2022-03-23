
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
    bool inGame;
    byte hits_emitted;
    byte hits_received;
    //unsigned long last_hit;

    Player(byte _id) {
        this.id = _id;
        this.inGame = true;
        this.hits_emitted = 0;
        this.hits_received = 0;
        //this.last_hit = 0;
    }
};



void setup(){
  lcd.init();
  lcd.backlight();
  vw_set_rx_pin(RF_RX_PIN);
  vw_set_tx_pin(RF_TX_PIN);
  vw_setup(2000);
  vw_rx_start();

  Player p1 = Player(0);
  Player p2 = Player(1);

  Player players[2] = {p1,p2};

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

  
  
  //vw_wait_rx_max(500);
  if (vw_get_message(message, &size_msg)) {

    if(message[0]==16){    // 16 => msg hit
      shot.shooter = message[1];
      shot.victim = message[2];
      if (players[shot.victim].inGame && players[shot.shooter].inGame){
        players[shot.shooter].hits_emitted++;
        players[shot.victim].hits_received++;
        players[shot.victim].inGame=false;

        response[0]=  shot.victim; // id du victim
        response[1]=20 // 20 => msg début paralysie
        response[2]=players[shot.victim].hits_received;
      }else if (players[shot.shooter].inGame){
        response[0] = shot.shooter; 
        response[1]=21; // 21 => you can't hit because paralyzed
        response[2]=0;
      }

      vw_send(response, 3);
      vw_wait_tx(); // attendre la fin de l'envoi
    }

    if (message[0]==17){  // 17 => end paralyzed 
      {
        int id = message[1];
        players[id].inGame = true;
      }
    }
  }

  //gere les display
  //On met un truc qui scroll
  //Score de tout les joueurs ordonnes

}