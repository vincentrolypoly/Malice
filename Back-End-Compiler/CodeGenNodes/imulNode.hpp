#ifndef IMUL_H
#define IMUL_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class imulNode: public IA32Nodes{
	string reg1;
	string reg2;
	public:
	imulNode(string r1);
	imulNode(string r1, string r2);
	string printSelf();
	bool removable();
};
#endif
