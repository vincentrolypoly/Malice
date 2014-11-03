
#include "callNode.hpp"
#include "actualParamsNode.hpp"
#include "functionDeclNode.hpp"
#include <iostream>
#include "../CFG.hpp"
#include "../checkInterface.hpp"

callNode::callNode(string name, actualParamsNode *p, int line) {
	callName = name;
	actualParams = p;
	lineNo = line;
	callTo = NULL;
}
        
void callNode::printVal() {
	cout<<"call name:" << callName <<endl;
	cout<<"params:";
	actualParams->printVal();			
	cout<<endl;
}

void callNode::setCallTo(functionDeclNode* f){
	callTo = f;
}

functionDeclNode* callNode::getCallTo(){
	return callTo;
}
     
actualParamsNode* callNode::getParams() {
	return actualParams;
}
        
void callNode::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}
        
string callNode::getName() {
	return callName;
}
        
void callNode::destroyAST() {
	actualParams->destroyAST();
	delete actualParams;
}

int callNode::weight(){
	//Always do calls first
	return 10000;
}

