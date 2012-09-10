#pragma once
#include "Cistron.h"
#include "../Definition.h"
class Moveable : public Cistron::Component
{
	public:
		Moveable() : Cistron::Component("Moveable") {};

		void addedToObject()
		{
			requestMessage("moveright", &Moveable::MoveRight);
			requestMessage("moveleft", &Moveable::MoveLeft);
			requestMessage("jump", &Moveable::Jump);
			requestMessage("oncollision", &Moveable::OnCollision);
			//requestMessage("update", &Moveable::update);
			requestMessage("init", &Moveable::init);
			requestMessage("gety", &Moveable::SetY);
		}
		void init(const Cistron::Message& msg)
		{
			Entity* d = boost::any_cast<Entity*>(msg.p);
			if(!d->IsDefined("move_speed"))
				speed.SetVal("move", 5);
			else
				speed.SetVal("move", d->GetVal<int>("move_speed"));
			if(!d->IsDefined("jump_force"))
				speed.SetVal("jump", -50);
			else
				speed.SetVal("jump", d->GetVal<int>("jump_force"));
			if(!d->IsDefined("moveable"))
				speed.SetVal("moveable", true);
			else
				speed.SetVal("moveable", d->GetVal<bool>("moveable"));
			hh = d->GetVal<int>("hh");
		}

		void MoveRight(const Cistron::Message& msg)
		{
			if(!speed.GetVal<bool>("moveable"))
				return;
			sendLocalMessage("applyforce", Vec2(speed.GetVal<int>("move"), 0));
		}

		void MoveLeft(const Cistron::Message& msg)
		{
			if(!speed.GetVal<bool>("moveable"))
				return;
			sendLocalMessage("applyforce", Vec2(speed.GetVal<int>("move") * -1, 0));
		}

		void Jump(const Cistron::Message& msg)
		{
			if(!can_jump)
				return;
			sendLocalMessage("applyforce", Vec2(0, speed.GetVal<int>("jump")));
			can_jump = false;
		}
		void OnCollision(const Cistron::Message& msg)
		{
			Entity* ent = boost::any_cast<Entity*>(msg.p);
			if((ent->GetY() - (ent->GetVal<int>("hh"))) > (y + (hh)))
			{
				can_jump = true;
			}
		}

		void SetY(const Cistron::Message& msg)
		{
			y = boost::any_cast<int>(msg.p);
		}

	private:
		Def speed; //Elegant hack to mirror Actor functionality
		bool can_jump;
		int y;
		int hh;
};
