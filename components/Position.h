#pragma once
#include "Cistron.h"

class Position : public Cistron::Component
{
	public:
		Position() : Cistron::Component("Position") {};

		void addedToObject()
		{
			//Auto assume authority because I'm too lazy to do proper error checking
			requestMessage("Get.Pos", &Position::SendPos);
			//fancy lambdas
			requestMessage("Get.X",[this](const Cistron::Message& msg){sendLocalMessage("Pos.X",x);});
			requestMessage("Get.Y",[this](const Cistron::Message& msg){sendLocalMessage("Pos.Y",y);});
			requestMessage("Set.X", &Position::SetX);
			requestMessage("Set.Y", &Position::SetY);
			requestMessage("Set.Angle", &Position::SetRot);
			requestMessage("Core.Init", &Position::init);
		}
		void init(const Cistron::Message& msg)
		{
			Entity* d = boost::any_cast<Entity*>(msg.p);
			x = d->GetVal<int>("x");
			y = d->GetVal<int>("y");
			angle = d->GetVal<float>("rotation");
		}

		void SendPos(const Cistron::Message& msg)
		{
			sendLocalMessage("Pos.X", x); //Message contains coordinates
			sendLocalMessage("Pos.Y", y);
			sendLocalMessage("Pos.Angle", angle);
		}
		void SetX(const Cistron::Message& msg)
		{
			x = boost::any_cast<int>(msg.p);
			sendLocalMessage("Pos.X", x);
		}
		void SetY(const Cistron::Message& msg)
		{
			y = boost::any_cast<int>(msg.p);
			sendLocalMessage("Pos.Y", y);
		}
		void SetRot(const Cistron::Message& msg)
		{
			angle = boost::any_cast<float>(msg.p);
			sendLocalMessage("Pos.Angle", angle);
		}
	public:
		int x;
		int y;
		float angle;
};
