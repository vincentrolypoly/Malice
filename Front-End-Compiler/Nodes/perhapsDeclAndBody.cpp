
#include "perhapsDeclAndBody.hpp"
#include "typeDeclNode.hpp" //CHANGE THIS
#include "statementListNode.hpp"
#include "../CFG.hpp"
#include "../checkInterface.hpp"
#include "../symbolTable.hpp"
#include <iostream>
using namespace std;
perhapsDeclAndBody::perhapsDeclAndBody() { }
      
perhapsDeclAndBody::perhapsDeclAndBody(typeDeclNode *d, statementListNode *s) {
	decl = d;
	stats = s;
}
   
void perhapsDeclAndBody::accept(CheckInterface *c, SymbolTable *ST) {
	ST = new SymbolTable(ST);
	c->check(this, ST);
}
   
void perhapsDeclAndBody::destroyAST() {
	if(decl)
	decl->destroyAST();
	stats->destroyAST();
	delete decl;
	delete stats;
}
   
void perhapsDeclAndBody::printVal() {
	cout<< "body of if statement node" << endl;
}
   
statementListNode* perhapsDeclAndBody::getBody() {
	return stats;
}
   
typeDeclNode* perhapsDeclAndBody::getDecls() {
	return decl;
}
   
CFG* perhapsDeclAndBody::buildCFG() {
	CFG* c = new CFG(this);
	CFG* top = c;
	deque<CFG*>* statCFG = stats->buildCFG();
	deque<CFG*>:: iterator cit;
	for(cit = statCFG->begin(); cit < statCFG->end(); cit++) {
		c->addChild((*cit));
		c = (*cit)->getToBottom();
	} 
	return top;
}

