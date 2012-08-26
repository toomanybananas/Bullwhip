
#include "Cistron.h"


using namespace Cistron;


#include <iostream>
#include <cassert>

using std::cout;
using std::endl;


// constructor/destructor
ObjectManager::ObjectManager() : fIdCounter(0), fRequestIdCounter(0), fNLocks(0) {

	// because we start counting from 1 for request id's, we add an empty request lock in front
	fRequestLocks.push_back(RequestLock());
}
ObjectManager::~ObjectManager() {

	// delete all objects
	for (unsigned i = 0; i < fObjects.size(); ++i) {

		// already destroyed earlier
		if (fObjects[i] == 0) continue;

		// destroy every component in the object
		list<Component*> comps = fObjects[i]->getComponents();
		for (list<Component*>::iterator it = comps.begin(); it != comps.end(); ++it) {
			destroyComponent(*it);
		}

		// destroy the object itself
		delete fObjects[i];
	}
}


// generate a unique request id or return one if it already exists
RequestId ObjectManager::getMessageRequestId(ComponentRequestType type, string name) {

	// ALL_COMPONENTS is changed to COMPONENT, it's the same in regards to the request id
	if (type == REQ_ALLCOMPONENTS) type = REQ_COMPONENT;

	// if it doesn't exist, create it
	if (fRequestToId[type].find(name) == fRequestToId[type].end()) {
		fRequestToId[type][name] = ++fRequestIdCounter;
		fIdToRequest[type][fRequestIdCounter] = name;
		fRequestLocks.push_back(RequestLock());
		return fRequestIdCounter;
	}

	// it exists, just return it
	return fRequestToId[type][name];
}


// return existing request id
RequestId ObjectManager::getExistingRequestId(ComponentRequestType type, string name) {

	// if it doesn't exist we don't return it
	if (fRequestToId[type].find(name) == fRequestToId[type].end()) {
		return 0;
	}

	// if it does exist, but there are no global requests, we don't return it either
	RequestId id = fRequestToId[type][name];
	if (fGlobalRequests.size() <= id) return 0;

	// we might have a global request - process it
	return id;
}



// create a new object
ObjectId ObjectManager::createObject() {

	// create a new object
	Object *obj = new Object(fIdCounter);
	//cout << "Created object " << fIdCounter << endl;
	++fIdCounter;

	// add it to the list
	fObjects.push_back(obj);
	return fIdCounter-1;
}


// activate lock
void ObjectManager::activateLock(RequestId reqId) {

	// if the lock is already activated, we have bounced against an infinite loop
	if (fRequestLocks[reqId].locked) {
		stringstream ss;
		ss << "Do not request a message or component in a callback function for the same message/component request or a function called by this callback function";
		error(ss);
	}

	// one more lofk
	++fNLocks;

	// activate the lock
	fRequestLocks[reqId].locked = true;
}


// release the lock, process the pending global and local requests
void ObjectManager::releaseLock(RequestId reqId) {

	// lock
	RequestLock& lock = fRequestLocks[reqId];

	// must be locked!
	assert(lock.locked);

	// release the lock
	lock.locked = false;

	// one lock less
	--fNLocks;

	// copy the pending requests
	list<pair<ComponentRequest, RegisteredComponent> > pendingGlobal = lock.pendingGlobalRequests;
	list<pair<ComponentRequest, RegisteredComponent> > pendingLocal = lock.pendingLocalRequests;
	lock.pendingGlobalRequests = list<pair<ComponentRequest, RegisteredComponent> >();
	lock.pendingLocalRequests = list<pair<ComponentRequest, RegisteredComponent> >();

	// process the global requests
	for (list<pair<ComponentRequest, RegisteredComponent> >::iterator it = pendingGlobal.begin(); it != pendingGlobal.end(); ++it) {
		registerGlobalRequest(it->first, it->second);
	}

	// process the local requests
	for (list<pair<ComponentRequest, RegisteredComponent> >::iterator it = pendingLocal.begin(); it != pendingLocal.end(); ++it) {
		registerLocalRequest(it->first, it->second);
	}

	// if there are no more locks, destroy any pending components & objects
	if (fNLocks == 0) {

		// first components
		list<Component*> deadComponents = fDeadComponents;
		fDeadComponents.clear();
		for (list<Component*>::iterator it = deadComponents.begin(); it != deadComponents.end(); ++it) {
			destroyComponent(*it);
		}

		// then entire objects
		list<ObjectId> deadObjects = fDeadObjects;
		fDeadObjects.clear();
		for (list<ObjectId>::iterator it = deadObjects.begin(); it != deadObjects.end(); ++it) {
			destroyObject(*it);
		}
	}
}


// add a new component to an object
void ObjectManager::addComponent(ObjectId id, Component *component) {

	// make sure the object exists
	if (id < 0 || id >= fObjects.size() || fObjects[id] == 0) {
		stringstream ss;
		ss << "Failed to add component " << component->toString() << " to object " << id << ": it does not exist!";
		error(ss);
	}

	// can only add once
	if (component->fObjectManager != 0) {
		stringstream ss;
		ss << "Component is already part of an ObjectManager. You cannot add a component twice.";
		error(ss);
	}

	// we get the appropriate object
	Object *obj = fObjects[id];

	// set the object manager
	component->fObjectManager = this;

	// set the owner of the component
	component->setOwner(id);

	// we add the component
	if (!obj->addComponent(component)) {
		stringstream ss;
		ss << "Failed to add component " << component->toString() << " to object " << id;
		error(ss);
	}

	// put in log
	//if (fStream.is_open()) fStream << "CREATE  " << *component << endl;
	//cout << "CREATE " << *component << endl;

	// let the component know
	component->addedToObject();

	// get request id for this component
	RequestId reqId = getExistingRequestId(REQ_COMPONENT, component->getName());

	// if there's no such request yet, we skip
	if (reqId == 0) return;

	// CREATE event
	Message msg(CREATE);
	msg.sender = component;

	// lock this request id
	activateLock(reqId);

	// look for requests and forward them
	for (list<RegisteredComponent>::iterator it = fGlobalRequests[reqId].begin(); it != fGlobalRequests[reqId].end(); ++it) {
		if (it->component->getId() != component->getId()) {
			if ((*it).trackMe) cout << it->component << " received component " << *component << " of type " << fIdToRequest[REQ_COMPONENT][reqId] << endl; 
			(*it).callback(msg);
		}
	}

	// forward to the object itself, so local requests are processed also
	obj->sendMessage(reqId, msg);

	// release the lock
	releaseLock(reqId);
}


// register a local request
// only COMPONENT requests can be local!!
void ObjectManager::registerLocalRequest(ComponentRequest req, RegisteredComponent reg) {

	// we generate the request id (might be new)
	RequestId reqId = getMessageRequestId(req.type, req.name);

	// if this request is locked, postpone the processing
	if (fRequestLocks[reqId].locked) {
		fRequestLocks[reqId].pendingLocalRequests.push_back(pair<ComponentRequest, RegisteredComponent>(req, reg));
		return;
	}

	// forward to appropriate object
	fObjects[reg.component->getOwnerId()]->registerRequest(reqId, reg);

	// put in log
	//if (fStream.is_open()) fStream << "DESTROY " << *comp << endl;

//cout << "Registered local request of " << (*reg.component) << " for " << req.name << endl;
	// if we want the previously created components as well, we process them
	if (req.type != REQ_COMPONENT) return;
	
	// lock this request id
	activateLock(reqId);

	// now look for existing components of this type
	Message msg(CREATE);

	// get component and forward it
	list<Component*> comps = fObjects[reg.component->getOwnerId()]->getComponents(req.name);
	for (list<Component*>::iterator it = comps.begin(); it != comps.end(); ++it) {
		if ((*it)->isValid() && reg.component->getId() != (*it)->getId()) {
			msg.sender = (*it);
			if (reg.trackMe) cout << *reg.component << " received component " << (*msg.sender) << " of type " << req.name << endl;
			//cout << "Warning component " << (*reg.component) << " for the local existence of component " << (*msg.sender) << endl;
			reg.callback(msg);
		}
	}

	// release the lock
	releaseLock(reqId);
}


// register a global request
void ObjectManager::registerGlobalRequest(ComponentRequest req, RegisteredComponent reg) {
	assert(reg.component->isValid());

	// first we request the id and create it if it doesn't exist
	RequestId reqId = getMessageRequestId(req.type, req.name);

	// we only really register component and message requests
	if (req.type != REQ_ALLCOMPONENTS) {

		// if this request is locked, postpone the processing
		if (fRequestLocks[reqId].locked) {
			fRequestLocks[reqId].pendingGlobalRequests.push_back(pair<ComponentRequest, RegisteredComponent>(req, reg));
			return;
		}

		// if the request list isn't large enough, we resize it
		if (fGlobalRequests.size() <= reqId) {
			fGlobalRequests.resize(reqId+1);
		}

		// we add the request
		fGlobalRequests[reqId].push_back(reg);
	//cout << "Registered global request of " << (*reg.component) << " for " << req.name << endl;
		// we also add it locally if it is a message
		if (req.type == REQ_MESSAGE) {
			fObjects[reg.component->getOwnerId()]->registerRequest(reqId, reg);
		}

		// we add it to the associative map (used at destruction of the component to look up all its requests)
		fRequestsByComponentId[reg.component->getId()].push_back(req);

		// if the request is required and the object isn't finalized yet, we add it to a special list
		ObjectId objId = reg.component->getOwnerId();
		if (reg.required && !fObjects[objId]->isFinalized()) {
			fRequiredComponents[objId].push_back(req.name);
		}
	}

	// if we want the previously created components as well, we process them
	if (req.type == REQ_MESSAGE) return;
	
	// activate the lock on this id
	activateLock(reqId);

	// now look for existing components of this type
	Message msg(CREATE);
	for (unsigned i = 0; i < fObjects.size(); ++i) {

		// only process objects that still exist
		if (fObjects[i] == 0) continue;

		// get component and forward it
		list<Component*> comps = fObjects[i]->getComponents(req.name);
		for (list<Component*>::iterator it = comps.begin(); it != comps.end(); ++it) {
			if ((*it)->isValid() && reg.component->getId() != (*it)->getId()) {
				msg.sender = (*it);
				if (reg.trackMe) cout << (*reg.component) << " received component " << (**it) << " of type " << req.name << endl; 
				//cout << "Warning component " << (*reg.component) << " for the global existence of component " << (*msg.sender) << endl;
				reg.callback(msg);
			}
		}
	}

	// release the lock
	releaseLock(reqId);
}


// send a message to everyone
void ObjectManager::sendGlobalMessage(RequestId reqId, Message const & msg) {

	// must be valid component
	assert(msg.sender->isValid());

	// activate the lock
	activateLock(reqId);

	// look for requests and forward them
	for (list<RegisteredComponent>::iterator it = fGlobalRequests[reqId].begin(); it != fGlobalRequests[reqId].end(); ++it) {
		if ((*it).trackMe) cout << it->component << " received message " << fIdToRequest[REQ_MESSAGE][reqId] << " from " << *msg.sender << endl; 
		(*it).callback(msg);
	}

	// release the lock
	releaseLock(reqId);
}


// error processing
void ObjectManager::error(stringstream& err) {
	cout << err.str() << endl;
	assert(false);
}


// destroy object
void ObjectManager::destroyObject(ObjectId id) {

	// if there's no lock, we delete the object immediately, otherwise, postpone
	if (fNLocks != 0) {
		fDeadObjects.push_back(id);
		return;
	}

	// object doesn't exist
	if (id < 0 || id >= fObjects.size() || fObjects[id] == 0) {
		stringstream ss;
		ss << "Failed to destroy object " << id << ": it does not exist!";
		error(ss);
	}

	// destroy every component in the object
	list<Component*> comps = fObjects[id]->getComponents();
	for (list<Component*>::iterator it = comps.begin(); it != comps.end(); ++it) {
		destroyComponent(*it);
	}

	// delete the actual object
	//cout << "Destroyed object " << id << endl;
	delete fObjects[id];
	fObjects[id] = 0;
}



// destroy a component
void ObjectManager::destroyComponent(Component *comp) {

	// invalid component shouldn't be possible
	if (!comp->isValid()) {
		stringstream ss;
		ss << "Error destroying component " << comp->toString() << ": component is not valid.";
		error(ss);
	}


	// see if there are any locks - if there are, postpone this destroyal
	if (fNLocks != 0) {
		fDeadComponents.push_back(comp);
		return;
	}
	

	// put in log
	//if (fStream.is_open()) fStream << "DESTROY " << *comp << endl;

	// remove its own requests
	list<ComponentRequest>& reqs = fRequestsByComponentId[comp->getId()];
	for (list<ComponentRequest>::iterator it = reqs.begin(); it != reqs.end(); ++it) {

		// get the appropriate id
		RequestId reqId = getExistingRequestId(it->type, it->name);

		// must exist!
		assert(reqId != 0);

		// look up the request and delete it
		for (list<RegisteredComponent>::iterator reg = fGlobalRequests[reqId].begin(); reg != fGlobalRequests[reqId].end();) {
			if (reg->component->getId() == comp->getId()) {
				reg = fGlobalRequests[reqId].erase(reg);
			}
			else ++reg;
		}
	}

	// remove its own local requests - only if the object itself wasn't removed yet
	fObjects[comp->getOwnerId()]->removeComponent(comp);

	// CREATE event
	Message msg(DESTROY);
	msg.sender = comp;

	// get req id
	RequestId reqId = getExistingRequestId(REQ_COMPONENT, comp->getName());

	// if there exist some requests, we process them
	if (reqId != 0) {

		// activate lock
		activateLock(reqId);

		// look up the request and delete it
		for (list<RegisteredComponent>::iterator reg = fGlobalRequests[reqId].begin(); reg != fGlobalRequests[reqId].end(); ++reg) {
			reg->callback(msg);
		}

		// forward to the object itself, so local requests are processed also
		fObjects[comp->getOwnerId()]->sendMessage(reqId, msg);

		// release the lock
		releaseLock(reqId);
	}

	// make it invalid
	delete comp;
}


// finalize an object
void ObjectManager::finalizeObject(ObjectId id) {

	// object doesn't exist
	if (id < 0 || id >= fObjects.size() || fObjects[id] == 0) {
		stringstream ss;
		ss << "Failed to destroy object " << id << ": it does not exist!";
		error(ss);
	}

	// finalize the object itself
	fObjects[id]->finalize();

	// see if there are any requirements
	if (fRequiredComponents.find(id) == fRequiredComponents.end()) return;

	// there are, do the checklist
	list<string> requiredComponents = fRequiredComponents[id];
	bool destroyObject = false;
	for (list<string>::iterator it = requiredComponents.begin(); it != requiredComponents.end(); ++it) {

		// get the components of this type
		list<Component*> comps = fObjects[id]->getComponents(*it);

		// if there are none, we want this object dead!
		if (comps.size() == 0) destroyObject = true;
	}
/*if (!destroyObject) cout << "Finalized object " << id << " succesfully!" << endl;
else cout << "Finalize on object " << id << " failed, destroying..." << endl;*/
	// we destroy the object if we didn't find what we needed
	if (destroyObject) this->destroyObject(id);
}


// register a unique name for an object
void ObjectManager::registerName(Component *comp, string name) {
	fComponentsByName[name].push_back(comp);
}
void ObjectManager::unregisterName(Component *comp, string name) {

	// not found
	if (fComponentsByName.find(name) == fComponentsByName.end()) return;

	// unregister
	for (list<Component*>::iterator it = fComponentsByName[name].begin(); it != fComponentsByName[name].end(); ++it) {
		if ((*it)->getId() == comp->getId()) {
			it = fComponentsByName[name].erase(it);
			return;
		}
	}
}


// get the id based on the unique name identified
list<Component*> ObjectManager::getComponentsByName(string name) {

	// see if the name doesn't exist yet
	if (fComponentsByName.find(name) == fComponentsByName.end()) {
		//error(format("Failed to acquire object id for unique name identifier %s because it doesn't exist!") % name);
		return list<Component*>();
	}

	// return id
	return fComponentsByName[name];
}


// logging
void ObjectManager::trackRequest(RequestId reqId, bool local, Component *component) {

	// if global, find it
	if (!local) {

		// find in global request list
		for (list<RegisteredComponent>::iterator it = fGlobalRequests[reqId].begin(); it != fGlobalRequests[reqId].end(); ++it) {
			if ((*it).component->getId() == component->getId()) (*it).trackMe = true;
		}

		// also pass to local for extra check (MESSAGE messages are always local AND global)
		fObjects[component->getOwnerId()]->trackRequest(reqId, component);


	}

	// if local, forward to object
	else {
		fObjects[component->getOwnerId()]->trackRequest(reqId, component);
	}
}