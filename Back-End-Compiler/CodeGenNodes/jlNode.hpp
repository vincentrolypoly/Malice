#ifndef jl_H
#define jl_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class jlNode: public IA32Nodes{
	string label;
	public:
	jlNode(string l);
	string printSelf();
	bool removable();
};
#endif
