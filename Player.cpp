#include "Player.h"

Player::Player()
{
    name = "player";
    attributes["teleport"] = true;
}

bool Player::onCollision(Entity* obj)
{
    if(obj->name == "phys_static" && (obj->GetY() - (obj->getspr().GetSize().y / 2)) > (GetY() + (draw.GetSize().y /2)))
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
    }
}

void Player::update(const sf::Input& in, SceneManager* scene)
{
    if(do_q)
    {
        SetX(xq);
        SetY(yq);
        do_q = false;
    }
    //movement
    if(in.IsKeyDown(sf::Key::Up))
    {
        jump();
    }
    if(in.IsKeyDown(sf::Key::Right))
    {
        ApplyForce(Vec2(500, -100), Vec2(0, 0));
    }
    if(in.IsKeyDown(sf::Key::Left))
    {
        ApplyForce(Vec2(-500, -100), Vec2(0, 0));
    }
    if((!in.IsKeyDown(sf::Key::Right)) && (!in.IsKeyDown(sf::Key::Left)))
    {
        SetXVel(0);
    }
    b2Vec2 pos = body->GetPosition();
    float angle = toDeg(body->GetAngle());
    draw.SetX(pos.x / SCALE);
    draw.SetY(pos.y / SCALE);
    draw.SetRotation(angle);
}

Entity* newPlayer(int i)
{
    return new Player;
}
