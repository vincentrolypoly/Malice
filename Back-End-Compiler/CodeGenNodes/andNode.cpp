#include "andNode.hpp"

#include <string>

andNode::andNode(string r1, string r2){
	reg1 = r1;
	reg2 = r2;
}

string andNode::printSelf(){
	return "	and " + reg1  + "," + reg2;
}

bool andNode::removable(){
	//if first and second argument are the same then node is removable
	return reg1.compare(reg2) == 0;
}
