
#include "auxillaryMethods.hpp"


#include "symbolTable.hpp"
#include "CFG.hpp"
#include "ASTAll.hpp"
#include <iostream>

extern programNode* startNode;

bool isArrayable(typeNode *t){
	string typeName = t->getTypeName();
	return ( typeName.compare("number")   == 0
		  || typeName.compare("letter")   == 0 
		  || typeName.compare("sentence") == 0); 
}

bool isRef(ExpressionASTNode* e, SymbolTable *ST){
	identifierASTNode *i = dynamic_cast<identifierASTNode*> (e);
	if(i==NULL){
		return false;
	}
	ASTNodes *decl = ST->searchEnclosing(i->getName());
	typeDeclNode *arrDecl = dynamic_cast<typeDeclNode*> (decl);
		
	return (arrDecl->isSpider());
}	

void printError(int lineNo){
	cerr << "ERROR: line " << lineNo << " ";
}

void cleanUp(){
	if(startNode)
	startNode->destroyAST(); //Propagate down the tree from the start and delete everything
	delete startNode;
	cerr << endl;
	cerr << endl;
	cerr << "===================END==================="<< endl;
	cerr << endl;
	cerr << endl;
	exit(EXIT_FAILURE);
}

bool isEvaluatable(ExpressionASTNode *e){
	unaryExpressionASTNode  *u = dynamic_cast<unaryExpressionASTNode*> (e);
	binaryExpressionASTNode *b = dynamic_cast<binaryExpressionASTNode*> (e);
	numberASTNode *n = dynamic_cast<numberASTNode*> (e);
	if( n != NULL){
		return true;
	}else if( u != NULL){
		return isEvaluatable(u->getExpr());
	}else if(b != NULL){
		return (isEvaluatable(b->getLeft()) 
			&& isEvaluatable(b->getRight())); 
	}else{
		return false;
	}
}


	bool isReturnable(typeNode *t){
		string typeName = t->getTypeName();
	    return ( typeName.compare("number")   == 0
			  || typeName.compare("letter")   == 0 
			  || typeName.compare("sentence") == 0); 
	}

	bool isSameType(string LHS, string RHS){

		return (RHS.compare(LHS) == 0);
	}
		
	

	int evaluate(ExpressionASTNode *e){
		unaryExpressionASTNode *u 	= dynamic_cast<unaryExpressionASTNode*> (e);
		binaryExpressionASTNode *b 	= dynamic_cast<binaryExpressionASTNode*> (e);
		numberASTNode *n 			= dynamic_cast<numberASTNode*> (e);


		if( n != NULL){
			return n->getValue();
		}else if( u != NULL){
			unaryOp op = u->getOp();
			switch(op){
				case neg: return 0 - evaluate(u->getExpr());
				case bitNot:return ~evaluate(u->getExpr()); 
			}
		}else if(b != NULL){
			binaryOp op = b->getOp();
			ExpressionASTNode *l = b->getLeft();
			ExpressionASTNode *r = b->getRight();
			switch(op){
				 case iplus: 	return evaluate(l) + evaluate(r); 
				 case subtract: return evaluate(l) - evaluate(r); 
				 case idiv: 	return evaluate(l) / evaluate(r); 
                 case mul: 		return evaluate(l) * evaluate(r); 	
				 case mod: 		return evaluate(l) % evaluate(r); 
			     case bitAnd:	return evaluate(l) & evaluate(r); 	
			     case bitOr: 	return evaluate(l) | evaluate(r);  	
				 case xOr: 		return evaluate(l) ^ evaluate(r); 
			}
		}else{
			return 0;
			 //never get to this case if you check its evaluatable before using
		}
	}
	
	

bool isArray(ExpressionASTNode *e, SymbolTable *ST){
	identifierASTNode *i = dynamic_cast<identifierASTNode*> (e);
	if(i==NULL){
		return false;
	}
	ASTNodes *decl = ST->searchEnclosing(i->getName());
	arrDeclNode *arrDecl = dynamic_cast<arrDeclNode*> (decl);
		
	return (arrDecl != NULL);
}
deque<returnNode*>* getReturnNodes(CFG* c){
			deque<returnNode*>* answer = new deque<returnNode*>();
			deque<returnNode*>::iterator rit;
			if (c == NULL){
				return NULL;
			}
			returnNode* r = dynamic_cast<returnNode*>(c->getStatement()); 
			if (r!=NULL){
				answer->push_back(r);
				return answer;
			}else if (c->getChildren()->empty()){	
				return NULL;
			}else{
				deque<CFG*>::iterator it;
				for(it=c->getChildren()->begin(); it!=c->getChildren()->end(); it++){
					deque<returnNode*>* res = getReturnNodes(*it);
					if(res == NULL){
						answer->push_back(NULL);
					}else{
						for(rit= res->begin(); rit != res->end(); rit++){
						answer->push_back(*rit);
						}
					}
				}
			}
			return answer;
}
	

string getRealType(ExpressionASTNode *node, SymbolTable *ST){
		//Assumes binaryExpression is well formed so left and right have same type 
       //and so it will return an expression of the same type
		
		//Case where expressionASTNode is a binary expression		
		binaryExpressionASTNode* binNode = dynamic_cast<binaryExpressionASTNode*> (node);
		if(binNode != NULL){
			binaryOp op = binNode->getOp();
			if(op < bin_compOp_pos){
				return getRealType(binNode->getLeft(),ST);
			}else{
				return "boolean";
			}
		}
		
		//Case where its a unary expression
		unaryExpressionASTNode* unNode = dynamic_cast<unaryExpressionASTNode*> (node);
		if(unNode != NULL){
			unaryOp op = unNode->getOp();
			if(op < un_boolOp_pos){
				return getRealType(unNode->getExpr(),ST);
			}else{
				return "boolean";
			}
		}
		
		//Case where its a number
		numberASTNode* numNode = dynamic_cast<numberASTNode*> (node);
		if(numNode !=NULL){
			return numNode->getType()->getTypeName();
		}
		
		//Case where its a Letter
		letterASTNode* letNode = dynamic_cast<letterASTNode*> (node);
		if (letNode != NULL){
			return letNode->getType()->getTypeName();
		}

		//Case where its a sentence
		sentenceASTNode* senNode = dynamic_cast<sentenceASTNode*> (node);
		if (senNode != NULL){
			return senNode->getType()->getTypeName();
		}
		
		//Case where its a call to a function 
		callNode* cNode = dynamic_cast<callNode*> (node);
		if (cNode != NULL){
			if (cNode->getCallTo() != NULL){
				return cNode->getCallTo()->getReturnType()->getTypeName();
			}
			ASTNodes *decl = ST->searchEnclosing(cNode->getName());
			//Decl now points to a functionDecl or procDecl
			functionDeclNode* funcDecl = dynamic_cast<functionDeclNode*> (decl);
			if(funcDecl != NULL){
					//is a call to a function
			
				return funcDecl->getReturnType()->getTypeName();
			}else{
					//is a call to procedure
				cerr << cNode->getName() << "has no return type" << endl;
				exit(EXIT_FAILURE);
			}
		}
					
		//Case where its a call to a procedure
		callNodeStatement* cSNode = dynamic_cast<callNodeStatement*> (node);
		if (cSNode != NULL){
			ASTNodes *decl = ST->searchEnclosing(cSNode->getName());
			//Decl now points to a functionDecl or procDecl
			procedureDeclNode *procDecl = dynamic_cast<procedureDeclNode*> (decl);
			if(procDecl != NULL){

				cerr << cSNode->getName() << "has no return type" << endl;
				exit(EXIT_FAILURE);
			}
		}

		//Case for array length
		arrayLengthNode* lengthNode = dynamic_cast<arrayLengthNode*> (node);

		if(lengthNode != NULL) {
			return "number";
		}

		//Case where its a variable or array access or an array
		variableASTNode* varNode = dynamic_cast<variableASTNode*> (node);
		
		if(varNode != NULL){
			typeDeclNode* d = varNode->getDecl();
			if(d != NULL){
				return d->getType()->getTypeName();
			}
				
			ASTNodes *decl = ST->searchEnclosing(varNode->getName());
			//Decl now points to arrayDecl or varDecl or an array
			typeDeclNode* declInfo = dynamic_cast<typeDeclNode*> (decl);
			
			return declInfo->getType()->getTypeName();
		}
		cerr << "none of them are types..." << endl;
		exit(EXIT_FAILURE);
}
