//Basic state prototype.
#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>

class State
{
    public:
        State();
        virtual void Init(sf::RenderWindow* win) {window = win;}; //Intializes the state, that line is a must.
        virtual std::string Update() {return "";}; //Called when the state is updated, returns the state to transtition to, "" for nothing.
    protected:
        sf::RenderWindow* window;
    private:
};

#endif // STATE_H
