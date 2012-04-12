#include "InvisPhysEntity.h"

InvisPhysEntity::InvisPhysEntity()
{
    //ctor
    attributes["physics"] = true;
}

void InvisPhysEntity::init()
{
    draw.setPosition(GetVal<int>("x"), GetVal<int>("y"));
    alive = true;

    body = new TriggerBody;
    SetVal("hw", hw);
    SetVal("hh", hh);
    body->Intialize(this);
}

