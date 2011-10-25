//Set to become part of BullwhipCommon
#pragma once
#include <string>
#include <map>
#include "File.h"
#define DEF_INT 1
#define DEF_UNDEF 0
#define DEF_FLOAT 2
#define DEF_STRING 3
#define DEF_BOOL 4
#define DEF_VOID 5
class Entity;
class Def
{
    public:
        Def();
        virtual void SetVal(std::string name, int val);
        virtual void SetVal(std::string name, bool val);
        virtual void SetVal(std::string name, float val);
        virtual void SetVal(std::string name, void* val);
        virtual void SetString(std::string name, std::string val);
        virtual void* GetVal(std::string name) {return vals[name];};
        virtual std::string& GetString(const std::string& name) {return strings[name];};
        virtual float GetFloat(std::string name) {return floats[name];};
        virtual void SetFunc(std::string name,int (*func)(Entity*));
        virtual void RunFunc(std::string name, Entity* obj);
        virtual bool IsDefined(std::string name) {return define[name];};
        virtual int GetType(std::string name) {return types[name];};
        virtual void SaveDef(std::string filename) {};
    protected:
        std::map<std::string, void*> vals;
        std::map<std::string, std::string> strings;
        std::map<std::string, float> floats;
        std::map<std::string, int (*)(Entity*)> funcs;
        std::map<std::string, bool> define;
        std::map<std::string, BYTE> types;
};
