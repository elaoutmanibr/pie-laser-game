#include "mode_jeu.h"

mode_jeu::mode_jeu()
{
    //ctor
}

mode_jeu::mode_jeu(equipe E1, equipe E2)
{
     this->E1=E1;
     this->E2=E2;
}

mode_jeu::~mode_jeu()
{
    //dtor
}
bool mode_jeu::JeuTermine()
{
        return true;
}

void mode_jeu::mettreajouretat(vector<pair<joueur,action>> changement)
{
    //
}
