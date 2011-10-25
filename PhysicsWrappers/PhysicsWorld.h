#pragma once
class PhysicsBody;
class Vec2;
#include "../Definition.h"
class PhysicsWorld
{
    public:
        virtual void Init(Vec2 gravity)=0;
        virtual void* CreateBody(Def d)=0;
        virtual void DestroyBody(PhysicsBody* body)=0;
        virtual void Step(float timestep)=0;
        virtual void SetGravity(Vec2 gravity)=0;
        virtual Vec2 GetGravity()=0;
    protected:
};
