#include "phys_static.h"

phys_static::phys_static()
{
    name = "phys_static";
    attributes["physics"] = true;
}

void phys_static::init(Def def)
{
    draw.SetTexture(*gImageManager.getResource(def.GetString("image")));
    std::cout << "Loaded image " << def.GetString("image") << std::endl;
    hw = draw.GetSize().x / 2;
    hh = draw.GetSize().y / 2;
    draw.SetOrigin(hw, hh);

    draw.SetX((int)def.GetVal("x"));
    draw.SetY((int)def.GetVal("y"));
    lx = (int)def.GetVal("x");
    ly = (int)def.GetVal("y");
    draw.SetRotation(def.GetFloat("rotation"));
    alive = true;
    mdef = def;

    body = new StaticBody;
    def.SetVal("hw", hw);
    def.SetVal("hh", hh);
    body->Intialize(def, this);
}


void phys_static::update(SceneManager* scene)
{
    if(do_q)
    {
        SetX(xq);
        SetY(yq);
        do_q = false;
    }
    Vec2 pos = body->GetPosition();
    draw.SetX(pos.x);
    draw.SetY(pos.y);
    draw.SetRotation(body->GetAngle());
}

Entity* newPhys_static(int i)
{
    return new phys_static;
}
