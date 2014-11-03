
#include "binaryExpressionASTNode.hpp"
#include "../checkInterface.hpp"
#include <algorithm>
binaryExpressionASTNode::binaryExpressionASTNode(ExpressionASTNode *l, ExpressionASTNode *r, binaryOp o, int line) {
	left = l;
	right = r;
    op = o;		
	lineNo = line;
} 
        
void binaryExpressionASTNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}
        
void binaryExpressionASTNode::destroyAST() {
	left->destroyAST();
	right->destroyAST();
	delete left;
	delete right;
}
        
void binaryExpressionASTNode::printVal() {
	left->printVal();
	right->printVal();
}
        
ExpressionASTNode* binaryExpressionASTNode::getRight() {
	return right;
} 
        
ExpressionASTNode* binaryExpressionASTNode::getLeft() {
	return left;
}

binaryOp binaryExpressionASTNode::getOp() {
	return op;
}

int binaryExpressionASTNode::weight(){
	int cost1 = max(left->weight(), right->weight()+1);
	int cost2 = max(left->weight()+1, right->weight());
	return min(cost1,cost2);
}
