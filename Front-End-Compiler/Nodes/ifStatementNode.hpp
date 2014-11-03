
#ifndef IFSTATNODE_H
#define IFSTATNODE_H

#include "statementNode.hpp"
class ExpressionASTNode;
class branchingNodes;
class statementListNode;
class CFG;
class CheckInterface;
class SymbolTable;

class ifStatementNode: public statementNode {
  private:
	ExpressionASTNode *expr; 
	statementListNode *body;
	branchingNodes* others;
	
  public:
	ifStatementNode(ExpressionASTNode *e, statementListNode *b, branchingNodes* o, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	ExpressionASTNode *getExpr();
	statementListNode *getBody();
	branchingNodes* getOthers();
	CFG* buildCFG();
};

#endif

