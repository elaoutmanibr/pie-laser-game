#ifndef BASEEQUIPE_H
#define BASEEQUIPE_H
#include"position.h"
using namespace std;

class baseEquipe
{
    public:
        baseEquipe();
        baseEquipe(position p);
        virtual ~baseEquipe();
        position getPosition();

    protected:

    private:
        position pos;
};

#endif // BASEEQUIPE_H
