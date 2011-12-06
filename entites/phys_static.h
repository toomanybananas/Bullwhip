//Another pro entity
//Provides basic physics functionality, and is a static platform to boot.
#pragma once
#include <Box2D/Box2D.h>
#include "../Entity.h"
#include "../Constants.h"
#include "../JMath.h"
#include "../Vec2.h"
#include "../PhysicsWrappers/PhysicsBody.h"
#include "../PhysicsWrappers/Box2DPhysics.h"
class phys_static : public Entity
{
    public:
        phys_static();
        virtual void init(Def def);
        virtual void SetX(float m) {body->SetTransform(Vec2(m, GetY()), GetRot());};
        virtual void SetY(float m) {body->SetTransform(Vec2(GetX(), m), GetRot());};

        virtual float GetX() {return body->GetPosition().x;};
        virtual float GetY() {return body->GetPosition().y;};


        virtual void SetRot(float m) {body->SetTransform(body->GetPosition(), toRad(m));};
        virtual float GetRot() {return toDeg(body->GetAngle());};
        virtual void update(SceneManager* scene);
        sf::Sprite& getspr() {return draw;};

        virtual void Destroy() {phys_world->DestroyBody(body);};
    protected:
        PhysicsBody* body; //The actual physics body object.
    private:
        typedef Entity super;
};
Entity* newPhys_static(int i);

