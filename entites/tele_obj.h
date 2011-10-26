//Teleports you to a position of another object.
//If you want moving teleport destinations, or simply want to be able to move an object around instead of retyping in coords, this is for you
#pragma once
#include "tele_coord.h"

class tele_obj : public tele_coord
{
    public:
        tele_obj();
        virtual void update(SceneManager* scene);
        virtual bool onCollision(Entity* obj);
    protected:
        int ox;
        int oy;
    private:
};

Entity* newTele_obj(int i);
