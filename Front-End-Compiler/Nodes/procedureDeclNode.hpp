
#ifndef PROCDECLNODE_H
#define PROCDECLNODE_H

#include "declNode.hpp"
#include <string>
class functionArgumentNode;
class bodyNode;
class CheckInterface;
class SymbolTable;
class CFG;

using namespace std;
class procedureDeclNode: public declNode {
  private:
	string functionName;
	functionArgumentNode *arguments;
	bodyNode *body;
       
  public:
	procedureDeclNode(string name, bodyNode *b, functionArgumentNode *a, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	functionArgumentNode* getArgs();
	bodyNode *getBody();
	string getName();
	CFG* buildCFG();
};

#endif

