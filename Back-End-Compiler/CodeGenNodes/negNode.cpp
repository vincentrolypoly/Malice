#include "negNode.hpp"

#include <string>

negNode::negNode(string r1){
	reg1 = r1;
}

string negNode::printSelf(){
	return "	neg " + reg1;
}

bool negNode::removable(){
	return false;
}
