#ifndef cmp_H
#define cmp_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class cmpNode: public IA32Nodes{
	string reg1;
	string reg2;
	public:
	cmpNode(string r1, string r2);
	string printSelf();
	bool removable();
};
#endif

