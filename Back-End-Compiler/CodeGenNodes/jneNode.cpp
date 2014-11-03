#include "jneNode.hpp"

#include <string>

jneNode::jneNode(string l){
	label = l;
}

string jneNode::printSelf(){
	return "	jne " + label;
}

bool jneNode::removable(){
	//never removable
	return false;
}
