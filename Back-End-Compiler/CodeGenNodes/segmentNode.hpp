#ifndef segment_H
#define segment_H
#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class segmentNode: public IA32Nodes{
	string type;
	public:
	segmentNode(string t);
	string printSelf();
	bool removable();
};
#endif
