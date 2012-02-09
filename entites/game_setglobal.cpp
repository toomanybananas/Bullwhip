#include "game_setglobal.h"

game_setglobal::game_setglobal()
{
    //ctor
}

void game_setglobal::onCollision(Entity* obj)
{
    Global.SetVal(mdef.GetVal<std::string>("gname"), mdef.GetVal<std::string>("gval"));
}
