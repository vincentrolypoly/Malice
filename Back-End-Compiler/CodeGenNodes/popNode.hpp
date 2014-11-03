#ifndef POP_H
#define POP_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class popNode: public IA32Nodes{
	string reg;
	string size;
	public:
	popNode(string r1);
	popNode(string size, string r1);
	string printSelf();
	bool removable();
};
#endif
