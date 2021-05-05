#ifndef MODE_JEU_H
#define MODE_JEU_H
#include"equipe.h"
#include"action.h"
#include"joueur.h"
using namespace std;

class mode_jeu
{
    public:
        mode_jeu();
        mode_jeu(equipe E1, equipe E2);
        virtual ~mode_jeu();
        bool JeuTermine();
        virtual void mettreajouretat(vector<pair<joueur,action>> changement)=0;
        virtual void eliminerJoueur(joueur)=0;

        equipe E1;
        equipe E2;
    protected:


    private:

};

#endif // MODE_JEU_H
