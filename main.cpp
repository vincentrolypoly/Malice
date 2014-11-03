#include "Front-End-Compiler/ASTAll.hpp"
#include "Front-End-Compiler/parser.hpp"
#include "Front-End-Compiler/semanticChecker.hpp"
#include "Front-End-Compiler/symbolTable.hpp"
#include "Back-End-Compiler/codeGenerator.hpp"

#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern programNode* startNode;

void setUp(SymbolTable *ST);
void compileFile(char* fileName);
char* removeAlice(char* fileName);
/*We know that we should not have put declarations into 
 *header files but we only knew after we got our C++ enigma 
 *feedback. By the time we got it back we had already written
 *the majority of the implementation using declarations inside
 *header files.  
 */
main(int argc, char** argv) {
	cout << endl;
	cout << "==================START==================" << endl;
	cout << endl;
	cout << endl;

	FILE *myfile = fopen(argv[1], "r");
    // make sure file given is a valid file
	if (!myfile) {
		cout << "file does not exist" << endl;
		cout << endl;
		cout << endl;
		cout << "===================END===================" << endl;
		cout << endl;
		cout << endl;
		return -1;
	}
	
    // set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
    // parse through the input until there is no more (lexical and syntax)
	cout << "=============CHECKING=SYNTAX=============" << endl;
	cout << endl;
	cout << endl;	
	do {
		yyparse();
	} while (!feof(yyin));
	cout << "================SYNTAX=OK!===============" << endl;
	cout << endl;
	cout << endl;
	//Make a new semantic checker
	semanticChecker *semCheck = new semanticChecker();
	//Make a new symbol table
	SymbolTable *ST = new SymbolTable(NULL);
	//Initialised the symbol table
	setUp(ST);
	cout << "===========CHECKING=SEMANTICS============" << endl;
	cout << endl;
	startNode->accept(semCheck, ST); 
	cout << "===============SEMANTICS=OK!=============" << endl;
	cout << endl;
	cout << endl;
	char* fileName = argv[1];
	fileName = removeAlice(fileName);
	codeGenerator* codeGen = new codeGenerator(fileName);
	startNode->accept(codeGen, ST);
	
	compileFile(fileName);

	//Clean up
	delete startNode;
	delete codeGen;
	delete ST;
	delete semCheck;
	cout << "===================END===================" << endl;
	cout << endl;
	cout << endl;
}

char* removeAlice(char* fileName){
	char* answer = strrchr(fileName, '/');
	char* extension = strrchr(fileName, '.');
	if(answer != NULL){
		answer++;
	}else{
		answer = fileName;
	}
	*extension = '\0';
	const char* newExt = ".asm";
	strncat(answer, newExt, 4);
	return answer;
}

void compileFile(char* fileName)
{
    cout << endl;
	cout << endl;

    cout << "==========ASSEMBLING=NASM=FILE===========" << endl;
	cout << endl;
	cout << endl;


    string commandString = string("nasm -f elf64 ") + string(fileName);

    char* woutExt = fileName;
	char* extension = strrchr(woutExt, '.');
   	*extension = '\0';
    //Extension clipped off
    const char* newExt = ".o";
    string linkerString = string("gcc ") + string(woutExt) + string(newExt) + " -o " + string(woutExt); 
    
    system(commandString.c_str());
    system(linkerString.c_str());
}

void setUp(SymbolTable* ST){
	string sentence = "sentence";
	string number = "number";
	string letter = "letter";
	ST->add(sentence , new sentenceTypeNode());
	ST->add(number , new intTypeNode());
	ST->add(letter, new letterTypeNode());
}
