#ifndef BOUGER_H
#define BOUGER_H
#include"action.h"
#include"position.h"
using namespace std;

class bouger:public action
{
    public:
        bouger();
        bouger(position);
        virtual ~bouger();

    protected:

    private:
};

#endif // BOUGER_H
