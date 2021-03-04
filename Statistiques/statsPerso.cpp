#include "statsPerso.h"
#include <string>



Player::Player(): id(-1), name("Default"), score(0), team(0) {}

Player::Player(int playerId, std::string playerName): id(playerId), name(playerName), score(0), team(0) {}

int Player::getId(){
  return id;
}

std::string Player::getName(){
  return name;
}

float Player::getScore(){
  return score;
}

int Player::getTeam(){
  return team;
}


void Player::setId(int theId){
  id=theId;
}

void Player::setName(std::string theName){
  name=theName;
}

void Player::setScore(float theScore){
  score=theScore;
}

void Player::setTeam(int theTeam){
  team=theTeam;
}
