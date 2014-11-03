
#include "branchingNode.hpp"
#include "ExpressionASTNode.hpp"
#include "statementListNode.hpp"
#include "../CFG.hpp"
#include "../checkInterface.hpp"
branchingNode::branchingNode(ExpressionASTNode *e, statementListNode *b, int line) {
	expr = e;
	body = b;
	lineNo = line;
}

void branchingNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}
	
void branchingNode::destroyAST() {
	if(expr)
	expr->destroyAST();
	body->destroyAST();
	delete expr;
	delete body;
}
	
void branchingNode::printVal() {
	if(expr != NULL)
	expr->printVal();
}
	
ExpressionASTNode* branchingNode::getExpr() {
	return expr;
}
	
statementListNode* branchingNode::getBody() {
	return body;			
}
	
deque<CFG*>* branchingNode::buildCFG() {
	return body->buildCFG();
}

