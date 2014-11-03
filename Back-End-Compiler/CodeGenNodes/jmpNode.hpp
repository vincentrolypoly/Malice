#ifndef jmp_H
#define jmp_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class jmpNode: public IA32Nodes{
	string label;
	public:
	jmpNode(string l);
	string printSelf();
	bool removable();
};
#endif
