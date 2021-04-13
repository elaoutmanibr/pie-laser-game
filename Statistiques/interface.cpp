#include <fstream>
#include <vector>
#include <string>
#include <functional>
#include "statsPerso.h"
#include "statsEquipe.h"
#include "interface.h"

void writeStatsPerso(std::ofstream file, Player player){
  file << "Personal statistics : \n";
  file << "Player name : " << player.getName() << "\n";
  file << "Score : " << player.getScore() << "\n";
  file << "Member of the team n° : " << player.getTeam() << "\n";

}

void writeStatsTeam(std::ofstream file, Team team){
  int size = team.getSize();
  std::vector<Player*> members = team.getMembers();
  file << "Statistics of the team number "<< team.getId() <<" :\n";
  file << "Score : " << team.getScore() << "\n";
  for (int i=0; i<size; i++){
    file << "\t" << "Player name : " << (*(members[i])).getName() <<" / "<< "Score : " << (*(members[i])).getScore() << "\n";
  }
}
