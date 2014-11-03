
#ifndef SENTENCETYPENODE_H
#define SENTENCETYPENODE_H

#include "typeNode.hpp"
class CheckInterface;
class SymbolTable;

class sentenceTypeNode: public typeNode {
  public:
	sentenceTypeNode();
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
};

#endif

