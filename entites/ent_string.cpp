#include "ent_string.h"

ent_string::ent_string()
{
    //ctor
}

void ent_string::init(Def def)
{
    str.SetX(any_cast<int>(def.GetVal("x")));
    str.SetY(any_cast<int>(def.GetVal("y")));
    lx = any_cast<int>(def.GetVal("x"));
    ly = any_cast<int>(def.GetVal("y"));
    str.SetRotation(any_cast<float>(def.GetVal("rotation")));
    alive = true;
    mdef = def;
    f.LoadFromFile("slkscr.ttf");
    str.SetFont(f);
    str.SetCharacterSize(any_cast<int>(def.GetVal("size")));
    str.SetString(any_cast<std::string>(def.GetVal("text")));
    str.SetColor(sf::Color(any_cast<int>(def.GetVal("colorr")), any_cast<int>(def.GetVal("colorg")), any_cast<int>(def.GetVal("colorb"))));
    std::cout << any_cast<std::string>(def.GetVal("text")) << std::endl;
}

Entity* newEnt_string(int i)
{
    return new ent_string;
}
