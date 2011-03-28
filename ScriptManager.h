#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdarg.h>

//Lua includes
extern "C"
{
    #include <lua/lua.h>
    #include <lua/lualib.h>
    #include <lua/lauxlib.h>
}


class ScriptManager
{
    public:
        void init();
        void ExecScript(std::string filename);

        static ScriptManager& Instance() {return m_ScriptManager;};

        void Close();

        //void CallFunc(std::string name, std::string s, ...);
        void CallFunc(std::string name);

        //Functions for calling functions
        void BeginCall(std::string name);
        void AddNumber(int number);
        void AddNumber(float f);
        void AddString(std::string str);
        void AddBool(bool b);
        void Call();
        int GetResultI();
        float GetResultF();
        std::string GetResultS();
        bool GetResultB();


        //Functions for tables
        void OpenTable(std::string table);
        void CloseTable();
        int GetTableInt(std::string name);
        float GetTableFloat(std::string name);
        std::string GetTableString(std::string name);
        bool GetTableBool(std::string name);
        void CallTableFunc(std::string func);

        //Functions for implemeting things
        void AddModule(luaL_reg lib[], std::string name);
        void RegisterFunc(int (*func)(lua_State*), std::string name);
    private:
        static ScriptManager m_ScriptManager;
        lua_State* state;
        int args;
        std::string fname;
        int tablepos;

    protected:
        ScriptManager() {}; //Singleton
};

int RandomFunc(lua_State* L);

