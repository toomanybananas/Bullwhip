#include "Player.h"

Player::Player()
{
    name = "player";
    attributes["teleport"] = true;
}

/*void Player::onCollision(Entity* obj)
{
    if(obj->name == "phys_static" && (obj->GetY() - (obj->GetHeight() / 2)) > (GetY() + (GetHeight() /2)))
    {
        can_jump = true;
    }
}*/

void Player::onBeginCollision(Entity* obj)
{
    if(obj->name == "ent_item")
    {
        pickup = obj;
    }
}

void Player::onEndCollision(Entity* obj)
{
    if(obj == pickup)
    {
        pickup = NULL;
    }
}


void Player::update(SceneManager* scene)
{
    super::update(scene);
    //movement
    if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Up))
    {
        /*if(can_jump == true)
        {
            body->ApplyForce(Vec2(0.f, -53.f));
            can_jump = false;
        }*/
        Jump();
    }
    if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Right))
    {
        //body->ApplyForce(Vec2(5, 0));
        MoveRight();
    }
    if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Left))
    {
        //body->ApplyForce(Vec2(-5, 0));
        MoveLeft();
    }
    if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Space))
    {
        body->ApplyTorque(100);
    }
    if((!sf::Keyboard::IsKeyPressed(sf::Keyboard::Right)) && (!sf::Keyboard::IsKeyPressed(sf::Keyboard::Left)))
    {
        body->SetLinearVelocity(Vec2(body->GetLinearVelocity().x * 0.90f, body->GetLinearVelocity().y));
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
        inv.AddItem(pickup->GetTag<std::string>("item"));
        if(inv.HasItem(pickup->GetTag<std::string>("item")))
        {
            std::cout << "Got the item\n";
        }
        else
        {
            std::cout << "life sucks\n";
        }
        //std::cout << "Picked up " << pickup->GetTag<std::string>("item") << std::endl;
        pickup->Destroy();
        delete pickup;
        pickup = NULL;
    }
}
