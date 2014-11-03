#ifndef jne_H
#define jne_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class jneNode: public IA32Nodes{
	string label;
	public:
	jneNode(string l);
	string printSelf();
	bool removable();
};
#endif
