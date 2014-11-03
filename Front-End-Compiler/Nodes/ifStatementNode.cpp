
#include "ifStatementNode.hpp"
#include "ExpressionASTNode.hpp"
#include "statementListNode.hpp"
#include "branchingNodes.hpp"
#include "../CFG.hpp"
#include "../checkInterface.hpp"
#include <iostream>
using namespace std;
ifStatementNode::ifStatementNode(ExpressionASTNode *e, statementListNode *b, branchingNodes* o, int line) {
	others = o;
	expr = e;
	body = b;			
	lineNo = line;
}
	
void ifStatementNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}
	
void ifStatementNode::destroyAST() {
	expr->destroyAST();
	body->destroyAST();
	others->destroyAST();
	delete expr;
	delete body;
	delete others;
}
	
void ifStatementNode::printVal() {
	cout<< "if statement node" << endl;
	expr->printVal();
	others->printVal();
}
	
ExpressionASTNode* ifStatementNode::getExpr() {
	return expr;
}
	
statementListNode* ifStatementNode::getBody() {
	return body;
}
	
branchingNodes* ifStatementNode::getOthers() {
	return others;
}
		
CFG* ifStatementNode::buildCFG() {
	deque<CFG*>* myBranch = body->buildCFG();
	CFG* c = new CFG(this);
	CFG* top = c;
	deque<CFG*>::iterator it;

	for(it=myBranch->begin(); it < myBranch->end(); it++) {
		c->addChild((*it));
		c = (*it)->getToBottom();
	}
     		
	CFG* bottom = new CFG(NULL);
	c->addChild(bottom);
	deque<deque<CFG*>*>* otherBranches = others->buildCFG();
	deque<deque<CFG*>*>::iterator oIt;
	for(oIt = otherBranches->begin(); oIt < otherBranches->end(); oIt++) {
		CFG* currPos =  top;
		for(it = (*oIt)->begin(); it < (*oIt)->end(); it++){
			
			currPos->addChild((*it));
			currPos = (*it)->getToBottom();
		}
		currPos->addChild(bottom);				
	}
	return top;
}	

