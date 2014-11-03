
#ifndef DECLLISTNODE_H
#define DECLLISTNODE_H

#include "ASTNodes.hpp"
class CheckInterface;
class SymbolTable;
class declNode;
#include <vector>
using namespace std;

class declListNode: public ASTNodes {
  private:
	vector<declNode*>* declarations;
	
  public:
    declListNode();
	void accept(CheckInterface *c, SymbolTable *currentST);
	void addChild(declNode *child);
	void destroyAST();
    void printVal();
};

#endif

