//Set to become part of BullwhipCommon
#pragma once
#include <string>
#include <map>
#include <boost/any.hpp>
#include "File.h"
#define DEF_INT 1
#define DEF_UNDEF 0
#define DEF_FLOAT 2
#define DEF_STRING 3
#define DEF_BOOL 4
#define DEF_ANY 5
#define DEF_DEF 6
using boost::any_cast;
class Def
{
    public:
        Def();
        void SetVal(std::string name, int val);
        void SetVal(std::string name, bool val);
        void SetVal(std::string name, float val);
        void SetVal(std::string name, Def val);
        void SetVal(std::string name, boost::any val);
        void SetString(std::string name, std::string val) {SetVal(name, val);}; //Compatibility reasons
        void SetVal(std::string name, std::string val);
        template<class T>
        T GetVal(std::string name) {return any_cast<T>(vals[name]);};
        //virtual boost::any GetVal(std::string name) {return vals[name];};
        bool IsDefined(std::string name) {return define[name];};
        int GetType(std::string name) {return types[name];};
        void Load(std::string filename);
        void Save(std::string filename);
        void Load(inFile& f);
        void Save(outFile& f);
    protected:
        std::map<std::string, boost::any> vals;
        std::map<std::string, bool> define;
        std::map<std::string, int> types;
};

