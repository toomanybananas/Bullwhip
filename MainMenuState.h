//Simple menu state
//Likely to be gone once the ability to load menus from a lua script is added.

///Currently killed because of SFML2 transition, current gui library is incompatible.

#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include "Constants.h"


class MainMenuState : public State
{
    public:
        MainMenuState();
        //virtual void Init(sf::RenderWindow* win);
        //virtual std::string Update();
    protected:
        bool alive;
        /*cp::cpGuiContainer gui;
        cp::cpButton* play_btn;
        cp::cpButton* exit_btn;*/
    private:
        typedef State super;
};
