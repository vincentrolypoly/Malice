
#ifndef CHECKINTERFACE_H
#define CHECKINTERFACE_H

class assignNode;
class returnNode;
class identifierASTNode;
class callNodeStatement;
class incrementNode;
class decrementNode;
class bodyNode;
class callNode;
class varDeclNode;
class arrDeclNode;
class binaryExpressionASTNode;
class unaryExpressionASTNode;
class printNode;
class procedureDeclNode;
class functionDeclNode;
class branchingNode;
class ifStatementNode;
class whatWasNode;
class perhapsDeclAndBody;
class loopNode;
class programNode;
class arrayAccessIdentifier;
class SymbolTable;
class numberASTNode;
class letterASTNode;
class sentenceASTNode;
class arrayLengthNode;
class forLoopNode;

using namespace std;

class CheckInterface 
{
	public:
	virtual void check(assignNode *n, SymbolTable *currentST) = 0;
	virtual void check(returnNode *n, SymbolTable *currentST) = 0;
	virtual void check(identifierASTNode *n, SymbolTable *currentST) = 0;
	virtual void check(callNodeStatement *n, SymbolTable *currentST) = 0;
	virtual void check(incrementNode *n, SymbolTable *currentST) = 0;
	virtual void check(arrayAccessIdentifier *n, SymbolTable *currentST) = 0;
	virtual void check(decrementNode *n, SymbolTable *currentST) = 0;
	virtual void check(bodyNode *n, SymbolTable *currentST) = 0;
	virtual void check(callNode *n, SymbolTable *currentST) = 0;
	virtual void check(varDeclNode *n, SymbolTable *currentST) = 0;
	virtual void check(arrDeclNode *n, SymbolTable *currentST) = 0;
	virtual void check(binaryExpressionASTNode *n, SymbolTable *currentST) = 0;
	virtual void check(unaryExpressionASTNode *n, SymbolTable *currentST) = 0;
	virtual void check(printNode *n, SymbolTable *currentST) = 0;
	virtual void check(procedureDeclNode *n, SymbolTable *currentST) = 0;
	virtual void check(functionDeclNode *n, SymbolTable *currentST) = 0;
	virtual void check(branchingNode *n, SymbolTable *currentST) = 0;
	virtual void check(ifStatementNode *n, SymbolTable *currentST) = 0;
	virtual void check(whatWasNode *n, SymbolTable *currentST) = 0;
	virtual void check(perhapsDeclAndBody *n, SymbolTable *currentST) = 0;
	virtual void check(loopNode *n, SymbolTable *currentST) = 0;
	virtual void check(programNode *n, SymbolTable *currentST) = 0;
	virtual void check(numberASTNode *n, SymbolTable *currentST) = 0;
    virtual void check(letterASTNode *n, SymbolTable *currentST) = 0;
    virtual void check(sentenceASTNode *n, SymbolTable *currentST) = 0;
    virtual void check(arrayLengthNode *n, SymbolTable *currentST) = 0;
	virtual void check(forLoopNode *n, SymbolTable *currentST) = 0;
};

#endif

