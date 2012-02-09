#include "Vec2.h"
#include "Constants.h"
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

b2Vec2 Vec2::tob2()
{
    b2Vec2 newvec;
    newvec.x = x;
    newvec.y = y;
    return newvec;
}

