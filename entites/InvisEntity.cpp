#include "InvisEntity.h"

InvisEntity::InvisEntity()
{
    //ctor
}

void InvisEntity::init(Def def)
{
    draw.SetX(any_cast<int>(def.GetVal("x")));
    draw.SetY(any_cast<int>(def.GetVal("y")));
    lx = any_cast<int>(def.GetVal("x"));
    ly = any_cast<int>(def.GetVal("y"));
    alive = true;
    mdef = def;
}
