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
        void Init(sf::RenderWindow* win) {window = win;};
        void RegisterState(std::string name, State* state);
        void RegisterState(std::string name, State state);
        void SetCurrentState(std::string name);
        void Update();
    protected:
    private:
        std::map<std::string, State*> states;
        State* current_state;
        sf::RenderWindow* window;
};

