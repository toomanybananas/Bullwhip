#include "ent_item.h"

ent_item::ent_item()
{
    //ctor
    name = "ent_item";
}

void ent_item::init(Def def)
{
    Entity::init(def);
    super::init(def);
}
