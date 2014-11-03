
#ifndef FUNCARGUEMENTNODE_H
#define FUNCARGUEMENTNODE_H

#include "ASTNodes.hpp"
#include <deque>
class varDeclNode;
class CheckInterface;
class SymbolTable;
using namespace std;
class functionArgumentNode: public ASTNodes {
  private:	
	deque<varDeclNode*> *arguments;
	
  public:
	functionArgumentNode();
	functionArgumentNode(varDeclNode* arg);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void addArg(varDeclNode *arg);
	void destroyAST();
	void printVal();
	int getNumArgs();
	deque<varDeclNode*>* getActualArgs();
};

#endif

