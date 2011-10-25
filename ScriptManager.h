//Lua script manager
//Major under construction
#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdarg.h>

//Lua include
#include <SLB/SLB.hpp>


class ScriptManager
{
    public:
        void init();
        void ExecScript(std::string filename);

        void Close();

        //Functions for implemeting things
        //void AddModule(luaL_reg lib[], std::string name);
        //void RegisterFunc(int (*func)(lua_State*), std::string name);
    private:
        static ScriptManager m_ScriptManager;
        //lua_State* state;
        int args;
        std::string fname;
        int tablepos;
};

//int RandomFunc(lua_State* L);

