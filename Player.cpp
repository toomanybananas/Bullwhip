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
    if(obj->name == "ent_item")
    {
        pickup = obj;
    }
    else
    {
        pickup = NULL;
    }
    return true;
}


void Player::update(SceneManager* scene)
{
    if(do_q)
    {
        SetX(xq);
        SetY(yq);
        do_q = false;
    }
    //movement
    if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Up))
    {
        if(can_jump == true)
        {
            body->ApplyForce(Vec2(0.f, -53.f));
            can_jump = false;
        }
    }
    if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Right))
    {
        body->ApplyForce(Vec2(5, 0));
    }
    if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Left))
    {
        body->ApplyForce(Vec2(-5, 0));
    }
    if((!sf::Keyboard::IsKeyPressed(sf::Keyboard::Right)) && (!sf::Keyboard::IsKeyPressed(sf::Keyboard::Left)))
    {
        body->SetLinearVelocity(Vec2(body->GetLinearVelocity().x* 0.90f, body->GetLinearVelocity().y));
    }

    //Item pickups
    if(pickup != NULL)
    {
        //TODO: Draw 'Press key to pickup' message
    }
    if(pickup != NULL && sf::Keyboard::IsKeyPressed(sf::Keyboard::E))
    {
        //Pickup the item and throw a message
        scene->RemoveEntityFromList(pickup);
        inv.AddItem(pickup->GetStr("item"));
        std::cout << "Picked up " << pickup->GetStr("item") << std::endl;
        pickup->Destroy();
        delete pickup;
        pickup = NULL;
    }
    Vec2 pos = body->GetPosition();
    float angle = body->GetAngle();
    draw.SetX(pos.x);
    draw.SetY(pos.y);
    draw.SetRotation(angle);
}

Entity* newPlayer(int i)
{
    return new Player;
}
