//Set to become part of BullwhipCommon
#pragma once
#include <string>
#include <map>
#include <windows.h>
#include <boost/any.hpp>
#define DEF_INT 1
#define DEF_UNDEF 0
#define DEF_FLOAT 2
#define DEF_STRING 3
#define DEF_BOOL 4
#define DEF_VOID 5
using boost::any_cast;
class Def
{
    public:
        Def();
        virtual void SetVal(std::string name, int val);
        virtual void SetVal(std::string name, bool val);
        virtual void SetVal(std::string name, float val);
        virtual void SetVal(std::string name, boost::any val);
        virtual void SetString(std::string name, std::string val) {SetVal(name, val);}; //Compatibility reasons
        virtual void SetVal(std::string name, std::string val);
        virtual boost::any GetVal(std::string name) {return vals[name];};
        virtual bool IsDefined(std::string name) {return define[name];};
        virtual int GetType(std::string name) {return types[name];};
        virtual void SaveDef(std::string filename) {};
    protected:
        std::map<std::string, boost::any> vals;
        std::map<std::string, bool> define;
        std::map<std::string, BYTE> types;
};

