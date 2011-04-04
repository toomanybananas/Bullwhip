#include "Entity.h"
using namespace std;
Entity::Entity()
{
    name = "base_ent";
}

void Entity::SetX(float m)
{
    draw.SetX(m);

}

void Entity::SetY(float m)
{
    draw.SetY(m);
}


void Entity::init(Def def)
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
}


void Entity::damage(int dmg)
{
    if((bool)mdef.GetVal("invincible"))
        return;
    mdef.SetVal("health", (int)mdef.GetVal("health") - dmg);
    if((int)mdef.GetVal("health") <= 0)
    {
        alive = false;
    }
}

void Entity::update(const sf::Input& in)
{
    //
}

Entity* newEntity(int i)
{
    return new Entity;
}

