
#include "arrDeclNode.hpp"
#include "ExpressionASTNode.hpp"
#include "typeNode.hpp"
#include <iostream>
#include "../CFG.hpp"
#include "../checkInterface.hpp"
arrDeclNode::arrDeclNode(string arrName, typeNode *t, ExpressionASTNode *n, bool sp, int line) {
	name = arrName;
	type = t;
	numberOfElems = n;
	spider = sp;
	lineNo = line;
}
   
void arrDeclNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}
   
void arrDeclNode::destroyAST() {
	type->destroyAST();
	numberOfElems->destroyAST();
	delete type;
	delete numberOfElems;
}
   
void arrDeclNode::printVal() {
	cout << name << endl;
}
   
ExpressionASTNode* arrDeclNode::getSize() {
	return numberOfElems;
}
   
typeNode* arrDeclNode::getType() {
	return type;
}

string arrDeclNode::getName() {
	return name;
}
bool arrDeclNode::isSpider() {
	return spider;
}


