
#ifndef STATDECLNODE_H
#define STATDECLNODE_H

#include "statementNode.hpp"
class typeDeclNode; //CHANGE THIS!
class statementListNode;
class CFG;
class CheckInterface;
class SymbolTable;

class perhapsDeclAndBody: public statementNode {
  private:
	typeDeclNode *decl;
	statementListNode *stats;
    
  public:
	perhapsDeclAndBody();
	perhapsDeclAndBody(typeDeclNode *d, statementListNode *s);
	void accept(CheckInterface *c, SymbolTable *ST);
	void destroyAST();
	void printVal();
	statementListNode *getBody();
	typeDeclNode *getDecls();
	CFG* buildCFG();
};

#endif

