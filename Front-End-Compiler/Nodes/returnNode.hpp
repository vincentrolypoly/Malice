
#ifndef RETURNNODE_H
#define RETURNNODE_H

#include "statementNode.hpp"
class CheckInterface;
class SymbolTable;
class ExpressionASTNode;
class CFG;


class returnNode: public statementNode {
  private:
	ExpressionASTNode *returnValue;
	
  public:
	returnNode(ExpressionASTNode *r, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	ExpressionASTNode* getvalue();
	CFG* buildCFG();
};

#endif

