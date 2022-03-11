#include "joueur.h"

joueur::joueur()
{
    //ctor


}

joueur::joueur(const joueur& J)
{
   this->setnomJ(J.nomJ);
   this->setageJ(J.ageJ);
   this->setprenomJ(J.prenomJ);
   this->setscoreJ(J.scoreJ);
}
joueur::joueur (string nom, string prenom, int age, int score)
{
    this->setnomJ(nom);
   this->setageJ(age);
   this->setprenomJ(prenom);
   this->setscoreJ(score);
}

joueur::~joueur()
{
    //dtor
}

string joueur::getnomJ()
        {
            return nomJ;
        }
void joueur::setnomJ(string nom)
    {
        this->nomJ=nom;
}
string joueur::getprenomJ()
        {
            return prenomJ;
        }
void joueur::setprenomJ(string prenom)
        {
            this->prenomJ=prenom;
        }
int joueur::getageJ()
        {
            return ageJ;
        }
void joueur::setageJ(int age)
        {
            this->ageJ=age;
        }
int joueur::getscoreJ()
        {
            return scoreJ;
        }
void joueur::setscoreJ(int score)
        {
            this->scoreJ=score;
        }
bool joueur::operator== (const joueur& J)
        {
            return ((this->nomJ==J.nomJ) &&(this->prenomJ==J.prenomJ));
        }
action joueur::choisirUneAction()
    {
        if(actif)
        {
            int a = 1;
            switch(a){
                case 1:
                    return bouger(this->getPosition());
                case 2:
                    return tirer();
            }
        }
    }

void joueur::setPosition(position p)
    {
        this->pos = p;
    }

position joueur::getPosition()
    {
        return pos;
    }

void joueur::setActif(bool actif)
    {
        this->actif = actif;
    }
