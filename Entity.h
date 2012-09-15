/**
 * @file Entity.h
 * @brief Skeleton for a basic entity
 * @author neos300
 * @version 1.0
 * @date 2012-06-20
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Definition.h"
#include "Vec2.h"
#include "ImageManager.h"
#include "Constants.h"
#include "ComponentRegistry.h"
#include "components/Listener.h"

class SceneManager;
class Entity : public Def
{
    public:
        Entity();
	/**
	 * @brief Initilization function
	 */
        virtual void init();

	
	/**
	 * @brief Adds a component to the entity
	 *
	 * @param comp The name of the component to add, fetched from the component registry
	 */
	void AddComponent(std::string comp);	
	/**
	 * @brief Basic functionality for entites, DO NOT OVERRIDE THIS (unless you're making an extension)
	 *
	 * @param scene The scene manager it is refering to.
	 */
        virtual void update(SceneManager* scene);
        
	/**
	 * @brief Determines whether the entity should be drawn/updated.
	 *
	 * @return Whether the entity is alive or not
	 */
        virtual bool isAlive() {return alive;}; //returns whether the entity is alive or not.
	/**
	 * @brief Collision callback, called every frame the collision is happening.
	 *
	 * @param obj Object being collided
	 */
        virtual void onCollision(Entity* obj)
	{
		SendMessage("Phys.Collision", obj);
	}
	/**
	 * @brief Collision callback called ONLY when the objects start to collide.
	 *
	 * @param obj Object being collided
	 */
        virtual void onBeginCollision(Entity* obj)
	{
		SendMessage("Phys.BeginCollision", obj);
	}	
	/**
	 * @brief Collosion callback called ONLY when the collision ends
	 *
	 * @param obj Object being collided
	 */
        virtual void onEndCollision(Entity* obj)
	{
		SendMessage("Phys.EndCollision", obj);
	}
	/**
	 * @brief Attribute setting, needs to go
	 *
	 * @param attribute Attribute to set
	 * @param val Value of the attribute
	 */
        //virtual void SetAttribute(std::string attribute, bool val) {attributes[attribute] = val;};
	/**
	 * @brief Getting attributes, needs to go
	 *
	 * @param attribute Attribute to set
	 *
	 * @return The attribute value
	 */
        //virtual bool GetAttribute(std::string attribute) {return attributes[attribute];};
	/**
	 * @brief Type of the entity (eg phys_static). Should be set in ctor
	 */
        std::string name; //Quick getting the name of the entity eg phys_static

        
	/**
	 * @brief Destroys the entity after use. Should be followed up by delete entity;
	 */
        virtual void Destroy() {}; //Unfinished destruction function. Use right before deleting.

	Cistron::ObjectId& getId() {return obj;};

	void SendMessage(std::string msg, boost::any payload = 0)
	{
		objManager->sendMessageToObject(msg, NULL, obj, payload);
	}



	//Shorthand for getting the x and y coords
	int GetX()
	{
		return listen->GetX();		
	}
	int GetY()
	{
		return listen->GetY();	
	}
	void SetX(int xx)
	{
		SendMessage("Set.X", xx);	
	}
	void SetY(int xx)
	{
		SendMessage("Set.Y", xx);
	}
    protected:
        bool alive; //Is the object alive? (used in things such as whether to call update or not)

        Def asset; //def loaded for asset stuff
        bool isasset;
        //std::map<std::string, bool> attributes;
	Cistron::ObjectId obj;
	std::vector<std::string> comps;
	Listener* listen;
};

