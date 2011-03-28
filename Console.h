#ifndef CONSOLE_H
#define CONSOLE_H

//Lua includes
extern "C"
{
    #include <lua/lua.h>
    #include <lua/lualib.h>
    #include <lua/lauxlib.h>
}

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Console
{
    public:
        Console();
        void Init();
        void Close();
        int GetCVarI(std::string name);
        float GetCVarF(std::string name);
        bool GetCVarB(std::string name);
        std::string GetCVarS(std::string name);
        void PushString(std::string str);
        void SetCVar(std::string name, int i);
        void SetCVar(std::string name, float i);
        void SetCVar(std::string name, bool i);
        void SetCVar(std::string name, std::string i);

        void AddLine(std::string line);

    protected:
    private:
    lua_State* state;
};

#endif // CONSOLE_H
