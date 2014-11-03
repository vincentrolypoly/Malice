#ifndef resb_H
#define resb_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class resbNode: public IA32Nodes{
	string name;
	int size;
	public:
	resbNode(string n, int s);
	string printSelf();
	bool removable();
};
#endif
