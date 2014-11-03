#ifndef je_H
#define je_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class jeNode: public IA32Nodes{
	string label;
	public:
	jeNode(string l);
	string printSelf();
	bool removable();
};
#endif
