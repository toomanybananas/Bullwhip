#include <boost/python.hpp>
#include "Definition.h"
using namespace boost::python;

void (Def::*s1)(std::string, int) = &Def::SetVal;
void (Def::*s2)(std::string, bool) = &Def::SetVal;
void (Def::*s3)(std::string, float) = &Def::SetVal;
void (Def::*s4)(std::string, Def) = &Def::SetVal;
void (Def::*s5)(std::string, boost::any) = &Def::SetVal;

void (Def::*load1)(std::string) = &Def::Load;
void (Def::*load2)(inFile&) = &Def::Load;

void (Def::*save1)(std::string) = &Def::Save;
void (Def::*save2)(outFile& f) = &Def::Save;

BOOST_PYTHON_MODULE(bullwhip)
{
	class_<Def>("Def")
		.def("SetInt", s1)
		.def("SetBool", s2)
		.def("SetFloat", s3)
		.def("SetDef", s4)
		//.def("SetAny", s5)
		.def("GetInt", &Def::GetVal<int>)
		.def("GetString", &Def::GetVal<std::string>)
		.def("GetFloat", &Def::GetVal<float>)
		.def("GetDef", &Def::GetVal<Def>)
		.def("SetString", &Def::SetString)
		.def("IsDefined", &Def::IsDefined)
		.def("GetType", &Def::GetType)
		.def("Load", load1)
		.def("Load", load2)
		.def("Save", save1)
		.def("Save", save2)
	;

	class_<inFile>("inFile");
	class_<outFile>("outFile");
}
