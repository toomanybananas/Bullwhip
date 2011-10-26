#include "phys_dynamic.h"

phys_dynamic::phys_dynamic()
{
    name = "phys_dynamic";
    attributes["physics"] = true;
}

void phys_dynamic::init(Def def)
{
    draw.SetTexture(*gImageManager.getResource(def.GetString("image")));
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

    body = new DynamicBody;
    def.SetVal("hw", hw);
    def.SetVal("hh", hh);
    body->Intialize(def, this);
}


void phys_dynamic::Destroy()
{
    //body->DestroyFixture(fix);
}

Entity* newPhys_dynamic(int i)
{
    return new phys_dynamic;
}
