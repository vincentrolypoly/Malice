
#include "decrementNode.hpp"
#include "variableASTNode.hpp"
#include "../CFG.hpp"
#include "../checkInterface.hpp"
#include <iostream>
using namespace std;
decrementNode::decrementNode(variableASTNode *v, int line) {
	var = v;
	lineNo = line;
}
	
void decrementNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}
	
void decrementNode::destroyAST() {
	var->destroyAST();
	delete var;
}
	
void decrementNode::printVal() {
	cout<<"decrement node" << endl;
}
	
variableASTNode* decrementNode::getVar() {
	return var;
}
	
CFG* decrementNode::buildCFG() {
	return new CFG(this);
}

