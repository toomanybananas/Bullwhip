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
	 * @brief Set X position
	 *
	 * @param m X coordinate
	 */
        virtual void SetX(float m); 
	/**
	 * @brief Set Y position
	 *
	 * @param m Y coordinate
	 */
        virtual void SetY(float m);
	/**
	 * @brief Set position (may or may not work)
	 *
	 * @param m Position vector
	 */
        virtual void SetPos(Vec2& m) {pos = m;};
	/**
	 * @brief Set quened X position, which will take place next update. When in doubt, use this
	 *
	 * @param m X oocrdninate
	 */
        virtual void SetXQ(float m); 
	/**
	 * @brief Set quened Y position
	 *
	 * @param m Y coordinate
	 */
        virtual void SetYQ(float m);

	/**
	 * @brief Get's the width of the entity
	 *
	 * @return The width of the entity
	 */
        virtual int GetWidth() {return w;};
	/**
	 * @brief Gets the height of the entity
	 *
	 * @return The height of the entity
	 */
        virtual int GetHeight() {return h;};


	/**
	 * @brief Gets the X coord
	 *
	 * @return The x coordinate of the entity
	 */
        virtual float GetX() {return draw.getPosition().x;}; //Getting position
	/**
	 * @brief Gets the Y coordinate
	 *
	 * @return The y coordinate of the entity
	 */
        virtual float GetY() {return draw.getPosition().y;};


	/**
	 * @brief Sets the rotation of the entity
	 *
	 * @param m The angle in degrees
	 */
        virtual void SetRot(float m) {draw.setRotation(m);angle = m;}; //Getting and setting rotation angle (Degrees)
	/**
	 * @brief Gets the rotation of the entity
	 *
	 * @return The angle in degrees`
	 */
        virtual float GetRot() {return draw.getRotation();};


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
	 * @brief Legacy function to access the sprite. Don't use.
	 *
	 * @return The sprite from the entity
	 */
        virtual sf::Sprite& getspr() {return draw;}; //Helper function for getting the sprite. Not used anymore, just here for compatiblity.
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
        virtual void onCollision(Entity* obj) {return;}; //Collision callback, used for physics collisions. Called every frame of the collision
	/**
	 * @brief Collision callback called ONLY when the objects start to collide.
	 *
	 * @param obj Object being collided
	 */
        virtual void onBeginCollision(Entity* obj) {return;}; //Called only when the collision starts
	/**
	 * @brief Collosion callback called ONLY when the collision ends
	 *
	 * @param obj Object being collided
	 */
        virtual void onEndCollision(Entity* obj) {return;};
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
	 * @brief Draws the entity to a window
	 *
	 * @param win The window to be drawn to.
	 */
        virtual void Draw(sf::RenderTarget& win) {win.draw(draw);}; //Drawing function, is called by the scene manager
	/**
	 * @brief Destroys the entity after use. Should be followed up by delete entity;
	 */
        virtual void Destroy() {}; //Unfinished destruction function. Use right before deleting.



    protected:
        sf::Sprite draw; //Sprite for drawing things
        float lx; //Variable to hold current position
        float ly; //see above
        Vec2 pos;
        float angle;
        float xq; //Quened position
        float yq;
        Vec2 qpos;
        bool do_q; //Whether or not a quene is active
        int hw; //Half width of sprite
        int hh; //Half height
        int w;
        int h;

        bool alive; //Is the object alive? (used in things such as whether to call update or not)

        Def asset; //def loaded for asset stuff
        bool isasset;
        std::map<std::string, bool> attributes;
};

