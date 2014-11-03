
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Front-End-Compiler/parser.y"


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


/* Line 189 of yacc.c  */
#line 102 "Front-End-Compiler/parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
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



/* Line 214 of yacc.c  */
#line 237 "Front-End-Compiler/parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

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


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 262 "Front-End-Compiler/parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   296

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNRULES -- Number of states.  */
#define YYNSTATES  207

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    14,    25,    28,    29,    31,    33,
      35,    41,    47,    55,    58,    59,    61,    63,    65,    66,
      72,    76,    79,    80,    85,    87,    88,    92,    94,    96,
      97,   100,   102,   106,   109,   111,   113,   115,   119,   121,
     125,   127,   129,   131,   134,   137,   140,   144,   147,   150,
     155,   157,   159,   161,   163,   165,   167,   169,   173,   175,
     179,   181,   185,   187,   191,   193,   197,   199,   203,   205,
     209,   211,   213,   215,   219,   221,   223,   225,   227,   232,
     234,   236,   238,   240,   242,   244,   248,   251,   254,   257,
     260,   263,   265,   267,   269,   271,   273,   275,   283,   285,
     293,   302,   304,   306,   314,   317,   318,   322,   324,   328,
     331,   333,   335,   338,   340,   342,   345,   347
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    73,    -1,    41,    47,     3,    78,     4,
      24,    80,    25,    -1,    42,    47,     3,    78,     4,    36,
      92,    24,    80,    25,    -1,    73,    74,    -1,    -1,    71,
      -1,    72,    -1,    75,    -1,    47,     5,    92,    76,    77,
      -1,    47,    27,    93,    92,    77,    -1,    47,     5,    92,
      33,    93,    43,    77,    -1,    33,    93,    -1,    -1,    88,
      -1,    91,    -1,    79,    -1,    -1,    84,    92,    47,    18,
      79,    -1,    84,    92,    47,    -1,    73,    85,    -1,    -1,
      47,     3,    82,     4,    -1,    83,    -1,    -1,    93,    18,
      83,    -1,    93,    -1,    37,    -1,    -1,    85,    86,    -1,
      86,    -1,    89,    88,    86,    -1,    89,    91,    -1,    87,
      -1,    22,    -1,   110,    -1,    34,    90,    35,    -1,   107,
      -1,    24,    80,    25,    -1,   109,    -1,    17,    -1,    18,
      -1,    90,    13,    -1,    90,    12,    -1,    93,     7,    -1,
      90,     6,    93,    -1,    93,     8,    -1,    23,    93,    -1,
      47,     3,    82,     4,    -1,    47,    -1,   103,    -1,    21,
      -1,    22,    -1,    14,    -1,    15,    -1,    16,    -1,    93,
      64,    94,    -1,    94,    -1,    94,    65,    95,    -1,    95,
      -1,    95,   106,    96,    -1,    96,    -1,    96,    58,    97,
      -1,    97,    -1,    97,    61,    98,    -1,    98,    -1,    98,
      59,    99,    -1,    99,    -1,    99,   100,   101,    -1,   101,
      -1,    49,    -1,    50,    -1,   101,   102,   104,    -1,   104,
      -1,    52,    -1,    53,    -1,    60,    -1,    47,    28,    93,
      26,    -1,    46,    -1,    68,    -1,    90,    -1,    81,    -1,
      45,    -1,   105,    -1,     3,    93,     4,    -1,    44,    47,
      -1,    57,   104,    -1,    50,   104,    -1,    49,   104,    -1,
      66,   104,    -1,    54,    -1,    55,    -1,    56,    -1,    67,
      -1,    62,    -1,    63,    -1,    40,     3,    93,     4,    39,
     108,    38,    -1,    85,    -1,    90,     9,    93,    11,    93,
     108,    10,    -1,   111,     3,    93,     4,    29,   115,   112,
      32,    -1,    19,    -1,    20,    -1,    31,     3,    93,     4,
      29,   115,   112,    -1,    30,   115,    -1,    -1,    34,    90,
      35,    -1,   107,    -1,    24,   116,    25,    -1,    89,    77,
      -1,   110,    -1,    22,    -1,   113,   114,    -1,   113,    -1,
     114,    -1,    75,   115,    -1,   115,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   138,   138,   141,   144,   149,   150,   153,   154,   155,
     158,   159,   160,   163,   164,   166,   167,   170,   171,   174,
     175,   179,   180,   182,   184,   185,   187,   188,   190,   191,
     194,   195,   197,   198,   199,   200,   204,   205,   206,   207,
     208,   212,   213,   216,   217,   218,   219,   220,   221,   222,
     224,   225,   229,   230,   233,   234,   235,   238,   239,   242,
     243,   246,   247,   250,   251,   254,   255,   257,   258,   260,
     261,   263,   264,   266,   267,   269,   270,   271,   274,   277,
     278,   279,   280,   281,   282,   283,   284,   287,   288,   289,
     290,   293,   294,   295,   296,   297,   298,   302,   305,   308,
     310,   314,   315,   318,   320,   321,   324,   325,   326,   327,
     328,   329,   332,   333,   335,   338,   339,   340
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LBRACKET", "RBRACKET", "T_WAS",
  "T_BECAME", "T_SAID", "T_SPOKE", "T_COUNT", "T_WOKEUP", "T_TO",
  "T_DRANK", "T_ATE", "T_TYPELETTER", "T_TYPENUMBER", "T_TYPESENTENCE",
  "T_CONNECT", "T_COMMA", "T_PERHAPS", "T_EITHER", "T_TOO", "T_END",
  "T_FOUND", "T_OPENED", "T_CLOSED", "T_PIECE", "T_HAD", "T_ARRAYACCESS",
  "T_SO", "T_OR", "T_MAYBE", "T_UNSUREWHICH", "T_OF", "T_WHATWAS",
  "T_QUESTIONMARK", "T_CONTAINED", "T_POINTER", "T_CLOSELOOP", "T_BECAUSE",
  "T_LOOP", "T_PROCEDURE", "T_ROOM", "T_FOREVER", "T_LENGTH", "TNUMBER",
  "TLETTER", "T_IDENT", "T_ERROR", "TPLUS", "TMINUS", "TEQU", "TMUL",
  "TDIV", "TLESS", "TGREATER", "TBOOLEQU", "NOT", "TOR", "TAND", "TMOD",
  "TXOR", "TLESSEQUAL", "TGREATEREQUAL", "TBOOLOR", "TBOOLAND",
  "T_BOOLNOT", "TNOTEQUAL", "T_STRING", "$accept", "program", "procedure",
  "function", "declarations", "declaration", "variabledeclarations", "of",
  "connOrEnd", "arguments", "argument", "body", "call", "params", "param",
  "maybepointer", "commandList", "statementList", "command", "connective",
  "statement", "variable", "endTerm", "type", "Expression", "boolOR",
  "boolFactor", "ors", "xors", "ands", "sums", "sumop", "multi", "multiop",
  "arrayaccess", "val", "unaryOp", "booloperator", "loop", "loopBody",
  "forloop", "perhaps", "choice", "branchingOption", "perhapsCommand",
  "perhapsCommands", "perhapsBody", "perhapsDeclAndBody", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    72,    73,    73,    74,    74,    74,
      75,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    80,    80,    81,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      90,    90,    91,    91,    92,    92,    92,    93,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   102,   103,   104,
     104,   104,   104,   104,   104,   104,   104,   105,   105,   105,
     105,   106,   106,   106,   106,   106,   106,   107,   108,   109,
     110,   111,   111,   112,   112,   112,   113,   113,   113,   113,
     113,   113,   114,   114,   115,   116,   116,   116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     8,    10,     2,     0,     1,     1,     1,
       5,     5,     7,     2,     0,     1,     1,     1,     0,     5,
       3,     2,     0,     4,     1,     0,     3,     1,     1,     0,
       2,     1,     3,     2,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     2,     2,     2,     3,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     3,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     7,     1,     7,
       8,     1,     1,     7,     2,     0,     3,     1,     3,     2,
       1,     1,     2,     1,     1,     2,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     1,     0,     0,     0,     7,     8,     5,
       9,     0,     0,     0,     0,    29,    29,    54,    55,    56,
      14,     0,     0,    83,    79,    50,     0,     0,     0,     0,
      80,    82,    81,     0,    58,    60,    62,    64,    66,    68,
      70,    51,    74,    84,    28,     0,    17,     0,     0,     0,
       0,     0,    86,    25,     0,    89,    88,    87,    90,     0,
       0,     0,    91,    92,    93,    95,    96,    94,     0,     0,
       0,     0,    71,    72,     0,    75,    76,    77,     0,     0,
       0,     0,    13,    41,    42,    52,    53,    10,    15,    16,
      85,     0,    24,    27,     0,    57,    11,    59,    61,    63,
      65,    67,    69,    73,     6,    20,     0,     0,    23,     0,
      78,     0,     0,    29,     0,    12,    26,   101,   102,    35,
       0,     6,     0,     0,    50,    21,    31,    34,     0,    81,
       0,    38,    40,    36,     0,     3,    19,     6,    48,     0,
      50,     0,     0,    25,    50,    30,     0,    33,     0,     0,
      44,    43,    45,    47,     0,     0,    39,    37,     0,     0,
      32,    46,     0,     0,     4,     0,    23,     0,     0,     0,
       0,     0,    98,     0,     0,   111,   117,     0,     0,    81,
     107,   110,   113,   114,   105,    97,    99,     0,   116,     0,
       0,   109,   112,     0,     0,     0,   115,   108,   106,   104,
       0,   100,     0,     0,     0,   105,   103
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     7,     8,   111,     9,    10,    50,    87,    45,
      46,   112,    31,    91,    92,    47,   172,   126,   127,    88,
     128,    32,    89,    20,   130,    34,    35,    36,    37,    38,
      39,    74,    40,    78,    41,    42,    43,    68,   131,   173,
     132,   133,   134,   195,   182,   183,   184,   189
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -109
static const yytype_int16 yypact[] =
{
    -109,    26,    89,  -109,   -38,   -19,    22,  -109,  -109,  -109,
    -109,    28,    43,   144,    42,     4,     4,  -109,  -109,  -109,
      47,    42,    50,  -109,  -109,    15,    42,    42,    42,    42,
    -109,  -109,  -109,     9,    29,   218,    45,    44,    53,   100,
     123,  -109,  -109,  -109,  -109,   112,  -109,   144,   119,    42,
     272,     1,  -109,    42,    42,  -109,  -109,  -109,  -109,    42,
     272,    42,  -109,  -109,  -109,  -109,  -109,  -109,    42,    42,
      42,    42,  -109,  -109,    42,  -109,  -109,  -109,    42,   103,
      92,   118,   -28,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,   152,  -109,    -6,   -22,    29,  -109,   218,    45,    44,
      53,   100,   123,  -109,   136,   151,   144,   272,  -109,    42,
    -109,    10,   140,   142,   156,  -109,  -109,  -109,  -109,  -109,
      42,   136,   134,   182,    97,   148,  -109,  -109,   272,   213,
      13,  -109,  -109,  -109,   186,  -109,  -109,   136,   127,   171,
     172,   164,    42,    42,    19,  -109,   148,  -109,    42,    42,
    -109,  -109,  -109,  -109,    42,   177,  -109,  -109,     2,   205,
    -109,   127,     8,     6,  -109,   173,   274,    42,   181,   148,
      98,   184,   148,   175,   201,  -109,   220,   134,   272,   101,
    -109,  -109,   184,  -109,   147,  -109,  -109,   184,  -109,   190,
     185,  -109,  -109,   184,   214,   189,  -109,  -109,  -109,  -109,
      42,  -109,     7,   198,   184,   147,  -109
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,  -109,   232,  -109,    59,  -109,   -59,   221,
     125,   -84,  -109,    93,   138,  -109,   137,   -35,  -109,   117,
     -78,  -108,   121,   -31,   -14,   194,   195,   187,   192,   188,
     200,  -109,   202,  -109,  -109,    55,  -109,  -109,   -30,   105,
    -109,    75,  -109,    54,  -109,    81,    -3,  -109
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -50
static const yytype_int16 yytable[] =
{
      33,    96,    60,   129,   110,    90,   165,    51,   -18,    11,
     168,   203,   109,    21,   141,   107,    80,   129,    53,   167,
     152,   153,   143,    17,    18,    19,     3,    13,    12,   117,
     118,    15,   119,   120,   121,    82,    59,   139,   129,    93,
      94,    44,    59,    54,   122,    21,    16,    54,   115,    14,
     123,     4,     5,   155,    22,    23,    24,   124,    59,    26,
      27,   129,   129,   179,   129,    59,    59,    28,   179,   190,
      59,    59,    59,    59,   179,   114,    29,    59,    30,   179,
      49,    55,    56,    57,    58,   179,    22,    23,    24,    25,
     145,    26,    27,   178,    61,    93,   179,    52,   178,    28,
     143,    21,    13,    69,   178,    70,   138,   148,    29,   178,
      30,   160,    71,   150,   151,   178,    79,   117,   118,   191,
     119,   120,   121,    81,    14,    54,   178,   104,   158,    93,
       4,     5,   122,   103,   161,   162,     6,   145,   123,   105,
     163,   180,    22,    23,    24,   144,   180,    26,    27,    72,
      73,    21,   180,   170,   106,    28,   108,   180,    17,    18,
      19,   -22,    59,   180,    29,   135,    30,   117,   118,   113,
     119,   120,   121,   188,   180,    75,    76,   193,   194,    44,
     137,   140,   122,    77,   196,   142,   202,    21,   123,   154,
     199,    59,    22,    23,    24,   144,   156,    26,    27,   157,
      54,   205,   164,   117,   118,    28,   175,   120,   176,   166,
     171,   186,   169,   185,    29,   197,    30,   200,   177,   148,
     198,   201,   149,    21,   123,   150,   151,   204,    22,    23,
      24,   144,     2,    26,    27,   187,   159,    48,   136,   117,
     118,    28,   175,   120,   176,   146,   181,   116,   125,   147,
      29,   181,    30,    95,   177,    98,    97,   181,   100,   206,
     123,    99,   181,   192,    22,    23,    24,   124,   181,    26,
      27,   101,    62,    63,    64,   174,   102,    28,     0,   181,
      65,    66,     0,     0,     0,    67,    29,     0,    30,    83,
      84,   -49,   -49,    85,    86,   -49,   -49
};

static const yytype_int16 yycheck[] =
{
      14,    60,    33,   111,    26,     4,     4,    21,     4,    47,
       4,     4,    18,     3,   122,    43,    47,   125,     3,    11,
       7,     8,     3,    14,    15,    16,     0,     5,    47,    19,
      20,     3,    22,    23,    24,    49,    64,   121,   146,    53,
      54,    37,    64,    28,    34,     3,     3,    28,   107,    27,
      40,    41,    42,   137,    44,    45,    46,    47,    64,    49,
      50,   169,   170,   171,   172,    64,    64,    57,   176,   177,
      64,    64,    64,    64,   182,   106,    66,    64,    68,   187,
      33,    26,    27,    28,    29,   193,    44,    45,    46,    47,
     125,    49,    50,   171,    65,   109,   204,    47,   176,    57,
       3,     3,     5,    58,   182,    61,   120,     6,    66,   187,
      68,   146,    59,    12,    13,   193,     4,    19,    20,   178,
      22,    23,    24,     4,    27,    28,   204,    24,   142,   143,
      41,    42,    34,    78,   148,   149,    47,   172,    40,    47,
     154,   171,    44,    45,    46,    47,   176,    49,    50,    49,
      50,     3,   182,   167,    36,    57,     4,   187,    14,    15,
      16,    25,    64,   193,    66,    25,    68,    19,    20,    18,
      22,    23,    24,   176,   204,    52,    53,    30,    31,    37,
      24,    47,    34,    60,   187,     3,   200,     3,    40,     3,
     193,    64,    44,    45,    46,    47,    25,    49,    50,    35,
      28,   204,    25,    19,    20,    57,    22,    23,    24,     4,
      29,    10,    39,    38,    66,    25,    68,     3,    34,     6,
      35,    32,     9,     3,    40,    12,    13,    29,    44,    45,
      46,    47,     0,    49,    50,   176,   143,    16,   113,    19,
      20,    57,    22,    23,    24,   128,   171,   109,   111,   128,
      66,   176,    68,    59,    34,    68,    61,   182,    70,   205,
      40,    69,   187,   182,    44,    45,    46,    47,   193,    49,
      50,    71,    54,    55,    56,   170,    74,    57,    -1,   204,
      62,    63,    -1,    -1,    -1,    67,    66,    -1,    68,    17,
      18,    17,    18,    21,    22,    21,    22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,    73,     0,    41,    42,    47,    71,    72,    74,
      75,    47,    47,     5,    27,     3,     3,    14,    15,    16,
      92,     3,    44,    45,    46,    47,    49,    50,    57,    66,
      68,    81,    90,    93,    94,    95,    96,    97,    98,    99,
     101,   103,   104,   105,    37,    78,    79,    84,    78,    33,
      76,    93,    47,     3,    28,   104,   104,   104,   104,    64,
      92,    65,    54,    55,    56,    62,    63,    67,   106,    58,
      61,    59,    49,    50,   100,    52,    53,    60,   102,     4,
      92,     4,    93,    17,    18,    21,    22,    77,    88,    91,
       4,    82,    83,    93,    93,    94,    77,    95,    96,    97,
      98,    99,   101,   104,    24,    47,    36,    43,     4,    18,
      26,    73,    80,    18,    92,    77,    83,    19,    20,    22,
      23,    24,    34,    40,    47,    85,    86,    87,    89,    90,
      93,   107,   109,   110,   111,    25,    79,    24,    93,    80,
      47,    90,     3,     3,    47,    86,    88,    91,     6,     9,
      12,    13,     7,     8,     3,    80,    25,    35,    93,    82,
      86,    93,    93,    93,    25,     4,     4,    11,     4,    39,
      93,    29,    85,   108,   108,    22,    24,    34,    89,    90,
     107,   110,   113,   114,   115,    38,    10,    75,   115,   116,
      90,    77,   114,    30,    31,   112,   115,    25,    35,   115,
       3,    32,    93,     4,    29,   115,   112
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 138 "Front-End-Compiler/parser.y"
    { startNode = new programNode((yyvsp[(1) - (1)].dec)) ;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 142 "Front-End-Compiler/parser.y"
    { (yyval.proc) = new procedureDeclNode((yyvsp[(2) - (8)].idName), (yyvsp[(7) - (8)].body), (yyvsp[(4) - (8)].args), yylloc.first_line);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 145 "Front-End-Compiler/parser.y"
    { (yyval.func) = new functionDeclNode((yyvsp[(2) - (10)].idName), (yyvsp[(7) - (10)].types), (yyvsp[(9) - (10)].body), (yyvsp[(4) - (10)].args),yylloc.first_line);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 149 "Front-End-Compiler/parser.y"
    { (yyvsp[(1) - (2)].dec)->addChild((yyvsp[(2) - (2)].decl)); (yyval.dec) = (yyvsp[(1) - (2)].dec);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 150 "Front-End-Compiler/parser.y"
    { (yyval.dec) = new declListNode();;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 153 "Front-End-Compiler/parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].proc);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 154 "Front-End-Compiler/parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].func);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 155 "Front-End-Compiler/parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].vardec);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 158 "Front-End-Compiler/parser.y"
    { (yyval.vardec) = new varDeclNode((yyvsp[(1) - (5)].idName),(yyvsp[(3) - (5)].types),(yyvsp[(4) - (5)].exp), false, false,yylloc.first_line);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 159 "Front-End-Compiler/parser.y"
    { (yyval.vardec) = new arrDeclNode((yyvsp[(1) - (5)].idName), (yyvsp[(4) - (5)].types), (yyvsp[(3) - (5)].exp), true,yyloc.first_line);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 160 "Front-End-Compiler/parser.y"
    { (yyval.vardec) = new varDeclNode((yyvsp[(1) - (7)].idName),(yyvsp[(3) - (7)].types),(yyvsp[(5) - (7)].exp), true, false,yylloc.first_line);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 163 "Front-End-Compiler/parser.y"
    { (yyval.exp) = (yyvsp[(2) - (2)].exp);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 164 "Front-End-Compiler/parser.y"
    { (yyval.exp) = NULL;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 170 "Front-End-Compiler/parser.y"
    {(yyval.args) = (yyvsp[(1) - (1)].args);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 171 "Front-End-Compiler/parser.y"
    {(yyval.args) = new functionArgumentNode();;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 174 "Front-End-Compiler/parser.y"
    {(yyvsp[(5) - (5)].args)->addArg(new varDeclNode((yyvsp[(3) - (5)].idName), (yyvsp[(2) - (5)].types), NULL, false, (yyvsp[(1) - (5)].reference),yylloc.first_line));(yyval.args) = (yyvsp[(5) - (5)].args);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 175 "Front-End-Compiler/parser.y"
    {(yyval.args) = new functionArgumentNode(new varDeclNode((yyvsp[(3) - (3)].idName),(yyvsp[(2) - (3)].types),NULL,false,(yyvsp[(1) - (3)].reference),yylloc.first_line));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 179 "Front-End-Compiler/parser.y"
    { (yyval.body) = new bodyNode((yyvsp[(2) - (2)].CS),(yyvsp[(1) - (2)].dec));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 180 "Front-End-Compiler/parser.y"
    { (yyval.body) = new bodyNode();;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 182 "Front-End-Compiler/parser.y"
    { (yyval.caller) = new callNode((yyvsp[(1) - (4)].idName), (yyvsp[(3) - (4)].param),yylloc.first_line);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 184 "Front-End-Compiler/parser.y"
    { (yyval.param) = (yyvsp[(1) - (1)].param) ;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 185 "Front-End-Compiler/parser.y"
    { (yyval.param) = new actualParamsNode();;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 187 "Front-End-Compiler/parser.y"
    { (yyvsp[(3) - (3)].param)->addParams((yyvsp[(1) - (3)].exp)); (yyval.param) = (yyvsp[(3) - (3)].param); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 188 "Front-End-Compiler/parser.y"
    { (yyval.param) = new actualParamsNode((yyvsp[(1) - (1)].exp)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 190 "Front-End-Compiler/parser.y"
    { (yyval.reference) = true;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 191 "Front-End-Compiler/parser.y"
    { (yyval.reference) = false;;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 194 "Front-End-Compiler/parser.y"
    { (yyvsp[(1) - (2)].CS)->addStatementList((yyvsp[(2) - (2)].sl)); (yyval.CS) = (yyvsp[(1) - (2)].CS);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 195 "Front-End-Compiler/parser.y"
    { (yyval.CS) = new compoundStatement((yyvsp[(1) - (1)].sl));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 197 "Front-End-Compiler/parser.y"
    {(yyvsp[(3) - (3)].sl)->addStatement((yyvsp[(1) - (3)].stat)); (yyval.sl) = (yyvsp[(3) - (3)].sl);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 198 "Front-End-Compiler/parser.y"
    {(yyval.sl) = new statementListNode((yyvsp[(1) - (2)].stat));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 199 "Front-End-Compiler/parser.y"
    {(yyval.sl) = new statementListNode((yyvsp[(1) - (1)].stat));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 200 "Front-End-Compiler/parser.y"
    {(yyval.sl) = new statementListNode();;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 204 "Front-End-Compiler/parser.y"
    {(yyval.stat) = (yyvsp[(1) - (1)].stat);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 205 "Front-End-Compiler/parser.y"
    {(yyval.stat) = new whatWasNode((yyvsp[(2) - (3)].var), yylloc.first_line);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 206 "Front-End-Compiler/parser.y"
    {(yyval.stat) = (yyvsp[(1) - (1)].stat);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 207 "Front-End-Compiler/parser.y"
    {(yyval.stat) = (yyvsp[(2) - (3)].body);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 208 "Front-End-Compiler/parser.y"
    {(yyval.stat) = (yyvsp[(1) - (1)].stat);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 216 "Front-End-Compiler/parser.y"
    {(yyval.stat) = new incrementNode((yyvsp[(1) - (2)].var),yyloc.first_line);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 217 "Front-End-Compiler/parser.y"
    {(yyval.stat) = new decrementNode((yyvsp[(1) - (2)].var),yylloc.first_line);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 218 "Front-End-Compiler/parser.y"
    {(yyval.stat) = new printNode((yyvsp[(1) - (2)].exp), yylloc.first_line);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 219 "Front-End-Compiler/parser.y"
    {(yyval.stat) = new assignNode((yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].exp), yylloc.first_line);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 220 "Front-End-Compiler/parser.y"
    {(yyval.stat) = new printNode((yyvsp[(1) - (2)].exp), yylloc.first_line);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 221 "Front-End-Compiler/parser.y"
    {(yyval.stat) = new returnNode((yyvsp[(2) - (2)].exp), yylloc.first_line);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 222 "Front-End-Compiler/parser.y"
    {(yyval.stat) = new callNodeStatement((yyvsp[(1) - (4)].idName),(yyvsp[(3) - (4)].param),yylloc.first_line);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 224 "Front-End-Compiler/parser.y"
    {(yyval.var) = new identifierASTNode((yyvsp[(1) - (1)].idName), yylloc.first_line);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 225 "Front-End-Compiler/parser.y"
    {(yyval.var) = (yyvsp[(1) - (1)].arr);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 233 "Front-End-Compiler/parser.y"
    { (yyval.types) = new letterTypeNode();;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 234 "Front-End-Compiler/parser.y"
    { (yyval.types) = new intTypeNode();;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 235 "Front-End-Compiler/parser.y"
    {(yyval.types) = new sentenceTypeNode();;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 238 "Front-End-Compiler/parser.y"
    { (yyval.exp) = new binaryExpressionASTNode((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),bOr,yylloc.first_line);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 239 "Front-End-Compiler/parser.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 242 "Front-End-Compiler/parser.y"
    {(yyval.exp) = new binaryExpressionASTNode((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), bAnd,yylloc.first_line);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 243 "Front-End-Compiler/parser.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 246 "Front-End-Compiler/parser.y"
    {(yyval.exp) = new binaryExpressionASTNode((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),(yyvsp[(2) - (3)].bOp),yylloc.first_line);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 250 "Front-End-Compiler/parser.y"
    {(yyval.exp) = new binaryExpressionASTNode((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),bitOr,yylloc.first_line);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 251 "Front-End-Compiler/parser.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 254 "Front-End-Compiler/parser.y"
    {(yyval.exp) = new binaryExpressionASTNode((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), xOr,yylloc.first_line);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 255 "Front-End-Compiler/parser.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 257 "Front-End-Compiler/parser.y"
    {(yyval.exp) = new binaryExpressionASTNode((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),bitAnd,yylloc.first_line);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 258 "Front-End-Compiler/parser.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 260 "Front-End-Compiler/parser.y"
    {(yyval.exp) = new binaryExpressionASTNode((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),(yyvsp[(2) - (3)].bOp),yylloc.first_line);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 261 "Front-End-Compiler/parser.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 263 "Front-End-Compiler/parser.y"
    {(yyval.bOp) = iplus;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 264 "Front-End-Compiler/parser.y"
    {(yyval.bOp) = subtract;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 266 "Front-End-Compiler/parser.y"
    {(yyval.exp) = new binaryExpressionASTNode((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),(yyvsp[(2) - (3)].bOp),yylloc.first_line);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 267 "Front-End-Compiler/parser.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 269 "Front-End-Compiler/parser.y"
    {(yyval.bOp) = mul;;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 270 "Front-End-Compiler/parser.y"
    {(yyval.bOp) = idiv;;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 271 "Front-End-Compiler/parser.y"
    {(yyval.bOp) = mod;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 274 "Front-End-Compiler/parser.y"
    { (yyval.arr) = new arrayAccessIdentifier((yyvsp[(1) - (4)].idName), (yyvsp[(3) - (4)].exp), yylloc.first_line);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 277 "Front-End-Compiler/parser.y"
    { (yyval.exp) = new letterASTNode((yyvsp[(1) - (1)].letterVal));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 278 "Front-End-Compiler/parser.y"
    { (yyval.exp) = new sentenceASTNode((yyvsp[(1) - (1)].stringVal));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 279 "Front-End-Compiler/parser.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].var);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 280 "Front-End-Compiler/parser.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].caller);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 281 "Front-End-Compiler/parser.y"
    { (yyval.exp) = new numberASTNode((yyvsp[(1) - (1)].numVal));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 282 "Front-End-Compiler/parser.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 283 "Front-End-Compiler/parser.y"
    {(yyval.exp) = (yyvsp[(2) - (3)].exp);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 284 "Front-End-Compiler/parser.y"
    { (yyval.exp) = new arrayLengthNode((yyvsp[(2) - (2)].idName), yylloc.first_line); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 287 "Front-End-Compiler/parser.y"
    {(yyval.exp) = new unaryExpressionASTNode((yyvsp[(2) - (2)].exp), bitNot,yylloc.first_line);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 288 "Front-End-Compiler/parser.y"
    {(yyval.exp) = new unaryExpressionASTNode((yyvsp[(2) - (2)].exp), neg,yylloc.first_line);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 289 "Front-End-Compiler/parser.y"
    {(yyval.exp) = new unaryExpressionASTNode((yyvsp[(2) - (2)].exp), unPlus,yylloc.first_line);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 290 "Front-End-Compiler/parser.y"
    {(yyval.exp) = new unaryExpressionASTNode((yyvsp[(2) - (2)].exp), boolNOT,yylloc.first_line);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 293 "Front-End-Compiler/parser.y"
    {(yyval.bOp) = lessThan;;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 294 "Front-End-Compiler/parser.y"
    {(yyval.bOp) = greaterThan;;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 295 "Front-End-Compiler/parser.y"
    {(yyval.bOp) = equalTo;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 296 "Front-End-Compiler/parser.y"
    {(yyval.bOp) = notEqualTo;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 297 "Front-End-Compiler/parser.y"
    {(yyval.bOp) = lessEqu;;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 298 "Front-End-Compiler/parser.y"
    {(yyval.bOp) = greaterEqu;;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 303 "Front-End-Compiler/parser.y"
    {(yyval.stat) = new loopNode((yyvsp[(3) - (7)].exp),(yyvsp[(6) - (7)].CS), yylloc.first_line);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 305 "Front-End-Compiler/parser.y"
    {(yyval.CS) = (yyvsp[(1) - (1)].CS);;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 308 "Front-End-Compiler/parser.y"
    { (yyval.stat) = new forLoopNode((yyvsp[(1) - (7)].var), (yyvsp[(3) - (7)].exp), (yyvsp[(5) - (7)].exp), (yyvsp[(6) - (7)].CS), yylloc.first_line);;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 311 "Front-End-Compiler/parser.y"
    { (yyval.stat) = new ifStatementNode((yyvsp[(3) - (8)].exp), (yyvsp[(6) - (8)].sl), (yyvsp[(7) - (8)].branches), yylloc.first_line);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 319 "Front-End-Compiler/parser.y"
    { (yyvsp[(7) - (7)].branches)->addBranch(new branchingNode((yyvsp[(3) - (7)].exp),(yyvsp[(6) - (7)].sl),yylloc.first_line)); (yyval.branches) = (yyvsp[(7) - (7)].branches);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 320 "Front-End-Compiler/parser.y"
    { (yyval.branches) = new branchingNodes(new branchingNode(NULL,(yyvsp[(2) - (2)].sl),yylloc.first_line));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 321 "Front-End-Compiler/parser.y"
    { (yyval.branches) = new branchingNodes();;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 324 "Front-End-Compiler/parser.y"
    {(yyval.stat) = new whatWasNode((yyvsp[(2) - (3)].var), yylloc.first_line);;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 325 "Front-End-Compiler/parser.y"
    {(yyval.stat) = (yyvsp[(1) - (1)].stat);;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 326 "Front-End-Compiler/parser.y"
    {(yyval.stat) = (yyvsp[(2) - (3)].PDB);;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 327 "Front-End-Compiler/parser.y"
    {(yyval.stat) = (yyvsp[(1) - (2)].stat);;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 328 "Front-End-Compiler/parser.y"
    {(yyval.stat) = (yyvsp[(1) - (1)].stat);;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 329 "Front-End-Compiler/parser.y"
    {(yyval.stat) = NULL;;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 332 "Front-End-Compiler/parser.y"
    {(yyvsp[(2) - (2)].sl)->addStatement((yyvsp[(1) - (2)].stat)); (yyval.sl) = (yyvsp[(2) - (2)].sl); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 333 "Front-End-Compiler/parser.y"
    { (yyval.sl) = new statementListNode((yyvsp[(1) - (1)].stat));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 335 "Front-End-Compiler/parser.y"
    { (yyval.sl) =(yyvsp[(1) - (1)].sl); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 338 "Front-End-Compiler/parser.y"
    {(yyval.PDB) = new perhapsDeclAndBody((yyvsp[(1) - (2)].vardec),(yyvsp[(2) - (2)].sl));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 339 "Front-End-Compiler/parser.y"
    {(yyval.PDB) = new perhapsDeclAndBody(NULL,(yyvsp[(1) - (1)].sl));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 340 "Front-End-Compiler/parser.y"
    {(yyval.PDB) = new perhapsDeclAndBody();;}
    break;



/* Line 1455 of yacc.c  */
#line 2460 "Front-End-Compiler/parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 365 "Front-End-Compiler/parser.y"



void yyerror(const char *s) {

	if(yylloc.first_line)
		cerr << s << ": From line:" << yylloc.first_line << "."<< yylloc.first_column << "-"<< yylloc.last_line<< "." <<yylloc.last_column <<  endl;
		cleanUp();
	
	// might as well halt now:
	exit(-1);
}

