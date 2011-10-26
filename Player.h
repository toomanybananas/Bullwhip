//Basic player entity.
//Most of the functionality should be handed over to the script.
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "entites/phys_dynamic.h"
#include "Definition.h"

class Player : public phys_dynamic
{
    public:
        Player();
        virtual bool onCollision(Entity* obj);
        virtual void jump();
        virtual void update(SceneManager* scene);
    protected:
        bool can_jump;
        std::string collide;
        float coly;
        sf::Clock jumptimer;
};
Entity* newPlayer(int i);
