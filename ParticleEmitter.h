#pragma once
#include "Particle.h"
#include <SFML/Graphics.hpp>
#include <vector>
class ParticleEmitter
{
    public:
        ParticleEmitter();
        virtual void Init(int max_p, sf::Vector2f p);
        virtual void Update(sf::RenderWindow* win);
    protected:
        int max_particles;
        std::vector<Particle*> particles;
        sf::Vector2f pos;
        sf::Image draw;
        sf::Sprite todraw;
    private:
};

