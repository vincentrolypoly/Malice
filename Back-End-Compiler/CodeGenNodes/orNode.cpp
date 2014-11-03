#include "orNode.hpp"

#include <string>

orNode::orNode(string r1, string r2){
	reg1 = r1;
	reg2 = r2;
}

string orNode::printSelf(){
	return "	or " + reg1  + "," + reg2;
}

bool orNode::removable(){
	//removable if r1 and r2 are the same register
	return reg1.compare(reg2) == 0;
}
