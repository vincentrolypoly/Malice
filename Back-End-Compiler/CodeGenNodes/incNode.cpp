#include "incNode.hpp"

#include <string>

incNode::incNode(string r){
	reg = r;
}

string incNode::printSelf(){
	return "	inc " + reg;
}

bool incNode::removable(){
	//Increment node is never removable
	return false;
}
