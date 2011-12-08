#include "phys_dynamic.h"

phys_dynamic::phys_dynamic()
{
    name = "phys_dynamic";
    attributes["physics"] = true;
}

void phys_dynamic::init(Def def)
{
    try
    {
        std::string s = any_cast<std::string>(def.GetVal("image"));
    }
    catch(boost::bad_any_cast b)
    {
        std::cout << b.what() << std::endl;
    }
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

    body = new DynamicBody;
    def.SetVal("hw", hw);
    def.SetVal("hh", hh);
    body->Intialize(def, this);
}


/*void phys_dynamic::Destroy()
{
    //body->DestroyFixture(fix);
}*/

Entity* newPhys_dynamic(int i)
{
    return new phys_dynamic;
}
