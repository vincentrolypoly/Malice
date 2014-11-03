
#include "functionArgumentNode.hpp"
#include "varDeclNode.hpp"
functionArgumentNode::functionArgumentNode() {
	arguments = new deque<varDeclNode*>();
}
	
functionArgumentNode::functionArgumentNode(varDeclNode* arg) {
	arguments = new deque<varDeclNode*>();
	addArg(arg);
}

void functionArgumentNode::accept(CheckInterface *c, SymbolTable *currentST) {
	deque<varDeclNode*>::iterator it;
	for(it=arguments->begin(); it < arguments->end(); it++) {
		(*it)->accept(c,currentST);
	}
}
	
void functionArgumentNode::addArg(varDeclNode *arg) {
	arguments->push_front(arg);
}
	
void functionArgumentNode::destroyAST() {
	deque<varDeclNode*>::iterator it;
	for(it=arguments->begin(); it < arguments->end(); it++) {
		(*it)->destroyAST();
		delete (*it);
	}
		
	delete arguments;
}
	
int functionArgumentNode::getNumArgs() {
	return (int) arguments->size();
}

void functionArgumentNode::printVal() {
	deque<varDeclNode*>::iterator it;
	for(it=arguments->begin(); it < arguments->end(); it++) {
		(*it)->printVal();
	}
}
	
deque<varDeclNode*>* functionArgumentNode::getActualArgs() {
	return arguments;
}

