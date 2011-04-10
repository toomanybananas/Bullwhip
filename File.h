#pragma once
#include <fstream>
#include <string>
#include <sstream>

class inFile
{
    public:
        inFile();
        void OpenFile(std::string filename);
        char* ReadBlock(int size);
        std::string ReadString();
        float ReadFloat();
        int ReadInt();
    protected:
    private:
        std::ifstream* f;
};


class outFile
{
    public:
        outFile();
        void OpenFile(std::string filename);
        void WriteBlock(char* data);
        void WriteString(std::string str);
        void WriteFloat(float ff);
        void WriteInt(int ff);
    protected:
    private:
        std::ofstream* f;
};
