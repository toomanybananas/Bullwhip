/**
 * @file Actor.h
 * @brief Basic skeleton for an actor entity
 * @author neos300
 * @version 1.0
 * @date 2012-06-20
 */
#pragma once
#include "entites/phys_dynamic.h"

/**
 * @brief Basic skeleton for an actor
 */
class Actor : public phys_dynamic
{
    public:
        virtual void init();
	/**
	 * @brief Moves the entity to the right by move_speed (Def)
	 */
        virtual void MoveRight();
	/**
	 * @brief Moves the entity to the left by move_speed (Def)
	 */
        virtual void MoveLeft();
	/**
	 * @brief Makes the entity jump by jump_force (Def)
	 */
        virtual void Jump();
	/**
	 * @brief Collision callback
	 *
	 * @param obj Object being collided with
	 */
        virtual void onCollision(Entity* obj);
        //virtual void onBeginCollision(Entity* obj);
        //virtual void onEndCollision(Entity* obj);
    private:
        bool can_jump;
        //int jump_force;
        //int move_speed;
        //bool can_move;
};
