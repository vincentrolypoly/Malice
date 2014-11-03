
#include "unaryExpressionASTNode.hpp"
#include "../checkInterface.hpp"
unaryExpressionASTNode::unaryExpressionASTNode(ExpressionASTNode *e, unaryOp o, int line) {
	op = o;
	expression = e;
	lineNo = line;
}
        
void unaryExpressionASTNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
} 
        
void unaryExpressionASTNode::destroyAST() {
	expression->destroyAST();
	delete expression;
}
        
void unaryExpressionASTNode::printVal() {
	expression->printVal();
}
        
ExpressionASTNode* unaryExpressionASTNode::getExpr() {
	return expression;
}
        
unaryOp unaryExpressionASTNode::getOp() {
	return op;
}
int unaryExpressionASTNode::weight(){
	return expression->weight();
}

