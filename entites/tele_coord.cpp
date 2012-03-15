#include "tele_coord.h"

tele_coord::tele_coord()
{
    //ctor
    name = "tele_coord";
    attributes["physics"] = true;
}

void tele_coord::onCollision(Entity* obj)
{
    if(obj->GetAttribute("teleport"))
    {
        obj->SetXQ(GetVal<int>("tx"));
        obj->SetYQ(GetVal<int>("ty"));
    }
}
