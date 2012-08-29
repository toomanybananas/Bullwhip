
#ifndef INC_COMPONENT
#define INC_COMPONENT


#include <string>
#include <map>
#include <list>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/any.hpp>
#include <ostream>


namespace Cistron {

using std::list;
using std::map;
using std::string;
using std::ostream;


// object & component id
typedef int ObjectId;
typedef int ComponentId;


// a request ID
typedef int RequestId;

// type of component requests
enum ComponentRequestType {
	REQ_COMPONENT = 0,
	REQ_MESSAGE = 1,
	REQ_ALLCOMPONENTS = 2
};

// a request
struct ComponentRequest {
	ComponentRequestType type;
	string name;
	ComponentRequest(ComponentRequestType t, string n) : type(t), name(n) {};
	ComponentRequest() {};
};




// event type
enum MessageType {
	CREATE,
	DESTROY,
	MESSAGE
};


// an event
class Component;
struct Message {
	MessageType type;
	Component *sender;
	boost::any p;
	Message(MessageType t) : type(t) {};
	Message(MessageType t, Component *c) : type(t), sender(c) {};
	Message(MessageType t, Component *c, boost::any payload) : type(t), sender(c), p(payload) {};
};




// component function
typedef boost::function<void(Message const &)> MessageFunction;


// a component registered for an event (message or component creation/destruction)
struct RegisteredComponent {
	Component *component;
	MessageFunction callback;
	bool required;
	bool trackMe;
	RegisteredComponent *next;
};

// object manager
class ObjectManager;


// a generic component
class Component {

	public:

		// constructor/destructor
		Component(string name);
		virtual ~Component();



		// function called when the component is added to an object
		virtual void addedToObject();

		// register a unique name for the object
		void registerName(string s);
		void unregisterName(string s);

		// get components
		list<Component*> getComponentsByName(string name);


		/**
		 * OBJECT/COMPONENT MODIFICATION FUNCTIONS
		 */

		// add another component to this object
		void addLocalComponent(Component*);

		// add a component to another object
		void addComponent(ObjectId, Component*);

		// create an object
		ObjectId createObject();

		// finalize an object
		void finalizeObject(ObjectId);

		// destroy object
		void destroyObject(ObjectId);


		/**
		 * REQUEST FUNCTIONS
		 */

		// message request function
		void requestMessage(string message, MessageFunction);

		// require a component in this object
		void requireComponent(string name, MessageFunction);

		// register a component request
		void requestComponent(string name, MessageFunction, bool local = false);

		// request all components of one type
		void requestAllExistingComponents(string name, MessageFunction);

		// request a request id of a message
		RequestId getMessageRequestId(string name);

		// request all components of a given type in a given object
		list<Component*> getComponents(string name, ObjectId id = -1);

		/**
		 * FANCY TEMPLATED REQUEST FUNCTIONS
		 */

		// message request function
		template<class T>
		void requestMessage(string message, void (T::*f)(Message const &));

		// require a component in this object
		template<class T>
		void requireComponent(string name, void (T::*f)(Message const &));

		// register a component request
		template<class T>
		void requestComponent(string name, void (T::*f)(Message const &), bool local = false);

		// request all components of one type
		template<class T>
		void requestAllExistingComponents(string name, void (T::*f)(Message const &));


		/**
		 * MESSAGING FUNCTIONS
		 */

		// send a message
		void sendMessage(string msg, boost::any  payload = 0);
		void sendMessage(RequestId id, boost::any  payload = 0);
		void sendMessageToObject(ObjectId id, string msg, boost::any payload = 0);
		void sendMessageToObject(ObjectId id, RequestId reqId, boost::any payload = 0);
		void sendMessageToObject(ObjectId id, RequestId reqId, Message const & msg);
		void sendLocalMessage(string msg, boost::any payload = 0);
		void sendLocalMessage(RequestId reqId, boost::any payload = 0);
		void sendLocalMessage(RequestId reqId, Message const & msg);

		/**
		 * IMPLEMENTED REQUESTS & LOGGING
		 */
		void processPing(Message const &);

		void trackComponentRequest(string name, bool local = false);
		void trackMessageRequest(string message);
		



		// get object manager this component belongs to
		inline ObjectManager* getObjectManager() {
			return fObjectManager;
		}

		// get owner
		ObjectId getOwnerId();

		// get id
		ComponentId getId();

		// destroy this component
		void destroy();
		bool isDestroyed();

		// valid component?
		bool isValid();

		// get the name of the component
		string getName();

		// to string
		string toString();

	private:

		// set owner
		void setOwner(ObjectId id);

		// set destroyed
		void setDestroyed();

		// object id
		ObjectId fOwnerId;

		// object manager
		ObjectManager *fObjectManager;

		// component it
		ComponentId fId;

		// name of the component
		string fName;

		// destroyed
		bool fDestroyed;

		// track this component in the log
		bool fTrack;

		// object manager is our friend
		friend class ObjectManager;

};


/**
 * TEMPLATED REQUEST FUNCTIONS
 */

// message request function
template<class T>
void Component::requestMessage(string message, void (T::*f)(Message const &)) {
	requestMessage(message, boost::bind(f, (T*)(this), _1));
}

// require a component in this object
template<class T>
void Component::requireComponent(string name, void (T::*f)(Message const &)) {
	requireComponent(name, boost::bind(f, (T*)(this), _1));
}

// register a component request
template<class T>
void Component::requestComponent(string name, void (T::*f)(Message const &), bool local) {
	requestComponent(name, boost::bind(f, (T*)(this), _1), local);
}

// request all components of one type
template<class T>
void Component::requestAllExistingComponents(string name, void (T::*f)(Message const &)) {
	requestAllExistingComponents(name, boost::bind(f, (T*)(this), _1));
}


};


// output
std::ostream& operator<<(std::ostream& s, Cistron::Component &v);


#endif
