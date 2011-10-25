//Simple menu state
//Likely to be gone once the ability to load menus from a lua script is added.
#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include "GUI/cpGUI.h"
#include "Constants.h"


class MainMenuState : public State
{
    public:
        MainMenuState();
        virtual void Init(sf::RenderWindow* win);
        virtual std::string Update();
    protected:
        bool alive;
        cp::cpGuiContainer gui;
        cp::cpButton* play_btn;
        cp::cpButton* exit_btn;
    private:
};
