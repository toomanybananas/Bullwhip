#pragma once
#include <string>
#include <map>
class Entity;
//Defintions. Use these well, you must.
class Def
{
    public:
        Def();
        virtual void SetVal(std::string name, int val);
        virtual void SetVal(std::string name, bool val);
        virtual void SetVal(std::string name, float val);
        virtual void SetString(std::string name, std::string val);
        virtual void* GetVal(std::string name) {return vals[name];};
        virtual std::string& GetString(const std::string& name) {return strings[name];};
        virtual float GetFloat(std::string name) {return floats[name];};
        virtual void SetFunc(std::string name,int (*func)(Entity*));
        virtual void RunFunc(std::string name, Entity* obj);
    protected:
        std::map<std::string, void*> vals;
        std::map<std::string, std::string> strings;
        std::map<std::string, float> floats;
        std::map<std::string, int (*)(Entity*)> funcs;
};

class TileDef : public Def
{
    public:
};

class PlayerDef : public Def
{
    public:
};
