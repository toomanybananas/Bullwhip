#include "Definition.h"

void Def::SetVal(std::string name, int val)
{
    vals[name] = val;
    define[name] = true;
    types[name] = DEF_INT;
}

void Def::SetVal(std::string name, bool val)
{
    vals[name] = val;
    define[name] = true;
    types[name] = DEF_BOOL;
}

void Def::SetVal(std::string name, float val)
{
    //floats[name] = val;
    vals[name] = val;
    define[name] = true;
    types[name] = DEF_FLOAT;
}

void Def::SetVal(std::string name, boost::any val)
{
    vals[name] = val;
    define[name] = true;
    types[name] = DEF_VOID;
}

void Def::SetVal(std::string name, std::string val)
{
    //strings[name] = val;
    vals[name] = val;
    define[name] = true;
    types[name] = DEF_STRING;
}

Def::Def()
{
    SetVal("x", 0);
    SetVal("y", 0);
    SetVal("rotation", 0.0f);
}
