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

}

void Entity::SetY(float m)
{
    draw.SetY(m);
}

void Entity::SetXQ(float m)
{
    xq = m;
    do_q = true;
}

void Entity::SetYQ(float m)
{
    yq = m;
    do_q = true;
}


void Entity::init(Def def)
{
    draw.SetTexture(*gImageManager.getResource(any_cast<std::string>(def.GetVal("image"))));
    hw = draw.GetSize().x / 2;
    hh = draw.GetSize().y / 2;
    draw.SetOrigin(hw, hh);

    draw.SetX(any_cast<int>(def.GetVal("x")));
    draw.SetY(any_cast<int>(def.GetVal("y")));
    lx = any_cast<int>(def.GetVal("x"));
    ly = any_cast<int>(def.GetVal("y"));
    draw.SetRotation(any_cast<float>(def.GetVal("rotation")));
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

