#include "game_setglobal.h"

game_setglobal::game_setglobal()
{
    //ctor
}

bool game_setglobal::onCollision(Entity* obj)
{
    Global.SetString(mdef.GetString("gname"), mdef.GetString("gval"));
}

Entity* newGame_setglobal(int i)
{
    return new game_setglobal;
}
