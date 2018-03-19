%{
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
%}

%union{
    char name[1000];

    int size;

    char type[1000];
    char params[1000];
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
	|multidec';' S
	|	
	;

func_def
	:modifiers datatype IDENTIFIER '(' params_list')' '{'statement_list'}' 
	{ 
		insert_fun ($<name>3, $<name>2, scope, depth, $<params>5); 
		if(strcmp($<type>2, "void") && strcmp($<type>2, $<type>8)) 
			yyerror("Return type not matching");
	}
	|modifiers datatype IDENTIFIER '('')' '{'statement_list'}' 
	{ 
		insert_fun ($<name>3, $<name>2, scope, depth, NULL); 
		if(strcmp($<type>2, "void") && strcmp($<type>2, $<type>7)) 
			yyerror("Return type not matching");
	}
	|modifiers datatype IDENTIFIER '(' params_list')' ';' 
	{ 
		insert_fun ($<name>3, $<name>2, scope, depth, $<params>5);
	}
	|modifiers datatype IDENTIFIER '('')' ';' 
	{
		insert_fun ($<name>3, $<name>2, scope, depth, NULL);
	}
	|modifiers datatype'*' IDENTIFIER '(' params_list')' '{'statement_list'}' 
	{
		char temp[1000];
		strcpy(temp,$<name>2);
		strcat(temp,"*"); 
		insert_fun ($<name>3, $<name>2, scope, depth, $<params>6); 
		if(strcmp(temp, "void") && strcmp(temp, $<type>9)) 
			yyerror("Return type not matching");
	}	
	|modifiers datatype'*' IDENTIFIER '('')' '{'statement_list'}' 
	{
		char temp[1000];
		strcpy(temp,$<name>2);
		strcat(temp,"*"); 
		insert_fun ($<name>3, $<name>2, scope, depth, NULL); 
		if(strcmp(temp, "void") && strcmp(temp, $<type>8)) 
			yyerror("Return type not matching");
	}	
	|modifiers datatype'*' IDENTIFIER '(' params_list')' ';' 
	{
		char temp[1000];
		strcpy(temp,$<name>2);
		strcat(temp,"*"); 
		insert_fun ($<name>3, $<name>2, scope, depth, $<params>6);
	}	
	|modifiers datatype'*' IDENTIFIER '('')' ';' 
	{
		char temp[1000];
		strcpy(temp,$<name>2);
		strcat(temp,"*"); 
		insert_fun ($<name>3, $<name>2, scope, depth, NULL);
	}	
	;

id_dec
	:modifiers datatype IDENTIFIER 
	{ 
		strcpy($<name>$,$<name>3); 
		insert ($<name>3, $<name>2, scope, depth, 0); 
		strcpy($<type>$,$<name>2); 
	}
	|modifiers datatype IDENTIFIER '['INTCONST']' 
	{ 
		strcpy($<name>$,$<name>3); 
		char temp[1000];
		strcpy(temp,$<name>2);
		strcat(temp,"*"); 
		insert ($<name>3, temp, scope, depth, 0); 
		strcpy($<type>$,temp);

		int t_array = atoi($<name>5);
		node* t = lookup($<name>3, SYM_TBL);
		t->array_bound = t_array; 


	}
	|modifiers datatype IDENTIFIER '['']' 
	{ 
		strcpy($<name>$,$<name>3); 
		char temp[1000];strcpy(temp,$<name>2);
		strcat(temp,"*"); 
		insert ($<name>3, temp, scope, depth, 0); 
		strcpy($<type>$,temp); 
	}
	|modifiers datatype '*' IDENTIFIER 
	{ 
		strcpy($<name>$,$<name>3); 
		char temp[1000];
		strcpy(temp,$<name>2);
		strcat(temp,"*"); 
		insert ($<name>4,temp, scope, depth, 0); 
		strcpy($<type>$,temp);
	}
	;

id_assign_dec
	:modifiers datatype IDENTIFIER '=' expression 
	{ 
		insert ($<name>3, $<name>2, scope, depth, 0);
	}
	|modifiers datatype IDENTIFIER'['']' '=' '{'const_list'}' 
	{
		char temp[1000];strcpy(temp,$<name>2);
		strcat(temp,"*"); 
		insert ($<name>3,temp, scope, depth, 0);

		node* t = lookup($<name>3, SYM_TBL);
		t->array_bound = $<size>9;
	}	
	|modifiers datatype IDENTIFIER'['INTCONST']' '=' '{'const_list'}' 
	{
		char temp[1000];
		strcpy(temp,$<name>2);
		strcat(temp,"*"); 
		insert ($<name>3,temp, scope, depth, 0);

		int t_array = atoi($<name>5);

		if(t_array != $<size>9)
			yyerror("Array index out of bound");
		node* t = lookup($<name>3, SYM_TBL);
		t->array_bound = t_array;
	}
	|modifiers datatype '*' IDENTIFIER '=' expression 
	{
		char temp[1000]; 
		strcpy(temp,$<name>2); 
		strcat(temp,"*"); 
		insert ($<name>4,temp, scope, depth, 0);
	}
	;

multidec
	:modifiers datatype id_chain 
	{
		varpt--;
		while(varpt>=0)
		{
			if(pnt[varpt])
			{
				char temp[1000];
				strcpy(temp,$<name>2);
				strcat(temp,"*"); 
				pnt[varpt] = 0;
				insert (vars[varpt--], $<name>2, scope, depth, 0);
			}
			else
				insert (vars[varpt--], $<name>2, scope, depth, 0);
		}		
	} 
	;

datatype
	:INT 
	{ strcpy($<type>$, "int"); }
	|FLOAT 
	{ strcpy($<type>$, "float"); }
	|CHAR 
	{ strcpy($<type>$, "char"); }
	|DOUBLE 
	{ strcpy($<type>$, "double"); }
	|VOID 
	{ strcpy($<type>$, "void"); }
	|LONG 
	{ strcpy($<type>$, "long"); }
	|SHORT 
	{ strcpy($<type>$, "short"); }
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
	{
		change_scope($<name>1, level); 
		strcpy($<params>$, $<type>1);
	}
	|id_dec ',' params_list 
	{
		change_scope($<name>1, level); 
		char temp[1000]; strcpy(temp, $<type>1); 
		strcat(temp, $<params>3); strcpy($<params>$, temp); 
	}
	;
	
brackets
	:'('expression')'{strcpy($<type>$, $<type>2);}
	;

expression
	:constant 
	{strcpy($<type>$, $<type>1);}
	|IDENTIFIER bin_op expression 
	{
		check_scope($<name>1, scope, depth, SYM_TBL);
		strcpy($<type>$, "bool");
	}
	|constant bin_op expression 
	{
		strcpy($<type>$, $<type>1);
		strcpy($<type>$, "bool");
	}
	|IDENTIFIER 
	{
		check_scope($<name>1, scope, depth, SYM_TBL); 
		node* t = lookup($<name>1, SYM_TBL); 
		strcpy($<type>$, t->type);
	}
	|un_op IDENTIFIER 
	{
		check_scope($<name>1, scope, depth, SYM_TBL); 
		node* t = lookup($<name>2, SYM_TBL); 
		strcpy($<type>$, t->type);
	}
	|un_op constant 
	{strcpy($<type>$, $<type>2);}
	|IDENTIFIER INCREMENT 
	{
		check_scope($<name>1, scope, depth, SYM_TBL); 
		node* t = lookup($<name>1, SYM_TBL); 
		strcpy($<type>$, t->type);
	}
	|IDENTIFIER DECREMENT 
	{
		check_scope($<name>1, scope, depth, SYM_TBL); 
		node* t = lookup($<name>1, SYM_TBL); 
		strcpy($<type>$, t->type);
	}
	|func_call bin_op expression 
	{strcpy($<type>$, "bool");}
	|func_call 
	{
		check_scope($<name>1, scope, depth, FUN_TBL); 
		node* t = lookup($<name>1, FUN_TBL); 
		strcpy($<type>$, t->type);
	}
	|un_op func_call 
	{
		check_scope($<name>1, scope, depth, FUN_TBL); 
		node* t = lookup($<name>2, FUN_TBL); 
		strcpy($<type>$, t->type);
	}
	|brackets 
	{ strcpy($<type>$, $<type>1); }
	|un_op brackets 
	{ strcpy($<type>$, $<type>2); }
	|brackets bin_op expression 
	{strcpy($<type>$, "bool");}
	;

const_list
	:constant 
	{ $<size>$ = 1; }
	|constant ',' const_list 
	{ $<size>$ = $<size>3 + 1; }
	;

statement_list
	:statement 
	{ strcpy($<type>$, $<type>1); }
	|statement statement_list 
	{ strcpy($<type>$, $<type>2); }
	;

constant
	:INTCONST 
	{ 
		insert ($<name>$, "int", scope, depth, 1); 
		strcpy($<type>$, "int");
	}
	|STRCONST 
	{ 
		insert ($<name>$, "string", scope, depth, 1); 
		strcpy($<type>$, "char*");
	}
	|FLTCONST 
	{ 
		insert ($<name>$, "float", scope, depth, 1); 
		strcpy($<type>$, "float");
	}
	|CHARCONST 
	{ 
		insert ($<name>$, "char", scope, depth, 1); 
		strcpy($<type>$, "char");
	}
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
	{
		check_scope($<name>1, scope, depth, FUN_TBL); 
		node* t = lookup($<name>1, FUN_TBL); 
		if(strcmp($<params>3, t->params)) 
			yyerror("Parameters type mismatch"); 
		strcpy($<name>$, $<name>1);
	}
	|IDENTIFIER '('')' 
	{
		check_scope($<name>1, scope, depth, FUN_TBL); 
		node* t = lookup($<name>1, FUN_TBL); 
		if(t->params!=NULL) yyerror("Parameters type mismatch"); 
		strcpy($<name>$, $<name>1);
	}
	;

expression_list
	:expression 
	{ strcpy($<params>$, $<type>1); }
	|expression ',' expression_list 
	{ 
		char temp[1000]; 
		strcpy(temp, $<type>1); 
		strcat(temp, $<params>3); 
		strcpy($<params>$, temp); 
	}
	;

statement
	:id_dec';'
	|id_assign_dec';'
	|multidec ';'
	|conditional
	|iterative
	|assignment
	|if_block
	|RETURN expression';' 
	{ strcpy($<type>$, $<type>2); }
	|func_call';'
	|func_def
	|IDENTIFIER INCREMENT ';' 
	{check_scope($<name>1, scope, depth, SYM_TBL);}
	|IDENTIFIER DECREMENT ';' 
	{check_scope($<name>1, scope, depth, SYM_TBL);}
	|'{'statement_list'}'
	|';'
	;
id_chain
	:IDENTIFIER 
	{ strcpy(vars[varpt++],$<name>1); }
	|IDENTIFIER '=' expression 
	{ strcpy(vars[varpt++],$<name>1); }
	|'*'IDENTIFIER 
	{ 
		strcpy(vars[varpt],$<name>1); 
		pnt[varpt] = 1; varpt++;
	}
	|'*'IDENTIFIER ',' id_chain 
	{ 
		strcpy(vars[varpt],$<name>1); 
		pnt[varpt] = 1; varpt++;
	}
	|'*'IDENTIFIER '=' expression 
	{ 
		strcpy(vars[varpt],$<name>1); 
		pnt[varpt] = 1; varpt++;
	}
	|'*'IDENTIFIER '=' expression ',' id_chain 
	{ 
		strcpy(vars[varpt],$<name>1); 
		pnt[varpt] = 1; varpt++;
	}
	|IDENTIFIER '=' expression ',' id_chain 
	{ strcpy(vars[varpt++],$<name>1); }
	|IDENTIFIER ',' id_chain 
	{ strcpy(vars[varpt++],$<name>1); }
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
	{check_scope($<name>1, scope, depth, SYM_TBL);}
	|'*'IDENTIFIER '=' expression';' 
	{check_scope($<name>1, scope, depth, SYM_TBL);}
	|IDENTIFIER'['INTCONST']' '=' expression';' 
	{
		check_scope($<name>1, scope, depth, SYM_TBL);

		int t_array = atoi($<name>3);

		node* t = lookup($<name>1, SYM_TBL);
		if(t->array_bound<=t_array)
			yyerror("Array index out of bound");
	}
	;


%%


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
