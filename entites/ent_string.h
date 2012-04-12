//Simplistic entity to simply display a static string
#pragma once
#include "../Entity.h"
class ent_string : public Entity
{
    public:
        ent_string();
        virtual void init();
        virtual void Draw(sf::RenderTarget& win) {win.draw(str);};
    protected:
        sf::Text str;
        sf::Font f;
    private:
        typedef Entity super;
};
