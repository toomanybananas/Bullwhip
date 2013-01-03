#ifndef CONSOLE_H
#define CONSOLE_H

//#include <SLB/SLB.hpp>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Console
{
    public:
        Console();
        void Init();
        void Close();
        //template<class T>
        //T GetCVar(std::string name) {return s->get<T>(name);};
        void PushString(std::string str);
        //template<class T>
        //void SetCVar(std::string name, T i) {s->set<T>(name, i);};

        void AddLine(std::string line);

    protected:
    private:
        //SLB::Script* s;
        //SLB::Manager m;
};

#endif // CONSOLE_H
