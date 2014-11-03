#include "jgNode.hpp"

#include <string>

jgNode::jgNode(string l){
	label = l;
}

string jgNode::printSelf(){
	return "	jg " + label;
}

bool jgNode::removable(){
	//jdNode is never removable
	return false;
}
