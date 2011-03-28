#include "ScriptManager.h"

void ScriptManager::ExecScript(std::string filename)
{
    luaL_dofile(state, filename.c_str());
}

void ScriptManager::Close()
{
    lua_close(state);
}

void ScriptManager::init()
{
    state = luaL_newstate();
    luaL_openlibs(state);
    luaL_reg misc[] = {
        {"stuff", &RandomFunc},
        {NULL, NULL}
    };
    AddModule(misc, "misc");
    RegisterFunc(&RandomFunc, "wo");
}


void ScriptManager::CallFunc(std::string name)
{
    lua_getglobal(state, name.c_str());
    if(lua_pcall(state, 0, 0, 0) != 0)
    {
        //error
        std::cout << "Error with function " << name << " with error " << lua_tostring(state, -1) << std::endl;
    }
}

void ScriptManager::BeginCall(std::string name)
{
    lua_getglobal(state, name.c_str());
    args = 0;
    fname = name;
}

void ScriptManager::AddNumber(int number)
{
    lua_pushnumber(state, number);
    args++;
}

void ScriptManager::AddNumber(float f)
{
    lua_pushnumber(state, f);
    args++;
}

void ScriptManager::AddString(std::string str)
{
    lua_pushstring(state, str.c_str());
    args++;
}

void ScriptManager::AddBool(bool b)
{
    lua_pushboolean(state, b);
    args++;
}

void ScriptManager::Call()
{
    if(lua_pcall(state, args, 0, 0) != 0)
    {
        std::cout << "Error with function " << fname << " with error " << lua_tostring(state, -1);
    }
}

int ScriptManager::GetResultI()
{
    if(lua_pcall(state, args, 1, 0) != 0)
    {
        std::cout << "Error with function " << fname << " with error " << lua_tostring(state, -1);
        return 0;
    }
    int x = lua_tonumber(state, -1);
    lua_pop(state, 1);
    return x;
}

float ScriptManager::GetResultF()
{
    if(lua_pcall(state, args, 1, 0) != 0)
    {
        std::cout << "Error with function " << fname << " with error " << lua_tostring(state, -1);
        return 0;
    }
    float x = lua_tonumber(state, -1);
    lua_pop(state, 1);
    return x;
}

std::string ScriptManager::GetResultS()
{
    if(lua_pcall(state, args, 1, 0) != 0)
    {
        std::cout << "Error with function " << fname << " with error " << lua_tostring(state, -1);
        return "";
    }
    std::string x = lua_tostring(state, -1);
    lua_pop(state, 1);
    return x;
}

bool ScriptManager::GetResultB()
{
    if(lua_pcall(state, args, 1, 0) != 0)
    {
        std::cout << "Error with function " << fname << " with error " << lua_tostring(state, -1);
        return false;
    }
    bool x = lua_toboolean(state, -1);
    lua_pop(state, 1);
    return x;
}


void ScriptManager::CallTableFunc(std::string func)
{
    lua_rawgeti(state, LUA_REGISTRYINDEX, tablepos);
    lua_getfield(state, -1, func.c_str());
    lua_pushvalue(state, -2);
    lua_call(state, 1, 0);
    lua_pop(state, 1);
}

void ScriptManager::RegisterFunc(int (*func)(lua_State*), std::string name)
{
    lua_register(state, name.c_str(), func);
}

void ScriptManager::AddModule(luaL_reg lib[], std::string name)
{
    luaL_openlib(state, name.c_str(), lib, 0);
}

void ScriptManager::OpenTable(std::string table)
{
    lua_getglobal(state, table.c_str());
    if(lua_isnil(state, -1) == 1)
    {
        std::cout << "NIL\n";
    }
    tablepos = luaL_ref(state, LUA_REGISTRYINDEX);
}

void ScriptManager::CloseTable()
{
    lua_pop(state, 1);
}

int ScriptManager::GetTableInt(std::string name)
{
    lua_rawgeti(state, LUA_REGISTRYINDEX, tablepos);
    lua_getfield(state, -1, name.c_str());

    int i = lua_tonumber(state, -1);
    lua_pop(state, 2);
    return i;
}

float ScriptManager::GetTableFloat(std::string name)
{
    lua_rawgeti(state, LUA_REGISTRYINDEX, tablepos);
    lua_getfield(state, -1, name.c_str());

    float i = lua_tonumber(state, -1);
    lua_pop(state, 2);
    return i;
}

std::string ScriptManager::GetTableString(std::string name)
{
    lua_rawgeti(state, LUA_REGISTRYINDEX, tablepos);
    lua_getfield(state, -1, name.c_str());

    std::string i = lua_tostring(state, -1);
    lua_pop(state, 2);
    return i;
}

bool ScriptManager::GetTableBool(std::string name)
{
    lua_rawgeti(state, LUA_REGISTRYINDEX, tablepos);
    lua_getfield(state, -1, name.c_str());

    bool i = lua_toboolean(state, -1);
    lua_pop(state, 2);
    return i;
}

ScriptManager ScriptManager::m_ScriptManager;

int RandomFunc(lua_State* L)
{
    std::cout << "hi" << std::endl;
    lua_pushnumber(L, 0);
    return 1;
}
