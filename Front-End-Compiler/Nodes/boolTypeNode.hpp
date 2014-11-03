
#ifndef BOOLTYPENODE_H
#define BOOLTYPENODE_H

#include "typeNode.hpp"
class CheckInterface;
class SymbolTable;
class boolTypeNode: public typeNode {
  public:
	boolTypeNode();
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
};

#endif

