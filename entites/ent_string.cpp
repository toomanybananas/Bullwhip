#include "ent_string.h"

ent_string::ent_string()
{
    //ctor
}

void ent_string::init(Def def)
{
    str.SetX((int)def.GetVal("x"));
    str.SetY((int)def.GetVal("y"));
    lx = (int)def.GetVal("x");
    ly = (int)def.GetVal("y");
    str.SetRotation(def.GetFloat("rotation"));
    alive = true;
    mdef = def;
    f.LoadFromFile("slkscr.ttf");
    str.SetFont(f);
    str.SetSize((int)def.GetVal("size"));
    str.SetText(def.GetString("text"));
    str.SetColor(sf::Color((int)def.GetVal("colorr"), (int)def.GetVal("colorg"), (int)def.GetVal("colorb")));
    std::cout << def.GetString("text") << std::endl;
}

Entity* newEnt_string(int i)
{
    return new ent_string;
}
