
#include "Object.h"
#include "ObjectManager.h"


using namespace Cistron;



// constructor/destructor
Object::Object(ObjectId id) : fId(id), fFinalized(false) {
}
Object::~Object() {

	// delete all components
	// deleted by the object manager
	/*for (map<string, list<Component*> >::iterator it = fComponents.begin(); it != fComponents.end(); ++it) {
		for (list<Component*>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
			delete (*it2);
		}
	}*/
}


// is the object finalized
bool Object::isFinalized() {
	return fFinalized;
}


// finalize the object
void Object::finalize() {

	// we're done
	fFinalized = true;
}


// add a component
bool Object::addComponent(Component *comp) {

	// component must be valid
	if (!comp->isValid()) return false;

	// make sure there's no such component yet
	//if (fComponents.find(comp->getName()) != fComponents.end()) return false;

	// just add to the right list
	fComponents[comp->getName()].push_back(comp);
	return true;
}


// get a component
list<Component*> Object::getComponents(string name) {

	// make sure there's no such component yet
	if (fComponents.find(name) == fComponents.end()) return list<Component*>();

	// return normally
	return fComponents[name];
}


// get all components
list<Component*> Object::getComponents() {

	// append them all
	list<Component*> comps;
	for (unordered_map<string, list<Component*> >::iterator it = fComponents.begin(); it != fComponents.end(); ++it) {
		comps.insert(comps.end(), it->second.begin(), it->second.end());
	}

	// return normally
	return comps;
}


// remove a component
void Object::removeComponent(Component *comp) {

	// look for the right component ant delete it
	list<Component*>& comps = fComponents[comp->getName()];
	for (list<Component*>::iterator it = comps.begin(); it != comps.end(); ++it) {
		if ((*it)->getId() == comp->getId()) {
			comps.erase(it);
			break;
		}
	}

	// now we remove all local requests
	for (unsigned i = 0; i < fLocalRequests.size(); ++i) {
		/*list<RegisteredComponent>& regs = fLocalRequests[i];
		for (list<RegisteredComponent>::iterator it = regs.begin(); it != regs.end();) {
			if (it->component->getId() == comp->getId()) {
				it = regs.erase(it);
			}
			else ++it;
		}*/
		/*vector<RegisteredComponent>& regs = fLocalRequests[i];
		for (unsigned j = 0; j < regs.size(); ++j) {
			if (regs[j].component->getId() == comp->getId()) {
				
			}
		}*/
	}
}


// send a local message
void Object::sendMessage(RequestId reqId, Message const & msg) {

	// if there are no registered components, we just skip
	if (fLocalRequests.size() <= reqId) return;

	// just forward to the appropriate registered components
	vector<RegisteredComponent>& regs = fLocalRequests[reqId];
	int n = regs.size();
	for (unsigned i = 0; i < n; ++i) {
		RegisteredComponent& comp = regs[i];
		if (comp.trackMe) {
			string name;
			if (msg.type == MESSAGE) {
				name = comp.component->getObjectManager()->getRequestById(REQ_MESSAGE, reqId);
			}
			else {
				name = comp.component->getObjectManager()->getRequestById(REQ_COMPONENT, reqId);
			}
		}
		comp.callback(msg);
	}
}

// register a request
void Object::registerRequest(RequestId reqId, RegisteredComponent reg) {

	// TODO OPTIMIZATION

	// if it doesn't exist yet, create it
	if (fLocalRequests.size() <= reqId) {
		fLocalRequests.resize(reqId+1);
	}
	fLocalRequests[reqId].push_back(reg);
}


// track a local request
void Object::trackRequest(RequestId reqId, Component *component) {

	// find in global request list
	for (unsigned i = 0; i < fLocalRequests[reqId].size(); ++i) {
		if (fLocalRequests[reqId][i].component->getId() == component->getId()) fLocalRequests[reqId][i].trackMe = true;
	}
}