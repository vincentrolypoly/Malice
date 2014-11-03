#ifndef IDIV_H
#define IDIV_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class idivNode: public IA32Nodes{
	string reg1;
	public:
	idivNode(string r1);
	string printSelf();
	bool removable();
};
#endif
