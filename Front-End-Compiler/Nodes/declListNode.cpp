
#include "declListNode.hpp"
#include "declNode.hpp"
#include <iostream>
#include "../checkInterface.hpp"

declListNode::declListNode() {
	declarations = new vector<declNode*>();
}
	
void declListNode::accept(CheckInterface *c, SymbolTable *currentST) {
	vector<declNode*>::iterator it;
	for(it=declarations->begin(); it < declarations->end(); it++) {
		(*it)->accept(c, currentST);
	}
}

void declListNode::addChild(declNode *child) {
	declarations->push_back(child);
}
	
void declListNode::destroyAST() {
	vector<declNode*>::iterator it;
	for(it=declarations->begin(); it < declarations->end(); it++) {
		(*it)->destroyAST();
		delete (*it);
	}
	
    delete declarations;
}
	
   void declListNode::printVal() {
	cout << "Children of declListNode" << endl;
	vector<declNode*>::iterator it;
	for(it=declarations->begin(); it < declarations->end(); it++) {
		(*it)->printVal();
	}
	
	cout << endl;
}

