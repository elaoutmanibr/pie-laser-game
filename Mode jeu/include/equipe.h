#ifndef EQUIPE_H
#define EQUIPE_H
#include"joueur.h"
#include"baseEquipe.h"
#include<vector>
#include<algorithm>
using namespace std;

class equipe
{
    public:
        equipe();
        virtual ~equipe();
        string getnomE();
        int getscoreE();
        int getnbJtotal();
        int getnbJvivant();
        void setnomE(string nom);
        void setscoreJ(int score);
        void setnbJtotal(int t);
        vector<joueur> getListeJ();
        void setListeJ(vector<joueur> liste);
        void ajouterJoueur(joueur j);
        void supprimerJoueur(joueur j);
        void setJoueursActifs();
        void setBase(baseEquipe);
        baseEquipe getBase();

    private:
        string nomE;
        int scoreE;
        int nbJtotal;
        int nbJvivant;
        vector<joueur> ListeJ;

        baseEquipe base;

};

#endif // EQUIPE_H
