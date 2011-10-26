#include "tele_obj.h"

tele_obj::tele_obj()
{
    //ctor
    name = "tele_obj";
}

Entity* newTele_obj(int i)
{
    return new tele_obj;
}

bool tele_obj::onCollision(Entity* obj)
{
    if(obj->GetAttribute("teleport"))
    {
        obj->SetXQ(ox);
        obj->SetYQ(oy);
    }
    return true;
}

void tele_obj::update(SceneManager* scene)
{
    ox = scene->GetEntity(mdef.GetString("entity"))->GetX();
    oy = scene->GetEntity(mdef.GetString("entity"))->GetY();
}
