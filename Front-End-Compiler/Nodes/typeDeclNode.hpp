
#ifndef TYPEDECLNODE_H
#define TYPEDECLNODE_H

#include "declNode.hpp"
class typeNode;
class CheckInterface;
class SymbolTable;

class typeDeclNode: public declNode {
  public:
	virtual void printVal()=0;
	virtual void accept(CheckInterface *c, SymbolTable *currentST)=0;
	virtual void destroyAST()=0;
	virtual typeNode* getType()=0;
	virtual bool isSpider()=0;
};

#endif

