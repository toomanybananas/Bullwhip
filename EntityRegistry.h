#pragma once
#include "Entity.h"
#include <map>
class EntityRegistry
{
    public:
        EntityRegistry();
        void AddFactory(std::string name, Entity* (*func)(int)) {factorys[name] = func;};
        Entity* NewEnt(std::string name) {return factorys[name](0);}
    protected:
    private:
        std::map<std::string, Entity* (*)(int)> factorys;
};
