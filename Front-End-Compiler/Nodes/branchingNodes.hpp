
#ifndef BRANCHINGNODES_H
#define BRANCHINGNODES_H

#include "ASTNodes.hpp"
#include <deque>
class CFG;
class branchingNode;
class CheckInterface;
class SymbolTable;


using namespace std;

class branchingNodes: public ASTNodes {
  private:
	deque<branchingNode*>* others;
	
  public:
	branchingNodes();
	branchingNodes(branchingNode *branch);
	void accept(CheckInterface *c, SymbolTable *currentST);
	void addBranch(branchingNode *branch);
	void destroyAST();
	void printVal();
	deque<branchingNode*>* getBranches();
	deque<deque<CFG*>*>* buildCFG();
};

#endif

