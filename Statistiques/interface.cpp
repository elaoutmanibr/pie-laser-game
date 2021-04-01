#include <fstream>
#include <vector>
#include <string>
#include <functional>
#include "statsPerso.h"
#include "statsEquipe.h"
#include "interface.h"

void writeStats(ofstream file, Player player){
  file << "Personal statistics : \n";
  file << "Player name : " << player.getName() << "\n";
  file << "Score : " << player.getScore() << "\n";
  file << "Member of the team n° : " << player.getTeam() << "\n";

}
