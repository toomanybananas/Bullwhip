#include "game_setglobal.h"

game_setglobal::game_setglobal()
{
    //ctor
}

bool game_setglobal::onCollision(Entity* obj)
{
    Global.SetVal(any_cast<std::string>(mdef.GetVal("gname")), any_cast<std::string>(mdef.GetVal("gval")));
    return true;
}

Entity* newGame_setglobal(int i)
{
    return new game_setglobal;
}
