
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LBRACKET = 258,
     RBRACKET = 259,
     T_WAS = 260,
     T_BECAME = 261,
     T_SAID = 262,
     T_SPOKE = 263,
     T_COUNT = 264,
     T_WOKEUP = 265,
     T_TO = 266,
     T_DRANK = 267,
     T_ATE = 268,
     T_TYPELETTER = 269,
     T_TYPENUMBER = 270,
     T_TYPESENTENCE = 271,
     T_CONNECT = 272,
     T_COMMA = 273,
     T_PERHAPS = 274,
     T_EITHER = 275,
     T_TOO = 276,
     T_END = 277,
     T_FOUND = 278,
     T_OPENED = 279,
     T_CLOSED = 280,
     T_PIECE = 281,
     T_HAD = 282,
     T_ARRAYACCESS = 283,
     T_SO = 284,
     T_OR = 285,
     T_MAYBE = 286,
     T_UNSUREWHICH = 287,
     T_OF = 288,
     T_WHATWAS = 289,
     T_QUESTIONMARK = 290,
     T_CONTAINED = 291,
     T_POINTER = 292,
     T_CLOSELOOP = 293,
     T_BECAUSE = 294,
     T_LOOP = 295,
     T_PROCEDURE = 296,
     T_ROOM = 297,
     T_FOREVER = 298,
     T_LENGTH = 299,
     TNUMBER = 300,
     TLETTER = 301,
     T_IDENT = 302,
     T_ERROR = 303,
     TPLUS = 304,
     TMINUS = 305,
     TEQU = 306,
     TMUL = 307,
     TDIV = 308,
     TLESS = 309,
     TGREATER = 310,
     TBOOLEQU = 311,
     NOT = 312,
     TOR = 313,
     TAND = 314,
     TMOD = 315,
     TXOR = 316,
     TLESSEQUAL = 317,
     TGREATEREQUAL = 318,
     TBOOLOR = 319,
     TBOOLAND = 320,
     T_BOOLNOT = 321,
     TNOTEQUAL = 322,
     T_STRING = 323
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 29 "Front-End-Compiler/parser.y"

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



/* Line 1676 of yacc.c  */
#line 151 "Front-End-Compiler/parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

