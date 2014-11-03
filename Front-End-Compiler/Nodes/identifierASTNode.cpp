
#include "identifierASTNode.hpp"
#include "../checkInterface.hpp"
#include <iostream>
identifierASTNode::identifierASTNode(string nameOfVar, int line) {
	name = nameOfVar;
	lineNo = line;
}

void identifierASTNode::accept(CheckInterface *c, SymbolTable *currentST) {
		c->check(this, currentST);
}

void identifierASTNode::destroyAST() {	}
	
void identifierASTNode::printVal() {
	cout<<name;
}
void identifierASTNode::setDecl(typeDeclNode* d){
	decl = d;
}
typeDeclNode* identifierASTNode::getDecl(){
	return decl;	
}
string identifierASTNode::getName() {
	return name;
}
int identifierASTNode::weight(){
	return 1;
}

