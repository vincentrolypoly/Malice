#ifndef jge_H
#define jge_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class jgeNode: public IA32Nodes{
	string label;
	public:
	jgeNode(string l);
	string printSelf();
	bool removable();
};
#endif
