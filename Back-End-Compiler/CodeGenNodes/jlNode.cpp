#include "jlNode.hpp"

#include <string>

jlNode::jlNode(string l){
	label = l;
}

string jlNode::printSelf(){
	return "	jl " + label;
}

bool jlNode::removable(){
	//never removable
	return false;
}
