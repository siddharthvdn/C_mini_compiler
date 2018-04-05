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
	
	int iterative = 0;

	struct Attributes 
	{
	    char name[1000];

	    int size;

	    char type[1000];
	    char params[1000];
	};


	/* ICG Variables*/

	char stack[1000][100];
	char idx[2] = "0";
	char temp[2] = "t";
	int top = 0;

	int label[1000];
	int ltop = 0;
	int lnum = 0;

	
	char pstack[1000][100];
	int ptop = 0;

	/* ICG Variables*/

	/* ICG Functions*/
	void gencode()
	{
		strcpy(temp,"t");
		strcat(temp, idx);
		printf("%s = %s %s %s\n",temp,stack[top-2],stack[top-1],stack[top]);
		top-=2;
		strcpy(stack[top],temp);
		idx[0]++;
	}

	void gencode_umin()
	{
		strcpy(temp,"t");
		strcat(temp,idx);
		printf("%s = -%s\n",temp,stack[top]);
		top--;
		strcpy(stack[top],temp);
		idx[0]++;
	}

	void post_increment()
	{
		while(top>0)
			printf("%s\n", stack[top--]);
	}

	void if1()
	{
		lnum++;
		strcpy(temp,"t");
		strcat(temp,idx);
		printf("%s = not %s\n",temp,stack[top]);
	 	printf("if %s goto L%d\n",temp,lnum);
		idx[0]++;
		label[++ltop]=lnum;	
		
	}

	void if2()
	{
		lnum++;
		printf("goto L%d\n",lnum);
		printf("L%d: \n",label[ltop--]);
		label[++ltop]=lnum;
	}

	void if3()
	{
		printf("L%d:\n",label[ltop--]);
	}

	void w1()
	{
		lnum++;
		label[++ltop]=lnum;
		printf("L%d:\n",lnum);
	}

	void w2()
	{
		lnum++;
		strcpy(temp,"t");
		strcat(temp,idx);
		printf("%s = not %s\n",temp,stack[top--]);
	 	printf("if %s goto L%d\n",temp,lnum);
		idx[0]++;
		label[++ltop]=lnum;
	}

	void w3()
	{
		int y=label[ltop--];
		printf("goto L%d\n",label[ltop--]);
		printf("L%d:\n",y);
	}

	void array(char* x)
	{
		strcpy(temp,"t");
		strcat(temp,idx);
		printf("%s = %s * 4\n",temp,stack[top]);
		strcpy(stack[top],temp);
		idx[0]++;
		strcpy(temp,"t");
		strcat(temp,idx);
		printf("%s = %s [ %s ] \n",temp,x,stack[top]);
		top--;
		strcpy(stack[top],temp);
		idx[0]++;	
	}

	void array_assign(char* x)
	{
		strcpy(temp,"t");
		strcat(temp,idx);
		printf("%s = %s * 4\n",temp,stack[top-1]);
		idx[0]++;
		printf("%s [ %s ] = %s \n",x,temp,stack[top]);
		top-=2;
	}
	/* ICG Functions*/

#line 229 "y.tab.c" /* yacc.c:339  */

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
#line 165 "basic.y" /* yacc.c:355  */

    struct Attributes attr;

#line 365 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 382 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   558

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  244

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
       2,     2,     2,    66,     2,     2,    19,     2,     8,     2,
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
       0,   192,   192,   193,   194,   198,   208,   218,   222,   226,
     238,   250,   257,   268,   299,   301,   303,   305,   307,   309,
     311,   316,   317,   318,   319,   320,   321,   322,   323,   327,
     340,   358,   372,   388,   396,   408,   412,   423,   423,   435,
     435,   447,   447,   459,   459,   471,   471,   483,   483,   495,
     495,   507,   507,   519,   519,   531,   531,   543,   543,   555,
     555,   567,   578,   585,   595,   597,   604,   621,   634,   675,
     711,   718,   725,   727,   729,   745,   756,   772,   791,   793,
     798,   800,   815,   823,   831,   839,   850,   851,   852,   853,
     857,   879,   894,   901,   914,   919,   924,   930,   935,   940,
     945,   950,   956,   962,   968,   974,   979,   984,  1000,  1006,
    1012,  1019,  1026,  1033,  1039,  1045,  1051,  1067,  1077,  1091,
    1107,  1117,  1135,  1139,  1143,  1143,  1151,  1151,  1151,  1151,
    1161,  1169,  1171
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
  "'{'", "'}'", "'['", "']'", "','", "'!'", "$accept", "S", "func_def",
  "multidec", "datatype", "modifiers", "params_dec", "params_list",
  "brackets", "expression", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6",
  "$@7", "$@8", "$@9", "$@10", "$@11", "@12", "const_list",
  "statement_list", "constant", "un_op", "func_call", "expression_list",
  "statement", "id_chain", "conditional", "ifblock", "$@13", "iterative",
  "$@14", "$@15", "$@16", "assignment", YY_NULLPTR
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
      41,   123,   125,    91,    93,    44,    33
};
# endif

#define YYPACT_NINF -164

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-164)))

#define YYTABLE_NINF -81

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     352,  -164,  -164,  -164,  -164,  -164,  -164,  -164,     9,   352,
     -47,    64,  -164,  -164,   352,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,    -1,  -164,   -21,     2,   -26,    11,   221,   339,
     -13,     3,   221,   456,  -164,  -164,   246,  -164,  -164,  -164,
    -164,  -164,    81,    22,    66,   221,  -164,  -164,   508,  -164,
     389,  -164,    34,    64,   -10,    62,    69,   131,    87,     4,
     508,    85,    91,  -164,  -164,  -164,  -164,   175,   221,  -164,
    -164,    14,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,    76,  -164,  -164,  -164,  -164,   423,
       5,   457,   113,   149,   103,   174,   221,   -11,  -164,   423,
     115,  -164,    32,   120,   114,  -164,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   126,
     127,   129,   221,  -164,     0,   130,   134,  -164,   423,  -164,
     135,   148,   138,   380,  -164,   190,  -164,  -164,   167,   160,
    -164,  -164,   423,   163,   144,   221,   508,   161,   223,   165,
    -164,   423,   221,  -164,    16,   522,   532,   540,   540,   187,
     187,   187,   187,    93,    93,  -164,  -164,   145,   225,   221,
    -164,   295,   180,   221,   182,   184,   221,   191,   192,   171,
    -164,  -164,  -164,  -164,   423,  -164,    12,   189,   144,   200,
     198,   508,   261,   204,  -164,   210,  -164,  -164,  -164,  -164,
     221,   243,  -164,   221,   310,  -164,  -164,   203,  -164,  -164,
    -164,  -164,   202,  -164,  -164,   211,  -164,   144,   213,   144,
    -164,   331,  -164,   279,  -164,   272,  -164,  -164,  -164,   144,
     217,  -164,   423,  -164,   221,   219,  -164,  -164,   423,   346,
    -164,  -164,  -164,  -164
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      28,    21,    22,    23,    24,    25,    26,    27,     0,    28,
       0,     0,     1,     2,    28,    16,    17,    15,    14,    19,
      20,    18,     0,     3,     0,   108,    13,   110,     0,    28,
       0,     0,     0,    28,    89,    87,     0,    88,    83,    82,
      84,    85,    61,     0,     0,     0,    86,    72,   109,    36,
       0,    70,     0,     0,    33,     0,     0,     0,     0,   115,
     112,     0,     0,    63,    65,    68,    69,     0,     0,    66,
      67,     0,    51,    49,    53,    59,    47,    45,    57,    55,
      37,    41,    39,    43,    62,    73,    64,    71,     8,    28,
       0,    28,     0,   116,     0,   111,     0,     0,    12,    28,
       0,    91,    92,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,     0,   106,    28,   100,
       0,     0,     0,    28,    95,   122,    96,    97,     0,    29,
      34,     7,    28,     0,     0,     0,   114,     0,     0,     0,
      11,    28,     0,    90,    74,    52,    50,    54,    60,    48,
      46,    58,    56,    38,    42,    40,    44,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     6,    99,    81,    28,    32,     0,     0,     0,     0,
      78,   113,   119,     0,    10,     0,    93,    76,    77,    75,
       0,     0,    98,     0,     0,   101,   102,     0,   103,   104,
     105,   123,     0,    31,     5,     0,   117,     0,     0,     0,
       9,     0,   124,     0,   130,     0,    30,   118,    79,     0,
       0,   131,    28,   127,     0,     0,   120,   125,    28,     0,
     121,   128,   132,   129
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,    24,    99,   106,   229,   -27,  -164,   -25,   235,   -28,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -117,    37,   -35,  -164,   -37,   146,  -163,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,   129,   130,    22,    11,    54,    55,    47,   102,
     114,   116,   115,   117,   111,   110,   107,   106,   108,   113,
     112,   109,   189,   131,    49,    50,    51,   103,   133,    26,
     134,   135,   232,   136,   172,   238,   243,   137
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    64,    53,   173,    60,    28,    53,    96,    62,    12,
      56,    14,   147,    87,    32,    86,    24,    71,    72,    73,
      58,   211,   138,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    13,    27,   212,    72,    73,    23,    31,
     104,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    57,   132,   148,    25,    91,   174,   175,    59,    67,
     139,    29,   132,   176,    53,    30,   140,    97,   146,   237,
      33,   215,   197,   198,   105,   241,   213,    69,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   132,    88,    15,   171,    89,   132,   152,    16,     9,
     228,    17,   230,    18,    19,   132,    10,    20,     9,   190,
      82,    83,   235,     9,   132,    10,    21,   191,    72,    73,
      10,    70,    92,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    93,    94,    67,   149,    65,    66,   118,
      67,   201,    95,    98,    68,   204,    99,   132,   207,    72,
      73,   100,   143,   190,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   144,   179,    38,    39,    40,    41,
     183,   141,   221,   150,   142,   223,   151,   145,   154,   187,
     153,   168,   190,    34,   190,   177,   169,   170,   195,   178,
      35,    36,    37,   180,   190,   132,   182,    38,    39,    40,
      41,   132,    80,    81,    82,    83,   239,    72,    73,   199,
     181,   184,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,   185,   186,   188,   192,   193,   194,   200,    34,
      42,    43,    44,   210,    45,   101,    35,    36,    37,   203,
     205,    46,   206,    38,    39,    40,    41,    72,    73,   208,
     209,   214,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,   216,   217,   218,   219,   226,   225,    38,    39,
      40,    41,   220,   227,   229,   234,    42,    43,    44,   236,
      45,   240,    90,    72,    73,    85,     0,    46,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   196,    72,
      73,    63,     0,   222,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    72,    73,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,    72,    73,     0,     0,   233,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      72,    73,    -4,   202,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     1,     0,     0,   224,     2,
       0,     0,     0,     0,     0,     3,     0,     0,     1,     0,
       4,     0,     2,     5,     0,     0,     0,     0,     3,   231,
       6,     0,     7,     4,     0,     0,     5,   119,     0,    52,
     120,     0,     0,     6,   242,     7,     1,   121,     0,     0,
       2,    38,    39,    40,    41,     0,     3,     0,     0,     0,
       0,     4,   122,     0,     5,     0,     0,     0,     0,     0,
       0,     6,     0,     7,   123,   124,   125,   126,   127,     0,
     119,   128,   -80,   120,    84,     0,     0,     0,    45,     1,
     121,     0,     0,     2,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     0,     4,   122,     0,     5,     0,     0,
       0,     0,     0,     0,     6,     0,     7,   123,   124,   125,
     126,   127,     1,     1,   128,     0,     2,     2,     0,     0,
       0,     0,     3,     3,     0,     0,     0,     4,     4,     0,
       5,     5,     0,     0,     0,     0,     0,     6,     6,     7,
       7,     0,    72,    73,     0,     0,    61,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    73,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    76,    77,    78,    79,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
      28,    36,    29,     3,    32,     3,    33,     3,    33,     0,
      23,    58,    23,    50,     3,    50,    17,    45,     4,     5,
      17,   184,    17,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     9,    55,    23,     4,     5,    14,    65,
      68,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    64,    89,    64,    55,    65,    56,    57,    55,    59,
      55,    59,    99,    63,    91,    63,    91,    63,    96,   232,
      59,   188,    56,    57,    60,   238,    64,    55,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   128,    58,    29,   122,    61,   133,    65,    34,     0,
     217,    37,   219,    39,    40,   142,     0,    43,     9,   144,
      17,    18,   229,    14,   151,     9,    52,   145,     4,     5,
      14,    55,    60,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    64,     3,    59,    99,    56,    57,    63,
      59,   169,    55,    58,    63,   173,    61,   184,   176,     4,
       5,    60,     3,   188,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    61,   128,    22,    23,    24,    25,
     133,    58,   200,    58,    61,   203,    61,     3,    64,   142,
      60,    55,   217,     8,   219,    55,    59,    58,   151,    55,
      15,    16,    17,    58,   229,   232,    58,    22,    23,    24,
      25,   238,    15,    16,    17,    18,   234,     4,     5,    64,
      62,    21,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    55,    63,    61,    64,     3,    62,     3,     8,
      55,    56,    57,    62,    59,    60,    15,    16,    17,    59,
      58,    66,    58,    22,    23,    24,    25,     4,     5,    58,
      58,    62,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    62,    65,     3,    61,    64,    64,    22,    23,
      24,    25,    62,    62,    61,     3,    55,    56,    57,    62,
      59,    62,    53,     4,     5,    50,    -1,    66,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   152,     4,
       5,    55,    -1,    60,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    60,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       4,     5,     0,    58,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    26,    -1,    -1,    58,    30,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    26,    -1,
      41,    -1,    30,    44,    -1,    -1,    -1,    -1,    36,    58,
      51,    -1,    53,    41,    -1,    -1,    44,    17,    -1,    60,
      20,    -1,    -1,    51,    58,    53,    26,    27,    -1,    -1,
      30,    22,    23,    24,    25,    -1,    36,    -1,    -1,    -1,
      -1,    41,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    53,    54,    55,    56,    57,    58,    -1,
      17,    61,    62,    20,    55,    -1,    -1,    -1,    59,    26,
      27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    54,    55,    56,
      57,    58,    26,    26,    61,    -1,    30,    30,    -1,    -1,
      -1,    -1,    36,    36,    -1,    -1,    -1,    41,    41,    -1,
      44,    44,    -1,    -1,    -1,    -1,    -1,    51,    51,    53,
      53,    -1,     4,     5,    -1,    -1,    60,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     5,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    11,    12,    13,    14,    15,    16,    17,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    30,    36,    41,    44,    51,    53,    68,    69,
      70,    72,     0,    68,    58,    29,    34,    37,    39,    40,
      43,    52,    71,    68,    17,    55,    96,    55,     3,    59,
      63,    65,     3,    59,     8,    15,    16,    17,    22,    23,
      24,    25,    55,    56,    57,    59,    66,    75,    76,    91,
      92,    93,    60,    72,    73,    74,    23,    64,    17,    55,
      76,    60,    74,    55,    91,    56,    57,    59,    63,    55,
      55,    76,     4,     5,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    55,    75,    91,    93,    58,    61,
      71,    65,    60,    64,     3,    55,     3,    63,    58,    61,
      60,    60,    76,    94,    76,    60,    84,    83,    85,    88,
      82,    81,    87,    86,    77,    79,    78,    80,    63,    17,
      20,    27,    42,    54,    55,    56,    57,    58,    61,    69,
      70,    90,    93,    95,    97,    98,   100,   104,    17,    55,
      74,    58,    61,     3,    61,     3,    76,    23,    64,    90,
      58,    61,    65,    60,    64,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    55,    59,
      58,    76,   101,     3,    56,    57,    63,    55,    55,    90,
      58,    62,    58,    90,    21,    55,    63,    90,    61,    89,
      91,    76,    64,     3,    62,    90,    94,    56,    57,    64,
       3,    76,    58,    59,    76,    58,    58,    76,    58,    58,
      62,    95,    23,    64,    62,    89,    62,    65,     3,    61,
      62,    76,    60,    76,    58,    64,    64,    62,    89,    61,
      89,    58,    99,    60,     3,    89,    62,    95,   102,    76,
      62,    95,    58,   103
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    74,    74,    75,    76,    77,    76,    78,
      76,    79,    76,    80,    76,    81,    76,    82,    76,    83,
      76,    84,    76,    85,    76,    86,    76,    87,    76,    88,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    89,    89,
      90,    90,    91,    91,    91,    91,    92,    92,    92,    92,
      93,    93,    94,    94,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    97,    99,    98,   101,   102,   103,   100,
     104,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     0,     9,     8,     7,     6,    10,
       9,     8,     7,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       6,     5,     4,     1,     3,     3,     1,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     1,     2,     4,     5,     5,     5,     1,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     1,     3,     2,     1,     1,     1,     3,     2,
       1,     3,     3,     3,     3,     3,     1,     2,     1,     3,
       2,     4,     4,     6,     5,     3,     4,     7,     8,     6,
       9,    10,     1,     3,     0,     6,     0,     0,     0,     8,
       4,     5,     7
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
#line 199 "basic.y" /* yacc.c:1646  */
    { 
		insert_fun ((yyvsp[-6].attr.name), (yyvsp[-7].attr.name), scope, depth, (yyvsp[-4].attr.params)); 
		//printf("dw%s",$<attr.type>8);
		if((!strcmp((yyvsp[-7].attr.type), "void") && strlen((yyvsp[-1].attr.type))!=0) && (strcmp((yyvsp[-7].attr.type), (yyvsp[-1].attr.type))) )
			yyerror("Return type not matching");

		node* t = lookup((yyvsp[-6].attr.name), FUN_TBL); 
		t->func_def = 1;
	}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 209 "basic.y" /* yacc.c:1646  */
    { 
		insert_fun ((yyvsp[-5].attr.name), (yyvsp[-6].attr.name), scope, depth, NULL); 
		//printf("dw%s",$<attr.type>7);
		if((!strcmp((yyvsp[-6].attr.type), "void") && strlen((yyvsp[-1].attr.type))!=0) && (strcmp((yyvsp[-6].attr.type), (yyvsp[-1].attr.type))) )
			yyerror("Return type not matching");

		node* t = lookup((yyvsp[-5].attr.name), FUN_TBL); 
		t->func_def = 1;
	}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 219 "basic.y" /* yacc.c:1646  */
    { 
		insert_fun ((yyvsp[-4].attr.name), (yyvsp[-5].attr.name), scope, depth, (yyvsp[-2].attr.params));
	}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 223 "basic.y" /* yacc.c:1646  */
    {
		insert_fun ((yyvsp[-3].attr.name), (yyvsp[-4].attr.name), scope, depth, NULL);
	}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 227 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-8].attr.name));
		strcat(temp,"*"); 
		insert_fun ((yyvsp[-7].attr.name), (yyvsp[-8].attr.name), scope, depth, (yyvsp[-4].attr.params)); 
		if(strcmp(temp, "void") && strcmp(temp, (yyvsp[-1].attr.type))) 
			yyerror("Return type not matching");

		node* t = lookup((yyvsp[-7].attr.name), FUN_TBL); 
		t->func_def = 1;
	}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 239 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-7].attr.name));
		strcat(temp,"*"); 
		insert_fun ((yyvsp[-6].attr.name), (yyvsp[-7].attr.name), scope, depth, NULL); 
		if(strcmp(temp, "void") && strcmp(temp, (yyvsp[-1].attr.type))) 
			yyerror("Return type not matching");

		node* t = lookup((yyvsp[-6].attr.name), FUN_TBL); 
		t->func_def = 1;
	}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 251 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-6].attr.name));
		strcat(temp,"*"); 
		insert_fun ((yyvsp[-5].attr.name), (yyvsp[-6].attr.name), scope, depth, (yyvsp[-2].attr.params));
	}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 258 "basic.y" /* yacc.c:1646  */
    {
		char temp[1000];
		strcpy(temp,(yyvsp[-5].attr.name));
		strcat(temp,"*"); 
		insert_fun ((yyvsp[-4].attr.name), (yyvsp[-5].attr.name), scope, depth, NULL);
	}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 269 "basic.y" /* yacc.c:1646  */
    {
		if(!strcmp((yyvsp[-1].attr.type) ,"void"))
			yyerror("Variable of type void");
		//printf("HIHI");
		//varpt--;
		while(varpt>=0)
		{
			//printf("%d - %s\n", varpt, vars[varpt]);
			if(pnt[varpt])
			{
				char temp[1000];
				strcpy(temp,(yyvsp[-1].attr.name));
				strcat(temp,"*"); 
				pnt[varpt] = 0;

				node* t = lookup(vars[varpt--], SYM_TBL); 
				strcpy(t->type, temp);
			}
			else
			{
				node* t = lookup(vars[varpt--], SYM_TBL); 
				strcpy(t->type, (yyvsp[-1].attr.name));
			}

		}		
	}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 300 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.attr.type), "int"); }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 302 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.attr.type), "float"); }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 304 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.attr.type), "char"); }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 306 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.attr.type), "double"); }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 308 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.attr.type), "void"); }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 310 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.attr.type), "long"); }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 312 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.attr.type), "short"); }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 328 "basic.y" /* yacc.c:1646  */
    { 
		if(!strcmp((yyvsp[-1].attr.type) ,"void"))
			yyerror("Parameter of type void");
		//printf("\n SDA %s",$<attr.name>3);
		strcpy((yyval.attr.name),(yyvsp[0].attr.name)); 
		insert ((yyvsp[0].attr.name), (yyvsp[-1].attr.name), scope, depth, 0); 
		strcpy((yyval.attr.type),(yyvsp[-1].attr.type)); 
		strcpy((yyval.attr.name),(yyvsp[0].attr.name)); 

		
		
	}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 341 "basic.y" /* yacc.c:1646  */
    { 
		if(!strcmp((yyvsp[-4].attr.type) ,"void"))
			yyerror("Parameter of type void");
		strcpy((yyval.attr.name),(yyvsp[-3].attr.name)); 
		char temp[1000];
		strcpy(temp,(yyvsp[-4].attr.name));
		strcat(temp,"*"); 
		insert ((yyvsp[-3].attr.name), temp, scope, depth, 0); 
		strcpy((yyval.attr.type),temp);

		int t_array = atoi((yyvsp[-1].attr.name));
		node* t = lookup((yyvsp[-3].attr.name), SYM_TBL);
		t->array_bound = t_array; 
		strcpy((yyval.attr.name),(yyvsp[-3].attr.name)); 

		
	}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 359 "basic.y" /* yacc.c:1646  */
    {
		if(!strcmp((yyvsp[-3].attr.type) ,"void"))
			yyerror("Parameter of type void"); 
		strcpy((yyval.attr.name),(yyvsp[-2].attr.name)); 
		char temp[1000];strcpy(temp,(yyvsp[-3].attr.name));
		strcat(temp,"*"); 
		insert ((yyvsp[-2].attr.name), temp, scope, depth, 0); 
		strcpy((yyval.attr.type),temp);
		strcpy((yyval.attr.name),(yyvsp[-2].attr.name));  

	
		
	}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 373 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.attr.name),(yyvsp[-1].attr.name)); 
		char temp[1000];
		strcpy(temp,multidec_type);
		strcat(temp,"*"); 
		insert ((yyvsp[0].attr.name), temp, scope, depth, 0); 
		strcpy((yyval.attr.type),temp);
		strcpy((yyval.attr.name),(yyvsp[0].attr.name));

		
		
	}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 389 "basic.y" /* yacc.c:1646  */
    {
		//printf("\n Name %s ",$<attr.type>1);
		change_scope((yyvsp[0].attr.name), level); 
		strcpy((yyval.attr.params), (yyvsp[0].attr.type));

		top--;
	}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 397 "basic.y" /* yacc.c:1646  */
    {
		//printf("\n Name %s ",$<attr.name>1);
		change_scope((yyvsp[-2].attr.name), level); 
		char temp[1000]; strcpy(temp, (yyvsp[-2].attr.type)); 
		strcat(temp, (yyvsp[0].attr.params)); strcpy((yyval.attr.params), temp); 

		top--;
	}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 408 "basic.y" /* yacc.c:1646  */
    {strcpy((yyval.attr.type), (yyvsp[-1].attr.type));}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 413 "basic.y" /* yacc.c:1646  */
    {
		node* t = lookup((yyvsp[0].attr.name), CONST_TBL);

		if(t!=NULL)
			strcpy((yyval.attr.type), t->type);	

		strcpy(stack[++top],(yyvsp[0].attr.name));
	
	
	}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 423 "basic.y" /* yacc.c:1646  */
    {strcpy(stack[++top],"+");}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 424 "basic.y" /* yacc.c:1646  */
    {
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp((yyvsp[-3].attr.type), (yyvsp[0].attr.type)))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), (yyvsp[-3].attr.type));

		gencode();
	}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 435 "basic.y" /* yacc.c:1646  */
    {strcpy(stack[++top],"*");}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 436 "basic.y" /* yacc.c:1646  */
    {
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp((yyvsp[-3].attr.type), (yyvsp[0].attr.type)))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), (yyvsp[-3].attr.type));

		gencode();
	}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 447 "basic.y" /* yacc.c:1646  */
    {strcpy(stack[++top],"-");}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 448 "basic.y" /* yacc.c:1646  */
    {
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp((yyvsp[-3].attr.type), (yyvsp[0].attr.type)))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), (yyvsp[-3].attr.type));

		gencode();
	}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 459 "basic.y" /* yacc.c:1646  */
    {strcpy(stack[++top],"/");}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 460 "basic.y" /* yacc.c:1646  */
    {
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp((yyvsp[-3].attr.type), (yyvsp[0].attr.type)))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), (yyvsp[-3].attr.type));

		gencode();
	}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 471 "basic.y" /* yacc.c:1646  */
    {strcpy(stack[++top],">");}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 472 "basic.y" /* yacc.c:1646  */
    {
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp((yyvsp[-3].attr.type), (yyvsp[0].attr.type)))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), (yyvsp[-3].attr.type));

		gencode();
	}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 483 "basic.y" /* yacc.c:1646  */
    {strcpy(stack[++top],"<");}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 484 "basic.y" /* yacc.c:1646  */
    {
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp((yyvsp[-3].attr.type), (yyvsp[0].attr.type)))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), (yyvsp[-3].attr.type));

		gencode();
	}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 495 "basic.y" /* yacc.c:1646  */
    {strcpy(stack[++top],"&&");}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 496 "basic.y" /* yacc.c:1646  */
    {
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp((yyvsp[-3].attr.type), (yyvsp[0].attr.type)))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), (yyvsp[-3].attr.type));

		gencode();
	}
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 507 "basic.y" /* yacc.c:1646  */
    {strcpy(stack[++top],"||");}
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 508 "basic.y" /* yacc.c:1646  */
    {
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp((yyvsp[-3].attr.type), (yyvsp[0].attr.type)))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), (yyvsp[-3].attr.type));

		gencode();
	}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 519 "basic.y" /* yacc.c:1646  */
    {strcpy(stack[++top],"==");}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 520 "basic.y" /* yacc.c:1646  */
    {
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp((yyvsp[-3].attr.type), (yyvsp[0].attr.type)))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), (yyvsp[-3].attr.type));

		gencode();
	}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 531 "basic.y" /* yacc.c:1646  */
    {strcpy(stack[++top],">=");}
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 532 "basic.y" /* yacc.c:1646  */
    {
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp((yyvsp[-3].attr.type), (yyvsp[0].attr.type)))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), (yyvsp[-3].attr.type));

		gencode();
	}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 543 "basic.y" /* yacc.c:1646  */
    {strcpy(stack[++top],"<=");}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 544 "basic.y" /* yacc.c:1646  */
    {
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp((yyvsp[-3].attr.type), (yyvsp[0].attr.type)))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), (yyvsp[-3].attr.type));

		gencode();
	}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 555 "basic.y" /* yacc.c:1646  */
    {strcpy(stack[++top],"!=");}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 556 "basic.y" /* yacc.c:1646  */
    {
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp((yyvsp[-3].attr.type), (yyvsp[-1].attr.type)))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), (yyvsp[-3].attr.type));

		gencode();
	}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 568 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[0].attr.name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[0].attr.name), SYM_TBL); 
		strcpy((yyval.attr.type), t->type);

		strcpy(stack[++top],(yyvsp[0].attr.name));


		strcpy((yyval.attr.name),(yyvsp[0].attr.name));
	}
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 579 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].attr.name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[0].attr.name), SYM_TBL); 
		strcpy((yyval.attr.type), t->type);

	}
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 586 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].attr.name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[0].attr.name), SYM_TBL); 
		strcpy((yyval.attr.type), t->type);

		strcpy(stack[++top], (yyvsp[0].attr.name));
		gencode_umin();
		
	}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 596 "basic.y" /* yacc.c:1646  */
    {strcpy((yyval.attr.type), (yyvsp[0].attr.type));}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 598 "basic.y" /* yacc.c:1646  */
    {
		strcpy((yyval.attr.type), (yyvsp[0].attr.type));

		strcpy(stack[++top], (yyvsp[0].attr.name));
		gencode_umin();
	}
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 605 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[0].attr.name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[-1].attr.name), SYM_TBL); 

		printf("\n");	
		if(strcmp(t->type, "int"))
			yyerror("Increment not possible");

		strcpy((yyval.attr.type), t->type);

		
		printf("%s = %s + 1\n", (yyvsp[0].attr.name), (yyvsp[0].attr.name));
		strcpy(stack[++top], (yyvsp[0].attr.name));


	}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 622 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[0].attr.name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[-1].attr.name), SYM_TBL); 

		if(strcmp(t->type, "int"))
			yyerror("Increment not possible");

		strcpy((yyval.attr.type), t->type);

		printf("%s = %s - 1\n", (yyvsp[0].attr.name), (yyvsp[0].attr.name));
		strcpy(stack[++top], (yyvsp[0].attr.name));
	}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 635 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].attr.name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[-1].attr.name), SYM_TBL); 

		if(strcmp(t->type, "int"))
			yyerror("Increment not possible");

		strcpy((yyval.attr.type), t->type);

		int i = 0;

		char tstack[1000][100];

		int ttop = 0;

		
		for(i=top; i>0; i--)
			strcpy(tstack[++ttop],stack[i]);

		top=0;
			strcpy(temp,(yyvsp[-1].attr.name));
		strcat(temp, " = ");
		strcat(temp, (yyvsp[-1].attr.name));
		strcat(temp, " + 1");
		
		strcpy(stack[++top], temp);


		for(i=ttop; i>0; i--)
			strcpy(stack[++top],tstack[i]);




		strcpy(stack[++top], (yyvsp[-1].attr.name));

	
		
	}
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 676 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].attr.name), scope, depth, SYM_TBL); 
		node* t = lookup((yyvsp[-1].attr.name), SYM_TBL); 

		if(strcmp(t->type, "int"))
			yyerror("Increment not possible");

		strcpy((yyval.attr.type), t->type);

		int i = 0;

		char tstack[1000][100];

		int ttop = 0;

		
		for(i=top; i>0; i--)
			strcpy(tstack[++ttop],stack[i]);

		top=0;
		strcpy(temp,(yyvsp[-1].attr.name));
		strcat(temp, " = ");
		strcat(temp, (yyvsp[-1].attr.name));
		strcat(temp, " - 1");
		
		strcpy(stack[++top], temp);


		for(i=ttop; i>0; i--)
			strcpy(stack[++top],tstack[i]);



		strcpy(stack[++top], (yyvsp[-1].attr.name));	
	}
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 712 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[0].attr.name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[0].attr.name), FUN_TBL); 

		strcpy((yyval.attr.type), t->type);
	}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 719 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-1].attr.name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[0].attr.name), FUN_TBL);

		strcpy((yyval.attr.type), t->type);
	}
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 726 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.attr.type), (yyvsp[0].attr.type)); }
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 728 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.attr.type), (yyvsp[0].attr.type)); }
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 730 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-3].attr.name), scope, depth, SYM_TBL); 	

		node* t = lookup((yyvsp[-3].attr.name), SYM_TBL);


		if(strcmp((yyvsp[-1].attr.type), "int"))
			yyerror("Array index not integer");
		char temp[1000];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		strcpy((yyval.attr.type), temp);

		array((yyvsp[-3].attr.name));
	}
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 746 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-2].attr.name), scope, depth, SYM_TBL);

		if(strcmp((yyvsp[-1].attr.type), "int"))
			yyerror("Array index not integer");	

		node* t = lookup((yyvsp[-4].attr.name), SYM_TBL);

		strcpy((yyval.attr.type), t->type);
	}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 757 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-4].attr.name), scope, depth, SYM_TBL); 

		if(strcmp((yyvsp[-2].attr.type), "int"))
			yyerror("Array index not integer");	

		node* t = lookup((yyvsp[-4].attr.name), SYM_TBL);
		char temp[100];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		if(strcmp((yyvsp[-4].attr.type), "int*"))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), temp);
	}
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 773 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-4].attr.name), scope, depth, SYM_TBL); 	

		if(strcmp((yyvsp[-2].attr.type), "int"))
			yyerror("Array index not integer");		

		node* t = lookup((yyvsp[-4].attr.name), SYM_TBL);
		char temp[100];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		if(strcmp((yyvsp[-4].attr.type), "int*"))
			yyerror("Type mismatch");

		strcpy((yyval.attr.type), temp);
	}
#line 2535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 792 "basic.y" /* yacc.c:1646  */
    { (yyval.attr.size) = 1; }
#line 2541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 794 "basic.y" /* yacc.c:1646  */
    { (yyval.attr.size) = (yyvsp[0].attr.size) + 1; }
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 799 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.attr.type), (yyvsp[0].attr.type)); }
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 801 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.attr.type), (yyvsp[0].attr.type));

		if(strlen((yyvsp[-1].attr.type))>0 && strlen((yyvsp[0].attr.type))>0 && strcmp((yyvsp[-1].attr.type), (yyvsp[0].attr.type)))
			yyerror("Return type not matching");

		if(strlen((yyvsp[-1].attr.type))>0)
			strcpy((yyval.attr.type), (yyvsp[-1].attr.type));


	}
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 816 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyvsp[0].attr.name), "int", scope, depth, 1); 
		
		strcpy((yyval.attr.type), "int");

		strcpy((yyval.attr.name), (yyvsp[0].attr.name));
	}
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 824 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyvsp[0].attr.name), "string", scope, depth, 1); 
		
		strcpy((yyval.attr.type), "char*");

		strcpy((yyval.attr.name), (yyvsp[0].attr.name));
	}
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 832 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyvsp[0].attr.name), "float", scope, depth, 1); 
		
		strcpy((yyval.attr.type), "float");

		strcpy((yyval.attr.name), (yyvsp[0].attr.name));
	}
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 840 "basic.y" /* yacc.c:1646  */
    { 
		insert ((yyvsp[0].attr.name), "char", scope, depth, 1); 
		
		strcpy((yyval.attr.type), "char");

		strcpy((yyval.attr.name), (yyvsp[0].attr.name));
	}
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 858 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-3].attr.name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[-3].attr.name), FUN_TBL); 

		if(t->func_def!=1)
			yyerror("Function not defined"); 

		if(strcmp((yyvsp[-1].attr.params), t->params)) 
			yyerror("Parameters type mismatch"); 
		strcpy((yyval.attr.name), (yyvsp[-3].attr.name));


		int ttop = ptop;
		while(ptop>0)
			printf("param %s\n", pstack[ptop--]);
		printf("call %s %d\n", (yyvsp[-3].attr.name), ttop);




	}
#line 2643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 880 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-2].attr.name), scope, depth, FUN_TBL); 
		node* t = lookup((yyvsp[-2].attr.name), FUN_TBL); 

		if(t->func_def!=1)
			yyerror("Function not defined"); 

		if(t->params!=NULL) 
			yyerror("Parameters type mismatch"); 
		strcpy((yyval.attr.name), (yyvsp[-2].attr.name));
	}
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 895 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.attr.params), (yyvsp[0].attr.type)); 

		strcpy(pstack[++ptop], (yyvsp[0].attr.name));

	}
#line 2670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 902 "basic.y" /* yacc.c:1646  */
    { 
		char temp[1000]; 
		strcpy(temp, (yyvsp[-2].attr.type)); 
		strcat(temp, (yyvsp[0].attr.params)); 
		strcpy((yyval.attr.params), temp); 


		strcpy(pstack[++ptop], (yyvsp[-2].attr.name));
	}
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 915 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.attr.type), ""); 
		post_increment();
	}
#line 2693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 920 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.attr.type), ""); 
		post_increment();
	}
#line 2702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 925 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.attr.type), ""); 
		post_increment();
	}
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 931 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.attr.type), ""); 
		post_increment();
	}
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 936 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.attr.type), (yyvsp[-1].attr.type)); 
		post_increment();
	}
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 941 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.attr.type), ""); 
		post_increment();
	}
#line 2738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 946 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.attr.type), ""); 
		post_increment();
	}
#line 2747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 951 "basic.y" /* yacc.c:1646  */
    {
		strcpy((yyval.attr.type), "");
		check_scope((yyvsp[-2].attr.name), scope, depth, SYM_TBL);
		post_increment();
	}
#line 2757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 957 "basic.y" /* yacc.c:1646  */
    {
		strcpy((yyval.attr.type), "");
		check_scope((yyvsp[-2].attr.name), scope, depth, SYM_TBL);
		post_increment();
	}
#line 2767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 963 "basic.y" /* yacc.c:1646  */
    {
		strcpy((yyval.attr.type), "");
		check_scope((yyvsp[-1].attr.name), scope, depth, SYM_TBL);
		post_increment();
	}
#line 2777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 969 "basic.y" /* yacc.c:1646  */
    {
		strcpy((yyval.attr.type), "");
		check_scope((yyvsp[-1].attr.name), scope, depth, SYM_TBL);
		post_increment();
	}
#line 2787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 975 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.attr.type), (yyvsp[-1].attr.type)); 
		post_increment();
	}
#line 2796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 980 "basic.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.attr.type), ""); 
		post_increment();
	}
#line 2805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 985 "basic.y" /* yacc.c:1646  */
    { 
		//printf("iterative: %d\n", iterative);
		if(iterative<=0)
			yyerror("Invalid use of break statement");
			
		strcpy((yyval.attr.type), "");

		printf("goto L%d\n",label[ltop]);
	}
#line 2819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1001 "basic.y" /* yacc.c:1646  */
    { 
		varpt++;strcpy(vars[varpt],(yyvsp[0].attr.name));

		insert ((yyvsp[0].attr.name), multidec_type, scope, depth, 0); 
	}
#line 2829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1007 "basic.y" /* yacc.c:1646  */
    { 
		varpt++;strcpy(vars[varpt],(yyvsp[-2].attr.name));

		insert ((yyvsp[-2].attr.name), multidec_type, scope, depth, 0); 
	}
#line 2839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1013 "basic.y" /* yacc.c:1646  */
    { 
		varpt++; strcpy(vars[varpt],(yyvsp[0].attr.name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[0].attr.name), multidec_type, scope, depth, 0); 
	}
#line 2850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1020 "basic.y" /* yacc.c:1646  */
    { 
		varpt++; strcpy(vars[varpt],(yyvsp[0].attr.name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[0].attr.name), multidec_type, scope, depth, 0);
	}
#line 2861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1027 "basic.y" /* yacc.c:1646  */
    { 
		varpt++; strcpy(vars[varpt],(yyvsp[-2].attr.name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[-2].attr.name), multidec_type, scope, depth, 0);
	}
#line 2872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1034 "basic.y" /* yacc.c:1646  */
    { 
		varpt++; strcpy(vars[varpt],(yyvsp[-2].attr.name)); 
		pnt[varpt] = 1;
		insert ((yyvsp[-2].attr.name), multidec_type, scope, depth, 0);
	}
#line 2882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1040 "basic.y" /* yacc.c:1646  */
    { 
		varpt++;strcpy(vars[varpt],(yyvsp[-2].attr.name));

		insert ((yyvsp[-2].attr.name), multidec_type, scope, depth, 0); 
	}
#line 2892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1046 "basic.y" /* yacc.c:1646  */
    { 
		varpt++;strcpy(vars[varpt],(yyvsp[0].attr.name));

		insert ((yyvsp[0].attr.name), multidec_type, scope, depth, 0); 
	}
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1052 "basic.y" /* yacc.c:1646  */
    { 
		varpt++; strcpy(vars[varpt],(yyvsp[-3].attr.name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[-3].attr.name), multidec_type, scope, depth, 0); 
		
		int t_array = atoi((yyvsp[-1].attr.name));

		if(t_array<=0)
			yyerror("Invalid array size");

		node* t = lookup((yyvsp[-3].attr.name), SYM_TBL);
		t->array_bound = t_array; 

	}
#line 2922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1068 "basic.y" /* yacc.c:1646  */
    {
		varpt++; strcpy(vars[varpt],(yyvsp[-6].attr.name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[-6].attr.name),multidec_type, scope, depth, 0);

		node* t = lookup((yyvsp[-6].attr.name), SYM_TBL);
		t->array_bound = (yyvsp[-1].attr.size);
	}
#line 2936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1078 "basic.y" /* yacc.c:1646  */
    {
		varpt++; strcpy(vars[varpt],(yyvsp[-7].attr.name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[-7].attr.name),multidec_type, scope, depth, 0);

		int t_array = atoi((yyvsp[-5].attr.name));

		if(t_array < (yyvsp[-1].attr.size))
			yyerror("Array index out of bound");
		node* t = lookup((yyvsp[-7].attr.name), SYM_TBL);
		t->array_bound = t_array;
	}
#line 2954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1092 "basic.y" /* yacc.c:1646  */
    { 
		varpt++; strcpy(vars[varpt],(yyvsp[-3].attr.name)); 
		pnt[varpt] = 1;
		
		insert ((yyvsp[-3].attr.name), multidec_type, scope, depth, 0); 
		
		int t_array = atoi((yyvsp[-1].attr.name));

		if(t_array<=0)
			yyerror("Invalid array size");

		node* t = lookup((yyvsp[-3].attr.name), SYM_TBL);
		t->array_bound = t_array; 

	}
#line 2974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1108 "basic.y" /* yacc.c:1646  */
    {
		varpt++; strcpy(vars[varpt],(yyvsp[-6].attr.name)); 
		pnt[varpt] = 1;

		insert ((yyvsp[-6].attr.name),multidec_type, scope, depth, 0);

		node* t = lookup((yyvsp[-6].attr.name), SYM_TBL);
		t->array_bound = (yyvsp[-1].attr.size);
	}
#line 2988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1118 "basic.y" /* yacc.c:1646  */
    {
		varpt++; strcpy(vars[varpt],(yyvsp[-7].attr.name)); 
		pnt[varpt] = 1; 

		insert ((yyvsp[-7].attr.name),multidec_type, scope, depth, 0);

		int t_array = atoi((yyvsp[-5].attr.name));

		if(t_array < (yyvsp[-1].attr.size))
			yyerror("Array index out of bound");
		node* t = lookup((yyvsp[-7].attr.name), SYM_TBL);
		t->array_bound = t_array;
	}
#line 3006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1136 "basic.y" /* yacc.c:1646  */
    {
		printf("L%d: \n",label[ltop--]);
	}
#line 3014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1139 "basic.y" /* yacc.c:1646  */
    {if3();}
#line 3020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1143 "basic.y" /* yacc.c:1646  */
    {if1();}
#line 3026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1144 "basic.y" /* yacc.c:1646  */
    {

		if(strcmp((yyvsp[-3].attr.type),"int"))
			yyerror("Invalid expression");
		if2();
	}
#line 3037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1151 "basic.y" /* yacc.c:1646  */
    {w1();}
#line 3043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1151 "basic.y" /* yacc.c:1646  */
    {w2();}
#line 3049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1151 "basic.y" /* yacc.c:1646  */
    {w3();}
#line 3055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1152 "basic.y" /* yacc.c:1646  */
    {
		iterative--;
		if(strcmp((yyvsp[-4].attr.type),"int"))
			yyerror("Invalid expression");	
	}
#line 3065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1162 "basic.y" /* yacc.c:1646  */
    {
		check_scope((yyvsp[-3].attr.name), scope, depth, SYM_TBL);


		printf("%s = %s\n",(yyvsp[-3].attr.name),stack[top]);
		top--;
	}
#line 3077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1170 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-4].attr.name), scope, depth, SYM_TBL);}
#line 3083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1172 "basic.y" /* yacc.c:1646  */
    {
		if(strcmp((yyvsp[-4].attr.type),"int"))
			yyerror("Invalid array index");

		array_assign((yyvsp[-6].attr.name));
	}
#line 3094 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3098 "y.tab.c" /* yacc.c:1646  */
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
#line 1181 "basic.y" /* yacc.c:1906  */



void yyerror(char* s)
{
	error = 1;
	//printf("ERROR: %s\n", s);
	fprintf(stderr, "\nLINE %d: %s \nERROR: %s\n", yylineno, s, yytext);
	//exit(0);	
	
}

int main()
{
	//yyin = fopen("test_cases/semantic/return_type.c", "r");
	yyin = fopen("test_cases/program.c", "r");

	yyparse();

	if(error)
		printf("\nUNSUCCESSFUL\n");
	else
		printf("\nSUCCESS!\n");
	
	display();
	
	return 0;
}
