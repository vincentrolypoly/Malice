
#ifndef CFG_H
#define CFG_H

#include "Nodes/ASTNodes.hpp"

#include <stdlib.h>
#include <deque>
#include <typeinfo>


using namespace std;

class CFG{
  private:
	deque<CFG*>* children;
	ASTNodes* statement;
       
  public:
	CFG(ASTNodes* stat);
	~CFG();
	void addChild(CFG* c);
	deque<CFG*>* getChildren();
   	ASTNodes* getStatement();
	CFG* getToBottom();
};


#endif
