#include "addNode.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string>

addNode::addNode(string r1, string r2){
	reg1 = r1;
	reg2 = r2;
}

string addNode::printSelf(){
	return "	add " + reg1 + "," + reg2;
}

bool addNode::removable(){
	//If the second arg given to add is a 0, then it is removable from the deque
	return reg2.compare("0") == 0;
}
