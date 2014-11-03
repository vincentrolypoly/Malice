
#ifndef DECNODE_H
#define DECNODE_H

#include "statementNode.hpp"
class variableASTNode;
class CheckInterface;
class SymbolTable;
class CFG;

class decrementNode: public statementNode {
  private:
	variableASTNode *var;
	
  public:
	decrementNode(variableASTNode *v, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	variableASTNode *getVar();
	CFG* buildCFG();
};

#endif

