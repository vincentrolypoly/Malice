
#ifndef FORLOOPNODE_H
#define FORLOOPNODE_H

#include "statementNode.hpp"
class ExpressionASTNode;
class compoundStatement;
class variableASTNode;
class CheckInterface;
class SymbolTable;
class CFG;

class forLoopNode: public statementNode {
  private:
	variableASTNode   *var;
	ExpressionASTNode *from;
	ExpressionASTNode *to;
	compoundStatement *body;
	
  public:
	forLoopNode(variableASTNode *v, ExpressionASTNode* f, ExpressionASTNode* t, compoundStatement *b , int line);
	void accept(CheckInterface *c, SymbolTable *ST);
	void printVal();
	void destroyAST();
	variableASTNode	  *getID();
	ExpressionASTNode *getFrom();
	ExpressionASTNode *getTo();
	compoundStatement *getBody();
	CFG* buildCFG();
};

#endif

