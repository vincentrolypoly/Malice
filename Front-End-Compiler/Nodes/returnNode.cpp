
#include "returnNode.hpp"
#include "ExpressionASTNode.hpp"
#include "../CFG.hpp"
#include "../checkInterface.hpp"
#include <iostream>
using namespace std;

returnNode::returnNode(ExpressionASTNode *r, int line) {
	returnValue = r;
	lineNo = line;
}
	
void returnNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}
	
void returnNode::destroyAST() {
	returnValue->destroyAST();
	delete returnValue;
}
	
void returnNode::printVal() {
	cout<<"return node" << endl;
}
	
ExpressionASTNode* returnNode::getvalue() {
	return returnValue;
}
	
CFG* returnNode::buildCFG() {
	return new CFG(this);
}

