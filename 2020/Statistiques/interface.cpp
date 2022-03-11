#include <fstream>
#include <vector>
#include <string>
#include <functional>
#include "statsPerso.h"
#include "statsEquipe.h"
#include "interface.h"

void writeStatsPerso(std::ofstream &file, Player player){
  file << "Personal statistics : \n";
  file << "Player name : " << player.getName() << "\n";
  file << "Score : " << player.getScore() << "\n";
  file << "Member of the team number : " << player.getTeam() << "\n";

}

void writeStatsTeam(std::ofstream &file, Team team){
  const std::string line_prefix("    ");
  int size = team.getSize();
  std::vector<Player*> members = team.getMembers();
  file << "Statistics of the team number "<< team.getId() <<" :\n";
  file << "Name : " << team.getName() << "\n";
  file << "Score : " << team.getScore() << "\n";
  for (int i=0; i<size; i++){
    file << line_prefix << "Player name : " << (*(members[i])).getName() <<" / "<< "Score : " << (*(members[i])).getScore() << "\n";
  }
  members.resize(0);
  members.shrink_to_fit();
}
