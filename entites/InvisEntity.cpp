#include "InvisEntity.h"

InvisEntity::InvisEntity()
{
    //ctor
}

void InvisEntity::init(Def def)
{
    draw.SetX((int)def.GetVal("x"));
    draw.SetY((int)def.GetVal("y"));
    lx = (int)def.GetVal("x");
    ly = (int)def.GetVal("y");
    alive = true;
    mdef = def;
}
