
#ifndef NUMBERASTNODE_H
#define NUMBERASTNODE_H

#include "valNode.hpp"
class CheckInterface;
class SymbolTable;
class intTypeNode;
class typeNode;
class numberASTNode: public valNode {
  private:
   	int value;
	intTypeNode *type;
    
  public:
	numberASTNode(int val);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	int getValue();
	typeNode* getType();
	int weight();
};

#endif

