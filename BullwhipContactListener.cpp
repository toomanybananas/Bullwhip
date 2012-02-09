#include "BullwhipContactListener.h"
using namespace std;
BullwhipContactListener::BullwhipContactListener()
{
    //ctor
}

void BullwhipContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
    Entity* a;
    Entity* b;
    a = (Entity*)contact->GetFixtureA()->GetBody()->GetUserData();
    b = (Entity*)contact->GetFixtureB()->GetBody()->GetUserData();
    a->onCollision(b);
    b->onCollision(a);

}

void BullwhipContactListener::BeginContact(b2Contact* contact)
{
    Entity* a;
    Entity* b;
    a = (Entity*)contact->GetFixtureA()->GetBody()->GetUserData();
    b = (Entity*)contact->GetFixtureB()->GetBody()->GetUserData();
    a->onBeginCollision(b);
    b->onBeginCollision(a);
}

void BullwhipContactListener::EndContact(b2Contact* contact)
{
    Entity* a;
    Entity* b;
    a = (Entity*)contact->GetFixtureA()->GetBody()->GetUserData();
    b = (Entity*)contact->GetFixtureB()->GetBody()->GetUserData();
    a->onEndCollision(b);
    b->onEndCollision(a);
}
