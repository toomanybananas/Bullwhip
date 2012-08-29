#include "Entity.h"
using namespace std;
Entity::Entity()
{
	name = "base_ent";
	obj = objManager->createObject(); 
}

void Entity::init()
{
	alive = true; 
	for(std::string &x : comps)
	{
		objManager->addComponent(obj, componentreg.NewComponent(x));
	}
	listen = new Listener;
	objManager->addComponent(obj, listen);
	objManager->sendMessageToObject("init", NULL, obj, (Def*)this);

}

void Entity::AddComponent(std::string comp)
{
	//objManager->addComponent(obj, componentreg.NewComponent(comp));
	//objManager->sendMessageToObject("init", NULL, obj, (Def*)this);
	comps.push_back(comp);
}


void Entity::damage(int dmg)
{
    /*if((bool)mdef.GetVal("invincible"))
        return;
    mdef.SetVal("health", (int)mdef.GetVal("health") - dmg);
    if((int)mdef.GetVal("health") <= 0)
    {
        alive = false;
    }*/
}

void Entity::update(SceneManager* scene)
{
	//do some stuff
	objManager->sendMessageToObject("update", NULL, obj, this);
}
