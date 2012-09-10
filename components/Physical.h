#pragma once
#include "Cistron.h"
#include "../PhysicsWrappers/Box2DPhysics.h"
#include "../Vec2.h"
#include "../JMath.h"
#include "../Entity.h"
class Physical : public Cistron::Component
{
	public:
		Physical() : Cistron::Component("Physical") {};

		void addedToObject()
		{
			//requestMessage("getx", &Physical::SetX);
			//requestMessage("gety", &Physical::SetY);
			//requestMessage("getrot", &Physical::SetRot);
			requestMessage("init", &Physical::init);
			requestMessage("update", &Physical::update);
			authority = false;
		}
		void init(const Cistron::Message& msg)
		{
			Entity* d = boost::any_cast<Entity*>(msg.p);
			std::string type = d->GetVal<std::string>("phystype");
			if(type == "static")
				body = new StaticBody;
			if(type == "dynamic")
				body = new DynamicBody;
			if(type == "trigger")
				body = new TriggerBody;
			if(d->GetVal<int>("auth") == 100)
			{
				authority = true;
				requestMessage("setx", &Physical::SetX);
				requestMessage("sety", &Physical::SetY);
				requestMessage("setrot", &Physical::SetRot);
			}
			else
			{
				std::cout << "Warning: You have a physics component that has no authority. This is generally very bad, and can result in a very unstable physics simulation\n";
				requestMessage("getx", &Physical::SetX);
				requestMessage("gety", &Physical::SetY);
				requestMessage("getrot", &Physical::SetRot);
			}
			body->Intialize(d);

			//sendLocalMessage("sendpos");
		}

		void update(const Cistron::Message& msg)
		{
			if(authority)
			{
				sendLocalMessage("getx", GetX());
				sendLocalMessage("gety", GetY());
				sendLocalMessage("getrot", GetRot());
			}
		}

		void SetX(const Cistron::Message& msg)
		{
			int x = boost::any_cast<int>(msg.p);
			body->SetTransform(Vec2(x, GetY()), GetRot());
		}
		void SetY(const Cistron::Message& msg)
		{
			int y = boost::any_cast<int>(msg.p);
			body->SetTransform(Vec2(GetX(), y), GetRot());
		}
		void SetRot(const Cistron::Message& msg)
		{
			float angle = boost::any_cast<float>(msg.p);
			body->SetTransform(body->GetPosition(), toRad(angle));
		}
		int GetX()
		{
			return body->GetPosition().x;
		}
		int GetY()
		{
			return body->GetPosition().y;
		}
		float GetRot()
		{
			return toDeg(body->GetAngle());
		}
	protected:
		PhysicsBody* body;
		bool authority;
};
