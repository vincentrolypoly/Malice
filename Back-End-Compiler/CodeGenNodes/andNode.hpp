#ifndef AND_H
#define AND_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class andNode: public IA32Nodes{
	string reg1;
	string reg2;
	public:
	andNode(string r1, string r2);
	string printSelf();
	bool removable();
};
#endif
