#include "jleNode.hpp"

#include <string>

jleNode::jleNode(string l){
	label = l;
}

string jleNode::printSelf(){
	return "	jle " + label;
}

bool jleNode::removable(){
	//never removable
	return false;
}
