/**
 * @file EntityRegistry.h
 * @brief Factory controller for entites
 * @author neos300
 * @version 1.0
 * @date 2012-06-20
 */
#pragma once
#include "Entity.h"
#include <map>
class EntityRegistry
{
    public:
        EntityRegistry() {};
	/**
	 * @brief Adds a entity to the registry
	 *
	 * @param name The class of the entity
	 * @param func The factory function for that class
	 */
        void AddFactory(std::string name, std::vector<std::string> comps, int auth = 100, std::string phystype = "") 
	{
		factorys[name] = comps;
		auths[name] = auth;
		phys[name] = phystype;
	}
	/**
	 * @brief Instantates a new entity
	 *
	 * @param name The class of the entity
	 *
	 * @return A pointer to the new entity
	 */
        Entity* NewEnt(std::string name)
	{
		Entity* ent = new Entity;
		if(phys[name] != "")
		{
			ent->SetVal("phystype", phys[name]);
		}
		ent->SetVal("auth", auths[name]);

		for(int i = 0; i < factorys[name].size(); i++)
		{
			ent->AddComponent(factorys[name][i]);
		}
		return ent;
	}
    protected:
    private:
        std::map<std::string, std::vector<std::string> > factorys;
	std::map<std::string, std::string> phys;
	std::map<std::string, int> auths;
};

/**
 * @brief A factory function for entites. Instantate with &NewEnt<Entity>
 *
 * @tparam T The derived class of the entity
 * @param i A useless int required for some reason
 *
 * @return A pointer to the new entity
 */
template<class T>
Entity* NewEnt()
{
    return new T;
}
