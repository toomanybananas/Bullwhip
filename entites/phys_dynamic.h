#ifndef PHYS_DYNAMIC_H
#define PHYS_DYNAMIC_H

#include "phys_static.h"


class phys_dynamic : public phys_static
{
    public:
        phys_dynamic();
        virtual void init(Def def);
        virtual void reg(b2World* world);
        virtual void ApplyForce(Vec2 force, Vec2 point) {body->ApplyForce(force.toBox(), body->GetWorldPoint(body->GetLocalCenter()));};
        virtual void SetXVel(float m) {body->SetLinearVelocity(b2Vec2(m * SCALE, body->GetLinearVelocity().y));};
    protected:
        b2FixtureDef fix_def;
        b2Fixture* fix;
};

#endif // PHYS_DYNAMIC_H
