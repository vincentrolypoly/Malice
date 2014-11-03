#include "cmpNode.hpp"

#include <string>

cmpNode::cmpNode(string r1, string r2){
	reg1 = r1;
	reg2 = r2;
}

string cmpNode::printSelf(){
	return "	cmp " + reg1 + "," + reg2;
}

bool cmpNode::removable(){
	//Comparison node is never removable	
	return false;
}
