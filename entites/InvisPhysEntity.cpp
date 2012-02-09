#include "InvisPhysEntity.h"

InvisPhysEntity::InvisPhysEntity()
{
    //ctor
    attributes["physics"] = true;
}

void InvisPhysEntity::init(Def def)
{
    draw.SetPosition(def.GetVal<int>("x"), def.GetVal<int>("y"));
    alive = true;
    mdef = def;

    body = new TriggerBody;
    def.SetVal("hw", hw);
    def.SetVal("hh", hh);
    body->Intialize(def, this);
}

