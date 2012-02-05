//Simple menu state
//Likely to be gone once the ability to load menus from a lua script is added.

//Now using Gwen!
#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include <Gwen/Renderers/SFML.h>
#include <Gwen/Input/SFML.h>
#include <Gwen/Skins/TexturedBase.h>
#include <Gwen/Controls/Canvas.h>
#include <Gwen/Controls/Button.h>
#include "Constants.h"


class MainMenuState : public State
{
    public:
        MainMenuState();
        virtual void Init(sf::RenderWindow* win);
        virtual std::string Update();
    protected:
        bool alive;
        Gwen::Controls::Button* play;
    private:
        typedef State super;
};
