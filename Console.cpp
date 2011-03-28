#include "Console.h"

Console::Console()
{
    //ctor
}


void Console::Init()
{
    state = luaL_newstate();
    luaL_openlibs(state);
}

void Console::Close()
{
    lua_close(state);
}

bool Console::GetCVarB(std::string name)
{
    lua_getglobal(state, name.c_str());
    return lua_toboolean(state, -1);
}

int Console::GetCVarI(std::string name)
{
    lua_getglobal(state, name.c_str());
    return lua_tonumber(state, -1);
}

float Console::GetCVarF(std::string name)
{
    lua_getglobal(state, name.c_str());
    return lua_tonumber(state, -1);
}

std::string Console::GetCVarS(std::string name)
{
    lua_getglobal(state, name.c_str());
    return lua_tostring(state, -1);
}

void Console::PushString(std::string str)
{
    //lua_dostring(str.c_str());
}

void Console::SetCVar(std::string name, int i)
{
    lua_pushnumber(state, i);
    lua_setglobal(state, name.c_str());
}

void Console::SetCVar(std::string name, float i)
{
    lua_pushnumber(state, i);
    lua_setglobal(state, name.c_str());
}

void Console::SetCVar(std::string name, std::string i)
{
    lua_pushstring(state, i.c_str());
    lua_setglobal(state, name.c_str());
}

void Console::SetCVar(std::string name, bool i)
{
    lua_pushboolean(state, i);
    lua_setglobal(state, name.c_str());
}

void Console::AddLine(std::string line)
{
    //
}
