#pragma once
#include "Cistron.h"

class Position : public Cistron::Component
{
	public:
		Position() : Cistron::Component("Position") {};

		void addedToObject()
		{
			requestMessage("sendpos", &Position::SendPos);
			requestMessage("setx", &Position::SetX);
			requestMessage("sety", &Position::SetY);
			requestMessage("setrot", &Position::SetRot);
			requestMessage("init", &Position::init);
		}
		void init(const Cistron::Message& msg)
		{
			Def* d = boost::any_cast<Def*>(msg.p);
			x = d->GetVal<int>("x");
			y = d->GetVal<int>("y");
			angle = d->GetVal<float>("rotation");
		}

		void SendPos(const Cistron::Message& msg)
		{
			sendLocalMessage("getx", x);
			sendLocalMessage("gety", y);
			sendLocalMessage("getrot", angle);
		}
		void SetX(const Cistron::Message& msg)
		{
			x = boost::any_cast<int>(msg.p);
			sendLocalMessage("getx", x);
		}
		void SetY(const Cistron::Message& msg)
		{
			y = boost::any_cast<int>(msg.p);
			sendLocalMessage("gety", y);
		}
		void SetRot(const Cistron::Message& msg)
		{
			angle = boost::any_cast<float>(msg.p);
			sendLocalMessage("getrot", angle);
		}
	public:
		int x;
		int y;
		float angle;
};
