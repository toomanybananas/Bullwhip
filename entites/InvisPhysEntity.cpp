#include "InvisPhysEntity.h"

InvisPhysEntity::InvisPhysEntity()
{
    //ctor
    attributes["physics"] = true;
}

void InvisPhysEntity::init(Def def)
{
    /*draw.SetX((int)def.GetVal("x")); //Not quite sure why this is here, commenting it out for now
    draw.SetY((int)def.GetVal("y"));
    lx = (int)def.GetVal("x");
    ly = (int)def.GetVal("y");
    draw.SetRotation(def.GetFloat("rotation"));*/
    alive = true;
    mdef = def;

    body = new TriggerBody;
    def.SetVal("hw", hw);
    def.SetVal("hh", hh);
    body->Intialize(def, this);
}

