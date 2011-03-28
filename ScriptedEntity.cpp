#include "ScriptedEntity.h"
using namespace std;

ScriptedEntity::ScriptedEntity() : m(ScriptManager::Instance())
{
    //
}

void ScriptedEntity::init(Def def)
{

    ScriptManager& inst = ScriptManager::Instance();
    mdef = def;

    ename = def.GetString("entname");
    inst.OpenTable(ename);

    draw.SetImage(*gImageManager.getResource(inst.GetTableString("image")));
    hw = draw.GetSize().x / 2;
    hh = draw.GetSize().y / 2;
    draw.SetCenter(hw, hh);

    draw.SetX(inst.GetTableInt("x") * 64 + hw);
    draw.SetY(inst.GetTableInt("y") * 64 + hh);
    lx = inst.GetTableInt("x");
    ly = inst.GetTableInt("y");

    //direction = inst.GetTableInt("rotation");
    //draw.SetRotation(direction * 90);
    alive = true;
    solid = inst.GetTableBool("solid");
    inst.CloseTable();
}

void ScriptedEntity::update(Entity* surround[3][3])
{
    //m.OpenTable(ename);
    //m.CallTableFunc("update");
    //m.CloseTable();
}
