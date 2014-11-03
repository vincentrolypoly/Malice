
#ifndef LETTERASTNODE_H
#define LETTERASTNODE_H

#include "valNode.hpp"

class CheckInterface;
class SymbolTable;
class typeNode;
class letterTypeNode;

class letterASTNode: public valNode {
  private:
	letterTypeNode *type;		
	char value;
        
  public:
	letterASTNode(char c);
	void accept(CheckInterface *c, SymbolTable *s);
	void destroyAST();
	void printVal();
    char getValue();
	typeNode* getType();
	int weight();
};

#endif

