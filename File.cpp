#include "File.h"

inFile::inFile()
{
    //ctor
}

void inFile::OpenFile(std::string filename)
{
    f = new std::ifstream(filename.c_str(), std::ios::binary);
}

char* inFile::ReadBlock(int size)
{
    char* mem;
    mem = new char[size];
    f->read(mem, size);
    return mem;
}

std::string inFile::ReadString()
{
    int length;
    f->read((char*)&length, sizeof(int));
    std::stringstream ss;
    for(int k = 0; k < length; k++)
    {
        char c;
        f->read((char*)&c, sizeof(char));
        ss << c;
    }
    return ss.str();
}

float inFile::ReadFloat()
{
    float ff;
    f->read((char*)&ff, sizeof(float));
    return ff;
}

int inFile::ReadInt()
{
    int ff;
    f->read((char*)&ff, sizeof(int));
    return ff;
}

BYTE inFile::ReadByte()
{
    BYTE ff;
    f->read((char*)&ff, sizeof(BYTE));
    return ff;
}

void inFile::Close()
{
    f->close();
    delete f;
}

void outFile::Close()
{
    f->close();
    delete f;
}

void outFile::WriteFloat(float ff)
{
    f->write((char*)&ff, sizeof(float));
}

void outFile::WriteInt(int ff)
{
    f->write((char*)&ff, sizeof(int));
}

void outFile::WriteByte(BYTE ff)
{
    f->write((char*)&ff, sizeof(BYTE));
}

void outFile::WriteString(std::string str)
{
    int length = str.size();
    f->write((char*)&length, sizeof(int));
    f->write(str.c_str(), str.size());
}

void outFile::WriteBlock(char* data)
{
    f->write(data, sizeof(data));
}

void outFile::OpenFile(std::string filename)
{
    f = new std::ofstream(filename.c_str(), std::ios::binary);
}

outFile::outFile()
{
    //ctor
}

