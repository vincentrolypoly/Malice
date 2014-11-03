#ifndef STRING_H
#define STRING_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class stringNode: public IA32Nodes{
	string str;
	string label;
	public:
	stringNode(string s, string l);
	string printSelf();
	bool removable();
};
#endif
