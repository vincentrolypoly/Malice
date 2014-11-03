
#ifndef SENTENCEASTNODE_H
#define SENTENCEASTNODE_H

#include "valNode.hpp"
#include <string>
class sentenceTypeNode;
class CheckInterface;
class SymbolTable;
class typeNode;
using namespace std;
class sentenceASTNode: public valNode {
  private:
	sentenceTypeNode *type;
	string value;
    
  public:
	sentenceASTNode(string s);
	void accept(CheckInterface *c, SymbolTable *s);
	void destroyAST();
	void printVal();
    string getValue();
	typeNode* getType();
	int weight();
};

#endif

