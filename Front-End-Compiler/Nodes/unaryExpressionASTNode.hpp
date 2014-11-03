
#ifndef UNEXPRNODE_H
#define UNEXPRNODE_H

#include "ExpressionASTNode.hpp"
class CheckInterface;
class SymbolTable;
class unaryExpressionASTNode: public ExpressionASTNode{
  private:
	unaryOp op;
   	ExpressionASTNode *expression;
  
  public:
	unaryExpressionASTNode(ExpressionASTNode *e, unaryOp o, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	unaryOp getOp();
	ExpressionASTNode *getExpr();
	int weight();
};

#endif

