#include "BoxWorld.h"
#include "../BullwhipContactListener.h"
#include "../Vec2.h"
BoxWorld::BoxWorld()
{
    //ctor
}

void BoxWorld::Init(Vec2 gravity)
{
    world = new b2World(gravity.toBox(), true);
    bclisten = new BullwhipContactListener;
    world->SetContactListener(bclisten);
}

void BoxWorld::Step(float timestep)
{
    world->Step(timestep, 10, 10);
    world->ClearForces();
}

void* BoxWorld::CreateBody(Def d)
{
    b2BodyDef bdef = *(b2BodyDef*)d.GetVal("def");
    return (void*)world->CreateBody(&bdef);
}
