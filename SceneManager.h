//Awesome class, handles drawing and updating of all entites.
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
#include "Constants.h"
#include "PhysicsWrappers/Box2DPhysics.h"


class SceneManager
{
    public:
        SceneManager();
        virtual void Update(sf::RenderWindow& win); //Updates everything
        virtual void AddEntity (Entity& obj); //Adds a entity to the global list
        virtual void AddEntity (Entity* obj);
        virtual void Init(Vec2 gravity); //Intializes the physics and views
        virtual void LoadScene(std::string filename); //Loads a level from a file.
        virtual void SetEntity(std::string n, Entity* ent) {specents[n] = ent;}; //Sets a entity to be  referred by name
        virtual Entity* GetEntity(std::string n) {return specents[n];};
        virtual void SetReg(EntityRegistry* r) {reg = r;}; //Sets the current entity registry
        virtual void AddSpawn(Entity& obj, std::string name) {spawnpoints[name] = &obj;}; //Adds a spawnpoint, this should be deprectated.
        virtual void AddSpawn(Entity* obj, std::string name) {spawnpoints[name] = obj;};
        virtual void Spawn(Entity& plyr, std::string spawnpoint); //Spawns an entity
        virtual void RemoveEntityFromList(std::string name); //Removes an entity from a list, so you can delete it.
        virtual void RemoveEntityFromList(Entity* ent);
    protected:
        std::vector<Entity*> entites; //Global list of entites
        sf::View v; //View for scrolling
        std::map<std::string, Entity*> specents; //List of entites to be reffered by name
        std::map<std::string, Entity*> spawnpoints; //Spawnpoint map
        Def worldprops; //World properties
        EntityRegistry* reg; //Entity registry

};

#endif // SCENEMANAGER_H
