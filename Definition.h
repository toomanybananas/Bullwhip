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
#define DEF_ANY 5
using boost::any_cast;
class Def
{
    public:
        Def();
        void SetVal(std::string name, int val);
        void SetVal(std::string name, bool val);
        void SetVal(std::string name, float val);
        void SetVal(std::string name, boost::any val);
        void SetString(std::string name, std::string val) {SetVal(name, val);}; //Compatibility reasons
        void SetVal(std::string name, std::string val);
        template<class T>
        T GetVal(std::string name) {return any_cast<T>(vals[name]);};
        //virtual boost::any GetVal(std::string name) {return vals[name];};
        bool IsDefined(std::string name) {return define[name];};
        int GetType(std::string name) {return types[name];};
        void SaveDef(std::string filename) {};
    protected:
        std::map<std::string, boost::any> vals;
        std::map<std::string, bool> define;
        std::map<std::string, BYTE> types;
};

