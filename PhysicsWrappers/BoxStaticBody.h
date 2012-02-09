#pragma once
#include <Box2D/Box2D.h>
#include "PhysicsBody.h"
#include "../Vec2.h"
#include "../JMath.h"
#include "../Constants.h"
class BoxStaticBody : public PhysicsBody
{
    public:
        BoxStaticBody();
        virtual void Intialize(Def d, Entity* obj);
        void SetTransform(Vec2 pos, float angle) {body->SetTransform(pos.toBox(), toRad(angle));};
        Vec2 GetPosition() {return toReg(body->GetPosition());};
        float GetAngle() {return toDeg(body->GetAngle());};
        void SetLinearVelocity(Vec2 v) {body->SetLinearVelocity(v.toBox());};
        Vec2 GetLinearVelocity() {return toReg(body->GetLinearVelocity());};
        float GetAngularVelocity() {return toDeg(body->GetAngularVelocity());};
        void SetAngularVelocity(float v) {body->SetAngularVelocity(toRad(v));};
        void ApplyForce(Vec2 force, Vec2 point) {body->ApplyForce(force.toBox(), point.toBox());};
        void ApplyForce(Vec2 force) {body->ApplyForce(force.tob2(), body->GetWorldPoint(body->GetLocalCenter()));};
        void ApplyTorque(float torque) {body->ApplyTorque(toRad(torque));};
        void* GetBody() {return body;};
    protected:
        b2Body* body;
        b2BodyDef body_def;
        b2PolygonShape bounding;
};
