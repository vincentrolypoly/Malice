
#ifndef ARRDECLNODE_H
#define ARRDECLNODE_H

#include "typeDeclNode.hpp"
#include <string>
class typeNode;
class ExpressionASTNode;
class CheckInterface;
class SymbolTable;
using namespace std;
class arrDeclNode: public typeDeclNode {
  private:	
	bool spider;
	string name;
	typeNode *type;
	ExpressionASTNode *numberOfElems;
  
  public:
	arrDeclNode(string arrName, typeNode *t, ExpressionASTNode *n, bool sp, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	ExpressionASTNode *getSize();
	typeNode* getType();
	string getName();
	bool isSpider();
};

#endif

