#include "InvisEntity.h"

InvisEntity::InvisEntity()
{
    //ctor
}

void InvisEntity::init(Def def)
{
    draw.SetX(def.GetVal<int>("x"));
    draw.SetY(def.GetVal<int>("y"));
    lx = def.GetVal<int>("x");
    ly = def.GetVal<int>("y");
    alive = true;
    mdef = def;
}
