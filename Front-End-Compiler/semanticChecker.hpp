
#ifndef SEMANTICCHECK_H
#define SEMANTICCHECK_H

#include "checkInterface.hpp"

#include <iostream>

class assignNode;
class returnNode;
class identifierASTNode;
class callNodeStatement;
class incrementNode;
class arrayAccessIdentifier;
class decrementNode;
class bodyNode;
class callNode;
class varDeclNode;
class arrDeclNode;
class binaryExpressionASTNode;
class unaryExpressionASTNode;
class printNode;
class procedureDeclNode;
class branchingNode;
class functionDeclNode;
class ifStatementNode;
class whatWasNode;
class perhapsDeclAndBody;
class loopNode;
class programNode;
class SymbolTable;
class letterASTNode;
class sentenceASTNode;
class arrayLengthNode;
class forLoopNode;

class semanticChecker: public CheckInterface {
  public:
	void check(assignNode *n, SymbolTable *currentST);
	void check(returnNode *n, SymbolTable *currentST);
	void check(identifierASTNode *n, SymbolTable *currentST);
	void check(callNodeStatement *n, SymbolTable *currentST);
	void check(incrementNode *n, SymbolTable *currentST);
	void check(arrayAccessIdentifier *n, SymbolTable *currentST);
	void check(decrementNode *n, SymbolTable *currentST);
	void check(bodyNode *n, SymbolTable *currentST);
	void check(callNode *n, SymbolTable *currentST);
	void check(varDeclNode *n, SymbolTable *currentST);
	void check(arrDeclNode *n, SymbolTable *currentST);
	void check(binaryExpressionASTNode *n, SymbolTable *currentST);
	void check(unaryExpressionASTNode *n, SymbolTable *currentST);
	void check(printNode *n, SymbolTable *currentST);
	void check(procedureDeclNode *n, SymbolTable *currentST);
	void check(functionDeclNode *n, SymbolTable *currentST);
	void check(branchingNode *n, SymbolTable *currentST);
	void check(ifStatementNode *n, SymbolTable *currentST);
	void check(whatWasNode *n, SymbolTable *currentST);
	void check(perhapsDeclAndBody *n, SymbolTable *currentST);
	void check(loopNode *n, SymbolTable *currentST);
	void check(programNode *n, SymbolTable *currentST);
	void check(numberASTNode *n, SymbolTable *currentST);
    void check(letterASTNode *n, SymbolTable *currentST);
    void check(sentenceASTNode *n, SymbolTable *currentST);
    void check(arrayLengthNode *n, SymbolTable *currentST);
	void check(forLoopNode *n, SymbolTable *currentST);
};

#endif

