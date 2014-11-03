
#ifndef LOOPNODE_H
#define LOOPNODE_H

#include "statementNode.hpp"
class ExpressionASTNode;
class compoundStatement;
class CheckInterface;
class SymbolTable;
class CFG;

class loopNode: public statementNode {
  private:
	ExpressionASTNode *expr;
	compoundStatement *body;
	
  public:
	loopNode(ExpressionASTNode *e, compoundStatement *b, int line);
	void accept(CheckInterface *c, SymbolTable *ST);
	void printVal();
	void destroyAST();
	ExpressionASTNode *getExpr();
	compoundStatement *getBody();
	CFG* buildCFG();
};

#endif

