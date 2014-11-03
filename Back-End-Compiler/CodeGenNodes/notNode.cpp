
#include "notNode.hpp"

#include <string>

notNode::notNode(string r1){
	reg1 = r1;
}

string notNode::printSelf(){
	return "	not " + reg1;
}


bool notNode::removable(){
	return false;
}
