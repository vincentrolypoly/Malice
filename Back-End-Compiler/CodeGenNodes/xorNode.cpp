#include "xorNode.hpp"

#include <string>

xorNode::xorNode(string r1, string r2){
	reg1 = r1;
	reg2 = r2;
}

string xorNode::printSelf(){
	return "	xor " + reg1  + "," + reg2;
}

bool xorNode::removable(){
	return reg2.compare("0")==0;
}
