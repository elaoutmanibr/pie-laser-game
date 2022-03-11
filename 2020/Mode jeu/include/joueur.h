#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include"action.h"
#include"bouger.h"
#include"tirer.h"
#include"position.h"
using namespace std;

class joueur
{
    public:
        joueur();
        joueur(const joueur&);
        joueur (string nom, string prenom, int age, int score);
        virtual ~joueur();
        string getnomJ();
        void setnomJ(string nom);
        string getprenomJ();
        void setprenomJ(string prenom);
        int getageJ();
        void setageJ(int age);
        int getscoreJ();
        void setscoreJ(int score);
        bool operator== (const joueur& J);
        action choisirUneAction();
        void setPosition(position p);
        position getPosition();

        void setActif(bool);

    private:
        string nomJ;
        string prenomJ;
        int ageJ;
        int scoreJ;

        position pos;
        bool actif = true;





};

#endif // JOUEUR_H
