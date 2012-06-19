#include <iostream>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "SimpleINI/SimpleIni.h"
#include "PlayState.h"
#include "MainMenuState.h"


using namespace std;
int main()
{
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
