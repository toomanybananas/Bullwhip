#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>

class State
{
    public:
        State();
        virtual void Init(sf::RenderWindow* win) {window = win;};
        virtual std::string Update() {return "";};
    protected:
        sf::RenderWindow* window;
    private:
};

#endif // STATE_H
