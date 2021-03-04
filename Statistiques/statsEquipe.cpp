#include <vector>
#include <string>
#include <functional>
#include "statsPerso.h"


Team::Team() : id(0), members(), score(0), size(0) {}
Team::Team(int theId, std::vector<Player*> theMembers, int theSize) : id(theId), members(theMembers), size(theSize) {}

void Team::setId(int theId){
  id=theId;
}

void Team::setMembers(std::vector<Player*> theMembers){
  members=theMembers;
}


void Team::setScore(float theScore){
  score=theScore;
}

void Team::addMember(Player *newPlayer){
  memnbers.resize(size+1);
  size++;
  members.push_back(newPlayer);
  (*newPlayer).setTeam(this.id);
}

void Team::rmMember(int theId){
  std::vector<Player*> temp(size-1);
  for(int i=0; i<size; i++){
    if ((*(members[i])).getId()!=theId){
      temp.push_back(member[i]);
    }
    else{
      (*(member[i])).setTeam(0);
    }
  }
  members.swap(temp);
  size--;
}
