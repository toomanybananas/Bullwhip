#include "InvisPhysEntity.h"

InvisPhysEntity::InvisPhysEntity()
{
    //ctor
    attributes["physics"] = true;
}

void InvisPhysEntity::init(Def def)
{
    draw.SetX((int)def.GetVal("x"));
    draw.SetY((int)def.GetVal("y"));
    lx = (int)def.GetVal("x");
    ly = (int)def.GetVal("y");
    draw.SetRotation(def.GetFloat("rotation"));
    alive = true;
    mdef = def;

    //physics initzilizatrion
    body_def.position.Set((lx + ((int)def.GetVal("width") / 2.f)) * SCALE, (ly + ((int)def.GetVal("height") / 2.f)) * SCALE);
    body_def.angle = toRad(draw.GetRotation());
    body_def.userData = this;
    body_def.type = b2_staticBody;
    bounding.SetAsBox( ((int)def.GetVal("width") / 2.f) * SCALE, ((int)def.GetVal("height") / 2.f) * SCALE);
    fix_def.density = 1.0f;
    fix_def.friction = 1.0f;
    fix_def.shape = &bounding;
    fix_def.isSensor = true;
}

void InvisPhysEntity::reg(b2World* world)
{
    body = world->CreateBody(&body_def);
    fix = body->CreateFixture(&fix_def);
}
