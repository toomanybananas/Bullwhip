/**
 * @file ComponentRegistry.h
 * @brief Factory controller for components
 * @author neos300
 * @version 1.0
 * @date 2012-06-20
 */
#pragma once
#include "Cistron.h"
#include <map>
class ComponentRegistry
{
    public:
        ComponentRegistry() {};
	/**
	 * @brief Adds a component to the registry
	 *
	 * @param name The class of the component
	 * @param func The factory function for that class
	 */
        void AddFactory(std::string name, Cistron::Component* (*func)(void)) {factorys[name] = func;};
	/**
	 * @brief Instantates a new component
	 *
	 * @param name The class of the component
	 *
	 * @return A pointer to the new component
	 */
	Cistron::Component* NewComponent(std::string name) {return factorys[name]();}
    protected:
    private:
        std::map<std::string, Cistron::Component* (*)(void)> factorys;
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
Cistron::Component* NewComp()
{
    return new T;
}
