#include "jeu.h"

jeu::jeu()
{
    //ctor
}

jeu::~jeu()
{
    //dtor
}
void jeu::initialiserJeu()
    {
        int c;
        joueur J1("liu","arthur",21,score_init);
        joueur J2("mokni","amani",22,score_init);
        joueur J3("ghrabli","mehdi",22,score_init);
        joueur J4("agrebi","afef",23,score_init);
        joueur J5("loric","andre",23,score_init);
        joueur J6("guerillon","tristan",23,score_init);
        equipe E1;
        equipe E2;
        E1.ajouterJoueur(J1);
        E1.ajouterJoueur(J2);
        E1.ajouterJoueur(J3);
        E2.ajouterJoueur(J4);
        E2.ajouterJoueur(J5);
        E2.ajouterJoueur(J6);

        E1.setJoueursActifs();
        E2.setJoueursActifs();

        if (c==1)
        {
            this->M= new match_a_mort(E1,E2);
        }
        else if (c==2)
        {
            //à compléter
        }
    }
void jeu::commencerJeu()
{
    while (!(M->JeuTermine()))
    {
        vector<pair<joueur,action>> changement;

        vector<joueur> E1 = M->E1.getListeJ();
        for (int j = 0;j<E1.size();j++)
        {
            action a = E1[j].choisirUneAction();
            changement.push_back(make_pair(E1[j],a));
        }
        vector<joueur> E2 = M->E2.getListeJ();
        for (int j = 0;j<E2.size();j++)
        {
            action a = E2[j].choisirUneAction();
            changement.push_back(make_pair(E2[j],a));
        }
        M->mettreajouretat(changement);
    }
}
