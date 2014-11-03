
#ifndef WHATWASNODE_H
#define WHATWASNODE_H

#include "statementNode.hpp"
class CheckInterface;
class SymbolTable;
class variableASTNode;
class CFG;

class whatWasNode: public statementNode {
  private:
	variableASTNode *store;
	
  public:
	whatWasNode(variableASTNode *s, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	variableASTNode* getStore();
	CFG* buildCFG();
};

#endif

