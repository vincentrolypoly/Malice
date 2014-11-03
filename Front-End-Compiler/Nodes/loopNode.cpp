
#include "loopNode.hpp"
#include "ExpressionASTNode.hpp"
#include "compoundStatement.hpp"
#include "../CFG.hpp"
#include "../checkInterface.hpp"
#include <iostream>
using namespace std;

loopNode::loopNode(ExpressionASTNode *e, compoundStatement *b, int line) {
	expr = e;
	body = b;
	lineNo = line;
}
	
void loopNode::accept(CheckInterface *c, SymbolTable *ST) {
	c->check(this, ST);
}
	
void loopNode::destroyAST() {
	expr->destroyAST();
	body->destroyAST();
	delete expr;
	delete body;
}
	
void loopNode::printVal() {
	cout<< "loop node" << endl;
	expr->printVal();
	body->printVal();
}
	
ExpressionASTNode* loopNode::getExpr() {
	return expr;
}
	
compoundStatement* loopNode::getBody() {
	return body;
}
	
CFG* loopNode::buildCFG() {
	CFG* c = new CFG(this);
	CFG* bottom = new CFG(NULL);
	c->addChild(bottom);
	CFG* child = body->buildCFG();
	c->addChild(child);
	child = child->getToBottom();
	child->addChild(bottom);
	
	return c;
}

