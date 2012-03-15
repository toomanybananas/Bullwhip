#include "phys_dynamic.h"

phys_dynamic::phys_dynamic()
{
    name = "phys_dynamic";
    attributes["physics"] = true;
}

void phys_dynamic::init()
{
    Entity::init();

    body = new DynamicBody;
    SetVal("hw", hw);
    SetVal("hh", hh);
    body->Intialize(this);
}
