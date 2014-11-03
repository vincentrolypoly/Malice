
#include "programNode.hpp"
#include "declListNode.hpp"
#include <iostream>
#include "../checkInterface.hpp"
using namespace std;
programNode::programNode(declListNode *s) {
	start = s;
}

void programNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}

void programNode::destroyAST() {
	start->destroyAST();
	delete start;
}
	
void programNode::printVal() {
	cout<< "program" << endl;
	start->printVal();
}

declListNode* programNode::getStart() {
	return start;
}	

