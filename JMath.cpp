
#include "JMath.h"

float distance(float x1, float y1, float x2, float y2)
{
    float d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return d;
}

bool inrange(float n, float x, float y)
{
    if(n > x && n < y)
        return true;
    return false;
}


float toRad(float deg)
{
    return deg * (PI / 180);
}

float toDeg(float rad)
{
    return (rad * 180) / PI;
}
