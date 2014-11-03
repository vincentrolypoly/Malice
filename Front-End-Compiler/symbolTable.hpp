
#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <string>
#include <map>


using namespace std;
class ASTNodes;
class SymbolTable
{
  public:
    typedef pair<string, ASTNodes*> objectPair;
    SymbolTable *encSymbolTable;
    map<string, ASTNodes*>* dictionary;

    SymbolTable(SymbolTable *est);
    ~SymbolTable();
    void add(string name, ASTNodes *obj);
    ASTNodes* searchCurrent(string name);
    ASTNodes* searchEnclosing(string name);
};

#endif

