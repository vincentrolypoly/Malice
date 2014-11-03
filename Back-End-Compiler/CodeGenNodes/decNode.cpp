#include "decNode.hpp"

#include <string>

decNode::decNode(string r){
	reg = r;
}

string decNode::printSelf(){
	return "	dec " + reg;
}

bool decNode::removable(){
	//Dec node is never removable	
	return false;
}
