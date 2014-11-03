
#include "functionDeclNode.hpp"
#include "typeNode.hpp"
#include "functionArgumentNode.hpp"
#include "bodyNode.hpp"
#include "../CFG.hpp"
#include "../checkInterface.hpp"
#include <iostream>
functionDeclNode::functionDeclNode(string name, typeNode *r, bodyNode *b, functionArgumentNode *a, int line) {
	functionName = name;
	returnType = r;
	body = b;
	arguments = a;
	lineNo = line;
}
   
void functionDeclNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}
   
void functionDeclNode::destroyAST() {
	arguments->destroyAST();
	returnType->destroyAST();
	body->destroyAST();
	delete arguments;
	delete returnType;
	delete body;
}
    
void functionDeclNode::printVal() {
	cout << functionName << endl;
	arguments->printVal();
	body->printVal();
}

functionArgumentNode* functionDeclNode::getArgs() {
	return arguments;
}
    
typeNode* functionDeclNode::getReturnType() {
	return returnType;
}
    
bodyNode* functionDeclNode::getBody() {
	return body;
}
    
string functionDeclNode::getName() {
	return functionName;
}
    
CFG* functionDeclNode::buildCFG() {
	CFG* c;
	if(body) {
		c = body->buildCFG();
	} else {
		c = new CFG(this);
	}
	return c;
}	

