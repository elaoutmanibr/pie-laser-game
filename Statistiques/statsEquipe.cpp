#include <vector>
#include <string>
#include <functional>
#include "statsPerso.h"
#include "statsEquipe.h"


Team::Team() : id(0), members(), score(0), size(0) {}
Team::Team(int theId, std::string theName, std::vector<Player*> theMembers, int theSize) : id(theId), name(theName), members(theMembers), score(0), size(theSize) {}
Team::~Team(){
  members.resize(0);
  members.shrink_to_fit();
}

void Team::setId(int theId){
  id=theId;
}

void Team::setMembers(std::vector<Player*> theMembers){
  members=theMembers;
}

void Team::setName(std::string theName){
  name=theName;
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

std::string Team::getName(){
  return name;
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
