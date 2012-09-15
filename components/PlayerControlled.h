#pragma once
#include "Cistron.h"
#include "../Definition.h"
//#include "../Item.h"
#include "../Entity.h"
class PlayerControlled : public Cistron::Component
{
	public:
		PlayerControlled() : Cistron::Component("PlayerControlled") {};

		void addedToObject()
		{
			//requestMessage("oncollision", &PlayerControlled::OnCollision);
			requestMessage("Phys.BeginCollision", &PlayerControlled::BeginCollision);
			requestMessage("Phys.EndCollision", &PlayerControlled::EndCollision);
			requestMessage("Core.Update", &PlayerControlled::update);
			//requestMessage("init", &PlayerControlled::init);
		}
		void update(const Cistron::Message& msg);
		//void OnCollision(const Cistron::Message& msg);
		void BeginCollision(const Cistron::Message& msg)
		{
			Entity* obj = boost::any_cast<Entity*>(msg.p);
			if(obj->name == "ent_item")
			{
				pickup = obj;
			}
		}

		void EndCollision(const Cistron::Message& msg)
		{
			Entity* obj = boost::any_cast<Entity*>(msg.p);
			if(obj == pickup)
			{
				pickup = NULL;
			}
		}
	private:
		//Inventory inv;
		Entity* pickup;
};
