#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "entites/phys_dynamic.h"
#include "Definition.h"

//Nothing to see here, move along
class Player : public phys_dynamic
{
    public:
        Player();
        virtual bool onCollision(Entity* obj);
        virtual void jump();
        virtual void update(const sf::Input& in);
    protected:
        bool can_jump;
        std::string collide;
        float coly;
        sf::Clock jumptimer;
};
Entity* newPlayer(int i);
