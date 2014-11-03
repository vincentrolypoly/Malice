#include "jgeNode.hpp"

#include <string>

jgeNode::jgeNode(string l){
	label = l;
}

string jgeNode::printSelf(){
	return "	jge " + label;
}

bool jgeNode::removable(){
	//jgeNode is never removable	
	return false;
}
