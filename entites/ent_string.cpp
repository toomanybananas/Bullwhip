#include "ent_string.h"

ent_string::ent_string()
{
    //ctor
}

void ent_string::init()
{
    str.setPosition(GetVal<int>("x"), GetVal<int>("y"));
    lx = GetVal<int>("x");
    ly = GetVal<int>("y");
    str.setRotation(GetVal<float>("rotation"));
    alive = true;
    f.loadFromFile("slkscr.ttf");
    str.setFont(f);
    str.setCharacterSize(GetVal<int>("size"));
    str.setString(GetVal<std::string>("text"));
    str.setColor(sf::Color(GetVal<int>("colorr"), GetVal<int>("colorg"), GetVal<int>("colorb")));
}
