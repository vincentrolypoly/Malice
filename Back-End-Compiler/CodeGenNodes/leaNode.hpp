#ifndef lea_H
#define lea_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class leaNode: public IA32Nodes{
	string label1;
	string label2;
	public:
	leaNode(string l1, string l2);
	string printSelf();
	bool removable();
};
#endif
