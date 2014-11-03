#ifndef SUB_H
#define SUB_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class subNode: public IA32Nodes{
	string reg1;
	string reg2;
	public:
	subNode(string r1, string r2);
	string printSelf();
	bool removable();
};
#endif
