	

#include "codeGenerator.hpp"
#include "../Front-End-Compiler/ASTAll.hpp"
#include "../Front-End-Compiler/symbolTable.hpp"
#include <deque>
#include "../Front-End-Compiler/auxillaryMethods.hpp"
#include "AllCodeGenNodes.hpp"
#include <sstream>

/*NOTES
* works for all tests
* need to implement register management using weighted trees
* need to implement something for when we run out of registers
* idea for extension: adding for-loops (VBA style) (-identifier- counted from 0 to 100)
* 					: adding in constants (x became a number of 10 forever)
*					: adding in ability to get array size (x became as long as arr)
* need to add run-time checks
*/

codeGenerator::codeGenerator(char* f){
	fileName = f;
	regAvail = new deque<string>();
	allRegs = new deque<string>();
	instr = new deque<IA32Nodes*>();
	global = new deque<IA32Nodes*>();
	addRegs();
	wordSize = 8;
	currentScope = new codeGenEnv(NULL); //Used to store variable names to addresses
	loopCounter = 0;
	stringCounter = 0;
	ifCounter = 0;
	elseCounter = 0;
	boolCounter = 0;
	currentScope->add("string", "string",0);
	currentScope->add("integer", "integer",0);
	currentScope->add("char", "char",0);
	decls = new deque<IA32Nodes*>();
	decls->push_front(new segmentNode("bss"));
	funcStack = new deque<deque<IA32Nodes*>*>();
	scopeCounter = 0;
	emptyDummy = new functionArgumentNode();
}

//Adds intermediate nodes to the current deque of instructions
void codeGenerator::add(IA32Nodes* n){
	instr->push_back(n);
}

//Gets current loopCount and increments
int codeGenerator::nextLoopCount(){
	int temp = loopCounter;
	loopCounter++;
	return temp;
}

//Gets the current elseCount and increments
int codeGenerator::nextElseCount(){
	int temp = elseCounter;
	elseCounter++;
	return temp;
}

//Gets the next stringCount and increments
int codeGenerator::nextStringCount(){
	int temp = stringCounter;
	stringCounter++;
	return temp;
}

//Gets the next ifCount and increments
int codeGenerator::nextIfCount(){
	int temp = ifCounter;
	ifCounter++;
	return temp;
}

//Gets the next boolCount and increments
int codeGenerator::nextBoolCounter(){
	int temp = boolCounter;
	boolCounter++;
	return temp;
}

void codeGenerator::clearMem(){
	delete(regAvail);
	delete(allRegs);
	deque<IA32Nodes*>::iterator it;
	for(it = instr->begin(); it != instr->end(); it++){
		delete(*it);
	}
	delete(instr);
	for(it = global->begin(); it != global->end(); it++){
		delete(*it);
	}
	delete(global);
	delete(currentScope);
	for(it = decls->begin(); it != decls->end(); it++){
		delete(*it);
	}
	delete(decls);
	//funcStack will be empty
	delete(funcStack);
	delete(emptyDummy);
		
}
//Post optimisation on intermediate nodes(removes useless statements such as "add rax 0"
void codeGenerator::postOptimise(){
	deque<IA32Nodes*>::iterator it;
	for(it = instr->begin(); it != instr->end(); it++){
		if((*it)->removable()){
			instr->erase(it);
		}
	}
		
	for(it = global->begin(); it != global->end(); it++){
		if((*it)->removable()){
			global->erase(it);
		}
	}
}

void combine(deque<IA32Nodes*>* newCode, deque<IA32Nodes*>* prevCode){
	while(newCode->back() != newCode->front()){
		prevCode->push_front(newCode->back());
		newCode->pop_back();
	}
	prevCode->push_front(newCode->back());
	newCode->pop_back();
}

//SET UP THE BEGINNING OF THE FILE
void codeGenerator::setUp(){
	file.open(fileName, fstream::app);
	file << "segment .text" << endl;
	file << "global main" << endl;
	file << "extern printf" << endl;
	file << "extern scanf" << endl;
	file << "extern malloc" << endl;
	file << "segment .data." << endl;
	file << "integer:" << endl;
	file << "	db " << "\"" << "%d" << "\"" << "," << "0 "<< endl;
	file << "string:" << endl;
	file << "	db " << "`%s`" << "," << "0 "<< endl;
    file << "char: " << endl;
    file << "   db " << "\"" << "%c" << "\"" << "," << "0 "<< endl;
	file << "scaninteger:" << endl;
	file << "	db " << "\"" << "%d" << "\"" << ", 0" <<  endl;
	file << "scanstring:" << endl;
	file << "	db " << "`" << "%[^\\n]%*c" << "` , 0" <<  endl;
    file << "scanchar: " << endl;
    file << "   db " << "\"" << "%c" << "\"" << endl;
	file.close();
}

//Prints list of Nodes into a file
void codeGenerator::printFile(){
	
	deque<IA32Nodes*>::iterator it;
	file.open(fileName, fstream::trunc);
	//.bss section
	for(it=decls->begin(); it<decls->end(); it++){
		file << (*it)->printSelf() << endl;
	} 
	file.close();
	//setup
	setUp();
	//global variable section
	file.open(fileName, fstream::app);
	for(it=global->begin(); it<global->end(); it++){
		file << (*it)->printSelf() << endl;
	}
	//body
	for(it=instr->begin(); it<instr->end(); it++){
		file << (*it)->printSelf() << endl;
	} 
	file.close();
}

void codeGenerator::returnToSystem(){
	file.open(fileName, fstream::app);
	file <<	"	mov  rax, 1	; Linux system call 1 : exit ()" << endl;
	file <<	"	mov  rbx, 0 ; Error code 0: no errors" << endl;		
	file <<	"	int  80H    ; Interrupt Linux Kernel"    << endl;	
	file.close();	
}

//Adds the list of registers we have to start with into the deque of available registers
void codeGenerator::addRegs(){
	//rax reserved
	regAvail->push_back("rbx");
	regAvail->push_back("rcx");
	//rdx reserved
	//rdi reserved
	//rsi reserved
	for(int i = 8 ; i < 16; i++){
		stringstream ss;
		ss << i;
		string reg = "R" + ss.str();
		regAvail->push_back(reg);
	}
	
	//List of all registers available
	allRegs->push_back("rbx");
	allRegs->push_back("rcx");
	for(int i = 8 ; i < 16; i++){
		stringstream s2;
		s2 << i;
		string reg = "R" + s2.str();
		allRegs->push_back(reg);
	}
}

//Returns true if the given register is inside the list of available registers
bool codeGenerator::isMember(string reg){
	deque<string>::iterator it;
	for(it=regAvail->begin(); it!= regAvail->end();it++){
		if((*it).compare(reg) == 0){
			return true;
		}
	}
	return false;
}

//Saves all the registers currently in use
void codeGenerator::saveRegs(){
	deque<string>::iterator it;
	for(it=allRegs->begin(); it!= allRegs->end(); it++){
		if(!isMember(*it)){
			add(new pushNode(*it));
		}
	}
}

//Restores all the registers that were saved
void codeGenerator::restoreRegs(){
	deque<string>::reverse_iterator it;
	for(it=allRegs->rbegin(); it!= allRegs->rend(); it++){
		if(!isMember(*it)){
			add(new popNode(*it));
		}
	}
}

//Generates code for an assignment statement
void codeGenerator::check(assignNode *n, SymbolTable *currentST){
	//Get LHS and RHS of assignment	
	variableASTNode* var = n->getLHS();
	ExpressionASTNode* b = n->getRHS();
	
	//Find where LHS variable is stored 
	string varBase = currentScope->searchEnclosingForBase(var->getName());
	int offset = currentScope->searchEnclosingForOffset(var->getName());
	stringstream ss;
	ss << offset;
	
	//Generate code for RHS
	string regExpr = regAvail->front();
	b->accept(this, currentST); //RHS stores its answer in regBase
	
	//Generate code for LHS
	string regVar = regAvail->front();
	var->accept(this, currentST); //LHS stores its answer in regVar

	//Variables on the RHS return an address so we look inside this address for the real value
	variableASTNode* RHS = dynamic_cast<variableASTNode*>(b);
	if(RHS != NULL){
		add(new moveNode(regExpr, "[" + regExpr +"]"));
	}

	add(new moveNode("[" +regVar+"]", " 0")); //CLEAR MEMORY BEFORE PUTTING ANYTHING 
	add(new moveNode("[" + regVar + "]", regExpr));
	
	//Put registers back onto the available list
	regAvail->push_front(regVar);
	regAvail->push_front(regExpr);
}

//Generate code for a return statement
void codeGenerator::check(returnNode *n, SymbolTable *currentST){
	//Generate code for the expression to be returned
	string regVal = regAvail->front();
	ExpressionASTNode* expr = n->getvalue();
	expr->accept(this, currentST);
	regAvail->push_front(regVal);
	
	//If expression is a variable we need to look inside the variable address	
	variableASTNode* var = dynamic_cast<variableASTNode*>(expr);
	if(var){
		add(new moveNode(regVal, "[" + regVal + "]"));
	}

	//Move answer into rax
	add(new xorNode("rax", "rax"));
	add(new moveNode("rax", regVal));
	add(new moveNode("rsp","rbp"));
	add(new popNode("rbp"));// restore stack pointers
	//Change base scope back
	add(new moveNode("[" + currentScope->getScopeLabel() + "]", "rbp"));
	add(new retNode());
}

//Generate code for an identifier
void codeGenerator::check(identifierASTNode *n, SymbolTable *currentST){
	//Find address of where variable is stored
	string baseAddress = currentScope->searchEnclosingForBase(n->getName()); 
	int offset = currentScope->searchEnclosingForOffset(n->getName());
	stringstream ss;
	ss << offset;

	//Store address of where variable is stored inside regVal
	string regVal = regAvail->front();
	regAvail->pop_front();
	add(new moveNode(regVal, baseAddress));
	add(new leaNode(regVal, "[" + regVal + "+" + ss.str()+ "]"));

}	

//Generate code for an increment statement
void codeGenerator::check(incrementNode *n, SymbolTable *currentST){
	variableASTNode* var = n->getVar();

	//Generate code to find where variable is stored
	string incReg = regAvail->front();
	var->accept(this, currentST);
	string reg = regAvail->front();

	//Look inside the address to get the real value
	add(new moveNode(reg, "[" + incReg + "]"));
	add(new incNode(reg));
	add(new moveNode("[" +incReg+"]", " 0")); //CLEAR MEMORY BEFORE PUTTING ANYTHING 
	add(new moveNode("[" + incReg + "]",reg)); //Put incremented value back into address
	regAvail->push_front(incReg);
	
}

//Generate code for array access
void codeGenerator::check(arrayAccessIdentifier *n, SymbolTable *currentST){
	//Find where pointer to top of the array is
	string baseAddress = currentScope->searchEnclosingForBase(n->getName());
	int offset = currentScope->searchEnclosingForOffset(n->getName());
	stringstream ss;
	ss << offset;
	
	string regVal = regAvail->front();
	regAvail->pop_front();
	typeDeclNode* decl = n->getDecl();

	//reg val has address to the address of top of array
	add(new moveNode(regVal, baseAddress));
	add(new moveNode(regVal, "[" + regVal + "+" + ss.str()+ "]")); 
	
	 //generate code for expression for index and store in regExpr
	string regExpr = regAvail->front();
	n->getExpr()->accept(this, currentST);
	variableASTNode* var = dynamic_cast<variableASTNode*>(n->getExpr());
	if(var){
		add(new moveNode(regExpr, "[" + regExpr + "]"));
	}

	 //increment it by 1 since first word is always size of array
	add(new incNode(regExpr));
	add(new imulNode(regExpr, "8"));
	//Add offset for where array element is stored relative to top address
	add(new addNode(regVal, regExpr));
	regAvail->push_front(regExpr);	
}

//Generate code to decrement
void codeGenerator::check(decrementNode *n, SymbolTable *currentST){
	variableASTNode* var = n->getVar();
	string reg  = regAvail->front();
		
	//Generate code to retrieve address of variable
	regAvail->pop_front();
	string decReg = regAvail->front();
	var->accept(this, currentST);

	//get actual value inside variable
	add(new moveNode(reg, "[" + decReg + "]"));
	add(new decNode(reg));
	add(new moveNode("[" +decReg+"]", " 0")); //CLEAR MEMORY BEFORE PUTTING ANYTHING 
	add(new moveNode("[" + decReg + "]",reg)); //store decremented variable back into address

	regAvail->push_front(decReg);
	regAvail->push_front(reg);
}

//Generate code for a body
void codeGenerator::check(bodyNode *n, SymbolTable *currentST){
	//create a new scope for variable environment	
	currentScope = new codeGenEnv(currentScope); 
	declListNode* decl = n->getDecls();
	compoundStatement* body = n->getBody();



	//Add new label for scope and and reserve space to store pointer to the base
	stringstream ss;
	ss << scopeCounter;
	currentScope->setScopeLabel("LC" + ss.str());
	decls->push_back(new resbNode(currentScope->getScopeLabel(),wordSize));
	
	//Save base and move to new scope
	add(new pushNode("rbp"));
	add(new moveNode("rbp","rsp"));
	add(new moveNode("[" + currentScope->getScopeLabel() + "]", "rbp"));
	scopeCounter++;
	
	//Add arguments to scope(if any)
	deque<varDeclNode*>* args = argBuffer->getActualArgs();
	deque<varDeclNode*>::iterator it;
	int argCounter = wordSize*2;
	for(it=args->begin(); it != args->end(); it++){
		currentScope->add((*it)->getName(), "[" + currentScope->getScopeLabel()+"]", (argCounter));
		argCounter+=wordSize;
	}
	
	//Empty the arguments for the scope
	argBuffer = emptyDummy;
	
	//Generate code for declarations and body of the body
	if(decl)
		decl->accept(this,currentST);	
	if(body)
		body->accept(this, currentST);
	
	//restore stack pointers
	add(new moveNode("rsp", "rbp"));
	add(new popNode("rbp"));
	//restore base scope
	add(new moveNode("[" + currentScope->getScopeLabel() + "]", "rbp"));

	//Return to previous scope
	codeGenEnv* toDelete = currentScope;
	if(currentScope)
		currentScope = currentScope->getPrevScope(); 
	delete(toDelete);//Scope no longer needed
}

//Generate code for a call Node
void codeGenerator::check(callNode *n, SymbolTable *currentST){
	string regVal            = regAvail->front();
	actualParamsNode* params = n->getParams();

	deque<ExpressionASTNode*>* givenParams = params->getGivenParams();
	deque<ExpressionASTNode*>::reverse_iterator rit;
	variableASTNode* var;
	//Save registers before call
	saveRegs();
	//Push arguments onto the stack
	for(rit=givenParams->rbegin();rit < givenParams->rend(); rit++) {
		(*rit)->accept(this,currentST);
		var = dynamic_cast<variableASTNode*>(*rit);
		if(var){
			add(new moveNode(regVal, "[" + regVal + "]"));			
		}

		add(new pushNode(regVal));
		regAvail->push_front(regVal);
	} 
	
	//Call function
	add(new callerNode(	currentScope->searchEnclosingForBase(n->getName())));	
	int usedStackSize = givenParams->size() * wordSize;
	stringstream ss;
	ss << usedStackSize;
	//Take off the arguments from the stack
	add(new addNode("rsp", ss.str()));
	//Restore registers
	restoreRegs();
	//move answer into first register
	add(new moveNode(regVal , "rax"));
	regAvail->pop_front();
}

//Generate code for a call node statement
void codeGenerator::check(callNodeStatement *n, SymbolTable *currentST){
	string regVal            = regAvail->front();
	actualParamsNode* params = n->getParams();

	deque<ExpressionASTNode*>* givenParams = params->getGivenParams();
	deque<ExpressionASTNode*>::reverse_iterator rit;
	variableASTNode* var;
	//Save registers before call
	saveRegs();
	
	//Push arguments onto stack
	for(rit=givenParams->rbegin();rit < givenParams->rend(); rit++) {
		(*rit)->accept(this,currentST);
		var = dynamic_cast<variableASTNode*>(*rit);
		if(var){			
			add(new moveNode(regVal, "[" + regVal + "]"));
		}

		add(new pushNode(regVal));
		regAvail->push_front(regVal);
	}
 	
	//Call procedure
	add(new callerNode(	currentScope->searchEnclosingForBase(n->getName())));
	int usedStackSize = givenParams->size() * wordSize;
	stringstream ss;
	ss << usedStackSize;
	//Take arguments off stack
	add(new addNode("rsp", ss.str()));
	//Restore registers
	restoreRegs();
}

//Generate code to declare a variable
void codeGenerator::check(varDeclNode *n, SymbolTable *currentST){
	//look for n being declared already in enclosing scopes
	//if not declared in enclosing scopes, define global variable and add to env
	//else push current value of variable onto stack and change global variable to updated variable
	ExpressionASTNode* val = n->getValue();
	stringstream ss;
	ss << wordSize;
	
	//Global Scope
	if(currentScope->getScopeLevel() == 0){
		currentScope->incVarCount();
		string baseLabel = currentScope->getScopeLabel();
		int relativeBase = currentScope->getVarCount() * wordSize * -1;	
		currentScope->add(n->getName(), "[" + baseLabel + "]", relativeBase); //work out relative address and add to env 
		funcStack->push_front(instr); //save current deque nodes
		instr = global; //change deque nodes to global
		
		//Work out initial value if it has one otherwise just reserve space on the stack
		if(val){
				string regVal = regAvail->front();
				val->accept(this,currentST);//generate code for value
				variableASTNode* var = dynamic_cast<variableASTNode*>(val);
				if(var){
					(new moveNode(regVal, "[" + regVal + "]"));
				}
				stringstream sss;
				sss << relativeBase;
				add(new pushNode(regVal));				
				regAvail->push_front(regVal);
		}else{
				add(new subNode("rsp" , ss.str()));
		}
		deque<IA32Nodes*>* front = funcStack->front(); //front is all the code generated previously
		funcStack->pop_front();
		instr = front; //restore original deque nodes

	}else{
		//local scope
		currentScope->incVarCount();
		string baseLabel = currentScope->getScopeLabel();
		int relativeBase = currentScope->getVarCount() * wordSize * -1;	
		currentScope->add(n->getName(), "[" + baseLabel + "]", relativeBase); //work out relative address and add to env 
		//Work out initial value if it has one otherwise just reserve space on the stack
		if(val){
				string regVal = regAvail->front();
				val->accept(this,currentST);//generate code for value
				variableASTNode* var = dynamic_cast<variableASTNode*>(val);
				if(var){
					add(new moveNode(regVal, "[" + regVal + "]"));
				}
				stringstream sss;
				sss << relativeBase;
				add(new pushNode(regVal));	
				regAvail->push_front(regVal);			
		}else{
				add(new subNode("rsp" , ss.str())); //reserve space on stack for variable
		}
	}	
}

//generate code for array declaration
void codeGenerator::check(arrDeclNode *n, SymbolTable *currentST){
	ExpressionASTNode* val = n->getSize();
	string regVal = regAvail->front();
	
	stringstream ss;
	ss << wordSize;
	string memPointer;
	variableASTNode* var = dynamic_cast<variableASTNode*>(val);	
	
	//Global Scope
	if(currentScope->getScopeLevel() == 0){
		funcStack->push_front(instr);
		instr = global;
		val->accept(this,currentST);
		if(var){
			global->push_back(new moveNode( regVal, "[" + regVal + "]"));
		}
		saveRegs();
		global->push_back(new moveNode("rdi", regVal));
		global->push_back(new addNode("rdi", "1")); //Add an extra space to store array length
		global->push_back(new imulNode("rdi", ss.str()));
		global->push_back(new pushNode("rax"));
		global->push_back(new xorNode("rax", "rax"));
		global->push_back(new callerNode("malloc"));
		restoreRegs();
		//New register to store pointer to top of array
		memPointer = regAvail->front();
		regAvail->pop_front();
		global->push_back(new moveNode(memPointer, "rax"));
		global->push_back(new popNode("rax"));
		global->push_back(new pushNode(memPointer ));
	
		//Move length calculated in rax into top of address		
		global->push_back(new moveNode("[" + memPointer + "]", regVal)); //memPoitner has address to the address of top of arra
		deque<IA32Nodes*>* front = funcStack->front(); //front is all the code generated previously
		funcStack->pop_front();
		instr = front;
	}else{
		//local scope
		val->accept(this,currentST);
		if(var){
			add(new moveNode( regVal, "[" + regVal + "]"));
		}
		saveRegs();
		add(new moveNode("rdi", regVal));	
		add(new addNode("rdi", "1")); //Add an extra space to store array length
		add(new imulNode("rdi", ss.str()));
		add(new pushNode("rax"));
		add(new xorNode("rax", "rax"));
		add(new callerNode("malloc"));
		restoreRegs();
		memPointer = regAvail->front();
		regAvail->pop_front();
		add(new moveNode(memPointer, "rax"));
		add(new popNode("rax"));
		add(new pushNode(memPointer )); 
		add(new moveNode("[" + memPointer + "]", regVal)); //memPointer has address to address of top of array 
	}
	 //adding pointer to array onto stack
	currentScope->incVarCount();

	//adding it to current environment
	string baseLabel = currentScope->getScopeLabel();
	int relativeBase = currentScope->getVarCount()*-(wordSize);
	currentScope->add(n->getName(), "[" + baseLabel + "]", relativeBase);
	regAvail->push_front(memPointer);
	regAvail->push_front(regVal);
}

//Generate code for binary Expression
void codeGenerator::check(binaryExpressionASTNode *n, SymbolTable *currentST){
	ExpressionASTNode* left = n->getLeft(); 
	ExpressionASTNode* right = n->getRight(); 
	binaryOp op = n->getOp(); 
	variableASTNode* var;
	numberASTNode* num = dynamic_cast<numberASTNode*>(right);

	string leftReg;
	string rightReg;
	//Calculate branch that uses the most registers first
	if(left->weight() > right->weight()){
		//generate code to retrieve left side	
		leftReg = regAvail->front();
		left->accept(this, currentST);

		var = dynamic_cast<variableASTNode*>(left);
		if(var){	
			add(new moveNode(leftReg, "[" + leftReg + "]"));
		}


		//generate code to retrieve right side
		//Catches case for immediate loading 
		if(num != NULL && op != idiv && op != mod){		
			stringstream ss;
			ss << num->getValue();
			rightReg = ss.str();
		}else{
			rightReg = regAvail->front();
			right->accept(this, currentST);
		}
		
	
		var = dynamic_cast<variableASTNode*>(right);
		if(var){	
			add(new moveNode(rightReg, "[" + rightReg + "]"));
		}
	}else{
		//Switch first 2 registers for right side leaves in second register 
		//and left side leaves in first register (first and second from original positions)

		
		//generate code to retrieve right side
		//Catches case for immediate loading 
		if(num != NULL && op != idiv && op != mod){		
			stringstream ss;
			ss << num->getValue();
			rightReg = ss.str();
		}else{
			leftReg = regAvail->front();
			regAvail->pop_front();
			rightReg = regAvail->front();
			regAvail->pop_front();
			regAvail->push_front(leftReg);	
			regAvail->push_front(rightReg);
			rightReg = regAvail->front();
			right->accept(this, currentST);
		}
		var = dynamic_cast<variableASTNode*>(right);
		if(var){	
			add(new moveNode(rightReg, "[" + rightReg + "]"));
		}
			
		//Generate code to retrieve right side
		leftReg = regAvail->front();
		left->accept(this, currentST);

		var = dynamic_cast<variableASTNode*>(left);
		if(var){	
			add(new moveNode(leftReg, "[" + leftReg + "]"));
		}
		
	}


	int thisBool = nextBoolCounter();
	stringstream ss;
	ss << thisBool;
	string boolLabel = "bool_" + ss.str();


	if (op == iplus){
		add(new addNode(leftReg,rightReg));
	}else
	if (op == subtract){
		add(new subNode(leftReg,rightReg));
	}else
	if (op == idiv){
		add(new pushNode("rax"));
		add(new pushNode("rdx"));
		add(new xorNode("rdx", "rdx"));
		add(new moveNode("rax", leftReg));
		add(new idivNode(rightReg));
		add(new moveNode(leftReg, "rax"));
		add(new popNode("rdx"));
		add(new popNode("rax"));
	}else
	if (op == mul){
		add(new imulNode(leftReg,rightReg));
	}else
	if (op == mod){
		add(new pushNode("rax"));
		add(new pushNode("rdx"));
		add(new xorNode("rdx","rdx"));
		add(new moveNode("rax", leftReg));
		add(new idivNode(rightReg));
		add(new moveNode(leftReg, "rdx"));
		add(new popNode("rdx"));
		add(new popNode("rax"));
	}else
	if (op == bitAnd){
		add(new andNode(leftReg, rightReg));
	}else
	if (op == bitOr){
		add(new orNode(leftReg,rightReg));
	}else
	if (op == xOr){
		add(new xorNode(leftReg,rightReg));
	}else if (op == lessThan){
		add(new cmpNode(leftReg,rightReg));
		add(new moveNode(leftReg, "0"));
		add(new jgeNode(boolLabel));
		add(new notNode(leftReg));
		add(new labelNode(boolLabel));
	}else if (op == greaterThan){
		add(new cmpNode(leftReg,rightReg));
		add(new moveNode(leftReg, "0"));
		add(new jleNode(boolLabel));
		add(new notNode(leftReg));
		add(new labelNode(boolLabel));
	}else if (op == equalTo) {
		add(new cmpNode(leftReg,rightReg));
		add(new moveNode(leftReg, "0"));
		add(new jneNode(boolLabel));
		add(new notNode(leftReg));
		add(new labelNode(boolLabel));
	}else if (op == notEqualTo) {
		add(new cmpNode(leftReg,rightReg));
		add(new moveNode(leftReg, "0"));
		add(new jeNode(boolLabel));
		add(new notNode(leftReg));
		add(new labelNode(boolLabel));
	}else if (op == lessEqu){
		add(new cmpNode(leftReg,rightReg));
		add(new moveNode(leftReg, "0"));
		add(new jgNode(boolLabel));
		add(new notNode(leftReg));
		add(new labelNode(boolLabel));
	}else if (op == greaterEqu){
		add(new cmpNode(leftReg,rightReg));
		add(new moveNode(leftReg, "0"));
		add(new jlNode(boolLabel));
		add(new notNode(leftReg));
		add(new labelNode(boolLabel));
	}else if (op == bAnd){
		add(new andNode(leftReg,rightReg));
	}else if (op == bOr) {
		add(new orNode(leftReg,rightReg));
	}
	//If we did not use immediate addressing then restore the register we had to use
	if(num == NULL || op == idiv || op == mod){		
		regAvail->push_front(rightReg);
	}
}

//Generate code for unary Expression
void codeGenerator::check(unaryExpressionASTNode *n, SymbolTable *currentST){
	ExpressionASTNode* exp = n->getExpr();
	unaryOp op = n->getOp();
	string regVal = regAvail->front();
	exp->accept(this, currentST);

	variableASTNode* var = dynamic_cast<variableASTNode*>(exp);
	if(var){	
		add(new moveNode(regVal, "[" + regVal + "]"));
	}

	if (op == neg){
		add(new negNode(regVal));
	}
	if ((op == bitNot) || (op == boolNOT)){
		add(new notNode(regVal));
	}
}

//Generate code for printing statement to stdout
void codeGenerator::check(printNode *n, SymbolTable *currentST){
	ExpressionASTNode* value = n->getVal();
	string regVal = regAvail->front(); //Get first available register
	string type = getRealType(value,currentST);
	//Save registers for use
	saveRegs();
	value->accept(this, currentST); //Generate code for value to be printed leave answer in first available register
	regAvail->push_front(regVal);
	variableASTNode* var = dynamic_cast<variableASTNode*>(value);
	if(var != NULL){
		add(new moveNode("rsi", "[" + regVal + "]"));
	}else{
		add(new moveNode("rsi",  regVal ));
	}

	if (type.compare("number") == 0){
			add(new moveNode("rdi", "integer"));
	}else if (type.compare("letter") == 0){
			add(new moveNode("rdi", "char")); //Format for printing char
    }else{
        	add(new moveNode("rdi", "string"));
	}
	
	add(new moveNode("rax", "0"));
	add(new callerNode("printf"));//Linked with GCC to call printf
	restoreRegs();
}

//Generates code for a procedure declaration
void codeGenerator::check(procedureDeclNode *n, SymbolTable *currentST){

	funcStack->push_front(instr); //stack has all code generated previously
	instr = new deque<IA32Nodes*>(); //create a new deque
	
	int scopeLevel = currentScope->getScopeLevel();
	stringstream sss;
	sss << scopeLevel;
	
	//add proc to current scope
	currentScope->add(n->getName(), n->getName()+"_"+sss.str(),0);

	//Set the scope label for proc	
	add(new labelNode(n->getName()+"_"+sss.str())); //print label for proc(unique)
	argBuffer = n->getArgs(); //Puts it args in argbuffer for bodynode to add to the scope
	n->getBody()->accept(this,currentST); //generate code for body

	//Add a return node onto the end
	add(new retNode());
	deque<IA32Nodes*>* front = funcStack->front(); //front is all the code generated previously
	funcStack->pop_front();
	combine(instr,front); //puts all the new code(instr) on top of old code(front)
	instr = front;
}

//Generates code for a function declaration
void codeGenerator::check(functionDeclNode *n, SymbolTable *currentST){	
	funcStack->push_front(instr); //stack has all code generated previously
	instr = new deque<IA32Nodes*>();

	int scopeLevel = currentScope->getScopeLevel();
	//convert scope level into str
	stringstream sss;
	sss << scopeLevel;
	
	//add proc to current scope
	currentScope->add(n->getName(), n->getName()+"_"+sss.str(),0);
	
	add(new labelNode(n->getName()+"_"+sss.str())); //print label for proc(unique)
	argBuffer = n->getArgs(); //Puts its args in argbuffer for bodynode to add to the scope
	n->getBody()->accept(this,currentST); //generate code for body
	
	deque<IA32Nodes*>* front = funcStack->front(); //front is all the code generated previously
	funcStack->pop_front();
	combine(instr,front); //puts all the new code(instr) on top of old code(front)
	instr = front;
	 //change scope back to previous one

}

//Generates code for an if-statement
void codeGenerator::check(ifStatementNode *n, SymbolTable *currentST)
{	
	ExpressionASTNode *e = n->getExpr();
	statementListNode* b = n->getBody();
	branchingNodes* o    = n->getOthers();

	int thisIf   = nextIfCount();
	int thisElse = nextElseCount();

	stringstream ss;
	ss << thisIf;
	stringstream s2;
	s2 << thisElse;

	string ifLabel     = "if_" + ss.str();
	string ifElseLabel = "else_" + s2.str();	
	string endIfLabel  = "endIf_" + ss.str();

    add(new labelNode(ifLabel));	
	string boolReg = regAvail->front();
	e->accept(this, currentST);
	regAvail->push_front(boolReg);

	add(new cmpNode(boolReg, "0"));
	add(new jeNode(ifElseLabel));
 
	b->accept(this, currentST);
	add(new jmpNode(endIfLabel));
    add(new labelNode(ifElseLabel));

	o->accept(this,currentST);
    add(new labelNode(endIfLabel));
}

//Generates code for a branch from an if-statement
void codeGenerator::check(branchingNode *n, SymbolTable *currentST)
{
	ExpressionASTNode* expr = n->getExpr();
	statementListNode* b = n->getBody();

	int thisElse = nextElseCount();
	int thisIf = ifCounter - 1;
	stringstream ss;
	ss << thisElse;
	stringstream s2;
	s2 << thisIf;
	string endIfLabel = "endIf_" + s2.str();
	string ifElseLabel = "else_" + ss.str();

	if (expr)
	{
		string boolReg = regAvail->front();
		expr->accept(this, currentST);
		regAvail->push_front(boolReg);
		add(new cmpNode(boolReg, "0"));
		add(new jeNode(ifElseLabel));	
		
	}

	b->accept(this, currentST);
	add(new jmpNode(endIfLabel));
	add(new labelNode(ifElseLabel));
}

//Generates code to read in from stdin
void codeGenerator::check(whatWasNode *n, SymbolTable *currentST){
	variableASTNode* var = n->getStore();
	string varBase = currentScope->searchEnclosingForBase(var->getName());
	int offset = currentScope->searchEnclosingForOffset(var->getName());
	stringstream ss;
	ss << offset;
	
	string type = getRealType(var, currentST);

	string regVal = regAvail->front();
	var->accept(this,currentST);
	add(new pushNode("rdi"));
	add(new pushNode("rsi"));
	add(new pushNode("rax"));
	add(new moveNode("rax" , regVal));
	regAvail->push_front(regVal);
	saveRegs();
	if (type.compare("number") == 0){
			
			add(new moveNode("rdi", "scaninteger"));
			
			add(new moveNode("[rax]", "0")); //CLEAR MEMORY BEFORE PUTTING ANYTHING 
			add(new moveNode("rsi","rax"));
			
	}else if (type.compare("letter") == 0){
			add(new moveNode("rdi", "scanchar"));
			
			add(new moveNode("[rax]", " 0")); //CLEAR MEMORY BEFORE PUTTING ANYTHING IN
			add(new moveNode("rsi","rax"));
    }else{        	
			add(new moveNode("rdi", "scanstring"));
			
			add(new moveNode("[rax]", " 0")); //CLEAR MEMORY BEFORE PUTTING ANYTHING IN
			add(new moveNode("rsi" , "rax"));
	}
	
	add(new moveNode("rax", "0"));
	add(new callerNode("scanf"));
	restoreRegs();
	add(new popNode("rax"));
	add(new popNode("rsi"));
	add(new popNode("rdi"));

}

//Generates code for body inside if statement
void codeGenerator::check(perhapsDeclAndBody *n, SymbolTable *currentST){
	currentScope = new codeGenEnv(currentScope); //create a new scope for variable environment	
	typeDeclNode* decl = n->getDecls();
	statementListNode* body = n->getBody();
	stringstream ss;
	ss << scopeCounter;
	currentScope->setScopeLabel("LC" + ss.str());
	decls->push_back(new resbNode(currentScope->getScopeLabel(),wordSize));
	
	add(new pushNode("rbp"));
	add(new moveNode("rbp","rsp"));
	add(new moveNode("[" + currentScope->getScopeLabel() + "]", "rbp"));
	scopeCounter++;
	if(decl)
		decl->accept(this,currentST);	
	if(body)
		body->accept(this, currentST);
	add(new moveNode("rsp", "rbp"));
	add(new popNode("rbp"));
	add(new moveNode("[" + currentScope->getScopeLabel() + "]", "rbp"));
	if(currentScope)
	currentScope = currentScope->getPrevScope(); 



}

//generates code for loopnode
void codeGenerator::check(loopNode *n, SymbolTable *currentST)
{
	ExpressionASTNode *e = n->getExpr();
	compoundStatement* b = n->getBody();

	int thisLoop = nextLoopCount();

	stringstream ss;
	ss << thisLoop;
	string loopLabel = "loop_" + ss.str();
	string endLoopLabel = "endloop_" + ss.str();

    add(new labelNode(loopLabel));
	string boolReg = regAvail->front();
	e->accept(this, currentST);
	regAvail->push_front(boolReg);

	add(new cmpNode(boolReg, "0"));
	add(new jneNode(endLoopLabel));

	b->accept(this, currentST);
	add(new jmpNode(loopLabel));
	add(new labelNode(endLoopLabel));
} 

//generates code for a sentence
void codeGenerator::check(sentenceASTNode *n, SymbolTable *currentST){
    string regVal = regAvail->front();
	regAvail->pop_front();
    string value = n->getValue();
	int thisCounter = nextStringCount();
	stringstream ss;
	ss << thisCounter;
	string label = "string" + ss.str();
	instr->push_front(new stringNode(value,label)); //Needs to be put at top of file
	add(new moveNode(regVal, label));

}

//generates code for a letter
void codeGenerator::check(letterASTNode *n, SymbolTable *currentST){
	string regVal = regAvail->front();
	regAvail->pop_front();
	char val = n->getValue();

    string value = string("'") + (val) + string("'");
    add(new moveNode(regVal,value));
    
}

//generates code for a number
void codeGenerator::check(numberASTNode *n, SymbolTable *currentST){
	string regVal = regAvail->front(); //Gets the first available register
	regAvail->pop_front();
	stringstream ss;//create a stringstream
   	ss << n->getValue();//add number to the stream
	add(new moveNode(regVal,ss.str()));
}

//generates code to get the length of an array
void codeGenerator::check(arrayLengthNode *n, SymbolTable *currentST){
	string baseAddress = currentScope->searchEnclosingForBase(n->getName());
	int offset = currentScope->searchEnclosingForOffset(n->getName());
	stringstream ss;
	ss << offset;
	string regVal = regAvail->front();
	regAvail->pop_front();
	typeDeclNode* decl = n->getDecl();

	add(new moveNode(regVal, baseAddress));
	add(new moveNode(regVal, "[" + regVal + "+" + ss.str()+ "]")); //reg val has address to the address of top of array
	add(new moveNode(regVal, "[" + regVal + "]"));
}

//generates code for a forloop
void codeGenerator::check(forLoopNode *n, SymbolTable *currentST){
	ExpressionASTNode *from = n->getFrom();
	ExpressionASTNode *to = n->getTo();
	variableASTNode* var = n->getID();
	compoundStatement* b = n->getBody();

	int thisLoop = nextLoopCount();

	stringstream ss;
	ss << thisLoop;
	string loopLabel = "forloop_" + ss.str();
	string endLoopLabel = "endforloop_" + ss.str();
	
	variableASTNode* isVar;
	//Calculate value of from
	string fromReg = regAvail->front();
	from->accept(this,currentST);
	isVar = dynamic_cast<variableASTNode*>(from);
	if(isVar){	
		add(new moveNode(fromReg, "[" + fromReg + "]"));
	}
		
	//Calculate value of to
	string toReg = regAvail->front();	
	to->accept(this,currentST);
	isVar = dynamic_cast<variableASTNode*>(to);
	if(isVar){	
		add(new moveNode(toReg, "[" + toReg + "]"));
	}
	
	//Calculate address of where variable is stored	
	string varReg = regAvail->front();
	var->accept(this,currentST);
	add(new moveNode("[" + varReg + "]","0"));
	add(new moveNode("[" + varReg + "]", fromReg));
	
    add(new labelNode(loopLabel));
	add(new cmpNode("qword [" + varReg +"]", toReg));
	add(new jgNode(endLoopLabel));
	add(new labelNode("forLoopBody_" + ss.str()));
	b->accept(this, currentST);
	add(new incNode(" qword [" + varReg + "]"));
	add(new jmpNode(loopLabel));
	add(new labelNode(endLoopLabel));
	regAvail->push_front(varReg);
	regAvail->push_front(toReg);
	regAvail->push_front(fromReg);
}

//Starts code generation
void codeGenerator::check(programNode *n, SymbolTable *currentST){
	cout << "========STARTING=CODE=GENERATION=========" << endl;
	cout << endl;
	cout << endl;	

	currentScope->setScopeLabel("global");
	decls->push_back(new resbNode(currentScope->getScopeLabel(),wordSize));
	//make a main function that sets up all the global scoped variables and calls hatta
	global->push_front(new labelNode("main"));
	global->push_back(new pushNode("rbp"));
	global->push_back(new moveNode("rbp","rsp"));
	global->push_back(new moveNode("[" + currentScope->getScopeLabel() + "]", "rbp"));

	n->getStart()->accept(this,currentST);
	global->push_back(new callerNode("hatta_0"));
	global->push_back(new moveNode("rsp","rbp"));
	global->push_back(new popNode("rbp"));
	global->push_back(new retNode());
	postOptimise();
	printFile();
	cout << "========FINISHED=CODE=GENERATION=========" << endl;
	clearMem();
}

