#include "leaNode.hpp"

#include <string>

leaNode::leaNode(string l1, string l2){
	label1 = l1;
	label2 = l2;
}

string leaNode::printSelf(){
	return "	lea " + label1 + ", " + label2;
} 

bool leaNode::removable(){
	//Maybe removable if l1 == [l1] 
	return false;
}
