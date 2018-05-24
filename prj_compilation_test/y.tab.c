/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VOID = 258,
     INT = 259,
     FOR = 260,
     WHILE = 261,
     IF = 262,
     ELSE = 263,
     SWITCH = 264,
     CASE = 265,
     DEFAULT = 266,
     IDENTIFICATEUR = 267,
     CONSTANTE = 268,
     BREAK = 269,
     RETURN = 270,
     PLUS = 271,
     MOINS = 272,
     MUL = 273,
     DIV = 274,
     LSHIFT = 275,
     RSHIFT = 276,
     BAND = 277,
     BOR = 278,
     LAND = 279,
     LOR = 280,
     LT = 281,
     GT = 282,
     GEQ = 283,
     LEQ = 284,
     EQ = 285,
     NEQ = 286,
     NOT = 287,
     EXTERN = 288,
     THEN = 289,
     OP = 290,
     REL = 291
   };
#endif
/* Tokens.  */
#define VOID 258
#define INT 259
#define FOR 260
#define WHILE 261
#define IF 262
#define ELSE 263
#define SWITCH 264
#define CASE 265
#define DEFAULT 266
#define IDENTIFICATEUR 267
#define CONSTANTE 268
#define BREAK 269
#define RETURN 270
#define PLUS 271
#define MOINS 272
#define MUL 273
#define DIV 274
#define LSHIFT 275
#define RSHIFT 276
#define BAND 277
#define BOR 278
#define LAND 279
#define LOR 280
#define LT 281
#define GT 282
#define GEQ 283
#define LEQ 284
#define EQ 285
#define NEQ 286
#define NOT 287
#define EXTERN 288
#define THEN 289
#define OP 290
#define REL 291




/* Copy the first part of user declarations.  */
#line 1 "./cfe.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int yylex();

int yylineno;
void yyerror(const char *str)
{
    fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,str);
	exit(1);
}
char* concat(int n_args, ...) {
	/* Fonction a arité variable qui concactène des chaines de caractères */
   va_list valist;
   int i;
   int BUFFER_SIZE;
   va_start(valist, n_args);
   for (i = 0; i < n_args; i++) BUFFER_SIZE += strlen(va_arg(valist, char*));
   va_end(valist);
   char* result = (char*) calloc(BUFFER_SIZE*2, sizeof(char));
   va_start(valist, n_args);
   for (i = 0; i < n_args; i++) strcat(result, va_arg(valist, char*));
   va_end(valist);
   return result;
}

int noEtq = 1;
    
char* newEtq() {
    char* nc = (char*) calloc(10, sizeof(char));
    sprintf(nc,"L%d",noEtq++);
    return nc;
}




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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 60 "./cfe.y"
{
	char* chaine; 
	int valnum;
}
/* Line 193 of yacc.c.  */
#line 213 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 226 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    37,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    13,    15,    19,    23,
      25,    27,    32,    42,    50,    52,    54,    56,    60,    61,
      64,    67,    68,    70,    72,    74,    77,    79,    81,    91,
      97,   103,   111,   117,   122,   126,   129,   132,   136,   140,
     145,   151,   153,   158,   162,   166,   169,   171,   173,   178,
     180,   184,   185,   190,   194,   198,   202,   204,   206,   208,
     210,   212,   214,   216,   218,   220,   222,   224,   226,   228,
     230,   232
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    50,    -1,    49,    51,    -1,    -1,
      50,    54,    -1,    54,    -1,    55,    52,    37,    -1,    52,
      38,    53,    -1,    53,    -1,    12,    -1,    53,    39,    13,
      40,    -1,    55,    12,    41,    56,    42,    43,    49,    58,
      44,    -1,    33,    55,    12,    41,    56,    42,    37,    -1,
       3,    -1,     4,    -1,    57,    -1,    56,    38,    57,    -1,
      -1,     4,    12,    -1,    58,    59,    -1,    -1,    60,    -1,
      61,    -1,    62,    -1,    63,    37,    -1,    64,    -1,    65,
      -1,     5,    41,    63,    37,    69,    37,    63,    42,    59,
      -1,     6,    41,    69,    42,    59,    -1,     7,    41,    69,
      42,    59,    -1,     7,    41,    69,    42,    59,     8,    59,
      -1,     9,    41,    67,    42,    59,    -1,    10,    13,    45,
      59,    -1,    11,    45,    59,    -1,    14,    37,    -1,    15,
      37,    -1,    15,    67,    37,    -1,    66,    46,    67,    -1,
      43,    49,    58,    44,    -1,    12,    41,    68,    42,    37,
      -1,    12,    -1,    66,    39,    67,    40,    -1,    41,    67,
      42,    -1,    67,    70,    67,    -1,    17,    67,    -1,    13,
      -1,    66,    -1,    12,    41,    68,    42,    -1,    67,    -1,
      68,    38,    67,    -1,    -1,    32,    41,    69,    42,    -1,
      69,    71,    69,    -1,    41,    69,    42,    -1,    67,    72,
      67,    -1,    16,    -1,    17,    -1,    18,    -1,    19,    -1,
      20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,
      30,    -1,    31,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    74,    75,    78,    79,    82,    85,    86,
      89,    90,    93,    94,    97,    98,   101,   103,   104,   107,
     110,   111,   114,   115,   116,   117,   118,   119,   122,   127,
     136,   142,   147,   151,   152,   155,   156,   157,   160,   163,
     166,   169,   170,   173,   174,   175,   176,   177,   178,   181,
     183,   184,   187,   188,   189,   190,   193,   194,   195,   196,
     197,   198,   199,   200,   203,   204,   207,   208,   209,   210,
     211,   212
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "FOR", "WHILE", "IF",
  "ELSE", "SWITCH", "CASE", "DEFAULT", "IDENTIFICATEUR", "CONSTANTE",
  "BREAK", "RETURN", "PLUS", "MOINS", "MUL", "DIV", "LSHIFT", "RSHIFT",
  "BAND", "BOR", "LAND", "LOR", "LT", "GT", "GEQ", "LEQ", "EQ", "NEQ",
  "NOT", "EXTERN", "THEN", "OP", "REL", "';'", "','", "'['", "']'", "'('",
  "')'", "'{'", "'}'", "':'", "'='", "$accept", "programme",
  "liste_declarations", "liste_fonctions", "declaration",
  "liste_declarateurs", "declarateur", "fonction", "type", "liste_parms",
  "parm", "liste_instructions", "instruction", "iteration", "selection",
  "saut", "affectation", "bloc", "appel", "variable", "expression",
  "liste_expressions", "condition", "binary_op", "binary_rel",
  "binary_comp", 0
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
     285,   286,   287,   288,   289,   290,   291,    59,    44,    91,
      93,    40,    41,   123,   125,    58,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    57,
      58,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    62,    62,    62,    63,    64,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     1,     3,     3,     1,
       1,     4,     9,     7,     1,     1,     1,     3,     0,     2,
       2,     0,     1,     1,     1,     2,     1,     1,     9,     5,
       5,     7,     5,     4,     3,     2,     2,     3,     3,     4,
       5,     1,     4,     3,     3,     2,     1,     1,     4,     1,
       3,     0,     4,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,    14,    15,     0,     2,     3,     6,
       0,     0,     5,     0,    10,     0,     9,     0,     0,    18,
       7,     0,     0,    18,     0,     0,    16,    10,     8,     0,
       0,    19,     0,     0,    11,     0,    17,     4,    13,    21,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     4,    12,    20,    22,    23,    24,     0,    26,    27,
       0,     0,     0,     0,     0,     0,     0,    51,    35,    41,
      46,     0,    36,     0,    47,     0,    21,    25,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      49,     0,    51,    45,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    37,     0,     0,     0,    38,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,     0,    64,
      65,     0,     0,     0,     0,    33,     0,     0,     0,    43,
      44,    39,    42,     0,     0,    54,    55,    29,    53,    30,
      32,    50,    40,    48,     0,    52,     0,     0,    31,     0,
      28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     7,     8,    15,    16,     9,    40,    25,
      26,    41,    53,    54,    55,    56,    57,    58,    59,    74,
      84,    91,    85,   104,   122,   118
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -66
static const yytype_int16 yypact[] =
{
     -66,    10,     0,   -66,   -66,   -66,   123,     0,   -66,   -66,
       6,    12,   -66,    25,   -14,    91,     9,    14,   -14,    39,
     -66,    41,    53,    39,    56,    -8,   -66,   -66,     9,    36,
      35,   -66,    39,    61,   -66,    70,   -66,   -66,   -66,   123,
      41,     2,    71,    79,   151,   152,   126,    33,   153,   119,
      57,   -66,   -66,   -66,   -66,   -66,   -66,   149,   -66,   -66,
     -24,   176,    89,    89,    19,   146,   104,    19,   -66,   154,
     -66,    19,   -66,    19,   166,   159,   123,   -66,    19,    19,
     -66,   169,   186,    89,   181,    15,    37,   132,   104,   -66,
     197,   145,    19,   203,   142,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,    19,    81,   150,   197,    89,    89,
     115,    75,   -66,   -66,   -66,   -66,   -66,   -66,    19,   -66,
     -66,   104,    89,   104,   104,   -66,    19,   191,   147,   -66,
     -66,   -66,   -66,     4,    98,   -66,   197,   -66,   -66,   221,
     -66,   197,   -66,   -66,   176,   -66,   104,   188,   -66,   104,
     -66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -32,   -66,   -66,   -66,   210,   225,    65,   211,
     201,   160,   -65,   -66,   -66,   -66,   -59,   -66,   -66,   -41,
     -29,   143,   -57,   -66,   -66,   -66
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      60,    89,    81,     4,     5,    39,    86,    42,    43,    44,
       3,    45,    46,    47,    48,    78,    49,    50,    14,    76,
      60,    75,    79,   125,    17,    60,   111,    19,   119,   120,
      32,    69,    70,     6,    33,    87,    71,    18,    90,   119,
     120,   144,    93,    24,    94,    51,    52,    60,    22,   106,
     107,   133,   134,    27,   110,    23,   137,   121,   139,   140,
      73,   119,   120,    90,    60,   138,    29,    10,    31,    69,
      70,    11,    13,    32,    71,   130,    34,    35,    66,   123,
      60,   148,    60,    60,   150,   147,    42,    43,    44,   136,
      45,    46,    47,    48,    72,    49,    50,   141,    73,   119,
     120,    69,    70,    60,    37,    60,    71,    38,    60,    42,
      43,    44,    61,    45,    46,    47,    48,   135,    49,    50,
      62,    82,   119,   120,    51,   131,     4,     5,    20,    21,
      83,    95,    96,    97,    98,    99,   100,   101,   102,    65,
     145,   112,   113,   114,   115,   116,   117,    51,    95,    96,
      97,    98,    99,   100,   101,   102,    68,   129,    95,    96,
      97,    98,    99,   100,   101,   102,    95,    96,    97,    98,
      99,   100,   101,   102,   124,    95,    96,    97,    98,    99,
     100,   101,   102,   126,   129,   126,    77,   127,    80,   143,
     132,    88,    63,    64,    67,    92,   103,    95,    96,    97,
      98,    99,   100,   101,   102,    78,   108,   112,   113,   114,
     115,   116,   117,    95,    96,    97,    98,    99,   100,   101,
     102,    97,    98,    99,   100,   101,   102,   109,   142,   146,
     149,    28,    12,    36,    30,   128,   105
};

static const yytype_uint8 yycheck[] =
{
      41,    66,    61,     3,     4,    37,    63,     5,     6,     7,
       0,     9,    10,    11,    12,    39,    14,    15,    12,    51,
      61,    50,    46,    88,    12,    66,    83,    41,    24,    25,
      38,    12,    13,    33,    42,    64,    17,    12,    67,    24,
      25,    37,    71,     4,    73,    43,    44,    88,    39,    78,
      79,   108,   109,    12,    83,    41,   121,    42,   123,   124,
      41,    24,    25,    92,   105,   122,    13,     2,    12,    12,
      13,     6,     7,    38,    17,   104,    40,    42,    45,    42,
     121,   146,   123,   124,   149,   144,     5,     6,     7,   118,
       9,    10,    11,    12,    37,    14,    15,   126,    41,    24,
      25,    12,    13,   144,    43,   146,    17,    37,   149,     5,
       6,     7,    41,     9,    10,    11,    12,    42,    14,    15,
      41,    32,    24,    25,    43,    44,     3,     4,    37,    38,
      41,    16,    17,    18,    19,    20,    21,    22,    23,    13,
      42,    26,    27,    28,    29,    30,    31,    43,    16,    17,
      18,    19,    20,    21,    22,    23,    37,    42,    16,    17,
      18,    19,    20,    21,    22,    23,    16,    17,    18,    19,
      20,    21,    22,    23,    42,    16,    17,    18,    19,    20,
      21,    22,    23,    38,    42,    38,    37,    42,    12,    42,
      40,    45,    41,    41,    41,    41,    37,    16,    17,    18,
      19,    20,    21,    22,    23,    39,    37,    26,    27,    28,
      29,    30,    31,    16,    17,    18,    19,    20,    21,    22,
      23,    18,    19,    20,    21,    22,    23,    41,    37,     8,
      42,    21,     7,    32,    23,    92,    76
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,     0,     3,     4,    33,    50,    51,    54,
      55,    55,    54,    55,    12,    52,    53,    12,    12,    41,
      37,    38,    39,    41,     4,    56,    57,    12,    53,    13,
      56,    12,    38,    42,    40,    42,    57,    43,    37,    49,
      55,    58,     5,     6,     7,     9,    10,    11,    12,    14,
      15,    43,    44,    59,    60,    61,    62,    63,    64,    65,
      66,    41,    41,    41,    41,    13,    45,    41,    37,    12,
      13,    17,    37,    41,    66,    67,    49,    37,    39,    46,
      12,    63,    32,    41,    67,    69,    69,    67,    45,    59,
      67,    68,    41,    67,    67,    16,    17,    18,    19,    20,
      21,    22,    23,    37,    70,    58,    67,    67,    37,    41,
      67,    69,    26,    27,    28,    29,    30,    31,    72,    24,
      25,    42,    71,    42,    42,    59,    38,    42,    68,    42,
      67,    44,    40,    69,    69,    42,    67,    59,    69,    59,
      59,    67,    37,    42,    37,    42,     8,    63,    59,    42,
      59
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 67 "./cfe.y"
    {
            FILE* fichier = fopen("out.c","w");
            fprintf(fichier, "%s%s\n", (yyvsp[(1) - (2)].chaine),(yyvsp[(2) - (2)].chaine));
            fclose(fichier);
        }
    break;

  case 3:
#line 74 "./cfe.y"
    { (yyval.chaine) = concat(2, (yyvsp[(1) - (2)].chaine), (yyvsp[(2) - (2)].chaine));}
    break;

  case 4:
#line 75 "./cfe.y"
    {(yyval.chaine) = "";}
    break;

  case 5:
#line 78 "./cfe.y"
    { (yyval.chaine) = concat(2, (yyvsp[(1) - (2)].chaine), (yyvsp[(2) - (2)].chaine));}
    break;

  case 6:
#line 79 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine);}
    break;

  case 7:
#line 82 "./cfe.y"
    {(yyval.chaine) = concat(4, (yyvsp[(1) - (3)].chaine), " ", (yyvsp[(2) - (3)].chaine), ";\n");}
    break;

  case 8:
#line 85 "./cfe.y"
    {(yyval.chaine) = concat(3, (yyvsp[(1) - (3)].chaine), ",", (yyvsp[(3) - (3)].chaine));}
    break;

  case 9:
#line 86 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine);}
    break;

  case 10:
#line 89 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine);}
    break;

  case 11:
#line 90 "./cfe.y"
    {(yyval.chaine) = concat(4, (yyvsp[(1) - (4)].chaine), "[",(yyvsp[(3) - (4)].chaine), "]");}
    break;

  case 12:
#line 93 "./cfe.y"
    {(yyval.chaine) = concat(10,(yyvsp[(1) - (9)].chaine)," ",(yyvsp[(2) - (9)].chaine),"(",(yyvsp[(4) - (9)].chaine),")","{\n",(yyvsp[(7) - (9)].chaine),(yyvsp[(8) - (9)].chaine),"}\n");}
    break;

  case 13:
#line 94 "./cfe.y"
    {(yyval.chaine) = concat(7, "extern ", (yyvsp[(2) - (7)].chaine)," ", (yyvsp[(3) - (7)].chaine), "(", (yyvsp[(5) - (7)].chaine), ");\n");}
    break;

  case 14:
#line 97 "./cfe.y"
    {(yyval.chaine) = "void";}
    break;

  case 15:
#line 98 "./cfe.y"
    {(yyval.chaine) = "int";}
    break;

  case 16:
#line 101 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine);}
    break;

  case 17:
#line 103 "./cfe.y"
    {(yyval.chaine) = concat(3,(yyvsp[(1) - (3)].chaine),",",(yyvsp[(3) - (3)].chaine));}
    break;

  case 18:
#line 104 "./cfe.y"
    {(yyval.chaine)="";}
    break;

  case 19:
#line 107 "./cfe.y"
    {(yyval.chaine) = concat(2,"int ",(yyvsp[(2) - (2)].chaine));}
    break;

  case 20:
#line 110 "./cfe.y"
    {(yyval.chaine) = concat(2,(yyvsp[(1) - (2)].chaine),(yyvsp[(2) - (2)].chaine));}
    break;

  case 21:
#line 111 "./cfe.y"
    {(yyval.chaine) = "";}
    break;

  case 22:
#line 114 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine);}
    break;

  case 23:
#line 115 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine);}
    break;

  case 24:
#line 116 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine);}
    break;

  case 25:
#line 117 "./cfe.y"
    {(yyval.chaine) = concat(2,(yyvsp[(1) - (2)].chaine),";\n");}
    break;

  case 26:
#line 118 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine);}
    break;

  case 27:
#line 119 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine);}
    break;

  case 28:
#line 122 "./cfe.y"
    {
            char* L1 = newEtq();
            char* L2 = newEtq();
            (yyval.chaine) = concat(18,(yyvsp[(3) - (9)].chaine),"\n",L1,":if(",(yyvsp[(5) - (9)].chaine),")","goto ",L2,";",(yyvsp[(9) - (9)].chaine),"\n",(yyvsp[(7) - (9)].chaine),"\n","goto ",L1,";\n",L2,":") ; 
        }
    break;

  case 29:
#line 128 "./cfe.y"
    {
        char* L1 = newEtq();
        char* L2 = newEtq();
        
        (yyval.chaine) = concat(14,"goto ",L1,";\n",L2,":",(yyvsp[(5) - (5)].chaine),L1,": if","(",(yyvsp[(3) - (5)].chaine),")","goto ",L2,";\n");
    }
    break;

  case 30:
#line 137 "./cfe.y"
    {   
            char* L = newEtq();
            (yyval.chaine) = concat(9,"if","(!",(yyvsp[(3) - (5)].chaine),") goto ",L,";\n",(yyvsp[(5) - (5)].chaine),L,": ");
        
        }
    break;

  case 31:
#line 142 "./cfe.y"
    {
            char* L1 = newEtq();
            char* L2 = newEtq();
            (yyval.chaine) = concat(16,"if","(",(yyvsp[(3) - (7)].chaine),") goto ",L1,";\n",(yyvsp[(7) - (7)].chaine),"goto ",L2,";\n",L1,": ",(yyvsp[(5) - (7)].chaine),"\n",L2,": ");
        }
    break;

  case 32:
#line 147 "./cfe.y"
    {
    
            (yyval.chaine) = concat( 5 , "switch","(",(yyvsp[(3) - (5)].chaine),")",(yyvsp[(5) - (5)].chaine));
        }
    break;

  case 33:
#line 151 "./cfe.y"
    {(yyval.chaine) = concat(4,"case",(yyvsp[(2) - (4)].chaine),":",(yyvsp[(4) - (4)].chaine));}
    break;

  case 34:
#line 152 "./cfe.y"
    {(yyval.chaine) = concat(3,"default",":",(yyvsp[(3) - (3)].chaine));}
    break;

  case 35:
#line 155 "./cfe.y"
    {(yyval.chaine) = concat(2,"break",";\n");}
    break;

  case 36:
#line 156 "./cfe.y"
    {(yyval.chaine) = concat(2,"return ",";\n");}
    break;

  case 37:
#line 157 "./cfe.y"
    {(yyval.chaine) = concat(3,"return ",(yyvsp[(2) - (3)].chaine),";\n");}
    break;

  case 38:
#line 160 "./cfe.y"
    {(yyval.chaine) = concat(3,(yyvsp[(1) - (3)].chaine)," = ",(yyvsp[(3) - (3)].chaine));}
    break;

  case 39:
#line 163 "./cfe.y"
    {(yyval.chaine) = concat(4,"{\n",(yyvsp[(2) - (4)].chaine),(yyvsp[(3) - (4)].chaine),"}\n");}
    break;

  case 40:
#line 166 "./cfe.y"
    {(yyval.chaine) = concat(5,(yyvsp[(1) - (5)].chaine),"(",(yyvsp[(3) - (5)].chaine),")",";\n");}
    break;

  case 41:
#line 169 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine) ;}
    break;

  case 42:
#line 170 "./cfe.y"
    {(yyval.chaine) = concat(4,(yyvsp[(1) - (4)].chaine),"[",(yyvsp[(3) - (4)].chaine),"]");}
    break;

  case 43:
#line 173 "./cfe.y"
    {(yyval.chaine) = concat(3,"(",(yyvsp[(2) - (3)].chaine),")");}
    break;

  case 44:
#line 174 "./cfe.y"
    {(yyval.chaine)= concat(3,(yyvsp[(1) - (3)].chaine),(yyvsp[(2) - (3)].chaine),(yyvsp[(3) - (3)].chaine));}
    break;

  case 45:
#line 175 "./cfe.y"
    {(yyval.chaine) = concat(2,"-",(yyvsp[(2) - (2)].chaine));}
    break;

  case 46:
#line 176 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine) ;}
    break;

  case 47:
#line 177 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine) ;}
    break;

  case 48:
#line 178 "./cfe.y"
    {(yyval.chaine) = concat(4,(yyvsp[(1) - (4)].chaine),"(",(yyvsp[(3) - (4)].chaine),")") ;}
    break;

  case 49:
#line 181 "./cfe.y"
    {(yyval.chaine) = (yyvsp[(1) - (1)].chaine);}
    break;

  case 50:
#line 183 "./cfe.y"
    {(yyval.chaine) = concat(3,(yyvsp[(1) - (3)].chaine),",",(yyvsp[(3) - (3)].chaine));}
    break;

  case 51:
#line 184 "./cfe.y"
    {(yyval.chaine) = "";}
    break;

  case 52:
#line 187 "./cfe.y"
    {(yyval.chaine) = concat(4,"!","(",(yyvsp[(3) - (4)].chaine),")");}
    break;

  case 53:
#line 188 "./cfe.y"
    {(yyval.chaine) = concat(3,(yyvsp[(1) - (3)].chaine),(yyvsp[(2) - (3)].chaine),(yyvsp[(3) - (3)].chaine));}
    break;

  case 54:
#line 189 "./cfe.y"
    {(yyval.chaine) = concat(3,"(",(yyvsp[(2) - (3)].chaine),")");}
    break;

  case 55:
#line 190 "./cfe.y"
    {(yyval.chaine) = concat(3,(yyvsp[(1) - (3)].chaine),(yyvsp[(2) - (3)].chaine),(yyvsp[(3) - (3)].chaine));}
    break;

  case 56:
#line 193 "./cfe.y"
    {(yyval.chaine) = "+";}
    break;

  case 57:
#line 194 "./cfe.y"
    {(yyval.chaine) = "-";}
    break;

  case 58:
#line 195 "./cfe.y"
    {(yyval.chaine) = "*";}
    break;

  case 59:
#line 196 "./cfe.y"
    {(yyval.chaine) = "/";}
    break;

  case 60:
#line 197 "./cfe.y"
    {(yyval.chaine) = "<<";}
    break;

  case 61:
#line 198 "./cfe.y"
    {(yyval.chaine) = ">>";}
    break;

  case 62:
#line 199 "./cfe.y"
    {(yyval.chaine) = "&";}
    break;

  case 63:
#line 200 "./cfe.y"
    {(yyval.chaine) = "|";}
    break;

  case 64:
#line 203 "./cfe.y"
    {(yyval.chaine) = "&&";}
    break;

  case 65:
#line 204 "./cfe.y"
    {(yyval.chaine) = "||";}
    break;

  case 66:
#line 207 "./cfe.y"
    {(yyval.chaine) = "<";}
    break;

  case 67:
#line 208 "./cfe.y"
    {(yyval.chaine) = ">";}
    break;

  case 68:
#line 209 "./cfe.y"
    {(yyval.chaine) = ">=";}
    break;

  case 69:
#line 210 "./cfe.y"
    {(yyval.chaine) = "<=";}
    break;

  case 70:
#line 211 "./cfe.y"
    {(yyval.chaine) = "==";}
    break;

  case 71:
#line 212 "./cfe.y"
    {(yyval.chaine) = "!=";}
    break;


/* Line 1267 of yacc.c.  */
#line 1943 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 214 "./cfe.y"


int main(int argc, const char *argv[]){	
 	yyparse();
 }


