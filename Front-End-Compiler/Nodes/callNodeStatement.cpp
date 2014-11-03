
#include "callNodeStatement.hpp"
#include "actualParamsNode.hpp"
#include <iostream>
#include "../CFG.hpp"
#include "../checkInterface.hpp"

callNodeStatement::callNodeStatement(string name, actualParamsNode *p, int line) {
	callName = name;
	actualParams = p;
	lineNo = line;
}
	
void callNodeStatement::accept(CheckInterface *c, SymbolTable *currentST) {
	c->check(this, currentST);
}


void callNodeStatement::destroyAST() {
    actualParams->destroyAST();
	delete actualParams;
}
	
void callNodeStatement::printVal() {
	cout<<"call name:" << callName <<endl;
	cout<<"params:";
	actualParams->printVal();			
	cout<<endl;
}
	
actualParamsNode* callNodeStatement::getParams() {
	return actualParams;
}
	
string callNodeStatement::getName() {
	return callName;
}
	
CFG* callNodeStatement::buildCFG() {
	return new CFG(this);
}

