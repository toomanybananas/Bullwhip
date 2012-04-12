//Extremely useless file, nothing more than a pitiful wrapper for the state manager
//This hopefully won't be around for too much longer

#pragma once
#define SFML_DYNAMIC
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "StateManager.h"
#include "Constants.h"

#define VERSION 0.1



class Game
{
    public:
        void init(std::string title, int x, int y);
        void draw();
        bool run() {return running;};

        sf::RenderWindow& getwin() {return win;};

        void clear() {win.clear();};
        void display() {win.display();};

        bool gEvent(sf::Event &ev) {return win.pollEvent(ev);};

        void HandleEvent(sf::Event& event) {};
        void Quit() {running = false;};
        StateManager* GetStateManager() {return state;};
    private:
        sf::RenderWindow win;
        sf::Text fps;
        sf::Font fpsfont;
        StateManager* state;
        sf::RenderTexture GUI;
        sf::Sprite GUI_sprite;
        //Gwen::Renderer::SFML* render;
        //Gwen::Skin::TexturedBase skin;
        //Gwen::Input::SFML input;
        sf::Clock counter;
        bool running;
        bool paused;
};
