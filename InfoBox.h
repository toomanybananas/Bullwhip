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
