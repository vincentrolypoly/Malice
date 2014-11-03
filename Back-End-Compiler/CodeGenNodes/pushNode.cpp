#include "pushNode.hpp"

#include <string>

pushNode::pushNode(string r){
	reg = r;
	size = "qword";
}

string pushNode::printSelf(){
	return "	push " + size + " " + reg;
}

pushNode::pushNode(string s, string r1){
	reg = r1;
	size = s;
}

bool pushNode::removable(){
	return false;
}
