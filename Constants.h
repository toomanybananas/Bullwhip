//Small file for defining constants and global values

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Definition.h"
#include "PhysicsWrappers/PhysicsWorld.h"
//#include <Gwen/Controls/Canvas.h>
class ItemManager;
const sf::Clock uptime; //Global uptime timer
extern Def Global; //Global def
#define SCALE 0.01
extern PhysicsWorld* phys_world; //Global physics world
extern ItemManager Items; //Global item manager
//extern Gwen::Controls::Canvas* canvas;
