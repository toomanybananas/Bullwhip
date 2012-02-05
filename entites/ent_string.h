//Simplistic entity to simply display a static string
#pragma once
#include "../Entity.h"
class ent_string : public Entity
{
    public:
        ent_string();
        virtual void init(Def def);
        virtual void Draw(sf::RenderTarget& win) {win.Draw(str);};
    protected:
        sf::Text str;
        sf::Font f;
    private:
        typedef Entity super;
};
Entity* newEnt_string(int i);
