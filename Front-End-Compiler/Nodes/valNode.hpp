
#ifndef VAL_H
#define VAL_H

#include "ExpressionASTNode.hpp"
class CheckInterface;
class SymbolTable;

class valNode: public ExpressionASTNode{
  public:	
	void printVal()=0;
	void accept(CheckInterface *c, SymbolTable *currentST)=0;
	void destroyAST()=0;
	int weight()=0;
};

#endif

