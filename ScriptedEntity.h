#pragma once
#include "Entity.h"
#include "ScriptManager.h"
#include <iostream>
#include "ImageManager.h"


class ScriptedEntity : public Entity
{
    public:
        ScriptedEntity();
        void init(Def def);
        void update(Entity* surround[3][3]);
    protected:
    private:
        std::string ename;
};

