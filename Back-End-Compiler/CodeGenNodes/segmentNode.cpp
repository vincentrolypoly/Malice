#include "segmentNode.hpp"
#include <sstream>
#include <string>

segmentNode::segmentNode(string t){
	type = t;
}

string segmentNode::printSelf(){
	return " segment " "." + type;
}

bool segmentNode::removable(){
	return false;
}
