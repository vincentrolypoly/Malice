
#ifndef VARDECLNODE_H
#define VARDECLNODE_H

#include "typeDeclNode.hpp"
#include <string>

class typeNode;
class CheckInterface;
class SymbolTable;
class ExpressionASTNode;

using namespace std;

class varDeclNode: public typeDeclNode { 
  private:	
	bool spider;
	bool constant;
	string name;
	typeNode *type; 
	ExpressionASTNode *value; 

  public:
	varDeclNode(string varName, typeNode *t, ExpressionASTNode *e, bool forever, bool sp, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);	
	void destroyAST();
	void printVal();
	ExpressionASTNode* getValue();
	typeNode* getType();
    string getName();
	bool isConst();
	void switchConst();
	bool isSpider();
};

#endif

