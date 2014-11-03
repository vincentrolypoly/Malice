
#ifndef AUX_H
#define AUX_H

class ExpressionASTNode;
class SymbolTable;
class typeNode;
class returnNode;
class CFG;
#include <string>
#include <deque>

using namespace std;

string getRealType(ExpressionASTNode *node, SymbolTable *ST);
bool isArrayable(typeNode *t);
deque<returnNode*>* getReturnNodes(CFG* c);
bool isArray(ExpressionASTNode *e, SymbolTable *ST);
bool isEvaluatable(ExpressionASTNode *e);
bool isReturnable(typeNode *t);
bool isSameType(string LHS, string RHS);
int evaluate(ExpressionASTNode *e);
bool isRef(ExpressionASTNode* e, SymbolTable *ST);
void cleanUp();	
void printError(int lineNo);

#endif

