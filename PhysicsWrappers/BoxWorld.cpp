#include "BoxWorld.h"
#include "../BullwhipContactListener.h"
#include "../Vec2.h"
BoxWorld::BoxWorld()
{
    //ctor
}

void BoxWorld::Init(Vec2 gravity)
{
    world = new b2World(gravity.toBox());
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
    b2BodyDef bdef = d.GetVal<b2BodyDef>("def");
    return (void*)world->CreateBody(&bdef);
}
