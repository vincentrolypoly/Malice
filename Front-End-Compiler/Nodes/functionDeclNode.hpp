
#ifndef FUNCDECLNODE_H
#define FUNCDECLNODE_H

#include "declNode.hpp"
#include <string>

class functionArgumentNode;
class bodyNode;
class typeNode;
class CheckInterface;
class SymbolTable;
class CFG;

using namespace std;

class functionDeclNode: public declNode {
  private:
	string functionName;
	functionArgumentNode *arguments;
	typeNode *returnType;
	bodyNode *body;

  public:
	functionDeclNode(string name, typeNode *r, bodyNode *b, functionArgumentNode *a, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	functionArgumentNode* getArgs();
	typeNode* getReturnType();
	bodyNode *getBody();
	string getName();
	CFG* buildCFG();
};

#endif

