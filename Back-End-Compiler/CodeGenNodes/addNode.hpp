#ifndef ADD_H
#define ADD_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class addNode: public IA32Nodes{
	string reg1;
	string reg2;
	public:
	addNode(string r1, string r2);
	string printSelf();
	bool removable();
};
#endif
