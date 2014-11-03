
#include "symbolTable.hpp"
#include "ASTAll.hpp"
#include <string>
#include <map>

typedef pair<string, ASTNodes*> objectPair;


// this is the constructor for the current symbol table
// which links it to those tables already constructed for the parser
// so each symbol table holds a 'reference' to those tables in the levels above it
SymbolTable::SymbolTable(SymbolTable *est)
{       
    encSymbolTable = est;
	dictionary = new map<string, ASTNodes*>();
}

SymbolTable::~SymbolTable()
{
	map<string, ASTNodes*>::iterator it;
	for(it = dictionary->begin(); it != dictionary->end(); ++it){
		//delete it->second;
	}

	dictionary->clear();
}

void SymbolTable::add(string name, ASTNodes *obj)
{
    dictionary->insert(objectPair(name, obj));
}

ASTNodes* SymbolTable::searchCurrent(string name)
{
    ASTNodes* searchItem;
 		
	searchItem = (dictionary->find(name))->second;
    return searchItem;
}

ASTNodes* SymbolTable::searchEnclosing(string name)
{
    ASTNodes* searchItem;
    SymbolTable *curr = this;
    
    while(curr != NULL)
    {	          
		 searchItem = curr->searchCurrent(name);
         if(searchItem != NULL)
        {
            return searchItem;
        }

        curr = curr->encSymbolTable;
    }
    
    return searchItem;
}

