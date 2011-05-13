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
    if((!a->onCollision(b)) || (!b->onCollision(a)))
        contact->SetEnabled(false);

}

void BullwhipContactListener::BeginContact(b2Contact* contact)
{
    Entity* a;
    Entity* b;
    a = (Entity*)contact->GetFixtureA()->GetBody()->GetUserData();
    b = (Entity*)contact->GetFixtureB()->GetBody()->GetUserData();
    if((!a->onCollision(b)) || (!b->onCollision(a)))
        contact->SetEnabled(false);

}
