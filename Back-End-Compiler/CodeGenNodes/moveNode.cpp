#include "moveNode.hpp"
#include <string>

moveNode::moveNode(string r1, string r2){
	reg1 = r1;
	reg2 = r2;
}

string moveNode::printSelf(){
	return "	mov qword " + reg1 + "," + reg2;
}

bool moveNode::removable(){
	//removable if r1 and r2 are the same register
	return reg1.compare(reg2) == 0;
}
