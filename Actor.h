#pragma once
#include "entites/phys_dynamic.h"

class Actor : public phys_dynamic
{
    public:
        virtual void init();
        virtual void MoveRight();
        virtual void MoveLeft();
        virtual void Jump();
        virtual void onCollision(Entity* obj);
        //virtual void onBeginCollision(Entity* obj);
        //virtual void onEndCollision(Entity* obj);
    private:
        bool can_jump;
        //int jump_force;
        //int move_speed;
        //bool can_move;
};
