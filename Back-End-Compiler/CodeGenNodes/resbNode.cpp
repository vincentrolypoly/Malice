#include "resbNode.hpp"
#include <sstream>
#include <string>

resbNode::resbNode(string n, int s){
	name = n;
	size = s;
}

string resbNode::printSelf(){
	stringstream ss;
	ss << size;
	return name + " resb " + ss.str();
}

bool resbNode::removable(){
	return false;
}
