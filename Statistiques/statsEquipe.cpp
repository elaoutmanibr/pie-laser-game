#include <vector>
#include <string>
#include <functional>
#include "statsPerso.h"
#include "statsEquipe.h"


Team::Team() : id(0), members(), score(0), size(0) {}
Team::Team(int theId, std::vector<Player*> theMembers, int theSize) : id(theId), members(theMembers), score(0), size(theSize) {}

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
  members.resize(size+1);
  size++;
  members.push_back(newPlayer);
  (*newPlayer).setTeam(id);
}

void Team::rmMember(int theId){
  std::vector<Player*> temp(size-1);
  for(int i=0; i<size; i++){
    if ((*(members[i])).getId()!=theId){
      temp.push_back(members[i]);
    }
    else{
      (*(members[i])).setTeam(0);
    }
  }
  members.swap(temp);
  size--;
}


void Team::upScore(){
  float val;
  for(int i=0; i<size; i++){
      val += (*(members[i])).getScore();
  }
  score=val;
}

int Team::getId(){
  return id;
}

std::vector<Player*> Team::getMembers(){
  return members;
}

float Team::getScore(){
  return score;
}

int Team::getSize(){
  return size;
}
