
#ifndef BRANCHINGNODE_H
#define BRANCHINGNODE_H

#include "ASTNodes.hpp"
#include <deque>
class ExpressionASTNode;
class statementListNode;
class CheckInterface;
class SymbolTable;
class CFG;

using namespace std;

class branchingNode: public ASTNodes {
  private:
	ExpressionASTNode *expr;
	statementListNode *body;
    
  public:
	branchingNode(ExpressionASTNode *e, statementListNode *b, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	ExpressionASTNode* getExpr();
	statementListNode *getBody();
	deque<CFG*>* buildCFG();
};

#endif

