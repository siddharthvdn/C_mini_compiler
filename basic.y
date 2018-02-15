%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define SYM_TBL 0
	#define CONST_TBL 1

	typedef struct node
	{
		char* name;		
		char* type;
			
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


	void insert(char* x, char* type, int table)
	{
		if(lookup(x, table))
			return;

		int idx = hash(x, 100);
	
		node* cell = (node*)malloc(sizeof(node));
		cell->name = (char*)malloc(strlen(x));
		cell->type = (char*)malloc(strlen(type));
		strcpy(cell->name, x);
		strcpy(cell->type, type);
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

	void display()
	{
		printf("\n----------------------------\n\tSymbol table\n----------------------------\n");
		printf("Value\t\t-\tType\n----------------------------\n");

		int i;	

		for(i=0; i<100; i++)
		{
			if(sym_tbl[i]==NULL)
				continue;
		
			node* t = sym_tbl[i];
		
			while(t!=NULL)	
			{
				printf("%s\t\t-\t%s\n", t->name, t->type);
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
		
	char* yytext;
	
	void yyerror(char*);
	
	
	char datatype_str[100];
	char vars[100][1000];
	int varpt = 1; 
%}

%union{
    char str[1000];
}

%right '='
%left OR
%left AND
%left '|'
%left '^'
%left '&'
%left EQUAL NOTEQUAL
%left '<' '>' LESSER GREATER
%left '+' '-'
%left '*' '/'
%left '$'
%right ELSE


%token STRCONST INTCONST FLTCONST CHARCONST
%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR IF INT LONG REGISTER RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE
%token IDENTIFIER
%token INCREMENT DECREMENT AND OR EQUAL GREATER LESSER NOTEQUAL


%%
S
	:func_def S
	|id_dec ';' S
	|id_assign_dec';' S
	|multidec S
	|	
	;
func_def
	:modifiers datatype IDENTIFIER '(' params_list')' '{'statement_list'}'
	|modifiers datatype IDENTIFIER '('')' '{'statement_list'}'
	|modifiers datatype IDENTIFIER '(' params_list')' ';'
	|modifiers datatype IDENTIFIER '('')' ';'
	;
id_dec
	:modifiers datatype IDENTIFIER { insert ($<str>3, $<str>2, 0);}
	|modifiers datatype IDENTIFIER '['INTCONST']' { insert ($<str>3, $<str>2, 0);}
	|modifiers datatype IDENTIFIER '['']' { insert ($<str>3, $<str>2, 0);}
	|modifiers datatype '*' IDENTIFIER {char temp[1000];strcpy(temp,$<str>2);strcat(temp,"*"); insert ($<str>4,temp, 0);}
	;
id_assign_dec
	:modifiers datatype IDENTIFIER '=' expression { insert ($<str>3, $<str>2, 0);}
	|modifiers datatype IDENTIFIER'['']' '=' '{'const_list'}' {char temp[1000];strcpy(temp,$<str>2);strcat(temp,"*"); insert ($<str>3,temp, 0);}	
	|modifiers datatype IDENTIFIER'['INTCONST']' '=' '{'const_list'}' {char temp[1000];strcpy(temp,$<str>2);strcat(temp,"*"); insert ($<str>3,temp, 0);}	
	;
multidec
	:modifiers datatype id_chain 
	{
		while(varpt)
		{
			insert (vars[varpt--], $<str>2, 0);
			printf("pop\n");
		}
		varpt++;
	} ';'
	;
datatype
	:INT
	|FLOAT
	|CHAR
	|DOUBLE
	|VOID
	|LONG
	|SHORT
	;

modifiers
	:AUTO
	|CONST
	|EXTERN
	|REGISTER
	|SIGNED
	|UNSIGNED
	|VOLATILE
	|
	;
params_list
	:id_dec
	|id_dec ',' params_list
	;
brackets
	:'('expression')'
	;
expression
	:constant
	|IDENTIFIER bin_op expression
	|constant bin_op expression
	|IDENTIFIER
	|un_op IDENTIFIER
	|un_op constant
	|IDENTIFIER INCREMENT
	|IDENTIFIER DECREMENT
	|func_call bin_op expression
	|func_call
	|un_op func_call
	|brackets 
	|un_op brackets
	|brackets bin_op expression
	;
const_list
	:constant
	|constant ',' const_list
	;
statement_list
	:statement 
	|statement statement_list
	;
constant
	:INTCONST { insert ($<str>$, "int", 1);}
	|STRCONST { insert ($<str>$, "string", 1);}
	|FLTCONST { insert ($<str>$, "float", 1);}
	|CHARCONST { insert ($<str>$, "char", 1);}
	;
bin_op
	:'+'
	|'-'
	|'*'
	|'/'
	|AND
	|OR
	|EQUAL
	|GREATER
	|LESSER
	|NOTEQUAL
	|'%'
	|'^'
	|'|'
	|'>'
	|'<'
	;
un_op
	:'!' %prec '$'
	|'+' %prec '$'
	|'-' %prec '$'
	|'*' %prec '$'
	|'&' %prec '$'
	|INCREMENT %prec '$'
	|DECREMENT %prec '$'
	;
func_call
	:IDENTIFIER '('expression_list')'
	|IDENTIFIER '('')'
	;
expression_list
	:expression
	|expression ',' expression_list
	;
statement
	:id_dec';'
	|id_assign_dec';'
	|multidec ';'
	|conditional
	|iterative
	|assignment
	|if_block
	|RETURN expression ';'
	|func_call';'
	|IDENTIFIER INCREMENT ';'
	|IDENTIFIER DECREMENT ';'
	;
id_chain
	:IDENTIFIER { strcpy(vars[varpt++],$<str>1); printf("push\n");}
	|IDENTIFIER '=' constant { strcpy(vars[varpt++],$<str>1); }
	|IDENTIFIER '=' constant ',' id_chain { strcpy(vars[varpt++],$<str>1); }
	|IDENTIFIER ',' id_chain { strcpy(vars[varpt++],$<str>1); printf("push\n");}
	;
if_block
	:IF '('expression')' statement 
	|IF '('expression')' '{'statement_list'}'
	;
conditional
	:if_block
	|if_block ELSE statement
	|if_block ELSE '{'statement_list'}'
	;
iterative
	:WHILE'('expression')' statement
	|WHILE '('expression')''{'statement_list'}'
	;
assignment
	:IDENTIFIER '=' expression ';'
	|'*'IDENTIFIER '=' expression';'
	|IDENTIFIER'['INTCONST']' '=' expression';'
	;


%%


void yyerror(char* s)
{
	//printf("ERROR: %s\n", s);
	fprintf(stderr, "LINE %d: %s \nERRROR: %s\n", yylineno, s, yytext);
	//exit(0);	
	
}

int main()
{
	//yyin = fopen("test_cases/program.c", "r");
	yyin = fopen("test_cases/program.c", "r");

	yyparse();
	
	printf("SUCCESS!\n");
	
	display();
	
	return 0;
}
