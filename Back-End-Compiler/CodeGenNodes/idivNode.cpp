#include "idivNode.hpp"

#include <string>

idivNode::idivNode(string r1){
	reg1 = r1;
}

string idivNode::printSelf(){
	return "	idiv " + reg1;
}

bool idivNode::removable(){
	//Dividing by 1 is removable
	return reg1.compare("1") == 0;
}
