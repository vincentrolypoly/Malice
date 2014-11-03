
#include "numberASTNode.hpp"
#include "intTypeNode.hpp"
#include "../checkInterface.hpp"
#include <iostream>
numberASTNode::numberASTNode(int val) {
	value = val;
	type = new intTypeNode();
} 
        
void numberASTNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this,currentST);
}
        
void numberASTNode::destroyAST() {
	type->destroyAST();
	delete type;
}
        
void numberASTNode::printVal() {
	std::cout<<value;
}
        
int numberASTNode::getValue() {
	return value;
}

typeNode* numberASTNode::getType() {
	return type;
}

int numberASTNode::weight(){
	return 1;
}

