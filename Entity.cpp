#include "Entity.h"
using namespace std;
Entity::Entity()
{
    name = "base_ent";
    do_q = false;
}

void Entity::SetX(float m)
{
    draw.SetPosition(m, GetX());
    //pos.x = m;
}

void Entity::SetY(float m)
{
    draw.SetPosition(GetY(), m);
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


void Entity::init()
{
    //draw.SetTexture(*gImageManager.getResource(any_cast<std::string>(def.GetVal("image"))));
    sf::Texture* tex = gImageManager.getResource(GetVal<std::string>("image"));
    draw.SetTexture(*tex);
    hw = tex->GetWidth() / 2;
    hh = tex->GetHeight() / 2;
    w = tex->GetWidth();
    h = tex->GetHeight();
    draw.SetOrigin(hw, hh);

    draw.SetPosition(GetVal<int>("x"), GetVal<int>("y"));
    lx = GetVal<int>("x");
    ly = GetVal<int>("y");
    draw.SetRotation(GetVal<float>("rotation"));
    alive = true;
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

