#ifndef INC_H
#define INC_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class incNode: public IA32Nodes{
	string reg;
	public:
	incNode(string r);
	string printSelf();
	bool removable();
};
#endif
