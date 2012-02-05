#include "ent_string.h"

ent_string::ent_string()
{
    //ctor
}

void ent_string::init(Def def)
{
    str.SetX(def.GetVal<int>("x"));
    str.SetY(def.GetVal<int>("y"));
    lx = def.GetVal<int>("x");
    ly = def.GetVal<int>("y");
    str.SetRotation(def.GetVal<float>("rotation"));
    //angle = any_cast<float>(def.GetVal("rotation"));
    alive = true;
    mdef = def;
    f.LoadFromFile("slkscr.ttf");
    str.SetFont(f);
    str.SetCharacterSize(def.GetVal<int>("size"));
    str.SetString(def.GetVal<std::string>("text"));
    str.SetColor(sf::Color(def.GetVal<int>("colorr"), def.GetVal<int>("colorg"), def.GetVal<int>("colorb")));
}

Entity* newEnt_string(int i)
{
    return new ent_string;
}
