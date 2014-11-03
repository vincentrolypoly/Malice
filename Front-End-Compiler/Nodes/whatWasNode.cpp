
#include "whatWasNode.hpp"
#include "variableASTNode.hpp"
#include "../CFG.hpp"
#include "../checkInterface.hpp"
#include <iostream>
using namespace std;
whatWasNode::whatWasNode(variableASTNode *s, int line) {
	store = s;
	lineNo = line;
}
	
void whatWasNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}
	
void whatWasNode::destroyAST() {
	store->destroyAST();
	delete store;
}
	
void whatWasNode::printVal() {
	cout<< "what was node" << endl;
}
	
variableASTNode* whatWasNode::getStore() {
	return store;
}
	
CFG* whatWasNode::buildCFG() {
	return new CFG(this);
}

