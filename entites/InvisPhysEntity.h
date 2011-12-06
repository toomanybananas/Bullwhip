//Slightly more useful than InvisEntity
//Is invisible, but uses a trigger body to detect a collision callback.
#pragma once
#include "../Constants.h"
#include "InvisEntity.h"
#include "phys_static.h"
#include "../SceneManager.h"
class InvisPhysEntity : public phys_static
{
    public:
        InvisPhysEntity();
        virtual void init(Def def);
        void Draw(sf::RenderWindow& win) {};
    protected:
    private:
        typedef phys_static super;
};


