#include "phys_static.h"

phys_static::phys_static()
{
    name = "phys_static";
    attributes["physics"] = true;
}

void phys_static::init(Def def)
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
    bounding.SetAsBox( (draw.GetSize().x / 2.f) * SCALE, (draw.GetSize().y / 2.f) * SCALE);
}

void phys_static::reg(b2World* world)
{
    body = world->CreateBody(&body_def);
    body->CreateFixture(&bounding, 0.0f);
}

void phys_static::update(const sf::Input& in, SceneManager* scene)
{
    if(do_q)
    {
        SetX(xq);
        SetY(yq);
        do_q = false;
    }
    b2Vec2 pos = body->GetPosition();
    float angle = toDeg(body->GetAngle());
    draw.SetX(pos.x / SCALE);
    draw.SetY(pos.y / SCALE);
    draw.SetRotation(angle);
}

Entity* newPhys_static(int i)
{
    return new phys_static;
}
