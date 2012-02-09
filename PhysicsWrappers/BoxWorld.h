#ifndef BOXWORLD_H
#define BOXWORLD_H

#include "PhysicsWorld.h"
#include "PhysicsBody.h"
#include "../BullwhipContactListener.h"
#include <Box2D/Box2D.h>
#include "../Vec2.h"
class BullwhipContactListener;

class BoxWorld : public PhysicsWorld
{
    public:
        BoxWorld();
        void Init(Vec2 gravity);
        void* CreateBody(Def d);
        void DestroyBody(PhysicsBody* body) {world->DestroyBody((b2Body*)body->GetBody());};
        void Step(float timestep);
        void SetGravity(Vec2 gravity) {};
        Vec2 GetGravity() {return Vec2(0,0);};
    protected:
        b2World* world;
        BullwhipContactListener* bclisten;
    private:
};

#endif // BOXWORLD_H
