
#ifndef STATEMENTNODE_H
#define STATEMENTNODE_H

#include "ASTNodes.hpp"
class CheckInterface;
class SymbolTable;
class CFG;

class statementNode: public ASTNodes {
  public:
	virtual void printVal()=0;
	virtual void accept(CheckInterface *c, SymbolTable *currentST)=0;
	virtual void destroyAST()=0;
	virtual CFG* buildCFG()=0;
};

#endif

