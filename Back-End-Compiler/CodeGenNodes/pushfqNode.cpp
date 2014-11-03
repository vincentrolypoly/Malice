#include "pushfqNode.hpp"

#include <string>

pushfqNode::pushfqNode(){
}

string pushfqNode::printSelf(){
	return "	pushfq ";
}

bool pushfqNode::removable(){
	return false;
}
