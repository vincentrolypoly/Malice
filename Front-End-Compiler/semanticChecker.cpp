
#include "semanticChecker.hpp"
#include "auxillaryMethods.hpp"
#include "symbolTable.hpp"
#include "ASTAll.hpp"
#include <iostream>

using namespace std;

void semanticChecker::check(assignNode *n, SymbolTable *ST) {
	variableASTNode *LHS = n->getLHS();
	ExpressionASTNode *RHS = n->getRHS();

	LHS->accept(this, ST); //Check if LHS is valid		
	RHS->accept(this, ST); //Check if RHS is valid
	
	if(isArray(LHS,ST) || isArray(RHS,ST)) {
		printError(n->getLineNo());
		cerr << "Cannot assign arrays" <<endl;
		delete ST;  
		cleanUp();
	}
	
	identifierASTNode* is_ID = dynamic_cast <identifierASTNode*> (LHS);
	
	if(is_ID) {
		ASTNodes* var = ST->searchEnclosing(LHS->getName());
		varDeclNode* varDec = dynamic_cast <varDeclNode*> (var);

		if(varDec) {
			if(varDec->isConst()) {
				printError(n->getLineNo());
				cerr << "Cannot change value of constant variables" << endl;
				delete ST;
				cleanUp();
			}
		}
	}

	//Checking type compatibility
	string LHSName = LHS->getName();	
	string LHSType = getRealType(LHS,ST);		
	string RHSType = getRealType(RHS,ST);
	
	if(!isSameType( LHSType, RHSType)) 	{
		printError(n->getLineNo());
		cerr << "Cannot assign values of type: '" << RHSType << "' into variable: '" ;
		cerr << LHSName << "' because '" << LHSName << "' is of type '" ;
           cerr << LHSType << "'"<< endl;
		delete ST;  
		cleanUp();
	}
}

void semanticChecker::check(printNode *n, SymbolTable *ST){
	ExpressionASTNode* valToBePrinted = n->getVal();
	valToBePrinted->accept(this, ST); //Checking value to be printed*/
	if(isArray(valToBePrinted,ST)){
		printError(n->getLineNo());
		cerr << "Can not print arrays" << endl;
		delete ST;  
		cleanUp();
	}
}
void semanticChecker::check(identifierASTNode *n, SymbolTable *ST){
	string identName 		  = n->getName();
	ASTNodes* identDecl 	  = ST->searchEnclosing(identName);
	
	
	if(identDecl == NULL){
		printError(n->getLineNo());
		cerr << "'" << identName << "' does not exist in this scope" << endl; 
		//checking if the identifier is in scope
		delete ST;  
		cleanUp();
	}
	typeDeclNode *variableInfo = dynamic_cast<typeDeclNode*> (identDecl);
	if(variableInfo == NULL){
		printError(n->getLineNo());
		cerr << "'" << identName <<"' is not a variable." << endl; 
		//checking if the identifier is a variable
		delete ST;  
		cleanUp();
	}
	typeDeclNode *Info = dynamic_cast<typeDeclNode*> (identDecl);
	n->setDecl(Info);
}

void semanticChecker::check(arrayAccessIdentifier *n, SymbolTable *ST){
	string arrayName 	   = n->getName();
	ASTNodes *arrayDecl    = ST->searchEnclosing(arrayName);
	typeDeclNode *checkSpider = dynamic_cast<typeDeclNode*> (arrayDecl);
	arrDeclNode *arrayInfo = dynamic_cast<arrDeclNode*> (arrayDecl);
	
	//Checking to see if array was declared in scope
	if(arrayDecl == NULL){
		printError(n->getLineNo());
		cerr << "'" << arrayName << "' does not exist in this scope" << endl;
		delete ST;  
		cleanUp();
	}
	//checking to see if identifier given is an array
	if(arrayInfo == NULL && checkSpider != NULL &&!(checkSpider->isSpider())){
		printError(n->getLineNo());
		cerr << "'" << arrayName << "' is not an array" << endl;
		delete ST;  
		cleanUp();
	}
	
	if(!(checkSpider->isSpider())){
		//checking to see if array index is in bounds
		ExpressionASTNode* index = n->getExpr();
		ExpressionASTNode* arrSize = arrayInfo->getSize();

		if(isEvaluatable(index) && isEvaluatable(arrSize)){
			int indexVal = evaluate(index);
			int arrSizeVal = evaluate(arrSize);
			if ((indexVal < 0 )||(indexVal >= arrSizeVal)){
				printError(n->getLineNo());
				cerr << "Array index out of bounds" << endl;
				delete ST;  
				cleanUp();
			}
		}
	}
	n->setDecl(checkSpider);
}

void semanticChecker::check(incrementNode *n, SymbolTable *ST){
	//Checking variable to be incremented is valid

	variableASTNode *varToBeInc = n->getVar();
	varToBeInc->accept(this, ST);
	if(isArray(varToBeInc,ST)){
		printError(n->getLineNo());
		cerr << "Can not increments arrays" << endl;
		delete ST;  
		cleanUp();
	}

	identifierASTNode* is_ID = dynamic_cast <identifierASTNode*> (varToBeInc);
	
	if(is_ID) {
		ASTNodes* var = ST->searchEnclosing(varToBeInc->getName());
		varDeclNode* varDec = dynamic_cast <varDeclNode*> (var);

		if(varDec) {
			if(varDec->isConst()) {
				printError(n->getLineNo());
				cerr << "Cannot change value of constant variables" << endl;
				delete ST;
				cleanUp();
			}
		}
	}

	//checking the variable is of type number
	string varName = n->getVar()->getName();
	
	//Get information about variable
	ASTNodes *varDecl = ST->searchEnclosing(varName);
	typeDeclNode *variableInfo = dynamic_cast<typeDeclNode*> (varDecl);
	
	//Check its type
	typeNode* varType = dynamic_cast<typeNode*> (variableInfo->getType());
	intTypeNode *intType = dynamic_cast<intTypeNode*> (variableInfo->getType());
	
	if(intType == NULL){ 
		printError(n->getLineNo());
		cerr << "Cannot increment '" << varName;
		cerr << "' because it is of type '" << varType->getTypeName() << "'" << endl;
		delete ST;  
		cleanUp();
	}
	
}
	
void semanticChecker::check(decrementNode *n, SymbolTable *ST){
	//Checking variable to be decremented is valid
	variableASTNode *varToBeDec = n->getVar();
	varToBeDec->accept(this,ST);

	if(isArray(varToBeDec,ST)){	
		printError(n->getLineNo());
		cerr << "Cannot decrement arrays" << endl;
		delete ST;  
		cleanUp();
	}

	identifierASTNode* is_ID = dynamic_cast <identifierASTNode*> (varToBeDec);
	
	if(is_ID) {
		ASTNodes* var = ST->searchEnclosing(varToBeDec->getName());
		varDeclNode* varDec = dynamic_cast <varDeclNode*> (var);

		if(varDec) {
			if(varDec->isConst()) {
				printError(n->getLineNo());
				cerr << "Cannot change value of constant variables" << endl;
				delete ST;
				cleanUp();
			}
		}
	}

	//checking the variable is of type number
	string varName = n->getVar()->getName();
	
	//Get information about variable
	ASTNodes *varDecl = ST->searchEnclosing(varName);
	typeDeclNode *variableInfo = dynamic_cast<typeDeclNode*> (varDecl);
	if(varDecl == NULL){
	cout<<"wtf";
	}
	//Check its type
	typeNode* varType = dynamic_cast<typeNode*> (variableInfo->getType());
	intTypeNode *intType = dynamic_cast<intTypeNode*> (variableInfo->getType());

	if(intType == NULL){ 
		printError(n->getLineNo());
		cerr << "Cannot decrement '" << varName;
		cerr << "' because it is of type '" << varType->getTypeName() << "'" << endl;
		delete ST;  
		cleanUp();
	}
}

void semanticChecker::check(varDeclNode *n, SymbolTable *ST){
	string typeName =n->getType()->getTypeName();
	typeNode *t = dynamic_cast<typeNode*>(ST->searchEnclosing(typeName));
	ASTNodes *prevDecl = ST->searchCurrent(n->getName());

	if (t == NULL) {
		//checking that the type given is an actual type
		printError(n->getLineNo());
		cerr << n->getType()->getTypeName() << " is not a type" << endl;
		delete ST;  
		cleanUp();
	}else if ( prevDecl != NULL ){
		//checking if the variable has already been declared in the same scope
		printError(n->getLineNo());
		cerr << n->getName() << " has already been declared";
		cerr << " on closing line: " << prevDecl->getLineNo() << endl;
		delete ST;  
		cleanUp();
	} 
	//add it to the current symbol table scope
	ST->add(n->getName(), n);
	
	//if the variable was declared with a value then check 
	//its allowed to be assigned to variable
	ExpressionASTNode *val = n->getValue();
	if(val != NULL){ 
		bool tempSwitch = n->isConst();

		//Create a temp assign node to do checking
		identifierASTNode *tempIdent = new identifierASTNode(n->getName(), n->getLineNo());
		assignNode *tempAssign = new assignNode(tempIdent, val, n->getLineNo());
		
		if(tempSwitch) {
			n->switchConst();
		}

		semanticChecker::check(tempAssign, ST);

		if(tempSwitch) {
			n->switchConst();
		}

		delete tempAssign;
		delete tempIdent;
	}
}


void semanticChecker::check(arrDeclNode *n, SymbolTable *ST){ 
	ASTNodes *prevDecl = ST->searchCurrent(n->getName());
	string arrTypeName = n->getType()->getTypeName();
	typeNode *t = dynamic_cast<typeNode*>(ST->searchEnclosing(arrTypeName));
	if (t == NULL) {
		//checking that the type given is an actual type
		printError(n->getLineNo());
		cerr << arrTypeName << " is not a type" << endl;
		delete ST;  
		cleanUp();
	}else if ( prevDecl != NULL ){
		//checking if the variable has already been declared in the same scope
		printError(n->getLineNo());
		cerr << n->getName() << " has already been declared";
		cerr << " on closing line: " << prevDecl->getLineNo() << endl;
		delete ST;  
		cleanUp();
	}else if ( !isArrayable(n->getType())){ //checking if can create arrays of that type
		printError(n->getLineNo());
		cerr << "cannot create arrays of type '" << arrTypeName << "'" << endl; 
		delete ST;  
		cleanUp();
	}
	
	//Checking if the expression given for the size of the array is valid
	ExpressionASTNode *size = n->getSize();
	size->accept(this,ST);
	
	//Checking if the expression is immediately evaluatable
	if (isEvaluatable(n->getSize())){
		if(evaluate(n->getSize()) <= 0){
			printError(n->getLineNo());
			cerr << "Cannot create arrays of negative size" << endl; 
			//checks array size if the size is immediately evaluatable 
			delete ST;  
			cleanUp();
		}
	}
	ST->add(n->getName(), n);
}

void semanticChecker::check(bodyNode *n, SymbolTable *ST){
	declListNode* decls = n->getDecls();
	compoundStatement* body = n->getBody();
	if(decls)
	decls->accept(this, ST);
	if(body)
	body-> accept(this, ST);
}

void semanticChecker::check(procedureDeclNode *n, SymbolTable *ST){
	ASTNodes *p = ST->searchCurrent(n->getName());

    //Checking if already declared
	if (p != NULL){
		cerr <<"ERROR: Procedure: '" << n->getName();
		cerr << "' closed on line: " << n->getLineNo();
		cerr << " is already declared on closing line:"<< p->getLineNo() << endl;
		delete ST;  
		cleanUp();
	}else{
		ST->add(n->getName(),n);
	}

	ST = new SymbolTable(ST);

	functionArgumentNode *args = n->getArgs();
	bodyNode *body = n->getBody();			
	args->accept(this, ST);
	semanticChecker::check(body, ST);
	CFG* funcCFG = n->buildCFG();
	//Returns null if there are paths that dont have a return statement
	deque<returnNode*>* returnNodes = getReturnNodes(funcCFG);
	deque<returnNode*>::iterator it;
	if(returnNodes != NULL && !(returnNodes->empty())){
		for( it=returnNodes->begin(); it < returnNodes->end(); it++){
			if((*it) != NULL){
				printError((*it)->getLineNo());
		 		cerr << "Return statement in " << n->getName() << " does not belong there" << endl;
		 		delete ST;  
				cleanUp();
			}
		}
	}
}

void semanticChecker::check(functionDeclNode *n, SymbolTable *ST) {
	string returnTypeName = n->getReturnType()->getTypeName();
	typeNode *t = dynamic_cast<typeNode*> (ST->searchEnclosing(returnTypeName));
	ASTNodes *prevDecl = ST->searchCurrent(n->getName());
	if (t == NULL){
		//Test to see if an actual type was given for return type
		cerr << n->getReturnType() << "is not a type" << endl;
		delete ST;  
		cleanUp();
	}else if(!isReturnable(t)){
		//Test to see if the type is returnable
		cerr << "ERROR: Function closing on line: " << n->getLineNo();
		cerr << " Cannot return type " << t->getTypeName();
		delete ST;  
		cleanUp();
	}else if ( prevDecl != NULL ) {
		//Test to see if something with same name has already been declared
		cerr << "ERROR: Function: ' " << n->getName();
		cerr << "' closed on line: " << n->getLineNo();
		cerr << " is already declared on closing line:"<< prevDecl->getLineNo() << endl;
		delete ST;  
		cleanUp();
	}else{
		ST->add(n->getName(), n);
	}
	
	ST = new SymbolTable(ST);
	functionArgumentNode *args = n->getArgs();
	bodyNode *body = n->getBody();
					
	args->accept(this, ST);
	semanticChecker::check(body, ST);

	CFG* funcCFG = n->buildCFG();
	//Returns null if there are paths that dont have a return statement
	deque<returnNode*>* returnNodes = getReturnNodes(funcCFG);
	
	deque<returnNode*>::iterator it;
	string returnType;
	
	if(returnNodes == NULL || returnNodes->empty()){
		cerr << "There are paths through function: " << n->getName() << " with no return statement" << endl;
		delete ST;  
		//delete funcCFG;
		cleanUp();
	}
	for( it=returnNodes->begin(); it < returnNodes->end(); it++){
		if((*it) == NULL){
			cerr << "There are paths through function: " << n->getName() << " with no return statement" << endl;
			//delete funcCFG;
			delete ST;  
			cleanUp();
		}
		returnType = getRealType((*it)->getvalue(),ST);
		if (!isSameType(returnTypeName, returnType)){
			printError((*it)->getLineNo());
			cerr << "Return type: " << returnType << " is not the same as '" << n->getName() << "' return type: " << returnTypeName << endl;
			//delete funcCFG;
			delete ST;  
			cleanUp();
		}
	}
	//delete funcCFG;
	delete(returnNodes);
}


void semanticChecker::check(whatWasNode *n, SymbolTable *ST) {
	variableASTNode* store = n->getStore();
	store->accept(this,ST);
	if(isArray(store,ST)){
		printError(n->getLineNo());
		cerr << "Can not store directly into array identifier" << endl;
		delete ST;  
		cleanUp();
	}
}
void semanticChecker::check(returnNode *n, SymbolTable *ST){
	ExpressionASTNode* returnVal = n->getvalue();
	returnVal->accept(this,ST);
	if(isArray(returnVal,ST)){
		printError(n->getLineNo());
		cerr << "Cannot return arrays" << endl;
		delete ST;  
		cleanUp();
	}
}
void semanticChecker::check(binaryExpressionASTNode *n, SymbolTable *ST){	
	string binOpStr[] = { "+", "-", "/" ,"*", "%", "&", "|" , "^", 
						"<", ">", "==", "!=","<=", ">=", "&&" ,"||"};
	ExpressionASTNode *left = n->getLeft();
	ExpressionASTNode *right = n->getRight();
	left->accept(this, ST); //Checking left is well formed
	right->accept(this, ST); //Checking right is well formed

	//Check operators? against both sides? can mod negatives?
	binaryOp op = n->getOp();
	
	//Check types of left and right are numbers
	if(isArray(left,ST) || isArray(right,ST)){
		printError(n->getLineNo());
		cerr << "Type clash: Cannot have an array argument with operator: ";
		cerr << binOpStr[op] <<endl;
		delete ST;  
		cleanUp();
	}

	string leftType = getRealType(left, ST);
	string rightType = getRealType(right,ST);
	if (!isSameType(leftType,rightType)){	
		printError(n->getLineNo());
		cerr << "Type clash: " << "Cannot have one value of type: '";
		cerr << leftType << "' and one value of '" << rightType;
		cerr << "' for operator: '" << binOpStr[op] << "'" <<  endl; 
		delete ST;  
		cleanUp();
	}
	
	
	bool leftIsSentence = isSameType(leftType,"sentence");
	bool leftIsNumber = isSameType(leftType,"number");
	bool leftIsLetter = isSameType(leftType,"letter");
	bool leftIsBool = isSameType(leftType, "boolean");
	//By here we know left and right are the same type so we
	//only check on one side
	if (op == 0){
		//case where operator is a plus
		//Allows string concat
		if((!leftIsNumber) && (!leftIsLetter)&&(!leftIsSentence)){
			printError(n->getLineNo());
			cerr << "Wrong type: '" << leftType << "' given to operator: '" ;
			cerr << binOpStr[op] << "'" << endl;
			delete ST;  
			cleanUp();
		}
	}else if (op < bin_compOp_pos){//defined in ASTNodes
		//case where operator is one that does not return a bool
		if((!leftIsNumber) && (!leftIsLetter)){
			printError(n->getLineNo());
			cerr << "Wrong type: '" << leftType << "' given to operator: '" ;
			cerr << binOpStr[op] << "'" << endl;
			delete ST;  
			cleanUp();
		}	
	}else if(op < bin_boolOp_pos){//defined in ASTNodes
		//case where operator is a comparison operator
		if((!leftIsNumber)&&(!leftIsLetter)){
			printError(n->getLineNo());
			cerr << "Wrong type: '" << leftType << "' given to operator: '" ;
			cerr << binOpStr[op] << "'" << endl;
			delete ST;  
			cleanUp();
		}
	}else{
		//case where operator is a boolean operator
		if(!leftIsBool){
			printError(n->getLineNo());
			cerr << "Wrong type: '" << leftType << "' given to operator: '" ;
			cerr << binOpStr[op] << "'" << endl;
			delete ST;  
			cleanUp();
		}
	}
}

void semanticChecker::check(unaryExpressionASTNode *n, SymbolTable *ST) {
	string unOpStr[] = {"-" , "~" , "+" , "!"};
	ExpressionASTNode *expr = n->getExpr();
	expr->accept(this,ST); //Checking expression is well formed
	
	string exprType = getRealType(expr,ST); 
	unaryOp op = n->getOp();
	//Check type of expression is a number
	if(isArray(expr,ST)){
		printError(n->getLineNo());
		cerr << "Type Clash: Can not have array arguments with operator: ";
		cerr <<unOpStr[op] << endl;
		delete ST;  
		cleanUp();
	}
	
	if(op < un_boolOp_pos){
		//case where operator is expecting a number
		if(!isSameType(exprType,"number")){
			printError(n->getLineNo());
			cerr << "Wrong type: '" << exprType << "' given to operator: '" ;
			cerr << unOpStr[op] << "'" << endl;
			delete ST;  
			cleanUp();
		}
	}else{
		//case where operator is expecting a bool
		if(!isSameType(exprType,"boolean")){
			printError(n->getLineNo());
			cerr << "Wrong type: '" << exprType << "' given to operator: '" ;
			cerr << unOpStr[op] << "'" << endl;
			delete ST; 
			cleanUp();
		}
	}
}

void semanticChecker::check(ifStatementNode *n, SymbolTable *ST) {
	ExpressionASTNode* condition = n->getExpr();
	condition->accept(this,ST); //Check condition expression is well formed
	//Check conditon is a boolean
	string condType = getRealType(condition, ST);
	if(!isSameType(condType,"boolean") || isArray(condition,ST)){
		printError(n->getLineNo());
		cerr << "Condition given to if statement";
		cerr << " does not evaluate to a boolean" << endl;
		delete ST;  
		cleanUp();
	}
	n->getBody()->accept(this,ST); //Check body of if statement is well formed
	n->getOthers()->accept(this,ST); //Check other branches
}

void semanticChecker::check(branchingNode *n, SymbolTable *ST) {
	ExpressionASTNode* condition = n->getExpr();
	if(condition){ //Check to see if its 'else' branch
		string condType = getRealType(condition, ST);
		if(!isSameType(condType,"boolean")|| isArray(condition,ST)){
			printError(n->getLineNo());
			cerr << "Condition given to if statement";
			cerr << " does not evaluate to a boolean" << endl;
			delete ST;  
			cleanUp();
		}
		condition->accept(this,ST); //Check expression if its 'else-if' branch
	}
	n->getBody()->accept(this,ST); //Check body*/
}


void semanticChecker::check(perhapsDeclAndBody *n, SymbolTable *ST) {
	typeDeclNode *decls = n->getDecls();
	statementListNode *body = n->getBody();
	if(decls)
	decls->accept(this,ST);
	if(body)
	body->accept(this,ST);
}
	
void semanticChecker::check(loopNode *n, SymbolTable *ST) {
	ExpressionASTNode* condition = n->getExpr();
	condition->accept(this,ST); //Check condition expression is well formed
	//Check conditon is a boolean
	string condType = getRealType(condition, ST);
	if(!isSameType(condType,"boolean")|| isArray(condition,ST)){
		printError(n->getLineNo());
		cerr << "Condition given to loop header";
		cerr << " does not evaluate to a boolean" << endl;
		delete ST;  
		cleanUp();
	}
	n->getBody()->accept(this,ST);
}

void semanticChecker::check(callNodeStatement *n, SymbolTable *ST){
			string callName = n->getName();
	actualParamsNode* pNode = n->getParams();
	pNode->accept(this,ST); //Checking parameters are well formed
	
	//check function exists
	ASTNodes *funcInfo = ST->searchEnclosing(callName);
	functionDeclNode *funcDecl = dynamic_cast<functionDeclNode*> (funcInfo);
	procedureDeclNode *procDecl = dynamic_cast<procedureDeclNode*> (funcInfo);
	
	if (funcInfo == NULL){
		printError(n->getLineNo());
		cerr << "Call to: '" << callName << " does not exist in this scope" << endl;
		delete ST;  
		cleanUp();
	}
	
	//check number of params
	deque<ExpressionASTNode*>* givenParams = n->getParams()->getGivenParams();
	int noGivenParams = (int) givenParams->size();
	deque<varDeclNode*> *actualArguments;
	int noActualParams;
    //Check call is to a procedure
	if (procDecl != NULL){
		actualArguments = procDecl->getArgs()->getActualArgs();
	}else{
		printError(n->getLineNo());
		cerr << callName << " is not a procedure" << endl;
		delete ST;  
		cleanUp();
	}
	noActualParams = (int) actualArguments->size();
	if (noActualParams != noGivenParams){
		printError(n->getLineNo());
		cerr << "Wrong number of arguments given to: '" << callName << "'" << endl;
		delete ST;  
		cleanUp();
	}
	
	//check param types
	deque<varDeclNode*>::iterator actualIT = actualArguments->begin();
	deque<ExpressionASTNode*>::iterator givenIT = givenParams->begin();
	string act;
	string giv;
	for( ; (actualIT < actualArguments->end()) ; actualIT++, givenIT++){
		act = (*actualIT)->getType()->getTypeName();
		giv = getRealType(*givenIT,ST);
		
		if((*actualIT)->isSpider()){
			if(!isArray(*givenIT,ST) && !isRef(*givenIT,ST)){
				printError(n->getLineNo());
				cerr << "Expected a pass by reference, got a pass by value" << endl;
				delete ST;  
				cleanUp();
			}
		}else if(isArray(*givenIT,ST)){
				printError(n->getLineNo());
				cerr << "Expected a pass by value, got a pass by reference" << endl;
				delete ST;  
				cleanUp();
		}
		if(!isSameType(act,giv)){
			printError(n->getLineNo());
			cerr<< "Wrong parameter given in call to " << callName;
			cerr<< " expecting type: '" << act << "' given type: '";
			cerr << giv << "'" <<endl;
			delete ST;  
			cleanUp();
		}
	}
}
	
void semanticChecker::check(callNode *n, SymbolTable *ST){	
	string callName = n->getName();
	actualParamsNode* pNode = n->getParams();
	pNode->accept(this,ST); //Checking parameters are well formed
	
	//check function exists
	ASTNodes *funcInfo = ST->searchEnclosing(callName);
	functionDeclNode *funcDecl = dynamic_cast<functionDeclNode*> (funcInfo);
	procedureDeclNode *procDecl = dynamic_cast<procedureDeclNode*> (funcInfo);
	
	if (funcInfo == NULL){
		printError(n->getLineNo());
		cerr << "Call to: '" << callName << " does not exist in this scope" << endl;
		delete ST;  
		cleanUp();
	}
	
	//check number of params
	deque<ExpressionASTNode*>* givenParams = n->getParams()->getGivenParams();
	int noGivenParams = (int) givenParams->size();
	deque<varDeclNode*> *actualArguments;
	int noActualParams;
	
	if (funcDecl != NULL){
		actualArguments = funcDecl->getArgs()->getActualArgs();
	}else{
		printError(n->getLineNo());
		cerr << callName << " is not a function" << endl;
		delete ST;  
		cleanUp();
	}
	noActualParams = (int) actualArguments->size();
	if (noActualParams != noGivenParams){
		printError(n->getLineNo());
		cerr << "Wrong number of arguments given to: '" << callName << "'" << endl;
		delete ST;  
		cleanUp();
	}
	
	//check param types
	deque<varDeclNode*>::iterator actualIT = actualArguments->begin();
	deque<ExpressionASTNode*>::iterator givenIT = givenParams->begin();
	string act;
	string giv;

	for( ; (actualIT < actualArguments->end()) ; actualIT++, givenIT++){
		act = (*actualIT)->getType()->getTypeName();
		giv = getRealType(*givenIT,ST);
		
		if((*actualIT)->isSpider()){
			if(!isArray(*givenIT,ST) && !isRef(*givenIT,ST)){
				printError(n->getLineNo());
				cerr << "Expected a pass by reference, got a pass by value" << endl;
				delete ST;  
				cleanUp();
			}
		}else if(isArray(*givenIT,ST)){
				printError(n->getLineNo());
				cerr << "Expected a pass by value, got a pass by reference" << endl;
				delete ST;  
				cleanUp();
		}

		if(!isSameType(act,giv)){
			printError(n->getLineNo());
			cerr<< "Wrong parameter given in call to " << callName;
			cerr<< " expecting type: '" << act << "' given type: '";
			cerr << giv << "'" <<endl;
			delete ST;  
			cleanUp();
		}
	}

	n->setCallTo(funcDecl);
}

void semanticChecker::check(programNode *n, SymbolTable *ST) {
	declListNode *start = n->getStart();		

	if(start)
		start->accept(this, ST);

	//Check for a function called hatta
	procedureDeclNode* main = dynamic_cast<procedureDeclNode*> (ST->searchCurrent("hatta"));

	if(main == NULL){
		cerr << "ERROR: Could not find main procedure..." << endl; 
		delete ST;  
		cleanUp();
	}

	cout << endl;
}

void semanticChecker::check(arrayLengthNode *n, SymbolTable *currentST) {
	string arrName = n->getName();

	ASTNodes* declInfo     = currentST->searchEnclosing(arrName);
	typeDeclNode* typeInfo = dynamic_cast<typeDeclNode*> (declInfo);
	varDeclNode* varInfo   = dynamic_cast<varDeclNode*> (typeInfo);
	arrDeclNode* arrInfo   = dynamic_cast<arrDeclNode*> (typeInfo);

	if(typeInfo == NULL){
		printError(n->getLineNo());
		cerr << n->getName() << " is not an array. Cannot find size of object which is not an array." << endl;
		delete currentST;
		cleanUp();
	}

	if(varInfo) {
		if(!(varInfo->isSpider())) {
			printError(varInfo->getLineNo());
			cerr << "Cannot find size of a variable" << endl;
			delete currentST;
			cleanUp();
		}
	}

	n->setDeclto(typeInfo);
}
void semanticChecker::check(forLoopNode *n, SymbolTable *currentST){
	//Check variable
	variableASTNode* var = n->getID(); //counter
	var->accept(this, currentST);
	
	//Checking counter is not an array
	if(isArray(var,currentST)){
		printError(n->getLineNo());
		cerr << "Can not increment or decrement arrays in forloop" << endl;
		delete currentST;  
		cleanUp();
	}

	//Checking counter is not a constant
	identifierASTNode* is_ID = dynamic_cast <identifierASTNode*> (var);
	
	if(is_ID) {
		ASTNodes* varInfo = currentST->searchEnclosing(var->getName());
		varDeclNode* varDec = dynamic_cast <varDeclNode*> (varInfo);

		if(varDec) {
			if(varDec->isConst()) {
				printError(n->getLineNo());
				cerr << "Cannot change value of constant variables" << endl;
				delete currentST;
				cleanUp();
			}
		}
	}
	
	//checking the variable is of type number
	string varName = var->getName();
	
	//Get information about variable
	ASTNodes *varDecl = currentST->searchEnclosing(varName);
	typeDeclNode *variableInfo = dynamic_cast<typeDeclNode*> (varDecl);
	
	//Check its type
	typeNode* varType = dynamic_cast<typeNode*> (variableInfo->getType());
	intTypeNode *intType = dynamic_cast<intTypeNode*> (variableInfo->getType());
	
	if(intType == NULL){ 
		printError(n->getLineNo());
		cerr << "Cannot increment or decrement '" << varName;
		cerr << "' because it is of type '" << varType->getTypeName() << "'" << endl;
		delete currentST;  
		cleanUp();
	}

	//Check from expression
	ExpressionASTNode *from = n->getFrom();
	from->accept(this, currentST);
	
	string fromType = getRealType(from, currentST);
	if(!isSameType(fromType,"number")){
		printError(n->getLineNo());
		cerr << "Loop header intial counter";
		cerr << " does not evaluate to a number" << endl;
		delete currentST;  
		cleanUp();
	}

	//Check to expression
	ExpressionASTNode *to   = n->getTo();
	to->accept(this, currentST);
	string toType = getRealType(to, currentST);
	if(!isSameType(toType,"number")){
		printError(n->getLineNo());
		cerr << "Loop header finishing counter";
		cerr << " does not evaluate to a number" << endl;
		delete currentST;  
		cleanUp();
	}
	
	//Check body of loop
	compoundStatement *body = n->getBody();
	body->accept(this,currentST);
}
void semanticChecker::check(letterASTNode *n, SymbolTable *currentST){
	//nothing to check
}
void semanticChecker::check(sentenceASTNode *n, SymbolTable *currentST){
    //nothing to check
}
void semanticChecker::check(numberASTNode *n, SymbolTable *currentST){
	//nothing to check
}

