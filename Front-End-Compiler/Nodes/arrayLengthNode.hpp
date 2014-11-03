
#ifndef ARRLEN_HPP
#define ARRLEN_HPP

#include "ExpressionASTNode.hpp"
#include <string>

class checkInterface;
class SymbolTable;
class typeDeclNode;

using namespace std;

class arrayLengthNode: public ExpressionASTNode {
  private:
	typeDeclNode* arrDecl;
	string arrName;

  public:
	arrayLengthNode(string name, int line);
	void printVal();
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	int weight();
	int getLineNo();
	string getName();
	void setDeclto(typeDeclNode *decl);
	typeDeclNode* getDecl();
};

#endif

