#ifndef __STATSPERSO__
#define __STATSPERSO__

#include <string>

class Player
{
  private:

    int id; //player id
    std::string name; //player name
    float score; //player score
    int team; //player team (the id of the team). 0 when the player is not in a team

  public:

    Player();
    Player(int playerId, std::string playerName);

    //getters

    int getId();
    std::string getName();
    float getScore();
    int getTeam();

    //setters

    void setId(int theId);
    void setName(std::string theName);
    void setScore(float theScore);
    void setTeam(int theTeam);


};

#endif
