#include "game_spawnpoint.h"

game_spawnpoint::game_spawnpoint()
{
    //ctor
    name = "game_spawnpoint";
}

Entity* newGame_spawnpoint(int i)
{
    return new game_spawnpoint;
}
