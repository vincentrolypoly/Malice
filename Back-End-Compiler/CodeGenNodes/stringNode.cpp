#include "stringNode.hpp"

#include <string>

stringNode::stringNode(string s, string l){
	str = s;
	str.erase (0,1);
	str.erase(str.length()-1, 1);
	label = l;
}

string stringNode::printSelf(){
	return label + ": " + string("\n") + "db `" + str + "`,0";
}

bool stringNode::removable(){
	return false;
}
