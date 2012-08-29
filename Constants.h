/**
 * @file Constants.h
 * @brief Globals
 * @author neos300
 * @version 1.0
 * @date 2012-06-20
 */


#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Definition.h"
#include "PhysicsWrappers/PhysicsWorld.h"
#include "Cistron.h"
#include "ComponentRegistry.h"
//class ItemManager;
const sf::Clock uptime; //Global uptime timer
extern Def Global; //Global def
#define SCALE 0.01
extern PhysicsWorld* phys_world; //Global physics world
//extern ItemManager Items; //Global item manager
extern std::vector<sf::Keyboard::Key> keys;
extern ComponentRegistry componentreg;
extern Cistron::ObjectManager* objManager;
