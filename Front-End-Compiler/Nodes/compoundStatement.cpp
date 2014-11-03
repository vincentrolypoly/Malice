
#include "compoundStatement.hpp"
#include "statementListNode.hpp"
#include "../checkInterface.hpp"
#include "../CFG.hpp"

compoundStatement::compoundStatement() {
	body = new vector<statementListNode*>();
}
	
compoundStatement::compoundStatement(statementListNode *SL) {
	body = new vector<statementListNode*>();
	addStatementList(SL);
}
	
void compoundStatement::accept(CheckInterface *c, SymbolTable *ST) {
	vector<statementListNode*>::iterator it;
	for(it=body->begin(); it < body->end(); it++){
		(*it)->accept(c,ST);
	}
}
	
void compoundStatement::addStatementList( statementListNode *SL) {
	body->push_back(SL);
}
	
void compoundStatement::destroyAST() {
	vector<statementListNode*>::iterator it;
	for(it=body->begin(); it < body->end(); it++){
		(*it)->destroyAST();
		delete(*it);
	}
	delete body;
}
	
void compoundStatement::printVal() {
    vector<statementListNode*>::iterator it;
	for(it=body->begin(); it < body->end(); it++){
		(*it)->printVal();
	}
}
	
CFG* compoundStatement::buildCFG() {
	CFG* c = new CFG(this);
	CFG* top = c;
	vector<statementListNode*>::iterator it;
	for(it=body->begin(); it < body->end(); it++){
		deque<CFG*>* child = (*it)->buildCFG();
		deque<CFG*>:: iterator cit;
		for (cit = child->begin(); cit < child->end(); cit++){
			c->addChild((*cit));
			c = (*cit)->getToBottom();
		} 
	}
		
	return top;
}

