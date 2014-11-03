%{
#include <iostream>

using namespace std;

#include "ASTAll.hpp"
#include "parser.hpp"
#include <string>
#define OPERATE(o) (yylval.operate = o)

int yycolumn = 1;

#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1; \
    yycolumn += yyleng;
#define YY_DECL extern "C" int yylex()
%}

%option yylineno

TPROC   "The looking-glass"
TNUM    "number"
TLET    "'"[a-zA-Z]"'"

IDENT   [a-zA-Z][a-zA-z0-9]*
STRINGS [""][^""]*[""]
NUMBER  [0-9]+
PERHAPS "perhaps"
AND     "and"
BUT     "but"
THEN    "then"
COMMA   ","
COMMENTS "###".*\n 
%%

[ \t] ;

\n        { yycolumn = 1; }
"<="	  { return OPERATE(TLESSEQUAL);}
">="	  { return OPERATE(TGREATEREQUAL);}
"="		  { return OPERATE(TEQU);}
"+"		  { return OPERATE(TPLUS);}
"-"		  { return OPERATE(TMINUS);}
"/"		  { return OPERATE(TDIV);}
"*"       { return OPERATE(TMUL);}
"^"		  { return OPERATE(TXOR);}
"%"		  { return OPERATE(TMOD);}
"&"		  { return OPERATE(TAND);}
"|"		  { return OPERATE(TOR);}
"~"		  { return OPERATE(NOT);}
"||"	  { return OPERATE(TBOOLOR);}
"&&"      { return OPERATE(TBOOLAND);}
"("	      { return LBRACKET;}
")"		  { return RBRACKET;}
"=="      { return OPERATE(TBOOLEQU); }
">"	      { return OPERATE(TGREATER); }
"<"		  { return OPERATE(TLESS); }
"!="      { return OPERATE(TNOTEQUAL); }
"!"       { return OPERATE(T_BOOLNOT); }

"new line"      { yylval.stringVal = strdup("\"\\n\""); return T_STRING;}
"was bigger than"  { return OPERATE(TGREATER); }
"was greater than" { return OPERATE(TGREATER); }
"was larger than"  { return OPERATE(TGREATER); }

"was smaller than" { return OPERATE(TLESS); }
"was less than"    { return OPERATE(TLESS); }

"added to"         { return OPERATE(TPLUS); }
"plus"			   { return OPERATE(TPLUS); }

"divided by" 	   { return OPERATE(TDIV);  }
"taken away from"  { return OPERATE(TMINUS);}
"subtracted from"  { return OPERATE(TMINUS);}

"was equal to"     { return OPERATE(TBOOLEQU);}
"was the same as"  { return OPERATE(TBOOLEQU);}

"was greater than or equal to" { return OPERATE(TGREATEREQUAL);}
"was at least as big as"       { return OPERATE(TGREATEREQUAL);}

"was at least as small as" 	   { return OPERATE(TLESSEQUAL);}
"was less than or equal to"    { return OPERATE(TLESSEQUAL);}

"mod" 			  {return OPERATE(TMOD);}

"multiplied by"   {return OPERATE(TMUL);}

"was not equal to" {return OPERATE(TNOTEQUAL);}
"was not the same as" {return OPERATE(TNOTEQUAL);}


"of"          { return T_OF;}
"was a"	      { return T_WAS; }
"became"      { return T_BECAME; }
"turned into" { return T_BECAME; }

"said Alice"  { return T_SAID; }
"spoke"       { return T_SPOKE; }
"what was"    { return T_WHATWAS; }
"?"	  		  { return T_QUESTIONMARK; }
"Alice found" { return T_FOUND; }
"had"         { return T_HAD; }
"spider"      { return T_POINTER; }
"forever"	  { return T_FOREVER; }
"as long as"  { return T_LENGTH; }
"counted from" { return T_COUNT; }


"piece"       { return T_PIECE; }

"drank"    { return T_DRANK; }
"ate"      { return T_ATE; }
"grew"	   { return T_ATE; }
"shrank"   { return T_DRANK; }

"letter"   { return T_TYPELETTER; }
"number"   { return T_TYPENUMBER; }
"sentence" { return T_TYPESENTENCE;   }

"."		  		{ return T_END; }
"too."   		{ return T_TOO; } 
"opened"  		{ return T_OPENED; }
"closed"  		{ return T_CLOSED; }
"enough times"  { return T_CLOSELOOP;}
"times" 		{ return OPERATE(TMUL);}
"so"      		{ return T_SO; }
"or maybe"   	{ return T_MAYBE; }
"or"      		{ return T_OR; }
"to" 			{ return T_TO; }
"and then Alice woke up" { return T_WOKEUP; } 
"because Alice was unsure which" { return T_UNSUREWHICH; }
"eventually" {return T_LOOP; }
"because"    {return T_BECAUSE;}
"The room" { return T_ROOM;}
"contained a" {return T_CONTAINED;}
{TPROC}   { return T_PROCEDURE; }
{AND}     { return T_CONNECT; }
{BUT}     { return T_CONNECT; }
{THEN}	  { return T_CONNECT; }
{COMMA}   { return T_COMMA; }
"either"  { return T_EITHER; }
{PERHAPS} { return T_PERHAPS; }
{STRINGS} { yylval.stringVal = strdup(yytext); return T_STRING;}
{NUMBER}  { yylval.numVal = atoi(yytext); return TNUMBER;}
{TLET} 	  { yylval.letterVal = *(yytext+1); return TLETTER;}
"'s"      { return T_ARRAYACCESS;}
{COMMENTS} ;
{IDENT}   { yylval.idName = strdup(yytext); return T_IDENT; }

.        { yylval.idName = strdup(yytext); return T_ERROR;}
%%
