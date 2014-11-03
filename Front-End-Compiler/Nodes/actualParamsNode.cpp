
#include "actualParamsNode.hpp"
#include "ExpressionASTNode.hpp"

actualParamsNode::actualParamsNode() {
	actualParams = new deque<ExpressionASTNode*>();
}

actualParamsNode::actualParamsNode(ExpressionASTNode *param) {
	actualParams = new deque<ExpressionASTNode*>();
	addParams(param);
}

void actualParamsNode::accept(CheckInterface *c, SymbolTable *currentST) {
	deque<ExpressionASTNode*>::iterator it;
	for(it=actualParams->begin(); it < actualParams->end(); it++) {
		(*it)->accept(c,currentST);
	}
}
	
void actualParamsNode::addParams(ExpressionASTNode *param) {
	actualParams->push_front(param);
}
	
deque<ExpressionASTNode*>* actualParamsNode::getGivenParams() {
	return actualParams;
}
	
int actualParamsNode::getNumParams() {
	return (int) actualParams->size();
}

void actualParamsNode::destroyAST() {
	deque<ExpressionASTNode*>::iterator it;
	for(it=actualParams->begin(); it < actualParams->end(); it++) {
		(*it)->destroyAST();
		delete (*it);
	}
	
	delete actualParams;
}
	
void actualParamsNode::printVal() {
	deque<ExpressionASTNode*>::iterator it;
	for(it=actualParams->begin(); it < actualParams->end(); it++) {
		(*it)->printVal();
	}
}

