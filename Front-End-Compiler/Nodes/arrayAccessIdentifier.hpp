
#ifndef ARRAYIDENT_H
#define ARRAYIDENT_H

#include "variableASTNode.hpp"
#include <string>
class CheckInterface;
class ExpressionASTNode;
class SymbolTable;
class typeDeclNode;
using namespace std;
class arrayAccessIdentifier: public variableASTNode {
  private:
	string arrayName;
	ExpressionASTNode *elementAccess;
	typeDeclNode* decl;
	
  public:
	arrayAccessIdentifier(string n, ExpressionASTNode *e, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	ExpressionASTNode* getExpr();
	string getName();
	typeDeclNode* getDecl();
	void setDecl(typeDeclNode* d);
	int weight();
};


#endif
