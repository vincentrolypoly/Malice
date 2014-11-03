#include "labelNode.hpp"

#include <string>

labelNode::labelNode(string l){
	label = l;
}

string labelNode::printSelf(){
	return label + ":";
}

bool labelNode::removable(){
	return false;
}
