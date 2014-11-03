
#ifndef ASSIGNNODE_H
#define ASSIGNNODE_H

#include "statementNode.hpp"
class variableASTNode;
class ExpressionASTNode;
class CheckerInterface;
class SymbolTable;
class CFG;

class assignNode: public statementNode {
  private:
	variableASTNode *LHS;
	ExpressionASTNode *RHS;
	
  public:
	assignNode(variableASTNode *lhs, ExpressionASTNode *rhs, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	ExpressionASTNode *getRHS();
	variableASTNode* getLHS();
	CFG* buildCFG();
};

#endif

