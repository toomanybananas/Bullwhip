#include "Entity.h"
using namespace std;
Entity::Entity()
{
    name = "base_ent";
    do_q = false;
}

void Entity::SetX(float m)
{
    draw.setPosition(m, GetX());
    //pos.x = m;
}

void Entity::SetY(float m)
{
    draw.setPosition(GetY(), m);
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
    isasset = false;
    sf::Texture* tex;
    if(IsDefined("image"))
        tex = gImageManager.getResource(GetVal<std::string>("image"));
    else //assume that an asset file is being referenced
    {
        asset.Load(GetVal<std::string>("asset"));
        tex = gImageManager.getResource(asset.GetVal<std::string>("image"));
        //load some other crap
        isasset = true;
    }
    draw.setTexture(*tex);
    hw = tex->getSize().x / 2;
    hh = tex->getSize().y / 2;
    w = tex->getSize().x;
    h = tex->getSize().y;
    draw.setOrigin(hw, hh);

    draw.setPosition(GetVal<int>("x"), GetVal<int>("y"));
    lx = GetVal<int>("x");
    ly = GetVal<int>("y");
    draw.setRotation(GetVal<float>("rotation"));
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

