#ifndef PUSHFQ_H
#define PUSHFQ_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class pushfqNode: public IA32Nodes{
	public:
	pushfqNode();
	string printSelf();
	bool removable();
};
#endif
