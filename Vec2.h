//Vector 2
//To be common
//Needs to be better, plus not include transforming functions
//Let the physics libraries implement static functions for that.
#ifndef VEC2_H
#define VEC2_H
#include <Box2D/Box2D.h>


class Vec2
{
    public:
        Vec2();
        Vec2(float m, float n) {x = m; y = n;};
        float x;
        float y;
        b2Vec2 toBox();
        b2Vec2 tob2();
    protected:
    private:
};

#endif // VEC2_H

