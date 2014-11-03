
#include "boolTypeNode.hpp"

boolTypeNode::boolTypeNode() {
	typeName = "boolean";
}
    
void boolTypeNode::accept(CheckInterface *c, SymbolTable *currentST) { }
void boolTypeNode::destroyAST() { }
void boolTypeNode::printVal(){}
