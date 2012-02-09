#include "phys_static.h"

phys_static::phys_static()
{
    name = "phys_static";
    attributes["physics"] = true;
}

void phys_static::init(Def def)
{
    super::init(def);

    body = new StaticBody;
    def.SetVal("hw", hw);
    def.SetVal("hh", hh);
    body->Intialize(def, this);
}


void phys_static::update(SceneManager* scene)
{
    Entity::update(scene);
    Vec2 pos = body->GetPosition();
    draw.SetPosition(pos.x, pos.y);
    draw.SetRotation(body->GetAngle());
}
