
#ifndef CALLNODE_H
#define CALLNODE_H

#include "valNode.hpp"
#include <string>
class actualParamsNode;
class CheckInterface;
class SymbolTable;
class functionDeclNode;
class CFG;
using namespace std;


class callNode: public valNode {
  private:
	string callName;
	actualParamsNode *actualParams;
	functionDeclNode *callTo;
        
  public:
	callNode(string name, actualParamsNode *p, int line);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void destroyAST();
	void setCallTo(functionDeclNode* f);
	functionDeclNode* getCallTo();
	void printVal();
	actualParamsNode* getParams();
	string getName();
	int weight();
};

#endif

