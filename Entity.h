#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <Box2D/Box2D.h>
#include "Definition.h"
#include "ImageManager.h"
#include "Constants.h"


class Entity
{
    public:
        Entity();
        virtual void init(Def def);


        virtual void SetX(float m);
        virtual void SetY(float m);


        virtual float GetX() {return draw.GetPosition().x;};
        virtual float GetY() {return draw.GetPosition().y;};


        virtual void SetRot(float m) {draw.SetRotation(m);};
        virtual float GetRot() {return draw.GetRotation();};


        virtual void update();


        virtual sf::Sprite& getspr() {return draw;};
        virtual bool isAlive() {return alive;};

        virtual void damage(int dmg);

        virtual bool isSolid() {return solid;};

        virtual void SetTag(std::string name, void* data) {mdef.SetVal(name, data);};
        virtual void* GetTag(std::string name) {return mdef.GetVal(name);};

        virtual void SetStr(std::string name, std::string data) {mdef.SetString(name, data);};
        virtual std::string GetStr(std::string name) {return mdef.GetString(name);};

        virtual bool onCollision(Entity* obj) {return true;};
        virtual void SetAttribute(std::string attribute, bool val) {attributes[attribute] = val;};
        virtual bool GetAttribute(std::string attribute) {return attributes[attribute];};
        virtual void reg(b2World* world) {};

        std::string name;



    protected:
        //MUST BE 64X64
        sf::Sprite draw;
        float lx;
        float ly;
        int hw;
        int hh;
        //0 is up, 1 right, 2 down, 3 left

        bool alive; //Is the object alive? (used in things such as whether to call update or not)
        bool solid;

        Def mdef;
        std::map<std::string, bool> attributes;
};

