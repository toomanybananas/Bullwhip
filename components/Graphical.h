#pragma once
#include "Cistron.h"
#include <SFML/Graphics.hpp>
#include "../Constants.h"
#include "../ImageManager.h"
class Graphical : public Cistron::Component
{
	public:
		Graphical() : Cistron::Component("Graphical")
		{
			//
		}

		void addedToObject()
		{
			requestMessage("init", &Graphical::init);
			requestMessage("update", &Graphical::Update);
			requestMessage("getx", &Graphical::SetX);
			requestMessage("gety", &Graphical::SetY);
			requestMessage("getrot", &Graphical::SetRot);
			requestMessage("draw", &Graphical::Draw);
		}

		void init(const Cistron::Message& msg);
		void Update(const Cistron::Message& msg);
		void SetX(const Cistron::Message& msg)
		{
			draw.setPosition(boost::any_cast<int>(msg.p), y);
			x = draw.getPosition().x;
		}
		void SetY(const Cistron::Message& msg)
		{
			draw.setPosition(x, boost::any_cast<int>(msg.p));
			y = draw.getPosition().y;
		}
		void SetRot(const Cistron::Message& msg)
		{
			draw.setRotation(boost::any_cast<float>(msg.p));
		}
		void Draw(const Cistron::Message& msg)
		{
			sf::RenderTarget* win = boost::any_cast<sf::RenderTarget*>(msg.p);
			win->draw(draw);
		}
	private:
		sf::Sprite draw;
		int hw;
		int hh;
		int w;
		int h;
		int x;
		int y;

		Def asset;
		bool isasset;
};
