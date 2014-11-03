
#ifndef COMPOUNDSTAT_H
#define COMPOUNDSTAT_H

#include "ASTNodes.hpp"
#include <vector>
class CheckInterface;
class SymbolTable;
class statementListNode;
class CFG;
using namespace std;
class compoundStatement: public ASTNodes {
  private:
	vector<statementListNode*>* body;
	
  public:
	compoundStatement();
	compoundStatement(statementListNode *SL);
	void accept(CheckInterface *c, SymbolTable *ST);
	void addStatementList( statementListNode *SL);
	void destroyAST();
	void printVal();
	CFG *buildCFG();
};

#endif

