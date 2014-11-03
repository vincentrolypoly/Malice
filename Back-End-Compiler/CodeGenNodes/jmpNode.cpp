#include "jmpNode.hpp"

#include <string>

jmpNode::jmpNode(string l){
	label = l;
}

string jmpNode::printSelf(){
	return "	jmp " + label;
}

bool jmpNode::removable(){
	//never removable
	return false;
}
