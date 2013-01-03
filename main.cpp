/**
 * @file main.cpp
 * @brief Main file that initalizes the game and checks at compile time for libraries
 * @author neos300
 * @version 1.0
 * @date 2012-06-20
 */

#include <iostream>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "SimpleINI/SimpleIni.h"
#include "PlayState.h"
#include "MainMenuState.h"

//Config sutff
using namespace std;
int main()
{
	objManager = new Cistron::ObjectManager();
    Game gam;
    gam.init("Bullwhip.Default", 800, 600); //Window title, width, height
    StateManager* state = gam.GetStateManager();
    PlayState* play = new PlayState;
    state->RegisterState("PlayState", play);
    //MainMenuState* menu = new MainMenuState;
    //state->RegisterState("MainMenuState", menu);
    state->SetCurrentState("PlayState");


    while(gam.run())
    {
        gam.draw();
    }
    return 0;
}
