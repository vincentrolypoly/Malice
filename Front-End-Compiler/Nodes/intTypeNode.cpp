
#include "intTypeNode.hpp"

intTypeNode::intTypeNode() {
	typeName = "number";
}
   
void intTypeNode::accept(CheckInterface *c, SymbolTable *currentST) { }
void intTypeNode::destroyAST() { }
void intTypeNode::printVal(){}
