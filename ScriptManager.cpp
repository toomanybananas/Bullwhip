#include "ScriptManager.h"

void ScriptManager::ExecScript(std::string filename)
{
    //luaL_dofile(state, filename.c_str());
}

void ScriptManager::Close()
{
    //lua_close(state);
}

void ScriptManager::init()
{
    /*state = luaL_newstate();
    luaL_openlibs(state);
    luaL_reg misc[] = {
        {"stuff", &RandomFunc},
        {NULL, NULL}
    };
    AddModule(misc, "misc");
    RegisterFunc(&RandomFunc, "wo");*/
}


/*void ScriptManager::RegisterFunc(int (*func)(lua_State*), std::string name)
{
    //lua_register(state, name.c_str(), func);
}

void ScriptManager::AddModule(luaL_reg lib[], std::string name)
{
    //luaL_openlib(state, name.c_str(), lib, 0);
}*/



/*int RandomFunc(lua_State* L)
{
    std::cout << "hi" << std::endl;
    lua_pushnumber(L, 0);
    return 1;
}*/
