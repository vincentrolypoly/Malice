#include "retNode.hpp"

#include <string>

retNode::retNode(){
}

string retNode::printSelf(){
	return "	ret";
}

bool retNode::removable(){
	return false;
}
