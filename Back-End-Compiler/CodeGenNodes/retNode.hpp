#ifndef RET_H
#define RET_H

#include "IA32Nodes.hpp"

#include <string>
#include <fstream>

using namespace std;

class retNode: public IA32Nodes{
	public:	
	retNode();
	string printSelf();
	bool removable();
};
#endif
