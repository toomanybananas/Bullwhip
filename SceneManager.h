/**
 * @file SceneManager.h
 * @brief Handles EVERYTHING
 * @author neos300
 * @version 1.0
 * @date 2012-06-20
 */

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
	/**
	 * @brief Updates all the entites and the physics engine, then draw
	 *
	 * @param win The render target to draw to
	 */
        virtual void Update(sf::RenderTarget& win); //Updates everything
	/**
	 * @brief Adds an entity to the global list
	 *
	 * @param obj The entity to add
	 */
        virtual void AddEntity (Entity& obj); //Adds a entity to the global list
        virtual void AddEntity (Entity* obj);
	/**
	 * @brief Initalizes the physics and the scene manager
	 *
	 * @param gravity The gravity for physics
	 */
        virtual void Init(Vec2 gravity); //Intializes the physics and views
	/**
	 * @brief Loads the scene from a file
	 *
	 * @param filename File to load from
	 */
        virtual void LoadScene(std::string filename); //Loads a level from a file.
	/**
	 * @brief Legacy v1 scene loading
	 *
	 * @param filename File to load
	 */
	virtual void LoadScenev1(std::string filename);
	/**
	 * @brief Sets a unique name for an entity
	 *
	 * @param n The name
	 * @param ent The entity
	 */
        virtual void SetEntity(std::string n, Entity* ent) {specents[n] = ent;}; //Sets a entity to be  referred by name
	/**
	 * @brief Gets an entity from a unique name
	 *
	 * @param n The name
	 *
	 * @return The entity
	 */
        virtual Entity* GetEntity(std::string n) {return specents[n];};
	/**
	 * @brief Sets the current entity registry
	 *
	 * @param r The registry to switch with
	 */
        virtual void SetReg(EntityRegistry* r) {reg = r;}; //Sets the current entity registry
	/**
	 * @brief Adds a spawnpoint (game_spawnpoint)
	 *
	 * @param obj The spawnpoint to add
	 * @param name The name of the spawnpoint
	 */
        virtual void AddSpawn(Entity& obj, std::string name) {spawnpoints[name] = &obj;}; //Adds a spawnpoint, this should be deprectated.
        virtual void AddSpawn(Entity* obj, std::string name) {spawnpoints[name] = obj;};
	/**
	 * @brief Spawns an entity at a spawnpoint
	 *
	 * @param plyr The player entity
	 * @param spawnpoint The name of the game_spawnpoint
	 */
        virtual void Spawn(Entity& plyr, std::string spawnpoint); //Spawns an entity
	/**
	 * @brief Remove an entity from the entity list, allowing you to destroy it
	 *
	 * @param name The name of the entity
	 */
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
