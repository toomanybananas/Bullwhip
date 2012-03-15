#include "Actor.h"

void Actor::init()
{
    phys_dynamic::init();
    if(!IsDefined("move_speed"))
        SetVal("move_speed", 5);
    if(!IsDefined("jump_force"))
        SetVal("jump_force", -50);
    if(!IsDefined("moveable"))
        SetVal("moveable", true); //actors can move unless otherwise stated
}

void Actor::MoveRight()
{
    if(!GetVal<bool>("moveable"))
        return;
    body->ApplyForce(Vec2(GetVal<int>("move_speed"), 0));
}

void Actor::MoveLeft()
{
    if(!GetVal<bool>("moveable"))
        return;
    body->ApplyForce(Vec2(GetVal<int>("move_speed") * -1, 0));
}

void Actor::Jump()
{
    if(!can_jump)
        return;
    body->ApplyForce(Vec2(0, GetVal<int>("jump_force")));
    can_jump = false;
}

void Actor::onCollision(Entity* obj)
{
    if((obj->GetY() - (obj->GetHeight() / 2)) > (GetY() + (GetHeight() /2)))
    {
        can_jump = true;
    }
}
