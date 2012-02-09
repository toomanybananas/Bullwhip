#include "phys_dynamic.h"

phys_dynamic::phys_dynamic()
{
    name = "phys_dynamic";
    attributes["physics"] = true;
}

void phys_dynamic::init(Def def)
{
    Entity::init(def);

    body = new DynamicBody;
    def.SetVal("hw", hw);
    def.SetVal("hh", hh);
    body->Intialize(def, this);
}
