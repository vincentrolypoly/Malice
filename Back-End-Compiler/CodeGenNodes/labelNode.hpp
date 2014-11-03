#ifndef LABEL_H
#define LABEL_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class labelNode: public IA32Nodes{
	string label;
	public:
	labelNode(string l);
	string printSelf();
	bool removable();
};
#endif
