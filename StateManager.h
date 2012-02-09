//Transfers states to one another
#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "State.h"

class StateManager
{
    public:
        StateManager();
        void Init(sf::RenderWindow* win) {window = win;}; //Inits the state manger with the window
        void RegisterState(std::string name, State* state); //Registers a state in the map
        void RegisterState(std::string name, State& state);
        void SetCurrentState(std::string name); //Sets the state as the one with this name
        void Update(); //Updates the current state
    protected:
    private:
        std::map<std::string, State*> states; //Map of the states.
        State* current_state;
        sf::RenderWindow* window;
};

