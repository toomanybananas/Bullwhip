#ifndef INVISPHYSENTITY_H
#define INVISPHYSENTITY_H
#include "InvisEntity.h"
#include "phys_static.h"
#include "../SceneManager.h"
class InvisPhysEntity : public phys_static
{
    public:
        InvisPhysEntity();
        virtual void init(Def def);
        virtual void reg(b2World* world);
        void Draw(sf::RenderWindow& win) {};
    protected:
        b2FixtureDef fix_def;
        b2Fixture* fix;
    private:
};

#endif // INVISPHYSENTITY_H
