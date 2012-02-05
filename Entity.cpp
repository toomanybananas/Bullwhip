#include "Entity.h"
using namespace std;
Entity::Entity()
{
    name = "base_ent";
    do_q = false;
}

void Entity::SetX(float m)
{
    draw.SetX(m);
    //pos.x = m;
}

void Entity::SetY(float m)
{
    draw.SetY(m);
    //pos.y = m;
}

void Entity::SetXQ(float m)
{
    xq = m;
    //qpos.x = m;
    do_q = true;
}

void Entity::SetYQ(float m)
{
    yq = m;
    //qpos.y = m;
    do_q = true;
}


void Entity::init(Def def)
{
    //draw.SetTexture(*gImageManager.getResource(any_cast<std::string>(def.GetVal("image"))));
    draw.SetTexture(*gImageManager.getResource(def.GetVal<std::string>("image")));
    hw = draw.GetSize().x / 2;
    hh = draw.GetSize().y / 2;
    draw.SetOrigin(hw, hh);

    draw.SetX(def.GetVal<int>("x"));
    draw.SetY(def.GetVal<int>("y"));
    lx = def.GetVal<int>("x");
    ly = def.GetVal<int>("y");
    draw.SetRotation(def.GetVal<float>("rotation"));
    //angle = draw.GetRotation();
    alive = true;
    mdef = def;
}


void Entity::damage(int dmg)
{
    /*if((bool)mdef.GetVal("invincible"))
        return;
    mdef.SetVal("health", (int)mdef.GetVal("health") - dmg);
    if((int)mdef.GetVal("health") <= 0)
    {
        alive = false;
    }*/
}

void Entity::update(SceneManager* scene)
{
    if(do_q)
    {
        SetX(xq);
        SetY(yq);
        do_q = false;
    }
}

Entity* newEntity(int i)
{
    return new Entity;
}

