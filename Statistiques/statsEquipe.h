#ifndef __STATSEQUIPE__
#define __STATSEQUIPE__

#include <vector>
#include <string>
#include <functional>
#include "statsPerso.h"

class Team
{
  private:
    int id; //id of the team, 0 is the default value
    std::string name; //name of the team
    std::vector<Player*> members; //list of players in the team
    float score;
    int size; //number of players in the team

  public:

    Team();
    Team(int theId, std::string theName, std::vector<Player*> theMembers, int theSize);
    ~Team();

    void setId(int theId);
    void setName(std::string theName);
    void setMembers(std::vector<Player*> theMembers);
    void setScore(float theScore);
    void addMember(Player* newPlayer);
    void rmMember(int theId);
    void upScore();

    int getId();
    std::string getName();
    std::vector<Player*> getMembers();
    float getScore();
    int getSize();

};


#endif
