#ifndef jle_H
#define jle_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class jleNode: public IA32Nodes{
	string label;
	public:
	jleNode(string l);
	string printSelf();
	bool removable();
};
#endif
