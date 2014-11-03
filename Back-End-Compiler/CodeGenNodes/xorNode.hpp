#ifndef XOR_H
#define XOR_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class xorNode: public IA32Nodes{
	string reg1;
	string reg2;
	public:
	xorNode(string r1, string r2);
	string printSelf();
	bool removable();
};
#endif
