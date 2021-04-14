#ifndef __INTERFACE__
#define __INTERFACE__



#include <fstream>
#include <vector>
#include <string>
#include <functional>
#include "statsPerso.h"
#include "statsEquipe.h"


void writeStatsPerso(std::ofstream &file, Player player);

void writeStatsTeam(std::ofstream &file, Team team);


#endif
