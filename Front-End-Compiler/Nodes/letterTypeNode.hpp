
#ifndef LETTERTYPENODE_H
#define LETTERTYPENODE_H

#include "typeNode.hpp"
class CheckInterface;
class SymbolTable;

class letterTypeNode: public typeNode {
  private:	
	char value;
    
  public:
	letterTypeNode();
    void accept(CheckInterface *c, SymbolTable *s);
	void destroyAST();
	void printVal();
};

#endif

