#ifndef CFG_CPP
#define CFG_CPP

#include "CFG.hpp"

CFG::CFG(ASTNodes* stat) {
	statement = stat;
	children = new deque<CFG*>(); 
}

CFG::~CFG(){
	if(children) {
		deque<CFG*>::iterator it;
		for(it = children->begin(); it<children->end();it++) {
			if(*it)			
			delete(*it);
			//Since children can have multiple parents, this is seg faulting		
		}

		delete children;
	}
}

void CFG::addChild(CFG* c) {
	children->push_back(c);
}

deque<CFG*>* CFG::getChildren() {
	return children;
}

ASTNodes* CFG::getStatement() {
	return statement;
}

CFG* CFG::getToBottom() {
	//Assumes all branches lead to a single node
	CFG* walker = this;
	
	while(!(walker->getChildren()->empty())){
		walker = walker->getChildren()->front();
	}

    return walker;
}


#endif
