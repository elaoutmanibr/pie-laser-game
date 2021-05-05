#include "position.h"

position::position()
{
    //ctor
}
position::position(const position& p){
    this->x = p.x;
    this->y = p.y;
}
position::~position()
{
    //dtor
}
