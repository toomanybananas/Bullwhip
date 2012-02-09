#include "ParticleEmitter.h"

ParticleEmitter::ParticleEmitter()
{
    //ctor
}

void ParticleEmitter::Init(int max_p, sf::Vector2f p)
{
    max_particles = max_p;
    pos = p;
}

void ParticleEmitter::Update(sf::RenderWindow* win)
{
    /*for(int i = 0; i < particles.size(); i++)
    {
        if(particles[i]->Update() == true)
        {
            delete particles[i];
            particles.erase(particles.begin()+i);
        }
    }
    if(particles.size() < max_particles)
    {
        Particle* p = new Particle;
        sf::Vector2f s;
        /*sf::Randomizer random;
        s.x = random.Random(-0.5f, 0.5f);
        s.y = random.Random(1.f, 3.f);
        sf::Vector2f po = pos;
        //po.x += random.Random(-10.f, 10.f);
        p->Init(po, sf::Color(61, 255, 255), s, sf::Vector2f(0,0), 5);
        particles.insert(particles.end(), p);
    }
    //draw particles
    //draw.CopyScreen(*win);
    for(int k = 0; k < particles.size(); k ++)
    {
        draw.SetPixel(particles[k]->pos.x, particles[k]->pos.y, particles[k]->color);
    }
    //todraw.SetImage(draw);
    //win->Draw(todraw);*/
}

