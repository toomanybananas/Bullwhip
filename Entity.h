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

	
	void AddComponent(std::string comp);	




	/**
	 * @brief Basic functionality for entites, DO NOT OVERRIDE THIS (unless you're making an extension)
	 *
	 * @param scene The scene manager it is refering to.
	 */
        virtual void update(SceneManager* scene);   //Update the basic components, don't overrider unless you need to add more
                                                    //basic components, such as physics
	/**
	 * @brief Override this with your code.
	 *
	 * @param scene The global scene manager
	 */
        virtual void Update(SceneManager* scene) {};//Function prototype, since c++ doesn't have a super call this is for
                                                    //user written code
        
	/**
	 * @brief Determines whether the entity should be drawn/updated.
	 *
	 * @return Whether the entity is alive or not
	 */
        virtual bool isAlive() {return alive;}; //returns whether the entity is alive or not.

	/**
	 * @brief The makings of an incomplete health system.
	 *
	 * @param dmg The damage to deal
	 */
        virtual void damage(int dmg); //Incomplete damage system.

      
	/**
	 * @brief Collision callback, called every frame the collision is happening.
	 *
	 * @param obj Object being collided
	 */
        virtual void onCollision(Entity* obj)
	{
		SendMessage("oncollision", obj);
	}
	/**
	 * @brief Collision callback called ONLY when the objects start to collide.
	 *
	 * @param obj Object being collided
	 */
        virtual void onBeginCollision(Entity* obj)
	{
		SendMessage("begincollision", obj);
	}	
	/**
	 * @brief Collosion callback called ONLY when the collision ends
	 *
	 * @param obj Object being collided
	 */
        virtual void onEndCollision(Entity* obj)
	{
		SendMessage("endcollision", obj);
	}
	/**
	 * @brief Attribute setting, needs to go
	 *
	 * @param attribute Attribute to set
	 * @param val Value of the attribute
	 */
        virtual void SetAttribute(std::string attribute, bool val) {attributes[attribute] = val;};  //Setting basic attributes, call in ctor only most
                                                                                                    //of the time
	/**
	 * @brief Getting attributes, needs to go
	 *
	 * @param attribute Attribute to set
	 *
	 * @return The attribute value
	 */
        virtual bool GetAttribute(std::string attribute) {return attributes[attribute];}; //Getting attributes

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
		SendMessage("setx", xx);	
	}
	void SetY(int xx)
	{
		SendMessage("sety", xx);
	}
    protected:
        bool alive; //Is the object alive? (used in things such as whether to call update or not)

        Def asset; //def loaded for asset stuff
        bool isasset;
        std::map<std::string, bool> attributes;
	Cistron::ObjectId obj;
	std::vector<std::string> comps;
	Listener* listen;
};

