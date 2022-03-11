#include <fstream>
#include <vector>
#include <string>
#include <functional>
#include "statsPerso.h"
#include "statsEquipe.h"
#include "interface.h"


int main(){
    Player player1;
    Player player2;
    Team team;
    player1.setId(1);
    player1.setName("Didier");
    player2.setId(2);
    player2.setName("Jeanne");
    team.setId(1);
    team.setName("Les rouges");
    // std::vector<Player*> theMembers;
    // theMembers.push_back(&player1);
    // theMembers.push_back(&player2);
    team.addMember(&player1);
    team.addMember(&player2);
    std::ofstream fs("test.txt", std::ios_base::app | std::ios_base::out);
    writeStatsPerso(fs, player1);
    writeStatsTeam(fs, team);
    fs.close();
    return 0;
}