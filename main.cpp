#include <iostream>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "SimpleINI/SimpleIni.h"
#include "PlayState.h"
#include "MainMenuState.h"

//Config sutff
#include "config.h"
#if HAVE_LIBBOX2D
#else
#error Needs box2d
#endif

#if HAVE_LIBSFML_SYSTEM
#else
#error Needs sfml
#endif

#if HAVE_LIBSFML_WINDOW
#else
#error Needs sfml
#endif

#if HAVE_LIBSFML_GRAPHICS
#else
#error Needs sfml
#endif
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
