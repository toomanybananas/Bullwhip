#include "Vec2.h"

Vec2::Vec2()
{
    //ctor
}

b2Vec2 Vec2::toBox()
{
    b2Vec2 newvec;
    newvec.x = x * SCALE;
    newvec.y = y * SCALE;
    return newvec;
}
