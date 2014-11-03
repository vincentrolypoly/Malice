
#ifndef BODYNODE_H
#define BODYNODE_H

#include "statementNode.hpp"
class compoundStatement;
class declListNode;
class CheckInterface;
class SymbolTable;
class CFG;

class bodyNode: public statementNode {
  private:
	compoundStatement *body;
	declListNode *decls;
	
  public:
	bodyNode();
	bodyNode(compoundStatement *b, declListNode *d);
	void accept(CheckInterface *c, SymbolTable *ST);
	void destroyAST();
	void printVal();
	compoundStatement* getBody();
	declListNode* getDecls();
	CFG *buildCFG();
};

#endif

