//Incredibly crappy debug box that pops up a window with the entity's postition
//Going to be removed soon.

#ifndef INFOBOX_H
#define INFOBOX_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <string>
#include <sstream>


class InfoBox
{
    public:
        InfoBox(Entity& o);
        Entity& Getobj() {return obj;};
        void Setobj(Entity& val) {obj = val;}
        void draw();
    protected:
    private:
        Entity& obj;
        sf::RenderWindow box;
        sf::Font arial;
};

#endif
