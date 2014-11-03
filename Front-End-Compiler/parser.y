%{

#include "auxillaryMethods.hpp"
#include "semanticChecker.hpp"
#include "ASTAll.hpp"

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

programNode *startNode;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

void yyerror(const char *s);
%}

%union {
	int numVal;
	char letterVal;
	char* idName;
	char* stringVal;
	int operate;	
	declListNode *dec;
	procedureDeclNode *proc;
	functionDeclNode *func;
	declNode *decl;
	typeDeclNode *vardec;
	typeNode *types;
	ExpressionASTNode *exp;
    binaryOp bOp;
	callNode *caller;
	actualParamsNode *param;
	bodyNode *body;
	functionArgumentNode *args;
	bool reference;
 	statementListNode *sl;
	statementNode *stat;
	variableASTNode *var;
	arrayAccessIdentifier *arr;
	branchingNodes *branches;
	branchingNode *branch;
	compoundStatement *CS;
	perhapsDeclAndBody *PDB;
}

%locations

%token LBRACKET
%token RBRACKET

%token T_WAS
%token T_BECAME
%token T_SAID
%token T_SPOKE

%token T_COUNT
%token T_WOKEUP
%token T_TO
%token T_DRANK
%token T_ATE
%token T_TYPELETTER
%token T_TYPENUMBER
%token T_TYPESENTENCE
%token T_CONNECT
%token T_COMMA
%token T_PERHAPS
%token T_EITHER
%token T_TOO
%token T_END
%token T_FOUND
%token T_OPENED
%token T_CLOSED
%token T_PIECE
%token T_HAD
%token T_ARRAYACCESS
%token T_SO
%token T_OR
%token T_MAYBE
%token T_UNSUREWHICH
%token T_OF
%token T_WHATWAS
%token T_QUESTIONMARK
%token T_CONTAINED
%token T_POINTER
%token T_CLOSELOOP
%token T_BECAUSE
%token T_LOOP
%token T_PROCEDURE
%token T_ROOM
%token T_FOREVER
%token T_LENGTH
%token <numVal> TNUMBER
%token <letterVal> TLETTER
%token <idName> T_IDENT T_ERROR
%token <operate> TPLUS TMINUS TEQU TMUL TDIV TLESS TGREATER TBOOLEQU NOT TOR TAND TMOD TXOR TLESSEQUAL TGREATEREQUAL TBOOLOR TBOOLAND T_BOOLNOT TNOTEQUAL
%token <stringVal> T_STRING


%type <dec> declarations
%type <proc> procedure
%type <func> function
%type <decl> declaration
%type <vardec> variabledeclarations
%type <types> type
%type <exp> ors xors ands sums multi Expression boolOR	boolFactor unaryOp val of 
%type <bOp> sumop multiop booloperator 
%type <caller> call
%type <param> params param
%type <body> body 
%type <args> arguments argument
%type <reference> maybepointer
%type <sl>	statementList perhapsBody perhapsCommands
%type <stat> statement command perhaps perhapsCommand loop forloop
%type <var> variable
%type <arr> arrayaccess
%type <branches> branchingOption
%type <CS> loopBody commandList
%type <PDB> perhapsDeclAndBody
%left TPLUS TMINUS TMUL TDIV TLESS TGREATER TLESSEQUAL TGREATEREQUAL TBOOLEQU TBOOLOR TBOOLAND
%right TEQU
%left T_END
%left T_CONNECT
%left T_COMMA
%start program
%%
program       : declarations { startNode = new programNode($1) ;}
			  ;

procedure     : T_PROCEDURE T_IDENT LBRACKET arguments RBRACKET T_OPENED body T_CLOSED
				{ $$ = new procedureDeclNode($2, $7, $4, yylloc.first_line);}
			  ;
function      : T_ROOM T_IDENT LBRACKET arguments RBRACKET T_CONTAINED type T_OPENED body T_CLOSED 
				{ $$ = new functionDeclNode($2, $7, $9, $4,yylloc.first_line);}
			  ;  


declarations  : declarations declaration { $1->addChild($2); $$ = $1;}
		      | /*empty*/				 { $$ = new declListNode();}
              ;

declaration   : procedure { $$ = $1;}
              | function  { $$ = $1;}
 			  | variabledeclarations {$$ = $1;}
              ;

variabledeclarations: T_IDENT T_WAS type of connOrEnd { $$ = new varDeclNode($1,$3,$4, false, false,yylloc.first_line);}
			 	    | T_IDENT T_HAD Expression type connOrEnd { $$ = new arrDeclNode($1, $4, $3, true,yyloc.first_line);}
					| T_IDENT T_WAS type T_OF Expression T_FOREVER connOrEnd { $$ = new varDeclNode($1,$3,$5, true, false,yylloc.first_line);}
			        ; 

of            : T_OF Expression { $$ = $2;}
			  | /*empty*/       { $$ = NULL;}
			  ;
connOrEnd     : connective
              | endTerm
              ;

arguments	  : argument {$$ = $1;}
 			  | /*empty*/{$$ = new functionArgumentNode();}
			  ;

argument      : maybepointer type T_IDENT T_COMMA argument	{$5->addArg(new varDeclNode($3, $2, NULL, false, $1,yylloc.first_line));$$ = $5;}
			  | maybepointer type T_IDENT	{$$ = new functionArgumentNode(new varDeclNode($3,$2,NULL,false,$1,yylloc.first_line));}
			  ; 


body		  : declarations commandList 		{ $$ = new bodyNode($2,$1);} 
			  | /*empty*/						{ $$ = new bodyNode();}
			  ;              
call          : T_IDENT LBRACKET params RBRACKET { $$ = new callNode($1, $3,yylloc.first_line);}
			  ;
params        : param			    			 { $$ = $1 ;}
              | /*empty*/					     { $$ = new actualParamsNode();}
			  ;
param         :  Expression T_COMMA param				 { $3->addParams($1); $$ = $3; }
			  |  Expression 			  				 { $$ = new actualParamsNode($1); }
              ;
maybepointer  : T_POINTER						{ $$ = true;}
			  | /*empty*/						{ $$ = false;}
              ;
        
commandList   : commandList statementList		{ $1->addStatementList($2); $$ = $1;}
              | statementList					{ $$ = new compoundStatement($1);}
              ;
statementList : statement connective statementList {$3->addStatement($1); $$ = $3;}
		      | statement endTerm				{$$ = new statementListNode($1);}
	          | command 						{$$ = new statementListNode($1);}
              | T_END                        	{$$ = new statementListNode();}
			  ;

			  
command		  : perhaps 						   {$$ = $1;}
			  | T_WHATWAS variable T_QUESTIONMARK  {$$ = new whatWasNode($2, yylloc.first_line);}
			  | loop 							   {$$ = $1;}	   
		      | T_OPENED body T_CLOSED			   {$$ = $2;}
			  | forloop						  	   {$$ = $1;}				
			  ;


connective	  : T_CONNECT
	          | T_COMMA
			  ;  

statement	  : variable T_ATE					 {$$ = new incrementNode($1,yyloc.first_line);}
			  | variable T_DRANK  		    	 {$$ = new decrementNode($1,yylloc.first_line);}
		 	  | Expression T_SAID 				 {$$ = new printNode($1, yylloc.first_line);}
		 	  | variable T_BECAME Expression  	 {$$ = new assignNode($1, $3, yylloc.first_line);}
			  | Expression T_SPOKE 				 {$$ = new printNode($1, yylloc.first_line);}
	          | T_FOUND Expression				 {$$ = new returnNode($2, yylloc.first_line);}
		      | T_IDENT LBRACKET params RBRACKET {$$ = new callNodeStatement($1,$3,yylloc.first_line);}
		  	  ;
variable      : T_IDENT {$$ = new identifierASTNode($1, yylloc.first_line);} 
		      | arrayaccess {$$ = $1;}
			  ;


endTerm       : T_TOO 
			  | T_END
		      ;
           
type		  : T_TYPELETTER { $$ = new letterTypeNode();}
			  | T_TYPENUMBER { $$ = new intTypeNode();}
	          | T_TYPESENTENCE {$$ = new sentenceTypeNode();}
			  ;
              
Expression	  : Expression TBOOLOR boolOR     { $$ = new binaryExpressionASTNode($1,$3,bOr,yylloc.first_line);}
			  | boolOR						  {$$ = $1;}
		      ;

boolOR		  : boolOR TBOOLAND boolFactor	 {$$ = new binaryExpressionASTNode($1, $3, bAnd,yylloc.first_line);}
			  | boolFactor					 {$$ = $1;}
			  ;
    				
boolFactor    : boolFactor booloperator ors	{$$ = new binaryExpressionASTNode($1,$3,$2,yylloc.first_line);}
			  | ors
			  ;  

ors           : ors TOR xors  {$$ = new binaryExpressionASTNode($1,$3,bitOr,yylloc.first_line);}
			  | xors				{ $$ = $1;}
		      ;
              
xors		  : xors TXOR ands {$$ = new binaryExpressionASTNode($1, $3, xOr,yylloc.first_line);}
			  | ands 		   {$$ = $1;}
			  ;
ands	      : ands TAND sums {$$ = new binaryExpressionASTNode($1,$3,bitAnd,yylloc.first_line);}
		      | sums 		   {$$ = $1;}
		      ;
sums	      : sums sumop multi {$$ = new binaryExpressionASTNode($1,$3,$2,yylloc.first_line);}
			  | multi			 {$$ = $1;}
			  ;
sumop         : TPLUS  {$$ = iplus;}
              | TMINUS {$$ = subtract;}
              ;
multi 		  : multi multiop val {$$ = new binaryExpressionASTNode($1,$3,$2,yylloc.first_line);}
			  | val				  {$$ = $1;}
			  ;
multiop       : TMUL {$$ = mul;}
              | TDIV {$$ = idiv;}
              | TMOD {$$ = mod;}
              ;

arrayaccess   : T_IDENT T_ARRAYACCESS Expression T_PIECE  { $$ = new arrayAccessIdentifier($1, $3, yylloc.first_line);}

      
val    		  : TLETTER  { $$ = new letterASTNode($1);}
	          | T_STRING { $$ = new sentenceASTNode($1);}
			  | variable { $$ = $1;}
			  | call	 { $$ = $1;}
			  | TNUMBER  { $$ = new numberASTNode($1);}
			  | unaryOp	 { $$ = $1;}
			  | LBRACKET Expression RBRACKET {$$ = $2;}
			  | T_LENGTH T_IDENT { $$ = new arrayLengthNode($2, yylloc.first_line); }		  
			  ;

unaryOp       : NOT val {$$ = new unaryExpressionASTNode($2, bitNot,yylloc.first_line);}
		      | TMINUS val {$$ = new unaryExpressionASTNode($2, neg,yylloc.first_line);}
			  | TPLUS val {$$ = new unaryExpressionASTNode($2, unPlus,yylloc.first_line);}
			  | T_BOOLNOT val {$$ = new unaryExpressionASTNode($2, boolNOT,yylloc.first_line);}
              ;

booloperator  : TLESS		{$$ = lessThan;}
			  | TGREATER	{$$ = greaterThan;}
			  | TBOOLEQU	{$$ = equalTo;}
	          | TNOTEQUAL	{$$ = notEqualTo;}
              | TLESSEQUAL	{$$ = lessEqu;}
              | TGREATEREQUAL {$$ = greaterEqu;}
	          ;


loop          : T_LOOP LBRACKET Expression RBRACKET T_BECAUSE loopBody T_CLOSELOOP   
				 {$$ = new loopNode($3,$6, yylloc.first_line);}
			  ;
loopBody	  : commandList {$$ = $1;}
			  ;

forloop		  : variable T_COUNT Expression T_TO Expression loopBody T_WOKEUP { $$ = new forLoopNode($1, $3, $5, $6, yylloc.first_line);}
			  ;           
perhaps       : choice LBRACKET Expression RBRACKET T_SO perhapsBody branchingOption T_UNSUREWHICH 
				{ $$ = new ifStatementNode($3, $6, $7, yylloc.first_line);}
              

choice	      : T_PERHAPS
			  | T_EITHER
			  ;

branchingOption: T_MAYBE LBRACKET Expression RBRACKET T_SO perhapsBody branchingOption
					{ $7->addBranch(new branchingNode($3,$6,yylloc.first_line)); $$ = $7;}
			   |  T_OR perhapsBody { $$ = new branchingNodes(new branchingNode(NULL,$2,yylloc.first_line));} 
               | /*empty*/		   { $$ = new branchingNodes();}
               ;

perhapsCommand: T_WHATWAS variable T_QUESTIONMARK {$$ = new whatWasNode($2, yylloc.first_line);}
		       | loop  								{$$ = $1;}
		       | T_OPENED perhapsDeclAndBody T_CLOSED		{$$ = $2;}
               | statement connOrEnd						{$$ = $1;}
               | perhaps 						{$$ = $1;}
			   | T_END						    {$$ = NULL;}
		       ;

perhapsCommands: perhapsCommand perhapsCommands  {$2->addStatement($1); $$ = $2; }
               | perhapsCommand { $$ = new statementListNode($1);}
               ;
perhapsBody: perhapsCommands { $$ =$1; }
           ;

perhapsDeclAndBody: variabledeclarations perhapsBody	{$$ = new perhapsDeclAndBody($1,$2);} 
                  | perhapsBody							{$$ = new perhapsDeclAndBody(NULL,$1);}
                  | /*empty*/							{$$ = new perhapsDeclAndBody();}
                  ;

/* THINGS TO TEST IN MALICE COMPILER
 * does local scope of variableso override global? yes, even when using "opened" and "closed". 
 * Applicable to
 * function and procedure names too.
 * which scope sre function parameters in? 
 * do you have to have a return statement when you make a function? yes, 
 * find all possible paths and all of them must lead to a func decl 
 * and must have a return statement on the way
 *
 * new block scopes can still have return statements in them to the nearest function
 * complete return statements
 * how does spider work? can treat spiders as reference to a single int or an array can only pass array. 
 * Dont know if there is a way to pass single value by reference. 
 * ref compiler does not care if return value is a single value or an array
 * will try to assign it to a number regardless
 * giving a spider number arg and giving an array and then returning a number is valid semantics
 */

/* THINGS TO COMPLETE
 * split things into .cpp files. Use header files only for declaration
 */

%%


void yyerror(const char *s) {

	if(yylloc.first_line)
		cerr << s << ": From line:" << yylloc.first_line << "."<< yylloc.first_column << "-"<< yylloc.last_line<< "." <<yylloc.last_column <<  endl;
		cleanUp();
	
	// might as well halt now:
	exit(-1);
}
