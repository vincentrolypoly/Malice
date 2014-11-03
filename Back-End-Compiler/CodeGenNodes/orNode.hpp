#ifndef OR_H
#define OR_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class orNode: public IA32Nodes{
	string reg1;
	string reg2;
	public:
	orNode(string r1, string r2);
	string printSelf();
	bool removable();
};
#endif
