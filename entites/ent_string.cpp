#include "ent_string.h"

ent_string::ent_string()
{
    //ctor
}

void ent_string::init()
{
    str.SetPosition(GetVal<int>("x"), GetVal<int>("y"));
    lx = GetVal<int>("x");
    ly = GetVal<int>("y");
    str.SetRotation(GetVal<float>("rotation"));
    alive = true;
    f.LoadFromFile("slkscr.ttf");
    str.SetFont(f);
    str.SetCharacterSize(GetVal<int>("size"));
    str.SetString(GetVal<std::string>("text"));
    str.SetColor(sf::Color(GetVal<int>("colorr"), GetVal<int>("colorg"), GetVal<int>("colorb")));
}
