//Basic player entity.
//Most of the functionality should be handed over to the script.
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "entites/phys_dynamic.h"
#include "Actor.h"
#include "Definition.h"
#include "Item.h"
#include "SceneManager.h"

class Player : public Actor
{
    public:
        Player();
        //virtual void onCollision(Entity* obj);
        virtual void onBeginCollision(Entity* obj);
        virtual void onEndCollision(Entity* obj);
        virtual void update(SceneManager* scene);
    protected:
        //bool can_jump;
        Inventory inv;
        Entity* pickup;
    private:
        typedef Actor super;
};
