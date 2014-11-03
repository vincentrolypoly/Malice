
#ifndef ASTNODES_H
#define ASTNODES_H

class CheckInterface;
class SymbolTable;

class ASTNodes {
  protected:
	int lineNo;
	
  public:

    virtual void printVal()=0;
    virtual void accept(CheckInterface *c, SymbolTable *currentST)=0;
    virtual void destroyAST()=0;
    int getLineNo();
};

#endif

