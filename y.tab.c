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
	int varpt = 0; 

#line 94 "y.tab.c" /* yacc.c:339  */

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
#line 29 "basic.y" /* yacc.c:355  */

    char name[1000];

    int size;

    char type[1000];
    char params[1000];

#line 235 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   340

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

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
       0,    61,    61,    62,    63,    64,    65,    69,    75,    81,
      85,    89,    98,   107,   114,   124,   130,   145,   153,   165,
     169,   178,   192,   202,   222,   224,   226,   228,   230,   232,
     234,   239,   240,   241,   242,   243,   244,   245,   246,   250,
     255,   264,   268,   270,   275,   280,   286,   292,   294,   300,
     306,   308,   314,   320,   322,   324,   329,   331,   336,   338,
     343,   348,   353,   358,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   384,
     385,   386,   387,   388,   389,   390,   394,   402,   412,   414,
     424,   425,   426,   427,   428,   429,   430,   432,   433,   434,
     436,   438,   439,   442,   444,   446,   451,   456,   461,   466,
     468,   473,   474,   477,   480,   482,   484
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
  "func_def", "id_dec", "id_assign_dec", "multidec", "datatype",
  "modifiers", "params_list", "brackets", "expression", "const_list",
  "statement_list", "constant", "bin_op", "un_op", "func_call",
  "expression_list", "statement", "id_chain", "conditional", "iterative",
  "assignment", YY_NULLPTR
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

#define YYPACT_NINF -145

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-145)))

#define YYTABLE_NINF -59

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     175,  -145,  -145,  -145,  -145,  -145,  -145,  -145,    16,   175,
     -41,   -19,   -17,    77,  -145,  -145,   175,   175,   175,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,     2,  -145,  -145,  -145,
       4,     8,  -145,    17,   165,   253,   -13,    11,   165,   266,
      11,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,   143,
    -145,  -145,   165,  -145,    20,    -4,    20,   170,    20,   -12,
      18,    77,    28,    29,    86,    39,    -1,  -145,    33,   -11,
      42,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,   111,  -145,
     165,    45,   165,    11,   165,    50,  -145,  -145,  -145,   165,
    -145,   227,   279,    25,    23,   107,    52,    12,   165,    11,
    -145,   227,    43,  -145,    57,    55,  -145,  -145,  -145,  -145,
    -145,  -145,    70,    71,   165,    72,    40,  -145,   227,  -145,
      74,    79,    80,    81,   116,   197,  -145,  -145,  -145,  -145,
     114,   123,  -145,   227,   118,   140,   165,    -4,  -145,   115,
    -145,   227,   165,  -145,   188,   165,   138,   165,   165,   139,
     145,   181,   136,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
     -10,   144,   140,   146,   142,    33,  -145,   148,  -145,   165,
     152,  -145,   153,   157,  -145,  -145,   154,  -145,   166,  -145,
    -145,   169,  -145,   140,  -145,   176,   227,   227,  -145,   232,
    -145,  -145,  -145,  -145,   215,  -145,   165,   227,   179,  -145,
    -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      38,    31,    32,    33,    34,    35,    36,    37,     0,    38,
       0,     0,     0,     0,     1,     2,    38,    38,    38,    26,
      27,    25,    24,    29,    30,    28,     0,     3,     4,     5,
       0,    15,    23,    18,     0,    38,     0,     0,     0,    38,
       0,    83,    80,    81,    82,    61,    60,    62,    63,    45,
      84,    85,     0,    79,    53,    19,    42,     0,    51,     0,
      39,     0,     0,     0,    17,     0,   103,   110,    22,     0,
       0,   106,    69,    68,    76,    75,    70,    73,    78,    77,
      72,    71,    64,    65,    66,    67,    48,    49,     0,    74,
       0,     0,     0,     0,     0,    46,    54,    47,    52,     0,
      10,    38,    38,     0,     0,    16,     0,   105,     0,     0,
      14,    38,     0,    87,    88,     0,    43,    41,    55,   109,
      44,    50,     0,     0,     0,     0,     0,   102,    38,    98,
       0,     0,     0,     0,     0,    38,    93,    94,    95,    40,
       0,    15,     9,    38,     0,     0,     0,   104,   108,     0,
      13,    38,     0,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     8,    97,    59,    18,
       0,     0,     0,     0,    56,   107,    12,     0,    89,     0,
       0,    96,     0,     0,    99,   100,     0,   101,     0,    17,
       7,     0,    20,     0,    11,     0,    38,    38,   114,     0,
      16,    21,    57,   115,   111,   113,     0,    38,     0,   112,
     116
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,   167,   256,     5,   318,   322,   182,   -27,   -32,   183,
     -34,  -124,   -43,   -54,    88,  -145,   -56,    90,  -144,   -31,
    -145,  -145,  -145
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,   129,   130,   131,   132,    26,    13,    62,    54,
     114,   173,   133,    56,    90,    57,    58,   115,   135,    32,
     136,   137,   138
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    98,   108,    97,    68,    10,    67,    70,    61,    71,
      63,    34,    61,   188,    10,   146,    14,    16,    91,    30,
      38,    10,    10,    10,    72,    73,    74,    75,    65,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    17,
      60,    18,   140,   158,    60,   134,   100,   110,   191,   101,
     111,    64,   204,   205,   189,   134,   116,    31,   118,    33,
     120,    93,   119,   209,    37,   121,    66,    35,   149,   202,
     139,    36,   134,    37,   147,    61,    39,    40,   148,   134,
     141,   142,    40,   102,   143,   162,    89,   134,   104,   106,
     156,   174,   168,   105,   107,   134,   159,   160,   109,    88,
     171,   150,   112,   161,   151,   117,    19,    60,   177,    88,
     144,    20,   175,   145,    21,   153,    22,    23,   174,    41,
      24,   180,   152,   182,   183,   154,    42,    43,    44,    25,
     155,   157,   163,    45,    46,    47,    48,   164,   165,   174,
     134,   134,    92,   166,    94,   195,    99,    72,    73,    74,
      75,   134,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    45,    46,    47,    48,    49,    50,    51,   169,
      52,   113,   208,    41,   167,    -6,    15,   176,    53,   172,
      42,    43,    44,    27,    28,    29,   170,    45,    46,    47,
      48,   179,    45,    46,    47,    48,   181,   184,   187,    86,
      87,     1,    88,   185,   186,     2,   190,   193,   192,    89,
     194,     3,   196,   197,   122,   198,     4,   123,   199,     5,
      49,    50,    51,     1,    52,    95,     6,     2,     7,    52,
     200,   201,    53,     3,   203,   206,   207,   210,     4,   124,
      96,     5,   178,   103,   122,     0,     0,   123,     6,     0,
       7,   125,   126,     1,     0,   127,     9,     2,   128,   -58,
       0,     0,     0,     3,     0,     9,     0,     0,     4,   124,
       0,     5,     9,     9,     9,     0,     0,     0,     6,     1,
       7,   125,   126,     2,     0,   127,     0,     0,   128,     3,
       0,     0,     1,     0,     4,     0,     2,     5,     0,     0,
       0,     0,     3,     0,     6,     1,     7,     4,     0,     2,
       5,     0,     0,    59,     0,     3,     0,     6,    11,     7,
       4,     0,    12,     5,     0,     0,    69,    11,     0,     0,
       6,    12,     7,     0,    11,    11,    11,     0,    12,    12,
      12
};

static const yytype_int16 yycheck[] =
{
      34,    57,     3,    57,    38,     0,    37,    39,    35,    40,
      23,     3,    39,    23,     9,     3,     0,    58,    52,    17,
       3,    16,    17,    18,     4,     5,     6,     7,    17,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    58,
      35,    58,    17,     3,    39,   101,    58,    58,   172,    61,
      61,    64,   196,   197,    64,   111,    90,    55,    92,    55,
      94,    65,    93,   207,    65,    99,    55,    59,   111,   193,
     102,    63,   128,    65,   108,   102,    59,    65,   109,   135,
      55,    58,    65,    65,    61,   128,    66,   143,    60,     3,
     124,   145,   135,    64,    55,   151,    56,    57,    65,    59,
     143,    58,    60,    63,    61,    60,    29,   102,   151,    59,
       3,    34,   146,    61,    37,    60,    39,    40,   172,     8,
      43,   155,    65,   157,   158,    55,    15,    16,    17,    52,
      59,    59,    58,    22,    23,    24,    25,    58,    58,   193,
     196,   197,    54,    62,    56,   179,    58,     4,     5,     6,
       7,   207,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    22,    23,    24,    25,    55,    56,    57,    55,
      59,    60,   206,     8,    58,     0,     9,    62,    67,    61,
      15,    16,    17,    16,    17,    18,    63,    22,    23,    24,
      25,     3,    22,    23,    24,    25,    58,    58,    62,    56,
      57,    26,    59,    58,    23,    30,    62,    65,    62,    66,
      62,    36,    60,    60,    17,    58,    41,    20,    64,    44,
      55,    56,    57,    26,    59,    55,    51,    30,    53,    59,
      64,    62,    67,    36,    58,     3,    21,    58,    41,    42,
      57,    44,   152,    61,    17,    -1,    -1,    20,    51,    -1,
      53,    54,    55,    26,    -1,    58,     0,    30,    61,    62,
      -1,    -1,    -1,    36,    -1,     9,    -1,    -1,    41,    42,
      -1,    44,    16,    17,    18,    -1,    -1,    -1,    51,    26,
      53,    54,    55,    30,    -1,    58,    -1,    -1,    61,    36,
      -1,    -1,    26,    -1,    41,    -1,    30,    44,    -1,    -1,
      -1,    -1,    36,    -1,    51,    26,    53,    41,    -1,    30,
      44,    -1,    -1,    60,    -1,    36,    -1,    51,     0,    53,
      41,    -1,     0,    44,    -1,    -1,    60,     9,    -1,    -1,
      51,     9,    53,    -1,    16,    17,    18,    -1,    16,    17,
      18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    30,    36,    41,    44,    51,    53,    69,    70,
      71,    72,    73,    75,     0,    69,    58,    58,    58,    29,
      34,    37,    39,    40,    43,    52,    74,    69,    69,    69,
      17,    55,    87,    55,     3,    59,    63,    65,     3,    59,
      65,     8,    15,    16,    17,    22,    23,    24,    25,    55,
      56,    57,    59,    67,    77,    78,    81,    83,    84,    60,
      71,    75,    76,    23,    64,    17,    55,    87,    78,    60,
      76,    87,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    56,    57,    59,    66,
      82,    78,    82,    65,    82,    55,    77,    81,    84,    82,
      58,    61,    65,    74,    60,    64,     3,    55,     3,    65,
      58,    61,    60,    60,    78,    85,    78,    60,    78,    87,
      78,    78,    17,    20,    42,    54,    55,    58,    61,    70,
      71,    72,    73,    80,    84,    86,    88,    89,    90,    76,
      17,    55,    58,    61,     3,    61,     3,    78,    87,    80,
      58,    61,    65,    60,    55,    59,    78,    59,     3,    56,
      57,    63,    80,    58,    58,    58,    62,    58,    80,    55,
      63,    80,    61,    79,    81,    78,    62,    80,    85,     3,
      78,    58,    78,    78,    58,    58,    23,    62,    23,    64,
      62,    79,    62,    65,    62,    78,    60,    60,    58,    64,
      64,    62,    79,    58,    86,    86,     3,    21,    78,    86,
      58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    69,    69,    69,    69,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    71,    71,    71,    72,
      72,    72,    72,    73,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    88,    88,    89,    90,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     3,     3,     0,     9,     8,     7,
       6,    10,     9,     8,     7,     3,     6,     5,     4,     5,
       9,    10,     6,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       3,     3,     1,     3,     3,     1,     2,     2,     2,     2,
       3,     1,     2,     1,     2,     3,     1,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     1,     3,
       2,     2,     2,     1,     1,     1,     3,     2,     1,     3,
       3,     3,     1,     1,     3,     2,     4,     4,     6,     5,
       3,     5,     7,     5,     4,     5,     7
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
        case 7:
#line 70 "basic.y" /* yacc.c:1646  */
    { 
		insert_fun ((yyvsp[-6].name), (yyvsp[-7].name), scope, depth, (yyvsp[-4].params)); 
		if(strcmp((yyvsp[-7].type), "void") && strcmp((yyvsp[-7].type), (yyvsp[-1].type))) 
			yyerror("Return type not matching");
	}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 76 "basic.y" /* yacc.c:1646  */
    { 
		insert_fun ((yyvsp[-5].name), (yyvsp[-6].name), scope, depth, NULL); 
		if(strcmp((yyvsp[-6].type), "void") && strcmp((yyvsp[-6].type), (yyvsp[-1].type))) 
			yyerror("Return type not matching");
	}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "basic.y" /* yacc.c:1646  */
    { 
		insert_fun ((yyvsp[-4].name), (yyvsp[-5].name), scope, depth, (yyvsp[-2].params));
	}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 86 "basic.y" /* yacc.c:1646  */
    {
		insert_fun ((yyvsp[-3].name), (yyvsp[-4].name), scope, depth, NULL);
	}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 90 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-8].name));
		strcat(temp,"*"); 
		insert_fun ((yyvsp[-7].name), (yyvsp[-8].name), scope, depth, (yyvsp[-4].params)); 
		if(strcmp(temp, "void") && strcmp(temp, (yyvsp[-1].type))) 
			yyerror("Return type not matching");
	}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 99 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-7].name));
		strcat(temp,"*"); 
		insert_fun ((yyvsp[-6].name), (yyvsp[-7].name), scope, depth, NULL); 
		if(strcmp(temp, "void") && strcmp(temp, (yyvsp[-1].type))) 
			yyerror("Return type not matching");
	}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 108 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-6].name));
		strcat(temp,"*"); 
		insert_fun ((yyvsp[-5].name), (yyvsp[-6].name), scope, depth, (yyvsp[-2].params));
	}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 115 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-5].name));
		strcat(temp,"*"); 
		insert_fun ((yyvsp[-4].name), (yyvsp[-5].name), scope, depth, NULL);
	}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 125 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.name),(yyvsp[0].name)); 
		insert ((yyvsp[0].name), (yyvsp[-1].name), scope, depth, 0); 
		strcpy((yyval.type),(yyvsp[-1].name)); 
	}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 131 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.name),(yyvsp[-3].name)); 
		char temp[1000];
		strcpy(temp,(yyvsp[-4].name));
		strcat(temp,"*"); 
		insert ((yyvsp[-3].name), temp, scope, depth, 0); 
		strcpy((yyval.type),temp);

		int t_array = atoi((yyvsp[-1].name));
		node* t = lookup((yyvsp[-3].name), SYM_TBL);
		t->array_bound = t_array; 


	}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 146 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.name),(yyvsp[-2].name)); 
		char temp[1000];strcpy(temp,(yyvsp[-3].name));
		strcat(temp,"*"); 
		insert ((yyvsp[-2].name), temp, scope, depth, 0); 
		strcpy((yyval.type),temp); 
	}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 154 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.name),(yyvsp[-1].name)); 
		char temp[1000];
		strcpy(temp,(yyvsp[-2].name));
		strcat(temp,"*"); 
		insert ((yyvsp[0].name),temp, scope, depth, 0); 
		strcpy((yyval.type),temp);
	}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 166 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyvsp[-2].name), (yyvsp[-3].name), scope, depth, 0);
	}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 170 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];strcpy(temp,(yyvsp[-7].name));
		strcat(temp,"*"); 
		insert ((yyvsp[-6].name),temp, scope, depth, 0);

		node* t = lookup((yyvsp[-6].name), SYM_TBL);
		t->array_bound = (yyvsp[0].size);
	}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 179 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-8].name));
		strcat(temp,"*"); 
		insert ((yyvsp[-7].name),temp, scope, depth, 0);

		int t_array = atoi((yyvsp[-5].name));

		if(t_array != (yyvsp[-1].size))
			yyerror("Array index out of bound");
		node* t = lookup((yyvsp[-7].name), SYM_TBL);
		t->array_bound = t_array;
	}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 193 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000]; 
		strcpy(temp,(yyvsp[-4].name)); 
		strcat(temp,"*"); 
		insert ((yyvsp[-2].name),temp, scope, depth, 0);
	}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 203 "basic.y" /* yacc.c:1646  */
    {
		varpt--;
		while(varpt>=0)
		{
			if(pnt[varpt])
			{
				char temp[1000];
				strcpy(temp,(yyvsp[-1].name));
				strcat(temp,"*"); 
				pnt[varpt] = 0;
				insert (vars[varpt--], (yyvsp[-1].name), scope, depth, 0);
			}
			else
				insert (vars[varpt--], (yyvsp[-1].name), scope, depth, 0);
		}		
	}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 223 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "int"); }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 225 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "float"); }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 227 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "char"); }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 229 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "double"); }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 231 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "void"); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 233 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "long"); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 235 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), "short"); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 251 "basic.y" /* yacc.c:1646  */
    {
		change_scope((yyvsp[0].name), level); 
		strcpy((yyval.params), (yyvsp[0].type));
	}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 256 "basic.y" /* yacc.c:1646  */
    {
		change_scope((yyvsp[-2].name), level); 
		char temp[1000]; strcpy(temp, (yyvsp[-2].type)); 
		strcat(temp, (yyvsp[0].params)); strcpy((yyval.params), temp); 
	}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 264 "basic.y" /* yacc.c:1646  */
    {strcpy((yyval.type), (yyvsp[-1].type));}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 269 "basic.y" /* yacc.c:1646  */
    {strcpy((yyval.type), (yyvsp[0].type));}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 271 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-2].name), scope, depth, SYM_TBL);
		strcpy((yyval.type), "bool");
	}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 276 "basic.y" /* yacc.c:1646  */
    {
		strcpy((yyval.type), (yyvsp[-2].type));
		strcpy((yyval.type), "bool");
	}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 281 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[0].name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[0].name), SYM_TBL); 
		strcpy((yyval.type), t->type);
	}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 287 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[0].name), SYM_TBL); 
		strcpy((yyval.type), t->type);
	}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 293 "basic.y" /* yacc.c:1646  */
    {strcpy((yyval.type), (yyvsp[0].type));}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 295 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[-1].name), SYM_TBL); 
		strcpy((yyval.type), t->type);
	}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 301 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[-1].name), SYM_TBL); 
		strcpy((yyval.type), t->type);
	}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 307 "basic.y" /* yacc.c:1646  */
    {strcpy((yyval.type), "bool");}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 309 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[0].name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[0].name), FUN_TBL); 
		strcpy((yyval.type), t->type);
	}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 315 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[0].name), FUN_TBL); 
		strcpy((yyval.type), t->type);
	}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 321 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), (yyvsp[0].type)); }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 323 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), (yyvsp[0].type)); }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 325 "basic.y" /* yacc.c:1646  */
    {strcpy((yyval.type), "bool");}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 330 "basic.y" /* yacc.c:1646  */
    { (yyval.size) = 1; }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 332 "basic.y" /* yacc.c:1646  */
    { (yyval.size) = (yyvsp[0].size) + 1; }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 337 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), (yyvsp[0].type)); }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 339 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), (yyvsp[0].type)); }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 344 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyval.name), "int", scope, depth, 1); 
		strcpy((yyval.type), "int");
	}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 349 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyval.name), "string", scope, depth, 1); 
		strcpy((yyval.type), "char*");
	}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 354 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyval.name), "float", scope, depth, 1); 
		strcpy((yyval.type), "float");
	}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 359 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyval.name), "char", scope, depth, 1); 
		strcpy((yyval.type), "char");
	}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 395 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-3].name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[-3].name), FUN_TBL); 
		if(strcmp((yyvsp[-1].params), t->params)) 
			yyerror("Parameters type mismatch"); 
		strcpy((yyval.name), (yyvsp[-3].name));
	}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 403 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-2].name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[-2].name), FUN_TBL); 
		if(t->params!=NULL) yyerror("Parameters type mismatch"); 
		strcpy((yyval.name), (yyvsp[-2].name));
	}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 413 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.params), (yyvsp[0].type)); }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 415 "basic.y" /* yacc.c:1646  */
    { 
		char temp[1000]; 
		strcpy(temp, (yyvsp[-2].type)); 
		strcat(temp, (yyvsp[0].params)); 
		strcpy((yyval.params), temp); 
	}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 431 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.type), (yyvsp[-1].type)); }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 435 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-2].name), scope, depth, SYM_TBL);}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 437 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-2].name), scope, depth, SYM_TBL);}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 443 "basic.y" /* yacc.c:1646  */
    { strcpy(vars[varpt++],(yyvsp[0].name)); }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 445 "basic.y" /* yacc.c:1646  */
    { strcpy(vars[varpt++],(yyvsp[-2].name)); }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 447 "basic.y" /* yacc.c:1646  */
    { 
		strcpy(vars[varpt],(yyvsp[-1].name)); 
		pnt[varpt] = 1; varpt++;
	}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 452 "basic.y" /* yacc.c:1646  */
    { 
		strcpy(vars[varpt],(yyvsp[-3].name)); 
		pnt[varpt] = 1; varpt++;
	}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 457 "basic.y" /* yacc.c:1646  */
    { 
		strcpy(vars[varpt],(yyvsp[-3].name)); 
		pnt[varpt] = 1; varpt++;
	}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 462 "basic.y" /* yacc.c:1646  */
    { 
		strcpy(vars[varpt],(yyvsp[-5].name)); 
		pnt[varpt] = 1; varpt++;
	}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 467 "basic.y" /* yacc.c:1646  */
    { strcpy(vars[varpt++],(yyvsp[-4].name)); }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 469 "basic.y" /* yacc.c:1646  */
    { strcpy(vars[varpt++],(yyvsp[-2].name)); }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 481 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-3].name), scope, depth, SYM_TBL);}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 483 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-4].name), scope, depth, SYM_TBL);}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 485 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-6].name), scope, depth, SYM_TBL);

		int t_array = atoi((yyvsp[-4].name));

		node* t = lookup((yyvsp[-6].name), SYM_TBL);
		if(t->array_bound<=t_array)
			yyerror("Array index out of bound");
	}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2100 "y.tab.c" /* yacc.c:1646  */
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
#line 497 "basic.y" /* yacc.c:1906  */



void yyerror(char* s)
{
	error = 1;
	//printf("ERROR: %s\n", s);
	fprintf(stderr, "\nLINE %d: %s \nERROR: %s\n", yylineno, s, yytext);
	//exit(0);	
	
}

int main()
{
	//yyin = fopen("test_cases/yacc/8.c", "r");
	yyin = fopen("test_cases/program.c", "r");

	yyparse();

	if(error)
		printf("\nUNSUCCESSFUL\n");
	else
		printf("\nSUCCESS!\n");
	
	display();
	
	return 0;
}
