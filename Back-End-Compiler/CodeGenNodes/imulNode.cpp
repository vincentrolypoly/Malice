#include "imulNode.hpp"

#include <string>

imulNode::imulNode(string r1){
	reg1 = r1;
	reg2 = "";
}

imulNode::imulNode(string r1, string r2){
	reg1 = r1;
	reg2 = "," + r2;
}

string imulNode::printSelf(){
	return "	imul " + reg1 + reg2;
}

bool imulNode::removable(){
	//multiplying by 1 is removable
	return reg2.compare("1") == 0;
}
