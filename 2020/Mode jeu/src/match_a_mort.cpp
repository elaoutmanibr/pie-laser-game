#include "match_a_mort.h"

match_a_mort::match_a_mort()
{
    //ctor
}
match_a_mort::match_a_mort(equipe E1,equipe E2)
{
    this->E1 = E1;
    this->E2 = E2;
}

match_a_mort::~match_a_mort()
{
    //dtor
}
void match_a_mort::eliminerJoueur(joueur j)
{
    j.setActif(false);
    vector<joueur> ListJ1 = E1.getListeJ();
    vector<joueur> ListJ2 = E2.getListeJ();

    if(find(ListJ1.begin(),ListJ1.end(),j) != ListJ1.end()){
        baseEquipe bEquipe = E1.getBase();
        j.setPosition(bEquipe.getPosition());
    }else if(find(ListJ2.begin(),ListJ2.end(),j) != ListJ2.end()){
        baseEquipe bEquipe = E2.getBase();
        j.setPosition(bEquipe.getPosition());
    }
}

void match_a_mort::mettreajouretat(vector<pair<joueur,action>> changement)
{

}
