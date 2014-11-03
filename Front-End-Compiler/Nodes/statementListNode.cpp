
#include "statementListNode.hpp"
#include "../CFG.hpp"
#include "statementNode.hpp"
statementListNode::statementListNode() {	
	statements = new deque<statementNode*>();
}
	
statementListNode::statementListNode(statementNode *s) {	
	statements = new deque<statementNode*>();
	addStatement(s);
}

void statementListNode::accept(CheckInterface *c, SymbolTable *ST) {
	deque<statementNode*>::iterator it;
	for(it=statements->begin(); it < statements->end(); it++) {
		if(*it)
		(*it)->accept(c,ST);
	}
}

void statementListNode::addStatement(statementNode *S) {
	if(S)
	statements->push_front(S);
}
	
void statementListNode::destroyAST() {
	deque<statementNode*>::iterator it;
	for(it=statements->begin(); it < statements->end(); it++) {
		if(*it)
		(*it)->destroyAST();
		delete(*it);
	}
		
	delete statements;
}
	
void statementListNode::printVal() {
 	deque<statementNode*>::iterator it;
	for(it=statements->begin(); it < statements->end(); it++) {
		(*it)->printVal();
	}
}
	
deque<CFG*>* statementListNode::buildCFG() {
    deque<CFG*>* c = new deque<CFG*>();
    deque<statementNode*>::iterator it;
    for( it=statements->begin(); it < statements->end(); it++) {
	    if(*it)
	    c->push_back((*it)->buildCFG());
	}
		
    return c;
}

