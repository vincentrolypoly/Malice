
#ifndef STATEMENTLISTNODE_H
#define STATEMENTLISTNODE_H

#include "ASTNodes.hpp"
#include <deque>
class statementNode;
class CheckInterface;
class SymbolTable;
class CFG;
using namespace std;
class statementListNode: public ASTNodes {
  private:
	deque<statementNode*>* statements;
	
  public:
	statementListNode();
	statementListNode(statementNode *s);
	void accept(CheckInterface *c, SymbolTable *ST);		
	void addStatement(statementNode *S);
	void destroyAST();
	void printVal();
	deque<CFG*>* buildCFG();
};

#endif

