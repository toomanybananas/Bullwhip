#pragma once
#include <SFML/Graphics.hpp>
class Particle
{
    public:
        Particle();
        sf::Vector2f origin;
        sf::Vector2f pos;
        sf::Color color;
        sf::Vector2f ospeed;
        sf::Vector2f speed;
        sf::Vector2f gravity;
        float lifetime;
        void Init(sf::Vector2f p, sf::Color c, sf::Vector2f s, sf::Vector2f g, float l);
        bool Update();
    protected:
        bool alive;
        sf::Clock life;
    private:
};

