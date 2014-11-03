
#ifndef EXPRASTNODE_H
#define EXPRASTNODE_H

#include "ASTNodes.hpp"

class CheckInterface;
class SymbolTable;

#define bin_boolOp_pos 14
#define bin_compOp_pos 8
#define un_boolOp_pos 3


enum binaryOp { iplus, subtract , idiv, mul , mod , bitAnd,
				 bitOr , xOr, lessThan, greaterThan, equalTo, 
				notEqualTo, lessEqu, greaterEqu, bAnd, bOr};
enum unaryOp  { neg, bitNot, unPlus, boolNOT };

class ExpressionASTNode: public ASTNodes{
  public:
	virtual void printVal()=0;
	virtual void accept(CheckInterface *c, SymbolTable *currentST)=0;
	virtual void destroyAST()=0;
	virtual int weight()=0;
};

#endif

