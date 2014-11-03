
#include "letterASTNode.hpp"
#include "letterTypeNode.hpp"
#include "../checkInterface.hpp"
#include <iostream>
letterASTNode::letterASTNode(char c) {
	value = c;
	type = new letterTypeNode();
}

void letterASTNode::accept(CheckInterface *c, SymbolTable *s) { 
    c->check(this,s);
}
        
void letterASTNode::destroyAST() {
	type->destroyAST();
	delete type;
}
        
void letterASTNode::printVal() {
	std::cout<<value;
}
char letterASTNode::getValue(){
    return value;
}
typeNode* letterASTNode::getType() {
	return type;
}
int letterASTNode::weight(){
	return 1;
}
