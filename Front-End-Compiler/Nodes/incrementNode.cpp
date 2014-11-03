
#include "incrementNode.hpp"
#include "variableASTNode.hpp"
#include "../CFG.hpp"
#include "../checkInterface.hpp"
#include <iostream>

incrementNode::incrementNode(variableASTNode *v, int line) {
	var = v;
	lineNo = line;
}
	
void incrementNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}
	
void incrementNode::destroyAST() {
	var->destroyAST();
	delete var;
}	
	
void incrementNode::printVal() {
	cout<<"increment node" <<endl;		
}
	
variableASTNode* incrementNode::getVar() {
	return var;
}
	
CFG* incrementNode::buildCFG() {
	return new CFG(this);
}

