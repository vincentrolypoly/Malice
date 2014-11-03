#ifndef NOT_H
#define NOT_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class notNode: public IA32Nodes{
	string reg1;
	public:
	notNode(string r1);
	string printSelf();
	bool removable();
};
#endif
