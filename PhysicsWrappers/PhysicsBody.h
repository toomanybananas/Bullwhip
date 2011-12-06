#pragma once
#include "../Vec2.h"
#include "../JMath.h"
//#include "../Constants.h"
#include "../Definition.h"
//Simple wrapper to make the engine physics engine independent.
class Vec2;
class Entity;
//Body type defines
#define BODY_DUMMY 0
#define BODY_STATIC 1
#define BODY_DYNAMIC 2
#define BODY_TRIGGER 3

class PhysicsBody
{
    public:
        virtual void Intialize(Def d, Entity* obj)=0;
        virtual void SetTransform(Vec2 pos, float angle)=0;
        virtual Vec2 GetPosition()=0;
        virtual float GetAngle()=0;
        virtual void SetLinearVelocity(Vec2 v)=0;
        virtual void SetAngularVelocity(float angle)=0;
        virtual Vec2 GetLinearVelocity()=0;
        virtual float GetAngularVelocity()=0;
        virtual void ApplyForce(Vec2 force, Vec2 point)=0;
        virtual void ApplyForce(Vec2 force)=0;
        virtual void ApplyTorque(float torque)=0;
        virtual int GetType() {return type;};
        virtual void* GetBody()=0;
    protected:
        int type;
    private:
};
