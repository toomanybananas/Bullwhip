#pragma once
#include "Cistron.h"

class Listener : public Cistron::Component
{
	public:
		Listener() : Cistron::Component("Listener") {};

		void addedToObject()
		{
			requestMessage("Pos.X", &Listener::SetX);
			requestMessage("Pos.Y", &Listener::SetY);
			requestMessage("Pos.Angle", &Listener::SetRot);
			x = 0;
			y = 0;
		}

		
		void SetX(const Cistron::Message& msg)
		{
			x = boost::any_cast<int>(msg.p);
		}
		void SetY(const Cistron::Message& msg)
		{
			y = boost::any_cast<int>(msg.p);
		}
		void SetRot(const Cistron::Message& msg)
		{
			angle = boost::any_cast<float>(msg.p);
		}
		int GetX()
		{
			sendLocalMessage("Get.X");
			return x;
		}
		int GetY()
		{
			sendLocalMessage("Get.Y");
			return y;
		}
	public:
		int x;
		int y;
		float angle;
};
