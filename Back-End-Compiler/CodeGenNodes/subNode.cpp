#include "subNode.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string>

subNode::subNode(string r1, string r2){
	reg1 = r1;
	reg2 = r2;
}

string subNode::printSelf(){
	return "	sub " + reg1  + "," + reg2;
}

bool subNode::removable(){
	return reg2.compare("0") == 0;
}
