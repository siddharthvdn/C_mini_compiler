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

	#define SYM_TBL 0
	#define CONST_TBL 1

	typedef struct node
	{
		char* name;		
		char* type;

		int* scope;
		int depth;
			
		struct node* next;
	}node;

	node* sym_tbl[100];
	node* const_tbl[100];

	int hash(char* x, int M) 
	{
	   int i, sum;
	   for (sum=0, i=0; i < strlen(x); i++)
	     sum += x[i];
	   return sum % M;
	}

	int lookup(char* x, int table)
	{
		int idx = hash(x, 100);

		node* t = NULL;

		if(table==0)
		{
	 		if(sym_tbl[idx]==NULL)
	 			return 0;
	 		
	 		t = sym_tbl[idx];
	 	}
	 	else
	 	{
	 		if(const_tbl[idx]==NULL)
		 		return 0;
	 		
	 		t = const_tbl[idx];
	 	}
	
		while(t!=NULL)
		{
			if(strcmp(t->name, x)==0)
				return 1;
			t = t->next;
		}
	
		return 0;
			
	}


	void insert(char* x, char* type, int* scope_in, int depth_in, int table)
	{
		if(lookup(x, table))
			return;

		int idx = hash(x, 100);
	
		node* cell = (node*)malloc(sizeof(node));
		cell->name = (char*)malloc(strlen(x));
		strcpy(cell->name, x);

		cell->type = (char*)malloc(strlen(type));		
		strcpy(cell->type, type);
		
		if(depth_in==0)
		{
			cell->scope = NULL;
			cell->depth = 0;
		}
		else
		{
			cell->scope = (int*)malloc(sizeof(int)*depth_in);
			cell->depth = depth_in;
		}

		for(int i=0; i<depth_in; i++)
		{
			cell->scope[i] = scope_in[i];
		}		

	
		cell->next = NULL;		
	
		node* t = NULL;
	
		if(table==0)
		{
	 		if(sym_tbl[idx]==NULL)
	 		{
	 			sym_tbl[idx] = cell;
	 			return;
	 		}
	 		
	 		t = sym_tbl[idx];
	 	}
	 	else
	 	{
	 		if(const_tbl[idx]==NULL)
	 		{
	 			const_tbl[idx] = cell;
	 			return;
	 		}
	 		
	 		t = const_tbl[idx];
	 	}
	
		while(t->next!=NULL)
		t = t->next;
	
		t->next = cell; 		
	}


	void check_scope(char* x, int* scope_in, int depth_in)
	{
		int idx = hash(x, 100);

		char error_msg[100];
		

		if(sym_tbl[idx]==NULL)
	 	{
	 		strcpy(error_msg,"Variable undeclared: ");
	 		strcat(error_msg, x); 
	 		yyerror(error_msg); 
	 		return;
	 	}
	 		
	 	node* t = NULL;	
	 	t = sym_tbl[idx];
	 	
	 	while(t!=NULL)
		{
			if(strcmp(t->name, x)==0)
				break;
			t = t->next;
		}
		
		int i;
		if(depth_in<t->depth)
		{
	 		strcpy(error_msg,"Variable out of scope: ");
	 		strcat(error_msg, x); 
	 		yyerror(error_msg); 
	 		return;
	 	}
	
		for(i = 0; i<t->depth;i++)
		{
			if(scope_in[i] != t->scope[i])	
			{
		 		strcpy(error_msg,"Variable out of scope: ");
		 		strcat(error_msg, x); 
		 		yyerror(error_msg); 
		 		return;
	 		}
		}
		
	}
	
	void change_scope(char* x, int level_in)
	{
		int idx = hash(x, 100);

		char error_msg[100];
		

		if(sym_tbl[idx]==NULL)
	 	{
	 		strcpy(error_msg,"Variable undeclared: ");
	 		strcat(error_msg, x); 
	 		yyerror(error_msg); 
	 		return;
	 	}
	 		
	 	node* t = NULL;	
	 	t = sym_tbl[idx];
	 	
	 	while(t!=NULL)
		{
			if(strcmp(t->name, x)==0)
				break;
			t = t->next;
		}
		
		t->depth = t->depth + 1;
		
		int *temp = (int*)malloc(sizeof(int)*(t->depth));
		for(int i=0; i<t->depth-1; i++)
		{
			temp[i] = t->scope[i];
		}
		t->scope = temp;
		
		t->scope[t->depth-1] = level_in + 1;	
	}
	
	void display()
	{
		printf("\n----------------------------\n\tSymbol table\n----------------------------\n");
		printf("Value\t\t-\tType\t-\tScope\n----------------------------\n");

		int i,j;	

		for(i=0; i<100; i++)
		{
			if(sym_tbl[i]==NULL)
				continue;
		
			node* t = sym_tbl[i];

			
				
		
			while(t!=NULL)	
			{
				printf("%s\t\t-\t%s\t-\t", t->name, t->type);

				if(t->depth==0)
					printf("Global");
				
				for(j=0; j<t->depth; j++)
					printf("%d ", t->scope[j]);

				printf("\n");
				t = t->next;
			}
			
		}
	
	
		printf("\n\n----------------------------\n\tConstant table\n----------------------------\n");
		printf("Value\t\t-\tType\n----------------------------\n");
	
		for(i=0; i<100; i++)
		{
			if(const_tbl[i]==NULL)
				continue;
		
			node* t = const_tbl[i];
		
			while(t!=NULL)	
			{
				printf("%s\t\t-\t%s\n", t->name, t->type);
				t = t->next;
			}
			
		}
	}

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

#line 350 "y.tab.c" /* yacc.c:339  */

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
    ELSE = 264,
    STRCONST = 265,
    INTCONST = 266,
    FLTCONST = 267,
    CHARCONST = 268,
    AUTO = 269,
    BREAK = 270,
    CASE = 271,
    CHAR = 272,
    CONST = 273,
    CONTINUE = 274,
    DEFAULT = 275,
    DO = 276,
    DOUBLE = 277,
    ENUM = 278,
    EXTERN = 279,
    FLOAT = 280,
    FOR = 281,
    IF = 282,
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
#define ELSE 264
#define STRCONST 265
#define INTCONST 266
#define FLTCONST 267
#define CHARCONST 268
#define AUTO 269
#define BREAK 270
#define CASE 271
#define CHAR 272
#define CONST 273
#define CONTINUE 274
#define DEFAULT 275
#define DO 276
#define DOUBLE 277
#define ENUM 278
#define EXTERN 279
#define FLOAT 280
#define FOR 281
#define IF 282
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
#line 285 "basic.y" /* yacc.c:355  */

    char str[1000];

#line 486 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 503 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   453

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  221

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
       0,   311,   311,   312,   313,   314,   315,   318,   319,   320,
     321,   322,   323,   324,   325,   328,   329,   330,   331,   334,
     335,   336,   337,   340,   359,   360,   361,   362,   363,   364,
     365,   369,   370,   371,   372,   373,   374,   375,   376,   380,
     381,   385,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   404,   405,   408,   409,
     412,   413,   414,   415,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   435,
     436,   437,   438,   439,   440,   441,   444,   445,   448,   449,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   468,   469,   470,   471,   472,   473,
     474,   475,   478,   479,   482,   483,   484,   487,   488,   491,
     492,   493
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "OR", "AND", "'|'", "'^'", "'&'",
  "EQUAL", "NOTEQUAL", "'<'", "'>'", "LESSER", "GREATER", "'+'", "'-'",
  "'*'", "'/'", "'$'", "ELSE", "STRCONST", "INTCONST", "FLTCONST",
  "CHARCONST", "AUTO", "BREAK", "CASE", "CHAR", "CONST", "CONTINUE",
  "DEFAULT", "DO", "DOUBLE", "ENUM", "EXTERN", "FLOAT", "FOR", "IF", "INT",
  "LONG", "REGISTER", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC",
  "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE",
  "WHILE", "IDENTIFIER", "INCREMENT", "DECREMENT", "';'", "'('", "')'",
  "'{'", "'}'", "'['", "']'", "','", "'%'", "'!'", "$accept", "S",
  "func_def", "id_dec", "id_assign_dec", "multidec", "datatype",
  "modifiers", "params_list", "brackets", "expression", "const_list",
  "statement_list", "constant", "bin_op", "un_op", "func_call",
  "expression_list", "statement", "id_chain", "if_block", "conditional",
  "iterative", "assignment", YY_NULLPTR
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

#define YYPACT_NINF -158

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-158)))

#define YYTABLE_NINF -59

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      82,  -158,  -158,  -158,  -158,  -158,  -158,  -158,    28,    82,
     -22,   -21,   -14,   401,  -158,  -158,    82,    82,    82,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,    -3,  -158,  -158,  -158,
      -6,     4,  -158,    19,   204,   223,   -11,    -1,   204,   382,
      -1,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,   152,
    -158,  -158,   204,  -158,   171,    18,   171,    11,   171,   -15,
      24,   401,    15,    29,    89,    43,    21,  -158,    34,   -10,
      40,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,   183,  -158,
     204,    42,   204,    -1,   204,    44,  -158,  -158,  -158,   204,
    -158,   268,   395,     9,     1,   105,    48,    22,   204,    -1,
    -158,   268,    10,  -158,    45,    55,  -158,  -158,  -158,  -158,
    -158,  -158,    61,    59,   204,    68,    38,  -158,   268,  -158,
      62,    78,    79,    81,    88,   237,   131,  -158,  -158,  -158,
    -158,    97,    91,  -158,   268,    99,   150,   204,    18,  -158,
     128,  -158,   268,   204,  -158,   189,   204,   135,   204,   204,
     136,   137,   174,   139,  -158,  -158,  -158,  -158,  -158,  -158,
     299,  -158,    -7,   140,   150,   141,   145,    34,  -158,   153,
    -158,   204,   154,  -158,   156,   159,  -158,  -158,   133,  -158,
     268,  -158,   160,  -158,  -158,   161,  -158,   150,  -158,   175,
     330,   361,  -158,   229,   172,  -158,  -158,  -158,  -158,   268,
    -158,   268,  -158,   204,  -158,   173,   179,   178,  -158,  -158,
    -158
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
      39,     0,     0,     0,    17,     0,   104,   111,    22,     0,
       0,   107,    69,    68,    76,    75,    70,    73,    78,    77,
      72,    71,    64,    65,    66,    67,    48,    49,     0,    74,
       0,     0,     0,     0,     0,    46,    54,    47,    52,     0,
      10,    38,    38,     0,     0,    16,     0,   106,     0,     0,
      14,    38,     0,    87,    88,     0,    43,    41,    55,   110,
      44,    50,     0,     0,     0,     0,     0,   103,    38,    99,
       0,     0,     0,     0,     0,    38,    96,    93,    94,    95,
      40,     0,    15,     9,    38,     0,     0,     0,   105,   109,
       0,    13,    38,     0,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     8,    98,    59,
      38,    18,     0,     0,     0,     0,    56,   108,    12,     0,
      89,     0,     0,    97,     0,     0,   100,   101,     0,   102,
      38,   115,     0,    17,     7,     0,    20,     0,    11,     0,
      38,    38,   119,     0,     0,    16,    21,    57,   120,    38,
     112,    38,   117,     0,   102,     0,     0,     0,   102,   102,
     121
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,   122,   112,     3,   132,   213,   184,   -26,   -29,   187,
     -34,  -157,  -105,   -55,   -27,  -158,   -56,    93,  -120,   -32,
    -158,  -158,  -158,  -158
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,   129,   130,   131,   132,    26,    13,    62,    54,
     114,   175,   133,    56,    90,    57,    58,   115,   135,    32,
     136,   137,   138,   139
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    98,    97,    10,    68,    67,   150,    34,    71,    61,
      70,    63,    10,    61,    30,   192,    65,   195,    91,    10,
      10,    10,    38,   163,   108,   147,   141,    92,    14,    94,
     169,    99,    45,    46,    47,    48,    16,    17,    60,   173,
     207,   159,    60,   100,    18,   134,   101,   179,   110,    33,
     191,   111,    31,    64,    66,   134,   116,   193,   118,   143,
     120,   119,   144,    35,   142,   121,    95,    36,   151,    37,
      52,   152,   134,   140,   148,   104,    61,   149,    39,   134,
     210,   212,    -6,    93,    40,   204,    37,    40,   134,   102,
     157,   176,   106,   105,   160,   161,   134,    88,   107,   109,
     112,   162,   117,    88,   215,    60,   216,     1,   145,   146,
     153,     2,     9,   177,   134,   154,   155,     3,   156,   176,
     164,     9,   182,     4,   184,   185,     5,   158,     9,     9,
       9,    15,    11,     6,   134,     7,   165,   166,    27,    28,
      29,    11,   176,   167,   134,   134,   168,   199,    11,    11,
      11,   170,   171,   134,   172,   134,    72,    73,    74,    75,
     174,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    45,    46,    47,    48,    72,    73,    74,    75,   217,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
     178,    41,   181,   183,   186,   187,   188,   203,    42,    43,
      44,   189,   194,   196,    45,    46,    47,    48,    86,    87,
     197,    88,    41,    12,   200,   198,   201,   202,    89,    42,
      43,    44,    12,   206,   205,    45,    46,    47,    48,    12,
      12,    12,   213,   208,   214,   218,   220,    89,    49,    50,
      51,   219,    52,   113,    96,   103,   180,     0,     1,     0,
      53,     0,     2,     0,   122,     0,     0,     0,     3,    49,
      50,    51,     1,    52,     4,     0,     2,     5,     0,     0,
       0,    53,     3,     0,     6,   123,     7,     0,     4,   124,
       0,     5,     0,    59,     0,   122,     0,     0,     6,     0,
       7,   125,   126,     1,     0,   127,     0,     2,   128,   -58,
       0,     0,     0,     3,     0,     0,   123,     0,     0,     4,
     124,     0,     5,     0,     0,     0,   122,     0,     0,     6,
       0,     7,   125,   126,     1,     0,   127,     0,     2,   128,
       0,     0,     0,     0,     3,     0,     0,   123,     0,     0,
       4,   124,     0,     5,     0,     0,     0,   122,     0,     0,
       6,     0,     7,   125,   126,     1,     0,   127,     0,     2,
     190,     0,     0,     0,     0,     3,     0,     0,   123,     0,
       0,     4,   124,     0,     5,     0,     0,     0,   122,     0,
       0,     6,     0,     7,   125,   126,     1,     0,   127,     0,
       2,   209,     0,     0,     0,     0,     3,     0,     0,   123,
       0,     0,     4,   124,     0,     5,     0,     1,     0,     0,
       0,     2,     6,     0,     7,   125,   126,     3,     0,   127,
       1,     0,   211,     4,     2,     0,     5,     0,     0,    19,
       3,     0,     0,     6,    20,     7,     4,    21,     0,     5,
      22,    23,    69,     0,    24,     0,     6,     0,     7,     0,
       0,     0,     0,    25
};

static const yytype_int16 yycheck[] =
{
      34,    57,    57,     0,    38,    37,   111,     3,    40,    35,
      39,    22,     9,    39,    17,    22,    17,   174,    52,    16,
      17,    18,     3,   128,     3,     3,    17,    54,     0,    56,
     135,    58,    21,    22,    23,    24,    58,    58,    35,   144,
     197,     3,    39,    58,    58,   101,    61,   152,    58,    55,
     170,    61,    55,    64,    55,   111,    90,    64,    92,    58,
      94,    93,    61,    59,    55,    99,    55,    63,    58,    65,
      59,    61,   128,   102,   108,    60,   102,   109,    59,   135,
     200,   201,     0,    65,    65,   190,    65,    65,   144,    65,
     124,   146,     3,    64,    56,    57,   152,    59,    55,    65,
      60,    63,    60,    59,   209,   102,   211,    25,     3,    61,
      65,    29,     0,   147,   170,    60,    55,    35,    59,   174,
      58,     9,   156,    41,   158,   159,    44,    59,    16,    17,
      18,     9,     0,    51,   190,    53,    58,    58,    16,    17,
      18,     9,   197,    62,   200,   201,    58,   181,    16,    17,
      18,    20,    55,   209,    63,   211,     4,     5,     6,     7,
      61,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    21,    22,    23,    24,     4,     5,     6,     7,   213,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      62,     8,     3,    58,    58,    58,    22,    64,    15,    16,
      17,    62,    62,    62,    21,    22,    23,    24,    56,    57,
      65,    59,     8,     0,    60,    62,    60,    58,    66,    15,
      16,    17,     9,    62,    64,    21,    22,    23,    24,    16,
      17,    18,     3,    58,    62,    62,    58,    66,    55,    56,
      57,    62,    59,    60,    57,    61,   153,    -1,    25,    -1,
      67,    -1,    29,    -1,    17,    -1,    -1,    -1,    35,    55,
      56,    57,    25,    59,    41,    -1,    29,    44,    -1,    -1,
      -1,    67,    35,    -1,    51,    38,    53,    -1,    41,    42,
      -1,    44,    -1,    60,    -1,    17,    -1,    -1,    51,    -1,
      53,    54,    55,    25,    -1,    58,    -1,    29,    61,    62,
      -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,    41,
      42,    -1,    44,    -1,    -1,    -1,    17,    -1,    -1,    51,
      -1,    53,    54,    55,    25,    -1,    58,    -1,    29,    61,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,
      41,    42,    -1,    44,    -1,    -1,    -1,    17,    -1,    -1,
      51,    -1,    53,    54,    55,    25,    -1,    58,    -1,    29,
      61,    -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    -1,
      -1,    41,    42,    -1,    44,    -1,    -1,    -1,    17,    -1,
      -1,    51,    -1,    53,    54,    55,    25,    -1,    58,    -1,
      29,    61,    -1,    -1,    -1,    -1,    35,    -1,    -1,    38,
      -1,    -1,    41,    42,    -1,    44,    -1,    25,    -1,    -1,
      -1,    29,    51,    -1,    53,    54,    55,    35,    -1,    58,
      25,    -1,    61,    41,    29,    -1,    44,    -1,    -1,    28,
      35,    -1,    -1,    51,    33,    53,    41,    36,    -1,    44,
      39,    40,    60,    -1,    43,    -1,    51,    -1,    53,    -1,
      -1,    -1,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    29,    35,    41,    44,    51,    53,    69,    70,
      71,    72,    73,    75,     0,    69,    58,    58,    58,    28,
      33,    36,    39,    40,    43,    52,    74,    69,    69,    69,
      17,    55,    87,    55,     3,    59,    63,    65,     3,    59,
      65,     8,    15,    16,    17,    21,    22,    23,    24,    55,
      56,    57,    59,    67,    77,    78,    81,    83,    84,    60,
      71,    75,    76,    22,    64,    17,    55,    87,    78,    60,
      76,    87,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    56,    57,    59,    66,
      82,    78,    82,    65,    82,    55,    77,    81,    84,    82,
      58,    61,    65,    74,    60,    64,     3,    55,     3,    65,
      58,    61,    60,    60,    78,    85,    78,    60,    78,    87,
      78,    78,    17,    38,    42,    54,    55,    58,    61,    70,
      71,    72,    73,    80,    84,    86,    88,    89,    90,    91,
      76,    17,    55,    58,    61,     3,    61,     3,    78,    87,
      80,    58,    61,    65,    60,    55,    59,    78,    59,     3,
      56,    57,    63,    80,    58,    58,    58,    62,    58,    80,
      20,    55,    63,    80,    61,    79,    81,    78,    62,    80,
      85,     3,    78,    58,    78,    78,    58,    58,    22,    62,
      61,    86,    22,    64,    62,    79,    62,    65,    62,    78,
      60,    60,    58,    64,    80,    64,    62,    79,    58,    61,
      86,    61,    86,     3,    62,    80,    80,    78,    62,    62,
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
      86,    86,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    88,    88,    89,    89,    89,    90,    90,    91,
      91,    91
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
       2,     2,     2,     1,     1,     1,     1,     3,     2,     1,
       3,     3,     3,     1,     1,     3,     2,     4,     4,     6,
       5,     3,     5,     7,     1,     3,     5,     5,     7,     4,
       5,     7
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
#line 318 "basic.y" /* yacc.c:1646  */
    { insert ((yyvsp[-6].str), (yyvsp[-7].str), scope, depth, 0);}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 319 "basic.y" /* yacc.c:1646  */
    { insert ((yyvsp[-5].str), (yyvsp[-6].str), scope, depth, 0);}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 320 "basic.y" /* yacc.c:1646  */
    { insert ((yyvsp[-4].str), (yyvsp[-5].str), scope, depth, 0);}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 321 "basic.y" /* yacc.c:1646  */
    { insert ((yyvsp[-3].str), (yyvsp[-4].str), scope, depth, 0);}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 322 "basic.y" /* yacc.c:1646  */
    {char temp[1000];strcpy(temp,(yyvsp[-8].str));strcat(temp,"*"); insert ((yyvsp[-6].str),temp, scope, depth, 0);}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 323 "basic.y" /* yacc.c:1646  */
    {char temp[1000];strcpy(temp,(yyvsp[-7].str));strcat(temp,"*"); insert ((yyvsp[-5].str),temp, scope, depth, 0);}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 324 "basic.y" /* yacc.c:1646  */
    {char temp[1000];strcpy(temp,(yyvsp[-6].str));strcat(temp,"*"); insert ((yyvsp[-4].str),temp, scope, depth, 0);}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 325 "basic.y" /* yacc.c:1646  */
    {char temp[1000];strcpy(temp,(yyvsp[-5].str));strcat(temp,"*"); insert ((yyvsp[-3].str),temp, scope, depth, 0);}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 328 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.str),(yyvsp[0].str)); insert ((yyvsp[0].str), (yyvsp[-1].str), scope, depth, 0);}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 329 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.str),(yyvsp[-3].str)); insert ((yyvsp[-3].str), (yyvsp[-4].str), scope, depth, 0);}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 330 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.str),(yyvsp[-2].str)); insert ((yyvsp[-2].str), (yyvsp[-3].str), scope, depth, 0);}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 331 "basic.y" /* yacc.c:1646  */
    { strcpy((yyval.str),(yyvsp[-1].str)); char temp[1000];strcpy(temp,(yyvsp[-2].str));strcat(temp,"*"); insert ((yyvsp[0].str),temp, scope, depth, 0);}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 334 "basic.y" /* yacc.c:1646  */
    { insert ((yyvsp[-2].str), (yyvsp[-3].str), scope, depth, 0);}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 335 "basic.y" /* yacc.c:1646  */
    {char temp[1000];strcpy(temp,(yyvsp[-7].str));strcat(temp,"*"); insert ((yyvsp[-6].str),temp, scope, depth, 0);}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 336 "basic.y" /* yacc.c:1646  */
    {char temp[1000];strcpy(temp,(yyvsp[-8].str));strcat(temp,"*"); insert ((yyvsp[-7].str),temp, scope, depth, 0);}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 337 "basic.y" /* yacc.c:1646  */
    {char temp[1000]; strcpy(temp,(yyvsp[-4].str)); strcat(temp,"*"); insert ((yyvsp[-2].str),temp, scope, depth, 0);}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 341 "basic.y" /* yacc.c:1646  */
    {
		varpt--;
		while(varpt>=0)
		{
			if(pnt[varpt])
			{
				char temp[1000];
				strcpy(temp,(yyvsp[-1].str));
				strcat(temp,"*"); 
				pnt[varpt] = 0;
				insert (vars[varpt--], (yyvsp[-1].str), scope, depth, 0);
			}
			else
				insert (vars[varpt--], (yyvsp[-1].str), scope, depth, 0);
		}		
	}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 380 "basic.y" /* yacc.c:1646  */
    {change_scope((yyvsp[0].str), level);}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 389 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-2].str), scope, depth);}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 391 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[0].str), scope, depth);}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 392 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-1].str), scope, depth);}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 394 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-1].str), scope, depth);}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 395 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-1].str), scope, depth);}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 412 "basic.y" /* yacc.c:1646  */
    { insert ((yyval.str), "int", scope, depth, 1);}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 413 "basic.y" /* yacc.c:1646  */
    { insert ((yyval.str), "string", scope, depth, 1);}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 414 "basic.y" /* yacc.c:1646  */
    { insert ((yyval.str), "float", scope, depth, 1);}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 415 "basic.y" /* yacc.c:1646  */
    { insert ((yyval.str), "char", scope, depth, 1);}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 444 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-3].str), scope, depth);}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 445 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-2].str), scope, depth);}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 462 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-2].str), scope, depth);}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 463 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-2].str), scope, depth);}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 468 "basic.y" /* yacc.c:1646  */
    { strcpy(vars[varpt++],(yyvsp[0].str)); }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 469 "basic.y" /* yacc.c:1646  */
    { strcpy(vars[varpt++],(yyvsp[-2].str)); }
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 470 "basic.y" /* yacc.c:1646  */
    { strcpy(vars[varpt],(yyvsp[-1].str)); pnt[varpt] = 1; varpt++;}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 471 "basic.y" /* yacc.c:1646  */
    { strcpy(vars[varpt],(yyvsp[-3].str)); pnt[varpt] = 1; varpt++;}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 472 "basic.y" /* yacc.c:1646  */
    { strcpy(vars[varpt],(yyvsp[-3].str)); pnt[varpt] = 1; varpt++;}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 473 "basic.y" /* yacc.c:1646  */
    { strcpy(vars[varpt],(yyvsp[-5].str)); pnt[varpt] = 1; varpt++;}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 474 "basic.y" /* yacc.c:1646  */
    { strcpy(vars[varpt++],(yyvsp[-4].str)); }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 475 "basic.y" /* yacc.c:1646  */
    { strcpy(vars[varpt++],(yyvsp[-2].str)); }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 491 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-3].str), scope, depth);}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 492 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-4].str), scope, depth);}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 493 "basic.y" /* yacc.c:1646  */
    {check_scope((yyvsp[-6].str), scope, depth);}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2052 "y.tab.c" /* yacc.c:1646  */
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
