#include "tele_coord.h"

tele_coord::tele_coord()
{
    //ctor
    name = "tele_coord";
    attributes["physics"] = true;
}

bool tele_coord::onCollision(Entity* obj)
{
    if(obj->GetAttribute("teleport"))
    {
        obj->SetXQ((int)mdef.GetVal("tx"));
        obj->SetYQ((int)mdef.GetVal("ty"));
    }
}

Entity* newTele_coord(int i)
{
    return new tele_coord;
}
