
#ifndef BINEXPRNODE_H
#define BINEXPRNODE_H

#include "ExpressionASTNode.hpp"
class CheckInterface;
class SymbolTable;

class binaryExpressionASTNode: public ExpressionASTNode {
  private:	
	binaryOp op;
	ExpressionASTNode *left;
   	ExpressionASTNode *right;
       
  public:
	binaryExpressionASTNode(ExpressionASTNode *l, ExpressionASTNode *r, binaryOp o, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	ExpressionASTNode* getLeft();
	ExpressionASTNode* getRight();
	binaryOp getOp();
	int weight();
};

#endif

