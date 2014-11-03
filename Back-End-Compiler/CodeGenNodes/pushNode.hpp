#ifndef PUSH_H
#define PUSH_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class pushNode: public IA32Nodes{
	string reg;
	string size;
	public:
	pushNode(string r1);
	pushNode(string size, string r1);
	string printSelf();
	bool removable();
};
#endif
