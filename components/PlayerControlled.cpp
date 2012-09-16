#include "PlayerControlled.h"


void PlayerControlled::update(const Cistron::Message& msg)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		sendLocalMessage("Actor.Jump");
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		sendLocalMessage("Actor.Right");
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		sendLocalMessage("Actor.Left");
	if((!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		sendLocalMessage("Get.LinearVelocity");
		sendLocalMessage("Set.LinearVelocity", Vec2(vel.x * 0.90f, vel.y));
	}
}
