#include "callerNode.hpp"

#include <string>

callerNode::callerNode(string l){
	label = l;
}

string callerNode::printSelf(){
	return "	call " + label;
}

bool callerNode::removable(){
	//A call node is never removable	
	return false;
}
