#include "Graphical.h"
using namespace Cistron;

void Graphical::init(const Message& msg)
{
	isasset = false;
	sf::Texture* tex;
	Def* d = boost::any_cast<Def*>(msg.p);
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
	hh = tex->getSize().y / 2;
	w = tex->getSize().x;
	h = tex->getSize().y;
	draw.setOrigin(hw, hh);
	sendLocalMessage("sendpos"); //Get the position entity to the send the position
}

void Graphical::Update(const Message& msg)
{
	//
}
