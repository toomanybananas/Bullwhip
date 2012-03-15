#include "phys_static.h"

phys_static::phys_static()
{
    name = "phys_static";
    attributes["physics"] = true;
}

void phys_static::init()
{
    super::init();

    body = new StaticBody;
    SetVal("hw", hw);
    SetVal("hh", hh);
    body->Intialize(this);
}


void phys_static::update(SceneManager* scene)
{
    Entity::update(scene);
    Vec2 pos = body->GetPosition();
    draw.SetPosition(pos.x, pos.y);
    draw.SetRotation(body->GetAngle());
}
