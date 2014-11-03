
#ifndef PRINTNODE_H
#define PRINTNODE_H

#include "statementNode.hpp"
class CheckInterface;
class SymbolTable;
class ExpressionASTNode;
class CFG;


class printNode: public statementNode{
  private:
	ExpressionASTNode *value;
	
  public:
	printNode(ExpressionASTNode *val, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	ExpressionASTNode* getVal();
	CFG* buildCFG();
};

#endif

