#ifndef MATCH_A_MORT_H
#define MATCH_A_MORT_H
#include"mode_jeu.h"
#include"baseEquipe.h"
#include<algorithm>
#include<vector>
using namespace std;

class match_a_mort:public mode_jeu
{
    public:
        match_a_mort();
        match_a_mort(equipe,equipe);
        virtual ~match_a_mort();
        void eliminerJoueur(joueur);
        void mettreajouretat(vector<pair<joueur,action>> changement);

    protected:

    private:
        int const duree=10;

};

#endif // MATCH_A_MORT_H
