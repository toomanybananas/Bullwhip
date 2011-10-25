#pragma once


/*
Incredibly basic entity, used just to define certain functions.
Could be used as a static decal


MEASUREMENTS:
ALL ANGLES ARE IN DEGREES
ALL POSTITIONS ARE IN PIXELS
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Definition.h"
#include "ImageManager.h"
#include "Constants.h"

class SceneManager;
class Entity
{
    public:
        Entity();
        virtual void init(Def def); //Intialization


        virtual void SetX(float m); //Setting position
        virtual void SetY(float m);
        virtual void SetXQ(float m); //Setting quened postion. Useful for modifiying position during a timestep.
        virtual void SetYQ(float m);


        virtual float GetX() {return draw.GetPosition().x;}; //Getting position
        virtual float GetY() {return draw.GetPosition().y;};


        virtual void SetRot(float m) {draw.SetRotation(m);}; //Getting and setting rotation angle (Degrees)
        virtual float GetRot() {return draw.GetRotation();};


        virtual void update(const sf::Input &in, SceneManager* scene);  //Update the basic components, don't overrider unless you need to add more
                                                                        //basic components, such as physics
        virtual void Update(const sf::Input &in, SceneManager* scene) {};   //Function prototype, since c++ doesn't have a super call this is for
                                                                            //user written code


        virtual sf::Sprite& getspr() {return draw;}; //Helper function for getting the sprite. Not used anymore, just here for compatiblity.
        virtual bool isAlive() {return alive;}; //returns whether the entity is alive or not.

        virtual void damage(int dmg); //Incomplete damage system.

        virtual void SetTag(std::string name, void* data) {mdef.SetVal(name, data);}; //Functions for accessing mdef.
        virtual void* GetTag(std::string name) {return mdef.GetVal(name);};

        virtual void SetStr(std::string name, std::string data) {mdef.SetString(name, data);};
        virtual std::string GetStr(std::string name) {return mdef.GetString(name);};

        virtual bool onCollision(Entity* obj) {return true;}; //Collision callback, used for physics collisions.
        virtual void SetAttribute(std::string attribute, bool val) {attributes[attribute] = val;};  //Setting basic attributes, call in ctor only most
                                                                                                    //of the time
        virtual bool GetAttribute(std::string attribute) {return attributes[attribute];}; //Getting attributes

        std::string name; //Quick getting the name of the entity eg phys_static

        virtual void Draw(sf::RenderWindow& win) {win.Draw(draw);}; //Drawing function, is called by the scene manager
        virtual void Destroy() {}; //Unfinished destruction function. Use right before deleting.



    protected:
        sf::Sprite draw; //Sprite for drawing things
        float lx; //Variable to hold current position
        float ly; //see above
        float xq; //Quened position
        float yq;
        bool do_q; //Whether or not a quene is active
        int hw; //Half width of sprite
        int hh; //Half height

        bool alive; //Is the object alive? (used in things such as whether to call update or not)

        Def mdef; //Def that is passed during intilization
        std::map<std::string, bool> attributes;
};

Entity* newEntity(int i);
