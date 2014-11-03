#ifndef check_H
#define check_H

#include "../Front-End-Compiler/checkInterface.hpp"
#include "codeGenEnv.hpp"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string>
#include <deque>

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
class IA32Nodes;
class functionArgumentNode;
class forLoopNode;

using namespace std;

class codeGenerator: public CheckInterface{ 
  private:
	char *fileName;
	ofstream file;
	deque<string>* regAvail;
	deque<string>* allRegs;
	deque<string>* savedRegs;
	int wordSize;
	codeGenEnv* currentScope;
	int loopCounter;
	int stringCounter;
	int ifCounter;
	int elseCounter;
	int boolCounter;
	deque<IA32Nodes*>* instr;
	deque<IA32Nodes*>* decls; 
	deque<IA32Nodes*>* global;
	deque<deque<IA32Nodes*>*>* funcStack; 
	functionArgumentNode* argBuffer;
	int scopeCounter;
	functionArgumentNode* emptyDummy;
  public:
	codeGenerator(char* f);
	bool isMember(string reg);
	void saveRegs();
	void restoreRegs();
	void clearMem();
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
	void postOptimise();
	void addRegs();
	void setUp();
	void printFile();
	void add(IA32Nodes* n);
	int nextLoopCount();
	int nextStringCount();
	int nextIfCount();
	int nextElseCount();
	int nextBoolCounter();
	void returnToSystem();
};

#endif
