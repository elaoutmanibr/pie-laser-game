#include "equipe.h"

equipe::equipe()
{
    //ctor
}

equipe::~equipe()
{
    //dtor
}


string equipe::getnomE()
    {
        return nomE;
    }
int equipe::getscoreE()
    {
        return scoreE;
    }
int equipe::getnbJtotal()
    {
        return nbJtotal;
    }
int equipe::getnbJvivant()
    {
        return nbJvivant;
    }
void equipe::setnomE(string nom)
    {
        this->nomE=nom;
    }
void equipe::setscoreJ(int score)
    {
        this->scoreE=score;
    }
void equipe::setnbJtotal(int t)
    {
        this->nbJtotal=t;
    }
vector<joueur> equipe::getListeJ()
    {
        return ListeJ;
    }
void equipe::setListeJ(vector<joueur> liste)
    {
        ListeJ=liste;
    }
void equipe::ajouterJoueur(joueur j)
    {
        ListeJ.push_back(j);
    }

void equipe::supprimerJoueur(joueur j)
    {
        remove(ListeJ.begin(),ListeJ.end(),j);
    }
void equipe::setJoueursActifs()
    {
        for (int j = 0;j<ListeJ.size();j++)
        {
            ListeJ[j].setActif(true);
        }
    }
void equipe::setBase(baseEquipe base)
    {
        this->base = base;
    }
baseEquipe equipe::getBase()
    {
        return base;
    }
