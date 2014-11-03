
#include "procedureDeclNode.hpp"
#include "functionArgumentNode.hpp"
#include "bodyNode.hpp"
#include "../CFG.hpp"
#include "../checkInterface.hpp"

#include <iostream>
procedureDeclNode::procedureDeclNode(string name, bodyNode *b, functionArgumentNode *a, int line) {
	functionName = name;
	body = b;
	arguments = a;
	lineNo = line;
}
   
void procedureDeclNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}
   
void procedureDeclNode::destroyAST() {
	arguments->destroyAST();
	body->destroyAST();
	delete arguments;
	delete body;
}
   
void procedureDeclNode::printVal() {
	cout << functionName << endl;
	arguments->printVal();
	body->printVal();
}
   
functionArgumentNode* procedureDeclNode::getArgs() {
	return arguments;
}
   
bodyNode* procedureDeclNode::getBody() {
	return body;
}
   
string procedureDeclNode::getName() {
	return functionName;
}

CFG* procedureDeclNode::buildCFG() {
	CFG* c;
	if(body) {
		c = body->buildCFG();
	}else{
		c = new CFG(this);
	}
	return c;
}

