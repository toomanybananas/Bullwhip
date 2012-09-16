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
			requestMessage("Core.Init", &Physical::init);
			requestMessage("Core.Update", &Physical::update);
			requestMessage("Phys.ApplyForce", &Physical::ApplyForce);
			requestMessage("Set.LinearVelocity", [this](const Cistron::Message& msg)
					{
						body->SetLinearVelocity(boost::any_cast<Vec2>(msg.p));	
					});
			requestMessage("Get.LinearVelocity", [this](const Cistron::Message& msg)
					{
						sendLocalMessage("Phys.LinearVelocity", body->GetLinearVelocity());
					});
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
				requestMessage("Set.X", &Physical::SetX);
				requestMessage("Set.Y", &Physical::SetY);
				requestMessage("Set.Angle", &Physical::SetRot);
				//I'm hooked on lambdas
				requestMessage("Get.X", [this](const Cistron::Message& msg){sendLocalMessage("Pos.X", GetX());});
				requestMessage("Get.Y", [this](const Cistron::Message& msg){sendLocalMessage("Pos.Y", GetY());});
				requestMessage("Get.Angle", [this](const Cistron::Message& msg){sendLocalMessage("Pos.Angle", GetRot());});
			}
			else
			{
				std::cout << "Warning: You have a physics component that has no authority. This is generally very bad, and can result in a very unstable physics simulation\n";
				requestMessage("Pos.X", &Physical::SetX);
				requestMessage("Pos.Y", &Physical::SetY);
				requestMessage("Pos.Angle", &Physical::SetRot);
			}
			body->Intialize(d);

			//sendLocalMessage("sendpos");
		}

		void update(const Cistron::Message& msg)
		{
			if(authority)
			{
				sendLocalMessage("Pos.X", GetX());
				sendLocalMessage("Pos.Y", GetY());
				sendLocalMessage("Pos.Angle", GetRot());
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
			return body->GetAngle();
		}
		void ApplyForce(const Cistron::Message& msg)
		{
			Vec2 vec = boost::any_cast<Vec2>(msg.p);
			body->ApplyForce(vec);
		}
	protected:
		PhysicsBody* body;
		bool authority;
};
