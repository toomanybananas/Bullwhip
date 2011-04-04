#include "phys_dynamic.h"

phys_dynamic::phys_dynamic()
{
    name = "phys_dynamic";
    attributes["physics"] = true;
}

void phys_dynamic::init(Def def)
{
    draw.SetImage(*gImageManager.getResource(def.GetString("image")));
    hw = draw.GetSize().x / 2;
    hh = draw.GetSize().y / 2;
    draw.SetCenter(hw, hh);

    draw.SetX((int)def.GetVal("x"));
    draw.SetY((int)def.GetVal("y"));
    lx = (int)def.GetVal("x");
    ly = (int)def.GetVal("y");
    draw.SetRotation(def.GetFloat("rotation"));
    alive = true;
    solid = (bool)def.GetVal("solid");
    mdef = def;

    //physics initzilizatrion
    body_def.position.Set(lx * SCALE, ly * SCALE);
    body_def.angle = toRad(draw.GetRotation());
    body_def.userData = this;
    body_def.type = b2_dynamicBody;
    bounding.SetAsBox( (draw.GetSize().x / 2.f) * SCALE, (draw.GetSize().y / 2.f) * SCALE);
    fix_def.density = 1.0f;
    fix_def.friction = 1.0f;
    fix_def.shape = &bounding;
}

void phys_dynamic::reg(b2World* world)
{
    body = world->CreateBody(&body_def);
    fix = body->CreateFixture(&fix_def);
}

Entity* newPhys_dynamic(int i)
{
    return new phys_dynamic;
}
