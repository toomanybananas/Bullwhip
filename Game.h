/**
 * @file Game.h
 * @brief A class that runs everything
 * @author neos300
 * @version 1.0
 * @date 2012-06-21
 */
#pragma once
#define SFML_DYNAMIC
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "StateManager.h"
#include "Constants.h"



/**
 * @brief Controller class that handles everything
 */
class Game
{
    public:
	    /**
	     * @brief Initalizes the game
	     *
	     * @param title The title of the window
	     * @param x The width of the window
	     * @param y The height of teh window
	     */
        void init(std::string title, int x, int y);
	/**
	 * @brief Draws the game window
	 */
        void draw();
	/**
	 * @brief Game status
	 *
	 * @return Whether the game is running or not
	 */
        bool run() {return running;};

	/**
	 * @brief Raw window getter
	 *
	 * @return The SFML window
	 */
        sf::RenderWindow& getwin() {return win;};

	/**
	 * @brief Clears the window
	 */
        void clear() {win.clear();};
	/**
	 * @brief Displays the window
	 */
        void display() {win.display();};

	/**
	 * @brief Gets an event from the window
	 *
	 * @param ev Ref to event
	 *
	 * @return Whether there is an event avaliable or not
	 */
        bool gEvent(sf::Event &ev) {return win.pollEvent(ev);};

	/**
	 * @brief Handles an event from gEvent
	 *
	 * @param event The event
	 */
        void HandleEvent(sf::Event& event) {};
	/**
	 * @brief Quits the game
	 */
        void Quit() {running = false;};
	/**
	 * @brief Returns the state manager
	 *
	 * @return 
	 */
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
