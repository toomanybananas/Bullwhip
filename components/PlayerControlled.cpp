#include "PlayerControlled.h"


void PlayerControlled::update(const Cistron::Message& msg)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		sendLocalMessage("jump");
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		sendLocalMessage("moveright");
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		sendLocalMessage("moveleft");
}
