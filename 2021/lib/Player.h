class Player
{
public:
    byte id;
    bool touchable;
    int hits_emitted;
    int hits_received;
    unsigned long last_hit;

    Player(byte _id) {
        this.id = _id;
        this.touchable = true;
        this.hits_emitted = 0;
        this.hits_received = 0;
        this.last_hit = 0;
    }
    
    void shotUpdate(Shot shot){
       
    }



};

struct Shot{
    byte shooter;
    byte victim;
};