#include "PlayerControlled.h"


void PlayerControlled::update(const Cistron::Message& msg)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		sendLocalMessage("Actor.Jump");
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		sendLocalMessage("Actor.Right");
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		sendLocalMessage("Actor.Left");
}
