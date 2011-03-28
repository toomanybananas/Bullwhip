#include "Player.h"

Player::Player()
{
    name = "player";
}

bool Player::onCollision(Entity* obj)
{
    if(obj->name == "phys_static" && obj->GetY() > GetY())
    {
        can_jump = true;
    }
    return true;
}

void Player::jump()
{
    if(can_jump == true)
    {
        ApplyForce(Vec2(0.f, -5300.f), Vec2(0.f, 0.f));
        can_jump = false;
        jumptimer.Reset();
    }
}

void Player::update()
{
    b2Vec2 pos = body->GetPosition();
    float angle = toDeg(body->GetAngle());
    draw.SetX(pos.x / SCALE);
    draw.SetY(pos.y / SCALE);
    draw.SetRotation(angle);
    /*if(jumptimer.GetElapsedTime() > 1.4)
    {
        can_jump = true;
    }*/
}
