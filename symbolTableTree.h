#include "symbolTable.h"



class SymbolTableTreeNode
{
	public:
	SymbolTable* st;
	SymbolTableTreeNode* sameLevel;
	SymbolTableTreeNode* nextLevel;

	SymbolTableTreeNode(SymbolTable* symT) {
		this->st = symT;
	}

	void addSameLevel() {
		SymbolTable* temp = new SymbolTable(st->encSymbolTable);
		this->sameLevel = new SymbolTableTreeNode(temp);
	}

	void addNextLevel() {
		SymbolTable* temp = new SymbolTable(st);
		this->nextLevel = new SymbolTableTreeNode(temp);
	}


};


class SymbolTableTree
{
	public:
	SymbolTableTreeNode* root;
	
	SymbolTableTree() {
		root = new SymbolTableTreeNode(NULL);
	}

};
