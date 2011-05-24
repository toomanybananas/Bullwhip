#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "EntityRegistry.h"
#include "entites/phys_static.h"
#include "BullwhipContactListener.h"
#include "File.h"


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
        virtual void SetEntity(std::string n, Entity* ent) {specents[n] = ent;};
        virtual Entity* GetEntity(std::string n) {return specents[n];};
        virtual void SetReg(EntityRegistry* r) {reg = r;};
        virtual void AddSpawn(Entity& obj, std::string name) {spawnpoints[name] = &obj;};
        virtual void AddSpawn(Entity* obj, std::string name) {spawnpoints[name] = obj;};
        virtual void Spawn(Entity& plyr, std::string spawnpoint);
        virtual void RemoveEntityFromList(std::string name);
        virtual void RemoveEntityFromList(Entity* ent);
    protected:
        std::vector<Entity*> entites;
        b2World* phys_world;
        BullwhipContactListener bclisten;
        sf::View v;
        std::map<std::string, Entity*> specents;
        std::map<std::string, Entity*> spawnpoints;
        Def worldprops;
        EntityRegistry* reg;

};

#endif // SCENEMANAGER_H
