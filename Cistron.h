
#ifndef INC_CISTRON
#define INC_CISTRON

// IMPORTANT!
// decide below which version you want - a version using boost::any or a version using a simple void pointer

// boost version
//#include <boost/any.hpp>
//#define Payload boost::any

// boostless version - uses plain void pointer
#define Payload void*

#include "Component.h"
#include "Object.h"
#include "ObjectManager.h"

#endif
