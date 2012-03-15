#include "game_setglobal.h"

game_setglobal::game_setglobal()
{
    //ctor
}

void game_setglobal::onCollision(Entity* obj)
{
    Global.SetVal(GetVal<std::string>("gname"), GetVal<std::string>("gval"));
}
