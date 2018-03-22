/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "basic.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "symtbl.h"

	extern FILE *yyin;
	
	int yylineno;

	/* Scope Evaluation */
	 int level = 0;
	 int depth = 0;
	 int scope[1000];
	//scope[0] = 0;
		
	char* yytext;
	
	void yyerror(char*);
	int error = 0;
	
	char datatype_str[100];
	char vars[100][1000];
	int pnt[100]={0};
	int varpt = -1; 	

	char multidec_type[1000];

#line 96 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OR = 258,
    AND = 259,
    EQUAL = 260,
    NOTEQUAL = 261,
    LESSER = 262,
    GREATER = 263,
    IF = 264,
    ELSE = 265,
    STRCONST = 266,
    INTCONST = 267,
    FLTCONST = 268,
    CHARCONST = 269,
    AUTO = 270,
    BREAK = 271,
    CASE = 272,
    CHAR = 273,
    CONST = 274,
    CONTINUE = 275,
    DEFAULT = 276,
    DO = 277,
    DOUBLE = 278,
    ENUM = 279,
    EXTERN = 280,
    FLOAT = 281,
    FOR = 282,
    INT = 283,
    LONG = 284,
    REGISTER = 285,
    RETURN = 286,
    SHORT = 287,
    SIGNED = 288,
    SIZEOF = 289,
    STATIC = 290,
    STRUCT = 291,
    SWITCH = 292,
    TYPEDEF = 293,
    UNION = 294,
    UNSIGNED = 295,
    VOID = 296,
    VOLATILE = 297,
    WHILE = 298,
    IDENTIFIER = 299,
    INCREMENT = 300,
    DECREMENT = 301
  };
#endif
/* Tokens.  */
#define OR 258
#define AND 259
#define EQUAL 260
#define NOTEQUAL 261
#define LESSER 262
#define GREATER 263
#define IF 264
#define ELSE 265
#define STRCONST 266
#define INTCONST 267
#define FLTCONST 268
#define CHARCONST 269
#define AUTO 270
#define BREAK 271
#define CASE 272
#define CHAR 273
#define CONST 274
#define CONTINUE 275
#define DEFAULT 276
#define DO 277
#define DOUBLE 278
#define ENUM 279
#define EXTERN 280
#define FLOAT 281
#define FOR 282
#define INT 283
#define LONG 284
#define REGISTER 285
#define RETURN 286
#define SHORT 287
#define SIGNED 288
#define SIZEOF 289
#define STATIC 290
#define STRUCT 291
#define SWITCH 292
#define TYPEDEF 293
#define UNION 294
#define UNSIGNED 295
#define VOID 296
#define VOLATILE 297
#define WHILE 298
#define IDENTIFIER 299
#define INCREMENT 300
#define DECREMENT 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "basic.y" /* yacc.c:355  */

    char name[1000];

    int size;

    char type[1000];
    char params[1000];

#line 237 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 254 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   352

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,     2,    19,    66,     8,     2,
      59,    60,    17,    15,    65,    16,     2,    18,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    58,
      11,     3,    12,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,     7,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     6,    62,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       9,    10,    13,    14,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    64,    65,    69,    79,    89,    93,    97,
     109,   121,   128,   139,   170,   172,   174,   176,   178,   180,
     182,   187,   188,   189,   190,   191,   192,   193,   194,   198,
     208,   226,   237,   250,   256,   266,   270,   272,   282,   293,
     299,   305,   307,   317,   327,   337,   344,   351,   353,   355,
     362,   376,   392,   403,   419,   438,   440,   445,   447,   462,
     467,   472,   477,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   503,   504,
     505,   506,   507,   508,   509,   513,   527,   542,   544,   554,
     556,   558,   560,   562,   564,   566,   568,   573,   578,   580,
     582,   590,   596,   602,   609,   616,   623,   629,   635,   641,
     657,   667,   681,   697,   707,   724,   729,   736,   743,   745,
     747
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "OR", "AND", "'|'", "'^'", "'&'",
  "EQUAL", "NOTEQUAL", "'<'", "'>'", "LESSER", "GREATER", "'+'", "'-'",
  "'*'", "'/'", "'$'", "IF", "ELSE", "STRCONST", "INTCONST", "FLTCONST",
  "CHARCONST", "AUTO", "BREAK", "CASE", "CHAR", "CONST", "CONTINUE",
  "DEFAULT", "DO", "DOUBLE", "ENUM", "EXTERN", "FLOAT", "FOR", "INT",
  "LONG", "REGISTER", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC",
  "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE",
  "WHILE", "IDENTIFIER", "INCREMENT", "DECREMENT", "';'", "'('", "')'",
  "'{'", "'}'", "'['", "']'", "','", "'%'", "'!'", "$accept", "S",
  "func_def", "multidec", "datatype", "modifiers", "params_dec",
  "params_list", "brackets", "expression", "const_list", "statement_list",
  "constant", "bin_op", "un_op", "func_call", "expression_list",
  "statement", "id_chain", "conditional", "iterative", "assignment", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    61,   258,   259,   124,    94,    38,   260,
     261,    60,    62,   262,   263,    43,    45,    42,    47,    36,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,    59,    40,
      41,   123,   125,    91,    93,    44,    37,    33
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -58

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     184,  -136,  -136,  -136,  -136,  -136,  -136,  -136,    11,   184,
     -15,   149,  -136,  -136,   184,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,    15,  -136,     3,    44,   -12,    46,   152,   270,
     -13,    31,   152,   271,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,     9,  -136,  -136,   152,  -136,   125,  -136,   125,
     249,   125,    34,   149,    -5,    16,     5,    90,    59,    -2,
    -136,    50,    41,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   139,
     152,  -136,   152,    60,   152,   152,    35,  -136,  -136,  -136,
     152,  -136,   234,    42,   299,    57,   123,    72,   142,   152,
      21,  -136,   234,    58,  -136,    84,    93,    94,  -136,  -136,
    -136,  -136,   152,  -136,   104,   106,   112,   152,   114,    43,
    -136,   234,  -136,   121,   110,   129,   204,  -136,  -136,  -136,
     135,   130,  -136,  -136,   234,   136,   193,   152,  -136,   138,
     200,   150,  -136,   234,   152,  -136,    24,   140,   220,   152,
    -136,   168,   152,   152,   169,   174,   152,   167,  -136,  -136,
    -136,  -136,  -136,    27,   176,   193,   177,   178,  -136,   230,
     175,  -136,   179,  -136,  -136,  -136,   152,  -136,   152,   182,
    -136,   187,   186,  -136,  -136,   185,  -136,   188,  -136,  -136,
     191,  -136,   193,   189,   193,  -136,  -136,   198,   234,   234,
    -136,   260,  -136,  -136,  -136,   193,   205,  -136,   247,  -136,
     152,   207,  -136,   234,   219,  -136,  -136,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      28,    21,    22,    23,    24,    25,    26,    27,     0,    28,
       0,     0,     1,     2,    28,    16,    17,    15,    14,    19,
      20,    18,     0,     3,     0,   101,    13,   103,     0,    28,
       0,     0,     0,    28,    82,    79,    80,    81,    60,    59,
      61,    62,    39,    83,    84,     0,    78,    47,   102,    36,
       0,    45,     0,     0,    33,     0,     0,     0,     0,   108,
     105,     0,     0,    68,    67,    75,    74,    69,    72,    77,
      76,    71,    70,    63,    64,    65,    66,    42,    43,     0,
       0,    73,     0,     0,     0,     0,    40,    48,    41,    46,
       0,     8,    28,     0,    28,     0,   109,     0,   104,     0,
       0,    12,    28,     0,    86,    87,     0,     0,    37,    35,
      49,    38,     0,    44,     0,     0,     0,     0,     0,     0,
      99,    28,    95,     0,     0,     0,    28,    90,    91,    92,
       0,    29,    34,     7,    28,     0,     0,     0,   107,     0,
       0,     0,    11,    28,     0,    85,    50,     0,     0,     0,
     100,     0,     0,     0,     0,     0,     0,     0,    89,     6,
      94,    58,    32,     0,     0,     0,     0,    55,   106,   112,
       0,    10,     0,    88,    53,    54,     0,    52,     0,     0,
      93,     0,     0,    96,    97,     0,    98,     0,    31,     5,
       0,   110,     0,     0,     0,     9,    51,     0,    28,    28,
     118,     0,    30,   111,    56,     0,     0,   119,   115,   117,
       0,     0,   113,    28,     0,   114,   116,   120
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,    68,   113,   171,   226,   -21,  -136,   -27,   231,   -28,
     -82,    79,   -48,   -42,  -136,   -47,   146,  -135,  -136,  -136,
    -136,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,   122,   123,    22,    11,    54,    55,    47,   105,
     166,   124,    49,    82,    50,    51,   106,   126,    26,   127,
     128,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    99,    88,    89,    60,    84,    62,    85,    53,    90,
      56,    12,    53,    63,    64,    65,    66,    83,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      65,    66,    24,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    14,   139,   125,   153,    28,    58,    32,
     187,    57,   107,    31,   108,   125,   110,   111,    27,   130,
      94,   100,   113,   208,   209,    77,    78,   132,    79,    96,
      25,   138,    80,    53,   125,    81,    95,    13,   216,   125,
     174,   175,    23,   190,   147,   140,    59,   125,   167,   151,
      81,   188,    91,    97,    79,    92,   125,   131,   112,   154,
     155,   103,    79,    29,   176,    33,   156,    30,   101,   168,
     204,   102,   206,     9,    98,   133,   142,   167,   134,   143,
     109,   179,     9,   211,   181,   182,   135,     9,   185,    63,
      64,    65,    66,   136,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,   167,   137,   167,    34,   196,   144,
     197,   125,   125,   145,    35,    36,    37,   167,   146,   148,
      34,    38,    39,    40,    41,   149,   125,    35,    36,    37,
     150,    10,   159,   152,    38,    39,    40,    41,    15,   158,
      10,   141,   214,    16,    -4,    10,    17,   160,    18,    19,
     162,    81,    20,   163,    42,    43,    44,   165,    45,   104,
     157,    21,   169,   170,   177,   161,    46,    42,    43,    44,
       1,    45,   171,   164,     2,    38,    39,    40,    41,    46,
       3,   114,   172,   178,   115,     4,   180,   183,     5,   186,
       1,   116,   184,   193,     2,     6,   194,     7,   189,   191,
       3,   195,   198,   192,   200,     4,   117,   199,     5,   201,
     205,   114,   202,   203,   115,     6,   207,     7,   118,   119,
       1,   116,   120,   210,     2,   121,   -57,   212,   213,   215,
       3,    38,    39,    40,    41,     4,   117,   217,     5,    93,
       0,    87,     0,     0,     0,     6,     0,     7,   118,   119,
     173,     0,   120,     0,     0,   121,     1,     1,     0,     0,
       2,     2,     0,     0,    86,     0,     3,     3,    45,     0,
       0,     4,     4,     0,     5,     5,     0,     0,     0,     0,
       0,     6,     6,     7,     7,     1,     0,     0,     0,     2,
      52,    61,     0,     0,     0,     3,     0,     0,     0,     0,
       4,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       6,     0,     7
};

static const yytype_int16 yycheck[] =
{
      28,     3,    50,    50,    32,    47,    33,    49,    29,    51,
      23,     0,    33,     4,     5,     6,     7,    45,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     4,     5,
       6,     7,    17,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    58,    23,    92,     3,     3,    17,     3,
      23,    64,    80,    65,    82,   102,    84,    85,    55,    17,
      65,    63,    90,   198,   199,    56,    57,    94,    59,    64,
      55,    99,    63,    94,   121,    66,    60,     9,   213,   126,
      56,    57,    14,   165,   112,    64,    55,   134,   136,   117,
      66,    64,    58,     3,    59,    61,   143,    55,    63,    56,
      57,    60,    59,    59,   146,    59,    63,    63,    58,   137,
     192,    61,   194,     0,    55,    58,    58,   165,    61,    61,
      60,   149,     9,   205,   152,   153,     3,    14,   156,     4,
       5,     6,     7,    61,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   192,     3,   194,     8,   176,    65,
     178,   198,   199,    60,    15,    16,    17,   205,    64,    55,
       8,    22,    23,    24,    25,    59,   213,    15,    16,    17,
      58,     0,    62,    59,    22,    23,    24,    25,    29,    58,
       9,   102,   210,    34,     0,    14,    37,    58,    39,    40,
      55,    66,    43,    63,    55,    56,    57,    61,    59,    60,
     121,    52,    64,     3,    64,   126,    67,    55,    56,    57,
      26,    59,    62,   134,    30,    22,    23,    24,    25,    67,
      36,    17,   143,     3,    20,    41,    58,    58,    44,    62,
      26,    27,    58,     3,    30,    51,    61,    53,    62,    62,
      36,    62,    60,    65,    58,    41,    42,    60,    44,    64,
      61,    17,    64,    62,    20,    51,    58,    53,    54,    55,
      26,    27,    58,     3,    30,    61,    62,    62,    21,    62,
      36,    22,    23,    24,    25,    41,    42,    58,    44,    53,
      -1,    50,    -1,    -1,    -1,    51,    -1,    53,    54,    55,
     144,    -1,    58,    -1,    -1,    61,    26,    26,    -1,    -1,
      30,    30,    -1,    -1,    55,    -1,    36,    36,    59,    -1,
      -1,    41,    41,    -1,    44,    44,    -1,    -1,    -1,    -1,
      -1,    51,    51,    53,    53,    26,    -1,    -1,    -1,    30,
      60,    60,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    30,    36,    41,    44,    51,    53,    69,    70,
      71,    73,     0,    69,    58,    29,    34,    37,    39,    40,
      43,    52,    72,    69,    17,    55,    86,    55,     3,    59,
      63,    65,     3,    59,     8,    15,    16,    17,    22,    23,
      24,    25,    55,    56,    57,    59,    67,    76,    77,    80,
      82,    83,    60,    73,    74,    75,    23,    64,    17,    55,
      77,    60,    75,     4,     5,     6,     7,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    56,    57,    59,
      63,    66,    81,    77,    81,    81,    55,    76,    80,    83,
      81,    58,    61,    72,    65,    60,    64,     3,    55,     3,
      63,    58,    61,    60,    60,    77,    84,    77,    77,    60,
      77,    77,    63,    77,    17,    20,    27,    42,    54,    55,
      58,    61,    70,    71,    79,    83,    85,    87,    88,    89,
      17,    55,    75,    58,    61,     3,    61,     3,    77,    23,
      64,    79,    58,    61,    65,    60,    64,    77,    55,    59,
      58,    77,    59,     3,    56,    57,    63,    79,    58,    62,
      58,    79,    55,    63,    79,    61,    78,    80,    77,    64,
       3,    62,    79,    84,    56,    57,    81,    64,     3,    77,
      58,    77,    77,    58,    58,    77,    62,    23,    64,    62,
      78,    62,    65,     3,    61,    62,    77,    77,    60,    60,
      58,    64,    64,    62,    78,    61,    78,    58,    85,    85,
       3,    78,    62,    21,    77,    62,    85,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    71,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      74,    74,    74,    75,    75,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    88,    89,    89,
      89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     0,     9,     8,     7,     6,    10,
       9,     8,     7,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       6,     5,     4,     1,     3,     3,     1,     3,     3,     1,
       2,     2,     2,     2,     3,     1,     2,     1,     2,     3,
       4,     6,     5,     5,     5,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     1,     3,     2,
       1,     1,     1,     3,     2,     1,     3,     3,     3,     1,
       2,     1,     3,     2,     4,     4,     6,     5,     3,     4,
       7,     8,     6,     9,    10,     5,     7,     5,     4,     5,
       7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 70 "basic.y" /* yacc.c:1646  */
    { 
		insert_fun ((yyvsp[-6].name), (yyvsp[-7].name), scope, depth, (yyvsp[-4].params)); 
		//printf("dw%s",$<type>8);
		if((!strcmp((yyvsp[-7].type), "void") && strlen((yyvsp[-1].type))!=0) && (strcmp((yyvsp[-7].type), (yyvsp[-1].type))) )
			yyerror("Return type not matching");

		node* t = lookup((yyvsp[-6].name), FUN_TBL); 
		t->func_def = 1;
	}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 80 "basic.y" /* yacc.c:1646  */
    { 
		insert_fun ((yyvsp[-5].name), (yyvsp[-6].name), scope, depth, NULL); 
		//printf("dw%s",$<type>7);
		if((!strcmp((yyvsp[-6].type), "void") && strlen((yyvsp[-1].type))!=0) && (strcmp((yyvsp[-6].type), (yyvsp[-1].type))) )
			yyerror("Return type not matching");

		node* t = lookup((yyvsp[-5].name), FUN_TBL); 
		t->func_def = 1;
	}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 90 "basic.y" /* yacc.c:1646  */
    { 
		insert_fun ((yyvsp[-4].name), (yyvsp[-5].name), scope, depth, (yyvsp[-2].params));
	}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 94 "basic.y" /* yacc.c:1646  */
    {
		insert_fun ((yyvsp[-3].name), (yyvsp[-4].name), scope, depth, NULL);
	}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 98 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-8].name));
		strcat(temp,"*"); 
		insert_fun ((yyvsp[-7].name), (yyvsp[-8].name), scope, depth, (yyvsp[-4].params)); 
		if(strcmp(temp, "void") && strcmp(temp, (yyvsp[-1].type))) 
			yyerror("Return type not matching");

		node* t = lookup((yyvsp[-7].name), FUN_TBL); 
		t->func_def = 1;
	}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 110 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-7].name));
		strcat(temp,"*"); 
		insert_fun ((yyvsp[-6].name), (yyvsp[-7].name), scope, depth, NULL); 
		if(strcmp(temp, "void") && strcmp(temp, (yyvsp[-1].type))) 
			yyerror("Return type not matching");

		node* t = lookup((yyvsp[-6].name), FUN_TBL); 
		t->func_def = 1;
	}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 122 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-6].name));
		strcat(temp,"*"); 
		insert_fun ((yyvsp[-5].name), (yyvsp[-6].name), scope, depth, (yyvsp[-2].params));
	}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-5].name));
		strcat(temp,"*"); 
		insert_fun ((yyvsp[-4].name), (yyvsp[-5].name), scope, depth, NULL);
	}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 140 "basic.y" /* yacc.c:1646  */
    {
		if(!strcmp((yyvsp[-1].type) ,"void"))
			yyerror("Variable of type void");
		//printf("HIHI");
		//varpt--;
		while(varpt>=0)
		{
			//printf("%d - %s\n", varpt, vars[varpt]);
			if(pnt[varpt])
			{
				char temp[1000];
				strcpy(temp,(yyvsp[-1].name));
				strcat(temp,"*"); 
				pnt[varpt] = 0;

				node* t = lookup(vars[varpt--], SYM_TBL); 
				strcpy(t->type, temp);
			}
			else
			{
				node* t = lookup(vars[varpt--], SYM_TBL); 
				strcpy(t->type, (yyvsp[-1].name));
			}

		}		
	}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 171 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "int"); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 173 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "float"); }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 175 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "char"); }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 177 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "double"); }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 179 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "void"); }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 181 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "long"); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 183 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "short"); }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 199 "basic.y" /* yacc.c:1646  */
    { 
		if(!strcmp((yyvsp[-1].type) ,"void"))
			yyerror("Parameter of type void");
		//printf("\n SDA %s",$<name>3);
		strcpy((yyval.name),(yyvsp[0].name)); 
		insert ((yyvsp[0].name), (yyvsp[-1].name), scope, depth, 0); 
		strcpy((yyval.type),(yyvsp[-1].type)); 
		strcpy((yyval.name),(yyvsp[0].name)); 
	}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 209 "basic.y" /* yacc.c:1646  */
    { 
		if(!strcmp((yyvsp[-4].type) ,"void"))
			yyerror("Parameter of type void");
		strcpy((yyval.name),(yyvsp[-3].name)); 
		char temp[1000];
		strcpy(temp,(yyvsp[-4].name));
		strcat(temp,"*"); 
		insert ((yyvsp[-3].name), temp, scope, depth, 0); 
		strcpy((yyval.type),temp);

		int t_array = atoi((yyvsp[-1].name));
		node* t = lookup((yyvsp[-3].name), SYM_TBL);
		t->array_bound = t_array; 
		strcpy((yyval.name),(yyvsp[-3].name)); 


	}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 227 "basic.y" /* yacc.c:1646  */
    {
		if(!strcmp((yyvsp[-3].type) ,"void"))
			yyerror("Parameter of type void"); 
		strcpy((yyval.name),(yyvsp[-2].name)); 
		char temp[1000];strcpy(temp,(yyvsp[-3].name));
		strcat(temp,"*"); 
		insert ((yyvsp[-2].name), temp, scope, depth, 0); 
		strcpy((yyval.type),temp);
		strcpy((yyval.name),(yyvsp[-2].name));  
	}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 238 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.name),(yyvsp[-1].name)); 
		char temp[1000];
		strcpy(temp,multidec_type);
		strcat(temp,"*"); 
		insert ((yyvsp[0].name), temp, scope, depth, 0); 
		strcpy((yyval.type),temp);
		strcpy((yyval.name),(yyvsp[0].name)); 
	}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 251 "basic.y" /* yacc.c:1646  */
    {
		printf("\n Name %s ",(yyvsp[0].type));
		change_scope((yyvsp[0].name), level); 
		strcpy((yyval.params), (yyvsp[0].type));
	}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 257 "basic.y" /* yacc.c:1646  */
    {
		//printf("\n Name %s ",$<name>1);
		change_scope((yyvsp[-2].name), level); 
		char temp[1000]; strcpy(temp, (yyvsp[-2].type)); 
		strcat(temp, (yyvsp[0].params)); strcpy((yyval.params), temp); 
	}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 266 "basic.y" /* yacc.c:1646  */
    {strcpy((yyval.type), (yyvsp[-1].type));}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 271 "basic.y" /* yacc.c:1646  */
    {strcpy((yyval.type), (yyvsp[0].type));}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 273 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-2].name), scope, depth, SYM_TBL);
		node* t = lookup((yyvsp[-2].name), SYM_TBL); 

		if(strcmp(t->type, (yyvsp[0].type)))
			yyerror("Type mismatch");

		strcpy((yyval.type), t->type);
	}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 283 "basic.y" /* yacc.c:1646  */
    {
		printf("entered");
		strcpy((yyval.type), (yyvsp[-2].type));
		node* t = lookup((yyvsp[-2].name), CONST_TBL);

		if(strcmp(t->type, (yyvsp[0].type)))
			yyerror("Type mismatch");

		strcpy((yyval.type), t->type);
	}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 294 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[0].name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[0].name), SYM_TBL); 
		strcpy((yyval.type), t->type);
	}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 300 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[0].name), SYM_TBL); 
		strcpy((yyval.type), t->type);
	}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 306 "basic.y" /* yacc.c:1646  */
    {strcpy((yyval.type), (yyvsp[0].type));}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 308 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[-1].name), SYM_TBL); 

		if(strcmp(t->type, "int"))
			yyerror("Increment not possible");

		strcpy((yyval.type), t->type);
	}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 318 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[-1].name), SYM_TBL); 

		if(strcmp(t->type, "int"))
			yyerror("Increment not possible");

		strcpy((yyval.type), t->type);
	}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 328 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-2].name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[-2].name), FUN_TBL); 

		if(strcmp(t->type, (yyvsp[0].type)))
			yyerror("Type mismatch");

		strcpy((yyval.type), t->type);
	}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 338 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[0].name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[0].name), FUN_TBL); 

		strcpy((yyval.type), t->type);
	}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 345 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[0].name), FUN_TBL);

		strcpy((yyval.type), t->type);
	}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 352 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), (yyvsp[0].type)); }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 354 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), (yyvsp[0].type)); }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 356 "basic.y" /* yacc.c:1646  */
    {
		if(strcmp((yyvsp[-2].type), (yyvsp[0].type)))
			yyerror("Type mismatch");

		strcpy((yyval.type), (yyvsp[0].type));
	}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 363 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-3].name), scope, depth, SYM_TBL); 	

		node* t = lookup((yyvsp[-3].name), SYM_TBL);


		if(strcmp((yyvsp[-1].type), "int"))
			yyerror("Array index not integer");
		char temp[1000];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		strcpy((yyval.type), temp);
	}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 377 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-5].name), scope, depth, SYM_TBL);

		if(strcmp((yyvsp[-3].type), "int"))
			yyerror("Array index not integer"); 

		node* t = lookup((yyvsp[-5].name), SYM_TBL);
		char temp[100];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		if(strcmp((yyvsp[-3].type), temp))
			yyerror("Type mismatch");

		strcpy((yyval.type),temp);
	}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 393 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-2].name), scope, depth, SYM_TBL);

		if(strcmp((yyvsp[-1].type), "int"))
			yyerror("Array index not integer");	

		node* t = lookup((yyvsp[-4].name), SYM_TBL);

		strcpy((yyval.type), t->type);
	}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 404 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-4].name), scope, depth, SYM_TBL); 

		if(strcmp((yyvsp[-2].type), "int"))
			yyerror("Array index not integer");	

		node* t = lookup((yyvsp[-4].name), SYM_TBL);
		char temp[100];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		if(strcmp((yyvsp[-4].type), "int*"))
			yyerror("Type mismatch");

		strcpy((yyval.type), temp);
	}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 420 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-4].name), scope, depth, SYM_TBL); 	

		if(strcmp((yyvsp[-2].type), "int"))
			yyerror("Array index not integer");		

		node* t = lookup((yyvsp[-4].name), SYM_TBL);
		char temp[100];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		if(strcmp((yyvsp[-4].type), "int*"))
			yyerror("Type mismatch");

		strcpy((yyval.type), temp);
	}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 439 "basic.y" /* yacc.c:1646  */
    { (yyval.size) = 1; }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 441 "basic.y" /* yacc.c:1646  */
    { (yyval.size) = (yyvsp[0].size) + 1; }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 446 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), (yyvsp[0].type)); }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 448 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.type), (yyvsp[0].type));

		if(strlen((yyvsp[-1].type))>0 && strlen((yyvsp[0].type))>0 && strcmp((yyvsp[-1].type), (yyvsp[0].type)))
			yyerror("Return type not matching");

		if(strlen((yyvsp[-1].type))>0)
			strcpy((yyval.type), (yyvsp[-1].type));


	}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 463 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyval.name), "int", scope, depth, 1); 
		strcpy((yyval.type), "int");
	}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 468 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyval.name), "string", scope, depth, 1); 
		strcpy((yyval.type), "char*");
	}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 473 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyval.name), "float", scope, depth, 1); 
		strcpy((yyval.type), "float");
	}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 478 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyval.name), "char", scope, depth, 1); 
		strcpy((yyval.type), "char");
	}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 514 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-3].name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[-3].name), FUN_TBL); 

		if(t->func_def!=1)
			yyerror("Function not defined"); 

		if(strcmp((yyvsp[-1].params), t->params)) 
			yyerror("Parameters type mismatch"); 
		strcpy((yyval.name), (yyvsp[-3].name));


	}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 528 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-2].name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[-2].name), FUN_TBL); 

		if(t->func_def!=1)
			yyerror("Function not defined"); 

		if(t->params!=NULL) 
			yyerror("Parameters type mismatch"); 
		strcpy((yyval.name), (yyvsp[-2].name));
	}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 543 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.params), (yyvsp[0].type)); }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 545 "basic.y" /* yacc.c:1646  */
    { 
		char temp[1000]; 
		strcpy(temp, (yyvsp[-2].type)); 
		strcat(temp, (yyvsp[0].params)); 
		strcpy((yyval.params), temp); 
	}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 555 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), ""); }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 557 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), ""); }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 559 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), ""); }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 561 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), ""); }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 563 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), (yyvsp[-1].type)); }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 565 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), ""); }
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 567 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), ""); }
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 569 "basic.y" /* yacc.c:1646  */
    {
		strcpy((yyval.type), "");
		check_scope((yyvsp[-2].name), scope, depth, SYM_TBL);
	}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 574 "basic.y" /* yacc.c:1646  */
    {
		strcpy((yyval.type), "");
		check_scope((yyvsp[-2].name), scope, depth, SYM_TBL);
	}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 579 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), (yyvsp[-1].type)); }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 581 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), ""); }
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 583 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), ""); }
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 591 "basic.y" /* yacc.c:1646  */
    { 
		varpt++;strcpy(vars[varpt],(yyvsp[0].name));

		insert ((yyvsp[0].name), multidec_type, scope, depth, 0); 
	}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 597 "basic.y" /* yacc.c:1646  */
    { 
		varpt++;strcpy(vars[varpt],(yyvsp[-2].name));

		insert ((yyvsp[-2].name), multidec_type, scope, depth, 0); 
	}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 603 "basic.y" /* yacc.c:1646  */
    { 
		varpt++; strcpy(vars[varpt],(yyvsp[0].name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[0].name), multidec_type, scope, depth, 0); 
	}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 610 "basic.y" /* yacc.c:1646  */
    { 
		varpt++; strcpy(vars[varpt],(yyvsp[0].name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[0].name), multidec_type, scope, depth, 0);
	}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 617 "basic.y" /* yacc.c:1646  */
    { 
		varpt++; strcpy(vars[varpt],(yyvsp[-2].name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[-2].name), multidec_type, scope, depth, 0);
	}
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 624 "basic.y" /* yacc.c:1646  */
    { 
		varpt++; strcpy(vars[varpt],(yyvsp[-2].name)); 
		pnt[varpt] = 1;
		insert ((yyvsp[-2].name), multidec_type, scope, depth, 0);
	}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 630 "basic.y" /* yacc.c:1646  */
    { 
		varpt++;strcpy(vars[varpt],(yyvsp[-2].name));

		insert ((yyvsp[-2].name), multidec_type, scope, depth, 0); 
	}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 636 "basic.y" /* yacc.c:1646  */
    { 
		varpt++;strcpy(vars[varpt],(yyvsp[0].name));

		insert ((yyvsp[0].name), multidec_type, scope, depth, 0); 
	}
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 642 "basic.y" /* yacc.c:1646  */
    { 
		varpt++; strcpy(vars[varpt],(yyvsp[-3].name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[-3].name), multidec_type, scope, depth, 0); 
		
		int t_array = atoi((yyvsp[-1].name));

		if(t_array<=0)
			yyerror("Invalid array size");

		node* t = lookup((yyvsp[-3].name), SYM_TBL);
		t->array_bound = t_array; 

	}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 658 "basic.y" /* yacc.c:1646  */
    {
		varpt++; strcpy(vars[varpt],(yyvsp[-6].name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[-6].name),multidec_type, scope, depth, 0);

		node* t = lookup((yyvsp[-6].name), SYM_TBL);
		t->array_bound = (yyvsp[-1].size);
	}
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 668 "basic.y" /* yacc.c:1646  */
    {
		varpt++; strcpy(vars[varpt],(yyvsp[-7].name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[-7].name),multidec_type, scope, depth, 0);

		int t_array = atoi((yyvsp[-5].name));

		if(t_array < (yyvsp[-1].size))
			yyerror("Array index out of bound");
		node* t = lookup((yyvsp[-7].name), SYM_TBL);
		t->array_bound = t_array;
	}
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 682 "basic.y" /* yacc.c:1646  */
    { 
		varpt++; strcpy(vars[varpt],(yyvsp[-3].name)); 
		pnt[varpt] = 1;
		
		insert ((yyvsp[-3].name), multidec_type, scope, depth, 0); 
		
		int t_array = atoi((yyvsp[-1].name));

		if(t_array<=0)
			yyerror("Invalid array size");

		node* t = lookup((yyvsp[-3].name), SYM_TBL);
		t->array_bound = t_array; 

	}
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 698 "basic.y" /* yacc.c:1646  */
    {
		varpt++; strcpy(vars[varpt],(yyvsp[-6].name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[-6].name),multidec_type, scope, depth, 0);

		node* t = lookup((yyvsp[-6].name), SYM_TBL);
		t->array_bound = (yyvsp[-1].size);
	}
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 708 "basic.y" /* yacc.c:1646  */
    {
		varpt++; strcpy(vars[varpt],(yyvsp[-7].name)); 
		pnt[varpt] = 1; 

		insert ((yyvsp[-7].name),multidec_type, scope, depth, 0);

		int t_array = atoi((yyvsp[-5].name));

		if(t_array < (yyvsp[-1].size))
			yyerror("Array index out of bound");
		node* t = lookup((yyvsp[-7].name), SYM_TBL);
		t->array_bound = t_array;
	}
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 725 "basic.y" /* yacc.c:1646  */
    {
		if(strcmp((yyvsp[-2].type),"int"))
			yyerror("Invalid expression");	
	}
#line 2407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 730 "basic.y" /* yacc.c:1646  */
    {
		if(strcmp((yyvsp[-4].type),"int"))
			yyerror("Invalid expression");	
	}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 737 "basic.y" /* yacc.c:1646  */
    {
		if(strcmp((yyvsp[-2].type),"int"))
			yyerror("Invalid expression");	
	}
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 744 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-3].name), scope, depth, SYM_TBL);}
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 746 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-4].name), scope, depth, SYM_TBL);}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 748 "basic.y" /* yacc.c:1646  */
    {
		if(strcmp((yyvsp[-4].type),"int"))
			yyerror("Invalid array index");	
	}
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2450 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 755 "basic.y" /* yacc.c:1906  */



void yyerror(char* s)
{
	error = 1;
	//printf("ERROR: %s\n", s);
	fprintf(stderr, "\nLINE %d: %s \nERROR: %s\n", yylineno, s, yytext);
	//exit(0);	
	
}

int main()
{
	yyin = fopen("test_cases/semantic/return_type.c", "r");
	//yyin = fopen("test_cases/program.c", "r");

	yyparse();

	if(error)
		printf("\nUNSUCCESSFUL\n");
	else
		printf("\nSUCCESS!\n");
	
	display();
	
	return 0;
}
