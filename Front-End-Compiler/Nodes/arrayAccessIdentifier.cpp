
#include "arrayAccessIdentifier.hpp"
#include <iostream>
#include "ExpressionASTNode.hpp"
#include "../checkInterface.hpp"
arrayAccessIdentifier::arrayAccessIdentifier(string n, ExpressionASTNode *e, int line) {
	arrayName = n;
	elementAccess = e;
	lineNo = line;
	decl = NULL;
}
typeDeclNode* arrayAccessIdentifier::getDecl(){
	return decl;
}
void arrayAccessIdentifier::setDecl(typeDeclNode* d){
	decl = d;
}
void arrayAccessIdentifier::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}

void arrayAccessIdentifier::destroyAST(){
	elementAccess->destroyAST();
	delete elementAccess;
}
	
void arrayAccessIdentifier::printVal() {
	cout<<arrayName << " access ";
	elementAccess->printVal();
	cout<<endl;
}
	
ExpressionASTNode* arrayAccessIdentifier::getExpr() {
	return elementAccess;
}
	
string arrayAccessIdentifier::getName() {
	return arrayName;
}

int arrayAccessIdentifier::weight(){
	return 2;
}
