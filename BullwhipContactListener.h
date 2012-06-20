/**
 * @file BullwhipContactListener.h
 * @brief Listener for collision callbacks, mumbo jumbo box2d stuff
 * @author neos300
 * @version 1.0
 * @date 2012-06-20
 */
#pragma once
#include <Box2D/Box2D.h>
#include <iostream>
#include "Entity.h"

class BullwhipContactListener : public b2ContactListener
{
    public:
        BullwhipContactListener();
        void BeginContact(b2Contact* contact);
        void EndContact(b2Contact* contact);
        void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
    protected:
    private:
};

