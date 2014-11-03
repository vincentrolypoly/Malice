#include "jeNode.hpp"

#include <string>

jeNode::jeNode(string l){
	label = l;
}

string jeNode::printSelf(){
	return "	je " + label;
}

bool jeNode::removable(){
	//je node is never removable
	return false;
}
