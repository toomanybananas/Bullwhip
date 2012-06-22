/**
 * @file StateManager.h
 * @brief FSM manager
 * @author neos300
 * @version 1.0
 * @date 2012-06-21
 */

#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "State.h"

/**
 * @brief FSM manager
 */
class StateManager
{
    public:
        StateManager();
	/**
	 * @brief Initalizes the state manager
	 *
	 * @param win The window to draw the states to.
	 */
        void Init(sf::RenderWindow* win) {window = win;}; //Inits the state manger with the window
	/**
	 * @brief Registers a state
	 *
	 * @param name The name of the state
	 * @param state The state
	 */
        void RegisterState(std::string name, State* state); //Registers a state in the map
        void RegisterState(std::string name, State& state);
	/**
	 * @brief Sets the current state
	 *
	 * @param name The state to set to
	 */
        void SetCurrentState(std::string name); //Sets the state as the one with this name
	/**
	 * @brief Updates the FSM
	 */
        void Update(); //Updates the current state
    protected:
    private:
        std::map<std::string, State*> states; //Map of the states.
        State* current_state;
        sf::RenderWindow* window;
};

