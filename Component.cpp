
#include "Component.h"
#include "ObjectManager.h"


using namespace Cistron;


#include <sstream>
#include <iostream>

using std::stringstream;
using namespace std;


// constructor/destructor
Component::Component(string name) : fOwnerId(-1), fName(name), fDestroyed(false), fTrack(false), fObjectManager(0) {
	static ComponentId IdCounter = 0;
	fId = ++IdCounter;
}
Component::~Component() {
}


// track activity in the log
/*void Component::trackMe(track) {
	fTrack = track;
}*/


// check for validity of the object
bool Component::isValid() {
	return fOwnerId >= 0 && fName.size() > 0 && !fDestroyed;
}



// get owner
ObjectId Component::getOwnerId() {
	return fOwnerId;
}
void Component::setOwner(ObjectId id) {

	// set the owner
	fOwnerId = id;

	// respond to ping requests
	requestMessage("ping", &Component::processPing);
}
void Component::setDestroyed() {
	fDestroyed = true;
}
bool Component::isDestroyed() {
	return fDestroyed;
}


// get id
ComponentId Component::getId() {
	return fId;
}
string Component::getName() {
	return fName;
}


/**
 * OBJECT/COMPONENT MODIFICATION FUNCTIONS
 */


// add another component to this object
void Component::addLocalComponent(Component *c) {
	fObjectManager->addComponent(getOwnerId(), c);
}


// add another component to another object
void Component::addComponent(ObjectId objId, Component *c) {
	fObjectManager->addComponent(objId, c);
}


// create an object
ObjectId Component::createObject() {
	return fObjectManager->createObject();
}

// finalize an object
void Component::finalizeObject(ObjectId objId) {
	fObjectManager->finalizeObject(objId);
}

// destroy object
void Component::destroyObject(ObjectId objId) {
	fObjectManager->destroyObject(objId);
}



/**
 * REQUEST FUNCTIONS
 */

// message request function
void Component::requestMessage(string message, MessageFunction f) {

	// construct registered component
	RegisteredComponent reg;
	reg.callback = f;
	reg.required = false;
	reg.component = this;
	reg.trackMe = false;

	// construct component request
	ComponentRequest req;
	req.type = REQ_MESSAGE;
	req.name = message;

	// forward to object manager
	fObjectManager->registerGlobalRequest(req, reg);
}

// require a component in this object
void Component::requireComponent(string name, MessageFunction f) {

	// construct registered component
	RegisteredComponent reg;
	reg.callback = f;
	reg.required = true;
	reg.component = this;
	reg.trackMe = false;

	// construct component request
	ComponentRequest req;
	req.type = REQ_COMPONENT;
	req.name = name;

	// forward to object manager
	fObjectManager->registerLocalRequest(req, reg);
}

// register a component request
void Component::requestComponent(string name, MessageFunction f, bool local) {

	// construct registered component
	RegisteredComponent reg;
	reg.callback = f;
	reg.required = false;
	reg.component = this;
	reg.trackMe = false;

	// construct component request
	ComponentRequest req;
	req.type = REQ_COMPONENT;
	req.name = name;

	// forward to object manager
	if (local) fObjectManager->registerLocalRequest(req, reg);
	else fObjectManager->registerGlobalRequest(req, reg);
}

// request all components of one type
void Component::requestAllExistingComponents(string name, MessageFunction f) {

	// construct registered component
	RegisteredComponent reg;
	reg.callback = f;
	reg.required = false;
	reg.component = this;
	reg.trackMe = false;

	// construct component request
	ComponentRequest req;
	req.type = REQ_ALLCOMPONENTS;
	req.name = name;

	// forward to object manager
	fObjectManager->registerGlobalRequest(req, reg);
}



// get a request id
RequestId Component::getMessageRequestId(string name) {
	return fObjectManager->getMessageRequestId(REQ_MESSAGE, name);
}


// request all components of a given type in a given object
list<Component*> Component::getComponents(string name, ObjectId id) {
	if (id == -1) return fObjectManager->getComponents(getOwnerId(), name);
	else return fObjectManager->getComponents(id, name);
}


/**
 * MESSAGING FUNCTIONS
 */

// send a message
void Component::sendMessage(string msg, boost::any payload) {
	fObjectManager->sendGlobalMessage(msg, this, payload);
}
void Component::sendMessage(RequestId reqId, boost::any payload) {
	fObjectManager->sendGlobalMessage(reqId, this, payload);
}
void Component::sendLocalMessage(string msg, boost::any payload) {
	fObjectManager->sendMessageToObject(msg, this, fOwnerId, payload);
}
void Component::sendLocalMessage(RequestId reqId, boost::any payload) {
	fObjectManager->sendMessageToObject(reqId, this, fOwnerId, payload);
}
void Component::sendLocalMessage(RequestId reqId, Message const & msg) {
	fObjectManager->sendMessageToObject(reqId, msg, fOwnerId);
}
void Component::sendMessageToObject(ObjectId id, string msg, boost::any payload) {
	fObjectManager->sendMessageToObject(msg, this, id, payload);
}
void Component::sendMessageToObject(ObjectId id, RequestId reqId, boost::any payload) {
	fObjectManager->sendMessageToObject(reqId, this, id, payload);
}
void Component::sendMessageToObject(ObjectId id, RequestId reqId, Message const & msg) {
	fObjectManager->sendMessageToObject(reqId, msg, id);
}



// called when added to an object
void Component::addedToObject() {
	// does nothing by default
}


// register a unique name
void Component::registerName(string s) {
	fObjectManager->registerName(this, s);
}
void Component::unregisterName(string s) {
	fObjectManager->unregisterName(this, s);
}
list<Component*> Component::getComponentsByName(string name) {
	return fObjectManager->getComponentsByName(name);
}


// destroy this component
void Component::destroy() {
	fObjectManager->destroyComponent(this);
}


// output
ostream& operator<<(ostream& s, Component &v) {
	return s << "Component[" << v.getId() << "][" << v.getName() << "] owned by [" << v.getOwnerId() << "]";
};


// to string
string Component::toString() {
	stringstream ss;
	ss << (*this);
	return ss.str();
}


/**
 * PING & LOGGING
 */


// process ping
void Component::processPing(Message const & msg) {
	cout << *this << " PING" << endl;
}


// track a component request
void Component::trackComponentRequest(string name, bool local) {

	// get request id
	RequestId reqId = fObjectManager->getMessageRequestId(REQ_COMPONENT, name);

	// start tracking
	fObjectManager->trackRequest(reqId, local, this);
}


// track a message request
void Component::trackMessageRequest(string message) {

	// get request id
	RequestId reqId = fObjectManager->getMessageRequestId(REQ_MESSAGE, message);

	// start tracking
	fObjectManager->trackRequest(reqId, false, this);
}