#ifndef jg_H
#define jg_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class jgNode: public IA32Nodes{
	string label;
	public:
	jgNode(string l);
	string printSelf();
	bool removable();
};
#endif
