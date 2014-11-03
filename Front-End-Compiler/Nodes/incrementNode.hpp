
#ifndef INCNODE_H
#define INCNODE_H

#include "statementNode.hpp"
class CheckInterface;
class SymbolTable;
class variableASTNode;
class CFG;

class incrementNode: public statementNode {
  private:
	variableASTNode *var;
	
  public:
	incrementNode(variableASTNode *v, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	variableASTNode* getVar();
	CFG* buildCFG();
};

#endif

