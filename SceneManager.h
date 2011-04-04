#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "entites/phys_static.h"
#include "BullwhipContactListener.h"


class SceneManager
{
    public:
        SceneManager();
        virtual void Update(sf::RenderWindow& win);
        virtual void AddEntity (Entity& obj);
        virtual void AddEntity (Entity* obj);
        virtual void Init(b2Vec2 gravity);
        virtual void PhysAdd(Entity* obj);
        virtual void LoadScene(std::string filename);
    protected:
        std::vector<Entity*> entites;
        b2World* phys_world;
        BullwhipContactListener bclisten;
        Entity* center;
        sf::View v;
};

#endif // SCENEMANAGER_H
