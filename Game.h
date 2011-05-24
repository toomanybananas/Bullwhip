#pragma once
#define SFML_DYNAMIC
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "JMath.h"
#include "Constants.h"
#include "SceneManager.h"
#include "EntityRegistry.h"
#include "StateManager.h"

#define VERSION 0.1



class Game
{
    public:
        void init(std::string title, int x, int y);
        void draw();
        bool run() {return running;};

        const sf::Input& getin() {return win.GetInput();};

        sf::RenderWindow& getwin() {return win;};

        void clear() {win.Clear();};
        void display() {win.Display();};

        bool gEvent(sf::Event &ev) {return win.GetEvent(ev);};

        void HandleEvent(sf::Event& event) {};
        void Quit() {running = false;};

        void SetScene(SceneManager* scenem) {scene = scenem;};
        SceneManager* GetScene() {return scene;};
        EntityRegistry* GetRegistry() {return reg;};
        StateManager* GetStateManager() {return state;};

    private:
        sf::RenderWindow win;
        sf::String fps;
        sf::Font fpsfont;
        bool running;
        bool paused;
        SceneManager* scene;
        EntityRegistry* reg;
        StateManager* state;
};
