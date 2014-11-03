
#include "assignNode.hpp"
#include "variableASTNode.hpp"
#include "ExpressionASTNode.hpp"
#include "../CFG.hpp"
#include "../checkInterface.hpp"
#include <iostream>
using namespace std;
assignNode::assignNode(variableASTNode *lhs, ExpressionASTNode *rhs, int line) {
	LHS = lhs;
	RHS = rhs;
	lineNo = line;
}

void assignNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}

void assignNode::destroyAST() {
	LHS->destroyAST();
	RHS->destroyAST();
	delete LHS;
	delete RHS;
}
	
void assignNode::printVal() {
	cout<< "RHS node" << endl;
	RHS->printVal();
}
	
ExpressionASTNode* assignNode::getRHS() {
	return RHS;
}
	
variableASTNode* assignNode::getLHS() {
	return LHS;
}
	
CFG* assignNode::buildCFG() {
	return new CFG(this);
}

