
#include "sentenceTypeNode.hpp"

sentenceTypeNode::sentenceTypeNode() {
	typeNode::typeName = "sentence";
}
    
void sentenceTypeNode::accept(CheckInterface *c, SymbolTable *currentST) { }
void sentenceTypeNode::destroyAST() { }
void sentenceTypeNode::printVal() { }
