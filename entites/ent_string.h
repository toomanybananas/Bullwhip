#pragma once
#include "../Entity.h"
class ent_string : public Entity
{
    public:
        ent_string();
        virtual void init(Def def);
        virtual void Draw(sf::RenderWindow& win) {win.Draw(str);};
    protected:
        sf::String str;
        sf::Font f;
    private:
};
Entity* newEnt_string(int i);
