
#include "sentenceASTNode.hpp"
#include "sentenceTypeNode.hpp"
#include "../checkInterface.hpp"
#include <iostream>

sentenceASTNode::sentenceASTNode(string s) {
	value = s;
	type = new sentenceTypeNode();
}
        
void sentenceASTNode::accept(CheckInterface *c, SymbolTable *s) {
    c->check(this,s);
}
        
void sentenceASTNode::destroyAST() {
	type->destroyAST();
	delete type;
}
string sentenceASTNode::getValue(){
    return value;
}
void sentenceASTNode::printVal() {
	std::cout<<value;
}
        
typeNode* sentenceASTNode::getType() {
	return type;
}
int sentenceASTNode::weight(){
	return 1;
}
