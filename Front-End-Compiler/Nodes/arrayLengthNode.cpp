
#include "arrayLengthNode.hpp"
#include "../checkInterface.hpp"
#include "../symbolTable.hpp"

#include <string>
#include <iostream>

arrayLengthNode::arrayLengthNode(string name, int line) {
	arrName = name;
	lineNo = line;
}

void arrayLengthNode::printVal() {
	cout << "array length node" << endl;
}

void arrayLengthNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}

void arrayLengthNode::destroyAST() {
}

int arrayLengthNode::weight() {
	return 0;
}

string arrayLengthNode::getName() {
	return arrName;
}

int arrayLengthNode::getLineNo() {
	return lineNo;
}

void arrayLengthNode::setDeclto(typeDeclNode *decl) {
	arrDecl = decl;
}

typeDeclNode* arrayLengthNode::getDecl() {
	return arrDecl;
}
