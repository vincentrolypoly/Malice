
#ifndef IDENTASTNODE_H
#define IDENTASTNODE_H

#include "variableASTNode.hpp"
#include <string>
class CheckInterface;
class SymbolTable;
class vartypeDeclNode;
using namespace std;
class identifierASTNode: public variableASTNode {
  private:
	string name;
	typeDeclNode* decl;
  public:
	identifierASTNode(string nameOfVar, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void printVal();
	void destroyAST();	
	void setDecl(typeDeclNode* d);
	typeDeclNode* getDecl();
	string getName();
	int weight();
};

#endif

