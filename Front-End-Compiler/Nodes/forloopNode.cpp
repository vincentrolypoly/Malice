#include "forloopNode.hpp"
#include "ExpressionASTNode.hpp"
#include "compoundStatement.hpp"
#include "variableASTNode.hpp"
#include "../CFG.hpp"
#include "../checkInterface.hpp"
#include <iostream>
using namespace std;

forLoopNode::forLoopNode(variableASTNode* v, ExpressionASTNode* f, ExpressionASTNode* t, compoundStatement *b, int line) {
	var = v;
	from = f;
	to = t;
	body = b;
	lineNo = line;
}
	
void forLoopNode::accept(CheckInterface *c, SymbolTable *ST) {
	c->check(this, ST);
}
	
void forLoopNode::destroyAST() {
	from->destroyAST();
	to->destroyAST();
	var->destroyAST();
	body->destroyAST();
	delete from;
	delete var;
	delete to;
	delete body;
}
		
void forLoopNode::printVal() {
	cout<< "for loop node" << endl;
	var->printVal();
	from->printVal();
	to->printVal();
	body->printVal();
}

variableASTNode* forLoopNode::getID(){
	return var;
}	
ExpressionASTNode* forLoopNode::getFrom() {
	return from;
}

ExpressionASTNode* forLoopNode::getTo(){
	return to;
}

compoundStatement* forLoopNode::getBody() {
	return body;
}
	
CFG* forLoopNode::buildCFG() {
	CFG* c = new CFG(this);
	CFG* bottom = new CFG(NULL);
	c->addChild(bottom);
	CFG* child = body->buildCFG();
	c->addChild(child);
	child = child->getToBottom();
	child->addChild(bottom);
	
	return c;
}
