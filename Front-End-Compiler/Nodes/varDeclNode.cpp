
#include "varDeclNode.hpp"
#include "ExpressionASTNode.hpp"
#include "typeNode.hpp"
#include "../checkInterface.hpp"
#include <iostream>
varDeclNode::varDeclNode(string varName, typeNode *t, ExpressionASTNode *e, bool forever, bool sp, int line) {
	name = varName;
	type = t;
	spider = sp;
	constant = forever;
	value = e;
	lineNo = line;
} 
   
void varDeclNode::accept(CheckInterface *c, SymbolTable *currentST) {	
	c->check(this, currentST);
}	
   
void varDeclNode::destroyAST() {
	type->destroyAST();
	if(value)
	value->destroyAST();
	delete type;
	delete value;
}
   
void varDeclNode::printVal() {
	cout << name << endl;
}
   
ExpressionASTNode* varDeclNode::getValue() {
	return value;
}

typeNode* varDeclNode::getType() {
	return type;
}
   
string varDeclNode::getName() {
	return name;
}

bool varDeclNode::isConst() {
	return constant;
}

void varDeclNode::switchConst() {
	constant = !constant;
}

bool varDeclNode::isSpider() {
	return spider;
}


