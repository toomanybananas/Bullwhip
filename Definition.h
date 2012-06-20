/**
 * @file Definition.h
 * @brief Powerful std::map extender
 * @author neos300
 * @version 1.0
 * @date 2012-06-20
 */

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
	/**
	 * @brief Sets a value in the def
	 *
	 * @param name Value to set
	 * @param val Value of value
	 */
        void SetVal(std::string name, boost::any val);
	/**
	 * @brief Compatability function to stop boost::any from catching literal strings.
	 *
	 * @param name
	 * @param val
	 */
        void SetString(std::string name, std::string val) {SetVal(name, val);}; //Compatibility reasons
        void SetVal(std::string name, std::string val);
	/**
	 * @brief Gets a value from the def
	 *
	 * @tparam T Type of value you want to retrieve
	 * @param name Name of value to retrieve
	 *
	 * @return Value of type T
	 */
        template<class T>
        T GetVal(std::string name) {return any_cast<T>(vals[name]);};
        
	/**
	 * @brief Determines whether a value has been defined or not.
	 *
	 * @param name Name of value to retrieve
	 *
	 * @return Whether the value exsists in this def
	 */
        bool IsDefined(std::string name) {return define[name];};
	/**
	 * @brief Get's the type of the value
	 *
	 * @param name Name of value
	 *
	 * @return Type of value (see table)
	 */
        int GetType(std::string name) {return types[name];};
	/**
	 * @brief Loads a def from a file
	 *
	 * @param filename File to load from
	 */
        void Load(std::string filename);
	/**
	 * @brief Saves a def to a file
	 *
	 * @param filename File to save to
	 */
        void Save(std::string filename);
        void Load(inFile& f);
        void Save(outFile& f);
    protected:
        std::map<std::string, boost::any> vals;
        std::map<std::string, bool> define;
        std::map<std::string, int> types;
};

