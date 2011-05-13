#pragma once
#include "tele_coord.h"

class tele_obj : public tele_coord
{
    public:
        tele_obj();
        virtual void update(const sf::Input& in, SceneManager* scene);
        virtual bool onCollision(Entity* obj);
    protected:
        int ox;
        int oy;
    private:
};

Entity* newTele_obj(int i);
