#ifndef CALLER_H
#define CALLER_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class callerNode: public IA32Nodes{
	string label;
	public:
	callerNode(string l);
	string printSelf();
	bool removable();
};
#endif
