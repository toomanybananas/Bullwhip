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
#include "Vec2.h"
#include "ImageManager.h"
#include "Constants.h"

class SceneManager;
class Entity : public Def
{
    public:
        Entity();
        virtual void init(); //Intialization


        virtual void SetX(float m); //Setting position
        virtual void SetY(float m);
        virtual void SetPos(Vec2& m) {pos = m;};
        virtual void SetXQ(float m); //Setting quened postion. Useful for modifiying position during a timestep.
        virtual void SetYQ(float m);

        virtual int GetWidth() {return w;};
        virtual int GetHeight() {return h;};


        virtual float GetX() {return draw.getPosition().x;}; //Getting position
        virtual float GetY() {return draw.getPosition().y;};


        virtual void SetRot(float m) {draw.setRotation(m);angle = m;}; //Getting and setting rotation angle (Degrees)
        virtual float GetRot() {return draw.getRotation();};


        virtual void update(SceneManager* scene);   //Update the basic components, don't overrider unless you need to add more
                                                    //basic components, such as physics
        virtual void Update(SceneManager* scene) {};//Function prototype, since c++ doesn't have a super call this is for
                                                    //user written code


        virtual sf::Sprite& getspr() {return draw;}; //Helper function for getting the sprite. Not used anymore, just here for compatiblity.
        virtual bool isAlive() {return alive;}; //returns whether the entity is alive or not.

        virtual void damage(int dmg); //Incomplete damage system.

        //virtual void SetTag(std::string name, boost::any data) {mdef.SetVal(name, data);}; //Functions for accessing mdef.
        //template<class T>
        //T GetTag(std::string name) {return mdef.GetVal<T>(name);};

        virtual void onCollision(Entity* obj) {return;}; //Collision callback, used for physics collisions. Called every frame of the collision
        virtual void onBeginCollision(Entity* obj) {return;}; //Called only when the collision starts
        virtual void onEndCollision(Entity* obj) {return;};
        virtual void SetAttribute(std::string attribute, bool val) {attributes[attribute] = val;};  //Setting basic attributes, call in ctor only most
                                                                                                    //of the time
        virtual bool GetAttribute(std::string attribute) {return attributes[attribute];}; //Getting attributes

        std::string name; //Quick getting the name of the entity eg phys_static

        virtual void Draw(sf::RenderTarget& win) {win.draw(draw);}; //Drawing function, is called by the scene manager
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

