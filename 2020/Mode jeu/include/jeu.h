#ifndef JEU_H
#define JEU_H
#include "equipe.h"
#include "joueur.h"
#include "mode_jeu.h"
#include "match_a_mort.h"
using namespace std;
class jeu
{
    public:
        jeu();
        virtual ~jeu();
        void commencerJeu();
        void initialiserJeu();

    private:
        int score_init=100;
        mode_jeu* M;
};

#endif // JEU_H
