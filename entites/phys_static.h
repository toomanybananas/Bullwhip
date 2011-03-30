#pragma once
#include <Box2D/Box2D.h>
#include "../Entity.h"
#include "../Constants.h"
#include "../JMath.h"
#include "../Vec2.h"
class phys_static : public Entity
{
    public:
        phys_static();
        virtual void init(Def def);
        virtual void SetX(float m) {body->SetTransform(b2Vec2(m * SCALE, GetY() * SCALE), toRad(GetRot()));};
        virtual void SetY(float m) {body->SetTransform(b2Vec2(GetX() * SCALE, m * SCALE), toRad(GetRot()));};

        virtual float GetX() {return body->GetPosition().x / SCALE;};
        virtual float GetY() {return body->GetPosition().y / SCALE;};


        virtual void SetRot(float m) {body->SetTransform(body->GetPosition(), toRad(m));};
        virtual float GetRot() {return toDeg(body->GetAngle());};
        virtual void reg(b2World* world);
        virtual void update(const sf::Input& in);
        sf::Sprite& getspr() {return draw;};
    protected:
        b2Body* body;
        b2BodyDef body_def;
        b2PolygonShape bounding;
};

