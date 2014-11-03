
#ifndef CALLNODESTAT_H
#define CALLNODESTAT_H

#include "statementNode.hpp"
#include <string>
class actualParamsNode;
class CheckInterface;
class SymbolTable;
class CFG;
using namespace std;

class callNodeStatement: public statementNode {
  private:
	string callName;
	actualParamsNode *actualParams;
  public:
	callNodeStatement(string name, actualParamsNode *p, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void printVal();
	actualParamsNode* getParams();
	string getName();
	CFG* buildCFG();
};

#endif

