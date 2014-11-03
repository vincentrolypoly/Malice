
#ifndef VARASTNODE_H
#define VARASTNODE_H

#include "valNode.hpp"
#include <string>
class CheckInterface;
class SymbolTable;
class typeDeclNode;
using namespace std;
class variableASTNode: public valNode {
  public:
	virtual void printVal()=0;
	virtual void accept(CheckInterface *c, SymbolTable *currentST)=0;
	virtual void destroyAST()=0;
	virtual string getName()=0;
	virtual typeDeclNode* getDecl()=0;
	virtual void setDecl(typeDeclNode* d)=0;
	virtual int weight()=0;
};

#endif

