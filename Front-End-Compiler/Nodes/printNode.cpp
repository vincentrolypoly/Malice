
#include "printNode.hpp"
#include "ExpressionASTNode.hpp"
#include <iostream>
#include "../checkInterface.hpp"
#include "../CFG.hpp"
using namespace std;
printNode::printNode(ExpressionASTNode *val, int line) {
	value = val;
	lineNo = line;
}

void printNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}
	
void printNode::destroyAST() {
	value->destroyAST();
	delete value;
}
	
void printNode::printVal() {
	cout<< "printnode with value:";
	value->printVal();
	cout<< endl;
}
	
ExpressionASTNode* printNode::getVal() {
	return value;
}
	
CFG* printNode::buildCFG() {
	return new CFG(this);
}

