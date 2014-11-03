
#ifndef TYPENODE_H
#define TYPENODE_H

#include "ASTNodes.hpp"
#include <string>

using namespace std;

class typeNode: public ASTNodes {
  protected:
	string typeName;
    
  public:
    string getTypeName();    
	void accept(CheckInterface *c, SymbolTable *currentST)=0;
	void destroyAST()=0;
	void printVal() = 0;
};

#endif

