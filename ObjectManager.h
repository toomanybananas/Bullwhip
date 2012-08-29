
#ifndef INC_OBJECTMANAGER
#define INC_OBJECTMANAGER


#include "Object.h"


#pragma warning( disable : 4396)
#include <boost/unordered_map.hpp>
#pragma warning( default : 4396)
#include <list>
#include <string>
#include <boost/format.hpp>


namespace Cistron {

using std::list;
using std::string;
using std::pair;

// the object manager manages all object entities, and performs communication between them
class ObjectManager {

	public:

		// constructor/destructor
		ObjectManager();
		virtual ~ObjectManager();

		// create a new object
		ObjectId createObject();

		// add a new component to an object
		void addComponent(ObjectId, Component*);

		// destroy object
		void destroyObject(ObjectId);

		// destroy a component
		void destroyComponent(Component*);

		// finalize an object, resolving the required components
		void finalizeObject(ObjectId);


		// register a unique name for an object
		void registerName(Component*, string name);
		void unregisterName(Component*, string name);

		// get the id based on the unique name identified
		list<Component*> getComponentsByName(string name);



		/**
		 * REQUEST MESSAGES
		 */

		// register global requests
		void registerGlobalRequest(ComponentRequest, RegisteredComponent reg);

		// register a local request
		void registerLocalRequest(ComponentRequest, RegisteredComponent reg);

		// get all components of a given type in a given object
		list<Component*> getComponents(ObjectId objId, string componentName) {
			return fObjects[objId]->getComponents(componentName);
		}


		/**
		 * SENDING MESSAGES
		 */

		// send global messages
		inline void sendGlobalMessage(string msg, Component *component, boost::any payload) {
			sendGlobalMessage(getExistingRequestId(REQ_MESSAGE, msg), Message(MESSAGE, component, payload));
		}
		inline void sendGlobalMessage(RequestId reqId, Component *component, boost::any payload) {
			sendGlobalMessage(reqId, Message(MESSAGE, component, payload));
		}
		void sendGlobalMessage(RequestId reqId, Message const & msg);

		// send local messages to another object
		inline void sendMessageToObject(string msg, Component *component, ObjectId id, boost::any payload) {
			fObjects[id]->sendMessage(getMessageRequestId(REQ_MESSAGE, msg), Message(MESSAGE, component, payload));
		}
		inline void sendMessageToObject(RequestId reqId, Component *component, ObjectId id) {
			fObjects[id]->sendMessage(reqId, Message(MESSAGE, component));
		}
		inline void sendMessageToObject(RequestId reqId, Component *component, ObjectId id, boost::any payload) {
			fObjects[id]->sendMessage(reqId, Message(MESSAGE, component, payload));
		}
		inline void sendMessageToObject(string name, Message const & msg, ObjectId id) {
			fObjects[id]->sendMessage(getMessageRequestId(REQ_MESSAGE, name), msg);
		}
		inline void sendMessageToObject(RequestId reqId, Message const & msg, ObjectId id) {
			fObjects[id]->sendMessage(reqId, msg);
		}

		// ask for a request id
		RequestId getMessageRequestId(ComponentRequestType, string name);

		/**
		 * LOGGING
		 */

		// track a request
		void trackRequest(RequestId, bool local, Component*);

		// get request name
		inline string getRequestById(ComponentRequestType type, RequestId reqId) {
			return fIdToRequest[type][reqId];
		}


	private:

		/**
		 * REQUEST IDS
		 */

		// request id counter
		RequestId fRequestIdCounter;

		// mapping from a request to a unique id that identifies the request
		boost::unordered_map<string, RequestId> fRequestToId[2];

		// mapping from request id to the original request name
		boost::unordered_map<RequestId, string> fIdToRequest[2];

		// get an existing request id
		RequestId getExistingRequestId(ComponentRequestType, string name);


		/**
		 * LOCKING MECHANISM
		 */

		// activate/release request lock
		// locks are activated when the current request id is being iterated on, to avoid conflicts with iterators
		void activateLock(RequestId);
		void releaseLock(RequestId);

		// number of active locks
		int fNLocks;

		// a request lock contains whether this request is at the moment locked
		// a request is locked if currently, a message is being processed for this request
		struct RequestLock {
			bool locked;
			list<pair<ComponentRequest, RegisteredComponent> > pendingLocalRequests;
			list<pair<ComponentRequest, RegisteredComponent> > pendingGlobalRequests;
			RequestLock() : locked(false) {};
		};

		// list of locked request id's
		vector<RequestLock> fRequestLocks;

		// list of pending destroyals
		list<ObjectId> fDeadObjects;
		list<Component*> fDeadComponents;

		/**
		 * OBJECTS
		 */

		// id counter
		ObjectId fIdCounter;

		// list of objects with their id's
		vector<Object*> fObjects;

		// mapping of objects to their unique name identified
		boost::unordered_map<string, list<Component*> > fComponentsByName;

		/**
		 * REQUESTS
		 */


		// vector of global requests
		vector<list<RegisteredComponent> > fGlobalRequests;

		// list of required components which still need to be processed
		boost::unordered_map<ObjectId, list<string> > fRequiredComponents;

		// list of component requests, by component id
		boost::unordered_map<ComponentId, list<ComponentRequest> > fRequestsByComponentId;


		/**
		 * ERROR PROCESSING
		 */

		// error function
		void error(boost::format str);



};

};


#endif
