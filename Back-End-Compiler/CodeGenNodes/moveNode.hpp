#include "IA32Nodes.hpp"
#include <string>
#include <fstream>
using namespace std;

class moveNode: public IA32Nodes{
	string reg1;
	string reg2;
	string instr;
	public:
	moveNode(string r1, string r2);
	string printSelf();
	bool removable();
};
