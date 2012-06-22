/**
 * @file State.h
 * @brief State for a FSM
 * @author neos300
 * @version 1.0
 * @date 2012-06-21
 */

#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>

/**
 * @brief State for a FSM. Abstract, meant to be derived
 */
class State
{
    public:
        State();
	/**
	 * @brief Initalizes a state
	 *
	 * @param win Window for the state to draw to
	 */
        virtual void Init(sf::RenderWindow* win) {window = win;}; //Intializes the state, that line is a must.
	/**
	 * @brief Updates the state, called by state manager
	 *
	 * @return The state to change to, or none
	 */
        virtual std::string Update() {return "";}; //Called when the state is updated, returns the state to transtition to, "" for nothing.
    protected:
        sf::RenderWindow* window;
    private:
};

#endif // STATE_H
