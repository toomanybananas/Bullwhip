#include "Particle.h"

Particle::Particle()
{
    //ctor
    alive = false;
}

void Particle::Init(sf::Vector2f p, sf::Color c, sf::Vector2f s, sf::Vector2f g, float l)
{
    pos = p;
    origin = p;
    color = c;
    ospeed = s;
    speed = s;
    gravity = g;
    lifetime = l;
    alive = true;
    life.Restart();
}

bool Particle::Update()
{
    pos += speed;
    speed += gravity;
    if(life.GetElapsedTime().AsMilliseconds() >= lifetime)
    {
        return true;
    }
    else
    {
        return false;
    }
}

