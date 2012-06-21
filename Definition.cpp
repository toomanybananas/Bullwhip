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
    types[name] = DEF_ANY;
}

void Def::SetVal(std::string name, std::string val)
{
    //strings[name] = val;
    vals[name] = val;
    define[name] = true;
    types[name] = DEF_STRING;
}
void Def::SetVal(std::string name, Def val)
{
    //strings[name] = val;
    vals[name] = val;
    define[name] = true;
    types[name] = DEF_DEF;
}
/*template<class T>
T Def::GetVal(std::string name)
{
	if(!IsDefined(name))
		return new T;
	return any_cast<T>(vals[name]);
}*/

Def::Def()
{
    SetVal("x", 0);
    SetVal("y", 0);
    SetVal("rotation", 0.0f);
}

void Def::Load(std::string filename)
{
    inFile f;
    f.OpenFile(filename);
    bool run = true;
    while(run)
    {
        char type = f.ReadByte();
        if(type == 0)
        {
            run = false;
            break;
        }

        std::string name = f.ReadString();
        if(type == 1) //int
            SetVal(name, f.ReadInt());
        if(type == 2) //float
            SetVal(name, f.ReadFloat());
        if(type == 3) //string
            SetVal(name, f.ReadString());
        if(type == 6) //def
        {
            Def d;
            d.Load(f);
            SetVal(name, d);
        }
    }
    f.Close();
}

void Def::Save(std::string filename)
{
    outFile f;
    f.OpenFile(filename);
    for(std::map<std::string, boost::any>::const_iterator iter = vals.begin(); iter != vals.end(); ++iter)
    {
        std::string name = (std::string)iter->first;
        boost::any val = vals[name];
        if(GetType(name) == DEF_UNDEF)
            continue;
        if(GetType(name) == DEF_INT)
        {
            f.WriteByte(DEF_INT);
            f.WriteString(name);
            f.WriteInt(any_cast<int>(val));
        }
        if(GetType(name) == DEF_FLOAT)
        {
            f.WriteByte(DEF_FLOAT);
            f.WriteString(name);
            f.WriteFloat(any_cast<float>(val));
        }
        if(GetType(name) == DEF_STRING)
        {
            f.WriteByte(DEF_STRING);
            f.WriteString(name);
            f.WriteString(any_cast<std::string>(val));
        }
        if(GetType(name) == DEF_DEF)
        {
            f.WriteByte(DEF_DEF);
            f.WriteString(name);
            any_cast<Def>(val).Save(f);
        }
    }
    f.WriteByte(0);
    f.Close();
}

void Def::Load(inFile& f)
{
    bool run = true;
    while(run)
    {
        char type = f.ReadByte();
        if(type == 0)
        {
            run = false;
            break;
        }

        std::string name = f.ReadString();
        if(type == 1) //int
            SetVal(name, f.ReadInt());
        if(type == 2) //float
            SetVal(name, f.ReadFloat());
        if(type == 3) //string
            SetVal(name, f.ReadString());
        if(type == 6) //def
        {
            Def d;
            d.Load(f);
            SetVal(name, d);
        }
    }
}

void Def::Save(outFile& f)
{
    for(std::map<std::string, boost::any>::const_iterator iter = vals.begin(); iter != vals.end(); ++iter)
    {
        std::string name = (std::string)iter->first;
        boost::any val = vals[name];
        if(GetType(name) == DEF_UNDEF)
            continue;
        if(GetType(name) == DEF_INT)
        {
            f.WriteByte(DEF_INT);
            f.WriteString(name);
            f.WriteInt(any_cast<int>(val));
        }
        if(GetType(name) == DEF_FLOAT)
        {
            f.WriteByte(DEF_FLOAT);
            f.WriteString(name);
            f.WriteFloat(any_cast<float>(val));
        }
        if(GetType(name) == DEF_STRING)
        {
            f.WriteByte(DEF_STRING);
            f.WriteString(name);
            f.WriteString(any_cast<std::string>(val));
        }
        if(GetType(name) == DEF_DEF)
        {
            f.WriteByte(DEF_DEF);
            f.WriteString(name);
            any_cast<Def>(val).Save(f);
        }
    }
    f.WriteByte(0);
}

void Def::Copy(Def& d)
{
	vals = d.getRawVals();
	define = d.getRawDefine();
	types = d.getRawTypes();
}

