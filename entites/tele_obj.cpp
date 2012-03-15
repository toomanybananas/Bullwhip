#include "tele_obj.h"

tele_obj::tele_obj()
{
    //ctor
    name = "tele_obj";
}


void tele_obj::onCollision(Entity* obj)
{
    if(obj->GetAttribute("teleport"))
    {
        obj->SetXQ(ox);
        obj->SetYQ(oy);
    }
}

void tele_obj::update(SceneManager* scene)
{
    ox = scene->GetEntity(GetVal<std::string>("entity"))->GetX();
    oy = scene->GetEntity(GetVal<std::string>("entity"))->GetY();
}
