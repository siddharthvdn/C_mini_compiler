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

	#include <stdio.h>
	extern FILE *yyin;
	
	int yylineno;
	
	char* yytext;
	
	void yyerror(char*);

#line 83 "y.tab.c" /* yacc.c:339  */

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
    STRCONST = 258,
    INTCONST = 259,
    FLTCONST = 260,
    CHARCONST = 261,
    AUTO = 262,
    BREAK = 263,
    CASE = 264,
    CHAR = 265,
    CONST = 266,
    CONTINUE = 267,
    DEFAULT = 268,
    DO = 269,
    DOUBLE = 270,
    ELSE = 271,
    ENUM = 272,
    EXTERN = 273,
    FLOAT = 274,
    FOR = 275,
    IF = 276,
    INT = 277,
    LONG = 278,
    REGISTER = 279,
    RETURN = 280,
    SHORT = 281,
    SIGNED = 282,
    SIZEOF = 283,
    STATIC = 284,
    STRUCT = 285,
    SWITCH = 286,
    TYPEDEF = 287,
    UNION = 288,
    UNSIGNED = 289,
    VOID = 290,
    VOLATILE = 291,
    WHILE = 292,
    IDENTIFIER = 293,
    INCREMENT = 294,
    DECREMENT = 295,
    AND = 296,
    OR = 297,
    EQUAL = 298,
    GREATER = 299,
    LESSER = 300,
    NOTEQUAL = 301
  };
#endif
/* Tokens.  */
#define STRCONST 258
#define INTCONST 259
#define FLTCONST 260
#define CHARCONST 261
#define AUTO 262
#define BREAK 263
#define CASE 264
#define CHAR 265
#define CONST 266
#define CONTINUE 267
#define DEFAULT 268
#define DO 269
#define DOUBLE 270
#define ELSE 271
#define ENUM 272
#define EXTERN 273
#define FLOAT 274
#define FOR 275
#define IF 276
#define INT 277
#define LONG 278
#define REGISTER 279
#define RETURN 280
#define SHORT 281
#define SIGNED 282
#define SIZEOF 283
#define STATIC 284
#define STRUCT 285
#define SWITCH 286
#define TYPEDEF 287
#define UNION 288
#define UNSIGNED 289
#define VOID 290
#define VOLATILE 291
#define WHILE 292
#define IDENTIFIER 293
#define INCREMENT 294
#define DECREMENT 295
#define AND 296
#define OR 297
#define EQUAL 298
#define GREATER 299
#define LESSER 300
#define NOTEQUAL 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  170
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  285

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
       2,     2,     2,    57,     2,     2,     2,    59,    52,     2,
      47,    48,    53,    54,    51,    55,     2,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,    67,
      60,    66,    61,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    62,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    63,    69,    56,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    28,    28,    29,    29,    29,    29,    30,    35,    36,
      37,    38,    39,    40,    44,    45,    49,    50,    51,    52,
      53,    54,    58,    59,    60,    61,    62,    63,    67,    68,
      72,    73,    74,    75,    79,    80,    81,    85,    86,    87,
      88,    89,    93,    94,    95,    99,   100,   104,   105,   109,
     110,   114,   115,   119,   120,   124,   125,   129,   130,   134,
     135,   139,   144,   148,   149,   150,   151,   152,   153,   157,
     158,   163,   164,   168,   169,   170,   171,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   187,   188,   189,   190,
     196,   197,   202,   203,   208,   209,   210,   211,   212,   213,
     214,   218,   219,   220,   221,   225,   226,   233,   234,   238,
     239,   240,   244,   245,   249,   250,   254,   255,   256,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   272,   273,
     274,   278,   279,   283,   284,   285,   286,   287,   288,   292,
     293,   294,   298,   299,   300,   301,   305,   306,   310,   311,
     315,   316,   320,   321,   322,   326,   327,   328,   329,   333,
     334,   335,   336,   341,   342,   346,   347,   351,   352,   353,
     354
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRCONST", "INTCONST", "FLTCONST",
  "CHARCONST", "AUTO", "BREAK", "CASE", "CHAR", "CONST", "CONTINUE",
  "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT", "FOR",
  "IF", "INT", "LONG", "REGISTER", "RETURN", "SHORT", "SIGNED", "SIZEOF",
  "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID",
  "VOLATILE", "WHILE", "IDENTIFIER", "INCREMENT", "DECREMENT", "AND", "OR",
  "EQUAL", "GREATER", "LESSER", "NOTEQUAL", "'('", "')'", "'['", "']'",
  "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "specifier_qualifier_list", "type_qualifier",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    40,    41,    91,
      93,    44,    38,    42,    43,    45,   126,    33,    47,    37,
      60,    62,    94,   124,    63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -147

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-147)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1125,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,    54,    -1,  -147,
      54,  1221,  1221,  1221,   704,    48,    51,  1004,  -147,  -147,
     -22,  -147,  -147,    -1,    -7,  -147,   669,  -147,  -147,  -147,
     225,  -147,    54,  -147,   704,  1158,   777,    48,  -147,  -147,
    -147,  -147,  -147,    54,  -147,   560,  -147,   704,  -147,  -147,
    -147,  -147,   -12,   913,     2,    -2,   522,    55,    59,   580,
     933,    74,    84,    93,   953,   953,   739,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,    83,    69,   913,  -147,
      80,    86,    43,    24,   128,   116,   122,   166,   -25,  -147,
    -147,    11,  -147,  -147,  -147,   292,   359,  -147,  -147,  -147,
    -147,   148,  -147,  -147,  -147,  -147,    67,    77,  -147,   112,
    -147,  -147,  -147,  -147,   169,  -147,   560,  -147,  -147,  -147,
    -147,   157,  -147,   522,   186,   618,   913,  -147,    14,   739,
    -147,   913,   913,   522,   913,  -147,  -147,   124,   366,    47,
     366,   176,  -147,  -147,   797,   913,   913,  -147,   913,   913,
     913,   913,   913,   913,   913,   913,   913,   913,   913,   913,
     913,   913,   913,   913,   913,   913,  -147,  -147,   426,  -147,
    -147,  1037,   835,  -147,    19,  -147,    66,  -147,  1221,  -147,
     187,  -147,  -147,   -27,   522,  -147,   180,   618,   126,  -147,
     207,   131,   138,  -147,  -147,  -147,  1081,    70,  -147,  -147,
     913,  -147,   152,  -147,   114,  -147,  -147,  -147,  -147,    80,
      80,    86,    86,    86,    86,    43,    43,    24,   128,   116,
     122,   166,   -15,  -147,  -147,  -147,   153,   209,  -147,   208,
      66,  1190,   855,  -147,  -147,   464,  -147,  -147,   913,   875,
     522,  -147,   522,   522,  -147,  -147,   913,  -147,   913,  -147,
    -147,  -147,  -147,   154,  -147,   216,  -147,  -147,   160,   522,
     164,   251,  -147,  -147,  -147,  -147,  -147,  -147,   201,  -147,
     522,   522,  -147,  -147,  -147
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    75,    78,    90,    83,    73,    82,    80,    81,    76,
      79,    84,    74,    85,    77,    91,    94,     0,   101,   166,
       0,    63,    65,    67,     0,    93,     0,     0,   163,   165,
       0,   105,   103,   102,     0,    69,    71,    64,    66,    68,
       0,   146,     0,   170,     0,     0,     0,    92,     1,   164,
      95,   106,   104,     0,    62,     0,   168,     0,     3,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,    22,    23,    24,
      25,    26,    27,   150,   142,     8,    16,    28,     0,    30,
      34,    37,    42,    45,    47,    49,    51,    53,    55,    57,
      59,     0,   148,   133,   134,     0,     0,   135,   136,   137,
     138,    71,   147,   169,   112,   100,   111,     0,   107,     0,
       2,    97,    28,    61,     0,    70,     0,   128,    72,   167,
     160,     0,   159,     0,     0,     0,     0,   161,     0,     0,
      20,     0,     0,     0,     0,    17,    18,     0,    87,   114,
      89,     0,    12,    13,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   144,     0,   143,
     149,     0,     0,   109,   116,   110,   117,    98,     0,    99,
       0,    96,   131,     0,     0,   141,     0,     0,     0,   162,
       0,     0,     0,   139,     7,    86,     0,   116,   115,    88,
       0,    10,     0,    14,     0,    58,    31,    32,    33,    35,
      36,    41,    40,    38,    39,    43,    44,    46,    48,    50,
      52,    54,     0,    60,   145,   124,     0,     0,   120,     0,
     118,     0,     0,   108,   113,     0,   129,   140,     0,     0,
       0,    21,     0,     0,    29,    11,     0,     9,     0,   125,
     119,   121,   126,     0,   122,     0,   130,   132,     0,     0,
       0,   152,   154,   155,    15,    56,   127,   123,     0,   157,
       0,     0,   156,   158,   153
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,  -147,   -16,  -147,   -74,    34,     4,    50,
     100,   101,    99,   102,   103,  -147,   -45,   -46,   -65,   -55,
       7,     0,  -147,   220,  -147,   -57,  -117,    23,    -5,   -23,
      10,  -147,   -43,    87,  -147,   144,  -100,  -146,  -121,  -147,
     -60,  -147,    -4,   -11,   179,  -122,  -147,  -147,  -147,  -147,
     258,  -147
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    85,    86,   212,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   124,
      41,    42,    34,    35,    21,    22,   149,    23,    24,    25,
      26,    33,   236,   118,   119,   151,   237,   186,   128,   193,
     102,   103,   104,    44,   106,   107,   108,   109,   110,    27,
      28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      20,   123,   117,    47,   138,   192,   134,    19,   131,   127,
       3,   147,    30,   197,   157,    36,   185,   173,   123,   148,
      43,    37,    38,    39,   245,    57,    50,    20,    32,   105,
     122,   205,    56,   209,    19,    15,   175,   111,   240,   174,
     113,    31,   246,    52,    53,   116,   180,   122,   111,   208,
     258,   112,    18,   129,   140,   130,    51,    16,   145,   146,
      54,   240,   175,   133,   112,   175,   181,   167,   182,   132,
     168,   198,   122,   195,   147,   249,   201,   202,   176,   147,
     127,   199,   148,   203,   216,   217,   218,   163,   164,    16,
     214,   148,    16,   148,   206,    45,   182,    46,    17,   150,
      18,    17,   135,   165,   166,    16,   136,    18,   213,   232,
     215,   183,   112,   241,   181,   242,   182,   206,   180,   182,
      18,   141,   152,   153,   267,   187,   184,   239,   188,   233,
     154,   142,   155,   158,   247,   156,   254,   123,   159,   160,
     161,   162,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   143,   207,
     189,    47,   150,   190,   257,   175,   122,   221,   222,   223,
     224,   150,   204,   150,   250,   175,    30,   175,   170,   252,
     169,   116,   175,   268,   270,   171,   253,   265,   116,   175,
     271,   184,   272,   273,   122,   219,   220,   123,   263,   127,
     255,   259,   276,   256,   188,   188,   116,   172,   278,   279,
     274,   175,   280,   275,    55,   175,   207,   225,   226,   191,
     283,   284,   194,   196,   210,   244,   122,   248,    58,    59,
      60,    61,     1,    62,    63,     2,     3,    64,    65,    66,
       4,   116,   122,     5,     6,    67,    68,     7,     8,     9,
      69,    10,    11,    70,    12,   251,    71,   260,   261,    13,
      14,    15,    72,    73,    74,    75,   277,   281,   282,   227,
     229,   228,    76,   125,   230,   243,   231,    77,    78,    79,
      80,    81,    82,   200,   178,    49,     0,     0,     0,     0,
       0,     0,    83,    40,    84,    58,    59,    60,    61,     1,
      62,    63,     2,     3,    64,    65,    66,     4,     0,     0,
       5,     6,    67,    68,     7,     8,     9,    69,    10,    11,
      70,    12,     0,    71,     0,     0,    13,    14,    15,    72,
      73,    74,    75,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      40,   177,    58,    59,    60,    61,     0,    62,    63,     0,
       0,    64,    65,    66,     0,     0,     2,     3,     0,    67,
      68,     4,     0,     0,    69,     6,     0,    70,     7,     8,
      71,     0,    10,    11,     0,     0,    72,    73,    74,    75,
      13,    14,    15,     0,     0,     0,    76,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    40,   179,    58,
      59,    60,    61,     0,    62,    63,     0,     0,    64,    65,
      66,     0,     0,     0,     0,     0,    67,    68,     0,     0,
       0,    69,     0,     0,    70,     0,     0,    71,     0,     0,
       0,     0,     0,    72,    73,    74,    75,    58,    59,    60,
      61,     0,     0,    76,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    83,    40,   234,     0,     0,     0,     0,
       0,     0,   120,    74,    75,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,     0,     0,     0,    58,    59,    60,    61,     0,
      62,    63,   126,   266,    64,    65,    66,     0,     0,     0,
       0,     0,    67,    68,     0,     0,     0,    69,     0,     0,
      70,     0,     0,    71,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    58,    59,    60,    61,     0,     0,    76,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
       0,     0,     0,    58,    59,    60,    61,     0,    70,    83,
      40,     0,     0,     0,     0,     0,     0,     0,   120,    74,
      75,     0,     0,     0,     0,     0,     0,    76,    70,     0,
       0,     0,    77,    78,    79,    80,    81,    82,   120,    74,
      75,    58,    59,    60,    61,     0,     0,    76,   126,     0,
       0,     0,    77,    78,    79,    80,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,    70,   137,     0,     0,
       0,     0,     0,     0,     0,     0,   120,    74,    75,     0,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,     1,     0,     0,     2,
       3,     0,     0,     0,     4,    83,     0,     5,     6,     0,
       0,     7,     8,     9,     0,    10,    11,     0,    12,     0,
       0,     0,     0,    13,    14,    15,     0,     0,     0,     0,
       0,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     0,     5,     6,     0,     0,     7,     8,     9,     0,
      10,    11,     0,    12,     0,    55,     0,    40,    13,    14,
      15,     0,    58,    59,    60,    61,     0,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     0,     0,     6,     0,
       0,     7,     8,     0,     0,    10,    11,    70,     0,     0,
       0,     0,    40,    13,    14,    15,     0,   120,    74,    75,
      58,    59,    60,    61,     0,     0,    76,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,     0,     0,     0,
      58,    59,    60,    61,     0,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,    74,    75,     0,     0,
       0,     0,     0,     0,    76,    70,     0,   121,     0,    77,
      78,    79,    80,    81,    82,   120,    74,    75,    58,    59,
      60,    61,     0,     0,    76,   211,     0,     0,     0,    77,
      78,    79,    80,    81,    82,     0,     0,     0,    58,    59,
      60,    61,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   120,    74,    75,     0,     0,    58,    59,
      60,    61,    76,    70,     0,   238,     0,    77,    78,    79,
      80,    81,    82,   120,    74,    75,     0,     0,     0,     0,
       0,     0,    76,    70,     0,   264,     0,    77,    78,    79,
      80,    81,    82,   120,    74,    75,    58,    59,    60,    61,
       0,     0,    76,   269,     0,     0,     0,    77,    78,    79,
      80,    81,    82,     0,     0,     0,    58,    59,    60,    61,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,    74,    75,     0,     0,    58,    59,    60,    61,
      76,    70,     0,     0,     0,    77,    78,    79,    80,    81,
      82,   120,    74,    75,     0,     0,     0,     0,     0,     0,
     139,    70,     0,     0,     0,    77,    78,    79,    80,    81,
      82,   120,    74,    75,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,    48,    77,    78,    79,    80,    81,
      82,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     0,     5,     6,     0,     0,     7,     8,     9,     0,
      10,    11,     0,    12,     0,     0,     0,     0,    13,    14,
      15,     0,    16,     0,     1,     0,     0,     2,     3,     0,
       0,    17,     4,     0,     0,     5,     6,    18,     0,     7,
       8,     9,     0,    10,    11,     0,    12,     0,     0,     0,
       0,    13,    14,    15,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   235,   182,     0,     1,     0,
      18,     2,     3,     0,     0,     0,     4,     0,     0,     5,
       6,     0,     0,     7,     8,     9,     0,    10,    11,     0,
      12,     0,     0,     0,     0,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   206,   235,
     182,     0,     1,     0,    18,     2,     3,     0,     0,     0,
       4,     0,     0,     5,     6,     0,     0,     7,     8,     9,
       0,    10,    11,     0,    12,     0,     0,     0,     0,    13,
      14,    15,     0,    16,     0,     1,     0,     0,     2,     3,
       0,     0,    17,     4,     0,     0,     5,     6,    18,     0,
       7,     8,     9,     0,    10,    11,     0,    12,     0,     0,
       0,     0,    13,    14,    15,     0,   114,     1,     0,     0,
       2,     3,     0,     0,     0,     4,   115,     0,     5,     6,
       0,     0,     7,     8,     9,     0,    10,    11,     0,    12,
       0,     0,     0,     0,    13,    14,    15,     0,     1,     0,
       0,     2,     3,     0,     0,     0,     4,     0,   262,     5,
       6,     0,     0,     7,     8,     9,     0,    10,    11,     0,
      12,     0,     0,     0,     0,    13,    14,    15
};

static const yytype_int16 yycheck[] =
{
       0,    46,    45,    26,    69,   126,    66,     0,    63,    55,
      11,    76,    17,   135,    88,    20,   116,    42,    63,    76,
      24,    21,    22,    23,    51,    36,    48,    27,    18,    40,
      46,   148,    36,   150,    27,    36,    51,    42,   184,    64,
      44,    18,    69,    33,    51,    45,   106,    63,    53,   149,
      65,    44,    53,    57,    70,    67,    33,    38,    74,    75,
      67,   207,    51,    65,    57,    51,    47,    43,    49,    67,
      46,   136,    88,   133,   139,   197,   141,   142,    67,   144,
     126,    67,   139,   143,   158,   159,   160,    44,    45,    38,
     155,   148,    38,   150,    47,    47,    49,    49,    47,    76,
      53,    47,    47,    60,    61,    38,    47,    53,   154,   174,
     156,   116,   105,    47,    47,    49,    49,    47,   178,    49,
      53,    47,    39,    40,   245,    48,   116,   182,    51,   175,
      47,    47,    49,    53,   194,    66,   210,   182,    58,    59,
      54,    55,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    65,   149,
      48,   184,   139,    51,    50,    51,   182,   163,   164,   165,
     166,   148,    48,   150,    48,    51,   181,    51,    62,    48,
      52,   181,    51,   248,   249,    63,    48,   242,   188,    51,
     250,   181,   252,   253,   210,   161,   162,   242,   241,   245,
      48,    48,    48,    51,    51,    51,   206,    41,    48,   269,
     256,    51,    48,   258,    66,    51,   206,   167,   168,    50,
     280,   281,    65,    37,    48,    38,   242,    47,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,   241,   258,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    48,    31,    48,    50,    34,
      35,    36,    37,    38,    39,    40,    50,    16,    67,   169,
     171,   170,    47,    53,   172,   188,   173,    52,    53,    54,
      55,    56,    57,   139,   105,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    12,    13,    14,    -1,    -1,    10,    11,    -1,    20,
      21,    15,    -1,    -1,    25,    19,    -1,    28,    22,    23,
      31,    -1,    26,    27,    -1,    -1,    37,    38,    39,    40,
      34,    35,    36,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    28,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,     3,     4,     5,
       6,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    68,    69,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      28,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,     3,     4,     5,     6,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,    28,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    28,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    38,    39,
      40,     3,     4,     5,     6,    -1,    -1,    47,    68,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,     7,    -1,    -1,    10,
      11,    -1,    -1,    -1,    15,    67,    -1,    18,    19,    -1,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    29,    -1,
      -1,    -1,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    10,    11,    -1,    -1,    -1,    15,
      -1,    -1,    18,    19,    -1,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    29,    -1,    66,    -1,    68,    34,    35,
      36,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      11,    -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    -1,
      -1,    22,    23,    -1,    -1,    26,    27,    28,    -1,    -1,
      -1,    -1,    68,    34,    35,    36,    -1,    38,    39,    40,
       3,     4,     5,     6,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    28,    -1,    50,    -1,    52,
      53,    54,    55,    56,    57,    38,    39,    40,     3,     4,
       5,     6,    -1,    -1,    47,    48,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,     3,     4,
       5,     6,    47,    28,    -1,    50,    -1,    52,    53,    54,
      55,    56,    57,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    28,    -1,    50,    -1,    52,    53,    54,
      55,    56,    57,    38,    39,    40,     3,     4,     5,     6,
      -1,    -1,    47,    48,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,     3,     4,     5,     6,
      47,    28,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    28,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,     0,    52,    53,    54,    55,    56,
      57,     7,    -1,    -1,    10,    11,    -1,    -1,    -1,    15,
      -1,    -1,    18,    19,    -1,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,
      36,    -1,    38,    -1,     7,    -1,    -1,    10,    11,    -1,
      -1,    47,    15,    -1,    -1,    18,    19,    53,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    29,    -1,    -1,    -1,
      -1,    34,    35,    36,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,     7,    -1,
      53,    10,    11,    -1,    -1,    -1,    15,    -1,    -1,    18,
      19,    -1,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,     7,    -1,    53,    10,    11,    -1,    -1,    -1,
      15,    -1,    -1,    18,    19,    -1,    -1,    22,    23,    24,
      -1,    26,    27,    -1,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    -1,    38,    -1,     7,    -1,    -1,    10,    11,
      -1,    -1,    47,    15,    -1,    -1,    18,    19,    53,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    29,    -1,    -1,
      -1,    -1,    34,    35,    36,    -1,    38,     7,    -1,    -1,
      10,    11,    -1,    -1,    -1,    15,    48,    -1,    18,    19,
      -1,    -1,    22,    23,    24,    -1,    26,    27,    -1,    29,
      -1,    -1,    -1,    -1,    34,    35,    36,    -1,     7,    -1,
      -1,    10,    11,    -1,    -1,    -1,    15,    -1,    48,    18,
      19,    -1,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      29,    -1,    -1,    -1,    -1,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    10,    11,    15,    18,    19,    22,    23,    24,
      26,    27,    29,    34,    35,    36,    38,    47,    53,    90,
      91,    94,    95,    97,    98,    99,   100,   119,   120,   121,
      98,    97,   100,   101,    92,    93,    98,    91,    91,    91,
      68,    90,    91,   112,   113,    47,    49,    99,     0,   120,
      48,    97,   100,    51,    67,    66,   112,   113,     3,     4,
       5,     6,     8,     9,    12,    13,    14,    20,    21,    25,
      28,    31,    37,    38,    39,    40,    47,    52,    53,    54,
      55,    56,    57,    67,    69,    71,    72,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    98,    90,   112,    38,    48,    91,   102,   103,   104,
      38,    50,    74,    86,    89,    93,    68,    87,   108,   112,
      67,    89,    67,    65,   110,    47,    47,    67,    88,    47,
      74,    47,    47,    65,    47,    74,    74,    88,    95,    96,
      97,   105,    39,    40,    47,    49,    66,    76,    53,    58,
      59,    54,    55,    44,    45,    60,    61,    43,    46,    52,
      62,    63,    41,    42,    64,    51,    67,    69,   114,    69,
     110,    47,    49,    98,   100,   106,   107,    48,    51,    48,
      51,    50,   108,   109,    65,   110,    37,   115,    88,    67,
     105,    88,    88,   110,    48,    96,    47,   100,   106,    96,
      48,    48,    73,    87,    88,    87,    76,    76,    76,    77,
      77,    78,    78,    78,    78,    79,    79,    80,    81,    82,
      83,    84,    88,    87,    69,    48,   102,   106,    50,    89,
     107,    47,    49,   103,    38,    51,    69,   110,    47,   115,
      48,    48,    48,    48,    76,    48,    51,    50,    65,    48,
      48,    50,    48,   102,    50,    89,    69,   108,    88,    48,
      88,   110,   110,   110,    87,    86,    48,    50,    48,   110,
      48,    16,    67,   110,   110
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    75,    75,    75,    75,    75,    75,    76,    76,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    79,
      79,    79,    80,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    90,    91,    91,    91,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    96,
      97,    97,    98,    98,    99,    99,    99,    99,    99,    99,
      99,   100,   100,   100,   100,   101,   101,   102,   102,   103,
     103,   103,   104,   104,   105,   105,   106,   106,   106,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   108,   108,
     108,   109,   109,   110,   110,   110,   110,   110,   110,   111,
     111,   111,   112,   112,   112,   112,   113,   113,   114,   114,
     115,   115,   116,   116,   116,   117,   117,   117,   117,   118,
     118,   118,   118,   119,   119,   120,   120,   121,   121,   121,
     121
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       3,     4,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       3,     1,     3,     1,     2,     1,     2,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       1,     1,     2,     1,     1,     3,     4,     3,     4,     4,
       3,     1,     2,     2,     3,     1,     2,     1,     3,     2,
       2,     1,     1,     3,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     2,     3,     3,     4,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     3,     4,     1,     2,     1,     2,
       1,     2,     5,     7,     5,     5,     7,     6,     7,     2,
       2,     2,     3,     1,     2,     1,     1,     4,     3,     3,
       2
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
      
#line 1720 "y.tab.c" /* yacc.c:1646  */
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
#line 357 "basic.y" /* yacc.c:1906  */



void yyerror(char* s)
{
	//printf("ERROR: %s\n", s);
	fprintf(stderr, "LINE %d: %s \nERRROR: %s\n", yylineno, s, yytext);
}

int main()
{
	//yyin = fopen("test_cases/program.c", "r");
	yyin = fopen("test_cases/yacc/1.c", "r");

	yyparse();
	
	printf("SUCCESS!\n");
	
	display();
	
	return 0;
}
