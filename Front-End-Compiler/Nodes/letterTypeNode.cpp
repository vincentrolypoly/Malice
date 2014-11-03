
#include "letterTypeNode.hpp"

letterTypeNode::letterTypeNode() {
	typeName = "letter";
}
void letterTypeNode::destroyAST(){
}
void letterTypeNode::accept(CheckInterface *c, SymbolTable *s) { }    
    
void letterTypeNode::printVal() {
}

