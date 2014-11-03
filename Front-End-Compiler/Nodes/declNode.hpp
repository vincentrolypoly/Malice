
#ifndef DECLNODE_H
#define DECLNODE_H

#include "ASTNodes.hpp"
class CheckInterface;
class SymbolTable;

class declNode: public ASTNodes {
	public:
	virtual void printVal()=0;
	virtual void accept(CheckInterface *c, SymbolTable *currentST)=0;
	virtual void destroyAST()=0;
};

#endif

