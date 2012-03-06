#include "Actor.h"

void Actor::init(Def d)
{
    phys_dynamic::init(d);
    if(d.IsDefined("move_speed"))
        move_speed = d.GetVal<int>("move_speed");
    else
        move_speed = 5;
    if(d.IsDefined("jump_force"))
        jump_force = d.GetVal<int>("jump_force");
    else
        jump_force = -50;
    if(d.IsDefined("moveable"))
        can_move = d.GetVal<bool>("moveable");
    else
        can_move = true; //actors can move unless otherwise stated
}

void Actor::MoveRight()
{
    if(!can_move)
        return;
    body->ApplyForce(Vec2(move_speed, 0));
}

void Actor::MoveLeft()
{
    if(!can_move)
        return;
    body->ApplyForce(Vec2(move_speed * -1, 0));
}

void Actor::Jump()
{
    if(!can_jump)
        return;
    body->ApplyForce(Vec2(0, jump_force));
    can_jump = false;
}

void Actor::onCollision(Entity* obj)
{
    if((obj->GetY() - (obj->GetHeight() / 2)) > (GetY() + (GetHeight() /2)))
    {
        can_jump = true;
    }
}
