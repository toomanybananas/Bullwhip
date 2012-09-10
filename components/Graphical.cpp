#include "Graphical.h"
using namespace Cistron;

void Graphical::init(const Message& msg)
{
	isasset = false;
	sf::Texture* tex;
	Entity* d = boost::any_cast<Entity*>(msg.p);
	if(d == NULL)
		std::cout << "bad def\n";
	std::cout << d->GetVal<std::string>("image") << std::endl;
	std::cout << d->GetVal<int>("x") << std::endl;
	if(d->IsDefined("image"))
		tex = gImageManager.getResource(d->GetVal<std::string>("image"));
	else
	{
		asset.Load(d->GetVal<std::string>("asset"));
		tex = gImageManager.getResource(asset.GetVal<std::string>("image"));
		//todo: load some other stuff from the asset
		isasset = true;
	}
	draw.setTexture(*tex);
	hw = tex->getSize().x / 2;
	d->SetVal("hw", hw);
	hh = tex->getSize().y / 2;
	d->SetVal("hh", hh);
	w = tex->getSize().x;
	h = tex->getSize().y;
	draw.setOrigin(hw, hh);
	//sendLocalMessage("sendpos"); //Get the position entity to the send the position
	//Determine whether component has authority
	if(d->GetVal<int>("auth") == 101)
	{
		//Get the proper messages
		requestMessage("setx", &Graphical::SetX);
		requestMessage("sety", &Graphical::SetY);
		requestMessage("setrot", &Graphical::SetRot);
	}
	else
	{
		requestMessage("getx", &Graphical::SetX);
		requestMessage("gety", &Graphical::SetY);
		requestMessage("getrot", &Graphical::SetRot);
	}
}

void Graphical::Update(const Message& msg)
{
	//
}
