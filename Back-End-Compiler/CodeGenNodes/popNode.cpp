#include "popNode.hpp"

#include <string>

popNode::popNode(string r){
	reg = r;
	size = "qword";
}
popNode::popNode(string s, string r1){
	reg = r1;
	size = s;
}

string popNode::printSelf(){
	return "	pop " + size + " " + reg;
}

bool popNode::removable(){
	return false;
}
