#include "InvisEntity.h"

InvisEntity::InvisEntity()
{
    //ctor
}

void InvisEntity::init()
{
    draw.setPosition(GetVal<int>("x"), GetVal<int>("y"));
    lx = GetVal<int>("x");
    ly = GetVal<int>("y");
    alive = true;
}
