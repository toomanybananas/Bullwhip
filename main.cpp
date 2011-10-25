#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "SimpleINI/SimpleIni.h"
#include "PlayState.h"
#include "MainMenuState.h"
//Version is 0.3

using namespace std;
int main()
{
    /*CSimpleIni bullwhipini;
    bullwhipini.LoadFile("Bullwhip.ini");*/
    Game gam;
    gam.init("Bullwhip.Default", 800, 600); //Window title, width, height
    StateManager* state = gam.GetStateManager();
    PlayState* play = new PlayState;
    state->RegisterState("PlayState", play);
    MainMenuState* menu = new MainMenuState;
    state->RegisterState("MainMenuState", menu);
    state->SetCurrentState("MainMenuState");


    while(gam.run())
    {
        const sf::Input& in = gam.getin();

        sf::Event event;

        while(gam.gEvent(event))
        {
            if(event.Type == sf::Event::Closed)
                gam.Quit();
        }
        gam.draw();
    }
    return 0;
}
