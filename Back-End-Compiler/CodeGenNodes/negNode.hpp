#ifndef NEG_H
#define NEG_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class negNode: public IA32Nodes{
	string reg1;
	public:
	negNode(string r1);
	string printSelf();
	bool removable();
};
#endif
