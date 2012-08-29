
#ifndef INC_OBJECT
#define INC_OBJECT

#include "Component.h"


#pragma warning( disable : 4396)
#include <boost/unordered_map.hpp>
#pragma warning( default : 4396)
#include <list>
#include <string>
#include <vector>


namespace Cistron {

using std::vector;
using std::list;
using std::string;
using boost::unordered_map;


// an object is a container of components
class Object {

	public:

		// constructor/destructor
		Object(ObjectId id);
		virtual ~Object();

	
	private:

		// object id
		ObjectId fId;


		/**
		 * COMPONENT MANAGEMENT
		 */

		// component map
		unordered_map<string, list<Component*> > fComponents;

		// add a component
		bool addComponent(Component*);

		// get a component
		list<Component*> getComponents(string name);

		// get all components
		list<Component*> getComponents();

		// remove all requests for a given component
		void removeComponent(Component*);

		/**
		 * LOCAL REQUESTS
		 */

		// send a local message
		void sendMessage(RequestId, Message const &);

		// register a request
		void registerRequest(RequestId, RegisteredComponent);

		// list of local requests
		vector<vector<RegisteredComponent> > fLocalRequests;

		/**
		 * OBJECT MANAGEMENT
		 */

		// is the object finalized?
		bool fFinalized;

		// finalize the object
		void finalize();

		// is the object finalized?
		bool isFinalized();

		/**
		 * LOGGING
		 */

		// track a request
		void trackRequest(RequestId, Component*);


		// object manager is our friend
		friend class ObjectManager;



};


};


#endif
