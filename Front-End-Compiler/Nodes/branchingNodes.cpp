
#include "branchingNodes.hpp"
#include "branchingNode.hpp"
#include "../checkInterface.hpp"
#include "../CFG.hpp"

branchingNodes::branchingNodes() {
	others = new deque<branchingNode*>();
}
	
branchingNodes::branchingNodes(branchingNode *branch) {
	others = new deque<branchingNode*>();
	addBranch(branch);
}

void branchingNodes::accept(CheckInterface *c, SymbolTable *currentST) {
	deque<branchingNode*>::iterator it;
	for(it=others->begin(); it < others->end(); it++) {
		(*it)->accept(c,currentST);
	}
}

void branchingNodes::addBranch(branchingNode *branch) {
	others->push_front(branch);
}
	
void branchingNodes::destroyAST() {
	deque<branchingNode*>::iterator it;
	for(it=others->begin(); it < others->end(); it++) {
		(*it)->destroyAST();
		delete(*it);
    }
    
	delete others;
}
deque<branchingNode*>* branchingNodes::getBranches(){
	return others;
}
void branchingNodes::printVal() {
	deque<branchingNode*>::iterator it;
	for(it=others->begin(); it < others->end(); it++) {
		(*it)->printVal();
	}
}
		
deque<deque<CFG*>*>* branchingNodes::buildCFG() {
	deque<deque<CFG*>*>* c = new deque<deque<CFG*>*>();
	deque<branchingNode*>::iterator it;
	for(it=others->begin(); it < others->end(); it++) {
		c->push_back((*it)->buildCFG());
	}
	return c;
}

