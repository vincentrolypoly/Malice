
#include "bodyNode.hpp"
#include "compoundStatement.hpp"
#include "declListNode.hpp"
#include <iostream>
#include "../CFG.hpp"
#include "../checkInterface.hpp"
#include "../symbolTable.hpp"

bodyNode::bodyNode() {
	body = new compoundStatement();
	decls = new declListNode();
}
	
bodyNode::bodyNode(compoundStatement *b, declListNode *d) {
	body = b;
	decls = d;
}
	
void bodyNode::accept(CheckInterface *c, SymbolTable *ST) {
	ST = new SymbolTable(ST);
	c->check(this, ST);  //create a new scope
}
	
void bodyNode::destroyAST() {
	if(body)
	body->destroyAST();
	if(decls)
	decls->destroyAST();
	delete body;
	delete decls;
}
	
void bodyNode::printVal() {
	cout << "Inside the body" << endl;
	decls->printVal();
	body->printVal();
}
	
compoundStatement* bodyNode::getBody() {
	return body;
}
	
declListNode* bodyNode::getDecls() {
	return decls;
}
	
CFG* bodyNode::buildCFG() {
	if (body){
		return body->buildCFG();
	}else{
		return new CFG(this);
	}
}

