#include "game_setglobal.h"

game_setglobal::game_setglobal()
{
    //ctor
}

bool game_setglobal::onCollision(Entity* obj)
{
    Global.SetVal(mdef.GetVal<std::string>("gname"), mdef.GetVal<std::string>("gval"));
    return true;
}

Entity* newGame_setglobal(int i)
{
    return new game_setglobal;
}
