//Really quick math library, does almost nothing but convert between my Vec2's and Box2D b2Vec2s
//Should be regulated to a general math library, and let the physics wrappers have tools for converting Vec2's, which should be done behind the scenes.
//Will become common

#pragma once
#include <math.h>
#include "Vec2.h"
#define PI 3.1459265

float distance(float x1, float y1, float x2, float y2);
bool inrange(float n, float x, float y);


float toRad(float deg);
float toDeg(float rad);
Vec2 toReg(b2Vec2 vec);
