#ifndef VEC2_H
#define VEC2_H
#include "Constants.h"
#include <Box2D/Box2D.h>


class Vec2
{
    public:
        Vec2();
        Vec2(float m, float n) {x = m; y = n;};
        float x;
        float y;
        b2Vec2 toBox();
    protected:
    private:
};

#endif // VEC2_H
