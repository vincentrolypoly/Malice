
#ifndef PROGRAMNODE_H
#define PROGRAMNODE_H

#include "ASTNodes.hpp"
class declListNode;
class CheckInterface;
class SymbolTable;
class programNode: public ASTNodes {
  private:	
	declListNode *start;
	
  public:
	programNode(declListNode *s);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	declListNode *getStart();
};


#endif
