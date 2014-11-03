#ifndef dec_H
#define dec_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class decNode: public IA32Nodes{
	string reg;
	public:
	decNode(string r);
	string printSelf();
	bool removable();
};
#endif

