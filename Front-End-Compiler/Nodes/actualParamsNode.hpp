
#ifndef ACTUALPARAMSNODE_H
#define ACTUALPARAMSNODE_H

#include "ASTNodes.hpp"
#include <deque>
using namespace std;
class ExpressionASTNode;
class CheckInterface;
class SymbolTable;
class actualParamsNode: public ASTNodes {
  private:
	deque<ExpressionASTNode*>* actualParams;
	
  public:
	actualParamsNode();
	actualParamsNode(ExpressionASTNode *param);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void addParams(ExpressionASTNode *param);
	void destroyAST();
	void printVal();
	int getNumParams();
	deque<ExpressionASTNode*>* getGivenParams();
};

#endif

