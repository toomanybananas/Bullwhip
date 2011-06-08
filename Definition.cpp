#include "Definition.h"

void Def::SetVal(std::string name, int val)
{
    vals[name] = (void*)val;
    define[name] = true;
    types[name] = DEF_INT;
}

void Def::SetVal(std::string name, bool val)
{
    vals[name] = (void*)val;
    define[name] = true;
    types[name] = DEF_BOOL;
}

void Def::SetVal(std::string name, float val)
{
    floats[name] = val;
    define[name] = true;
    types[name] = DEF_FLOAT;
}



void Def::SetString(std::string name, std::string val)
{
    strings[name] = val;
    define[name] = true;
    types[name] = DEF_STRING;
}

Def::Def()
{
    vals["x"] = 0;
    vals["y"] = 0;
    vals["rotation"] = 0;
    vals["health"] = 0;
    vals["invincible"] = 0;
    vals["solid"] = 0;
    strings["image"] = "none.png";
}


void Def::SetFunc(std::string name,int (*func)(Entity*))
{
    funcs[name] = func;
}

void Def::RunFunc(std::string name, Entity* obj)
{
    funcs[name](obj);
}
