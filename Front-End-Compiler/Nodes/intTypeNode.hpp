
#ifndef INTTYPENODE_H
#define INTTYPENODE_H

#include "typeNode.hpp"
class CheckInterface;
class SymbolTable;

class intTypeNode: public typeNode {
  public:
	intTypeNode();
    void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
};

#endif

