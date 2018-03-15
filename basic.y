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
	|multidec';' S
	|	
	;
func_def
	:modifiers datatype IDENTIFIER '(' params_list')' '{'statement_list'}' { insert ($<str>3, $<str>2, scope, depth, 0);}
	|modifiers datatype IDENTIFIER '('')' '{'statement_list'}' { insert ($<str>3, $<str>2, scope, depth, 0);}
	|modifiers datatype IDENTIFIER '(' params_list')' ';' { insert ($<str>3, $<str>2, scope, depth, 0);}
	|modifiers datatype IDENTIFIER '('')' ';' { insert ($<str>3, $<str>2, scope, depth, 0);}
	|modifiers datatype'*' IDENTIFIER '(' params_list')' '{'statement_list'}' {char temp[1000];strcpy(temp,$<str>2);strcat(temp,"*"); insert ($<str>4,temp, scope, depth, 0);}	
	|modifiers datatype'*' IDENTIFIER '('')' '{'statement_list'}' {char temp[1000];strcpy(temp,$<str>2);strcat(temp,"*"); insert ($<str>4,temp, scope, depth, 0);}	
	|modifiers datatype'*' IDENTIFIER '(' params_list')' ';' {char temp[1000];strcpy(temp,$<str>2);strcat(temp,"*"); insert ($<str>4,temp, scope, depth, 0);}	
	|modifiers datatype'*' IDENTIFIER '('')' ';' {char temp[1000];strcpy(temp,$<str>2);strcat(temp,"*"); insert ($<str>4,temp, scope, depth, 0);}	
	;
id_dec
	:modifiers datatype IDENTIFIER { strcpy($<str>$,$<str>3); insert ($<str>3, $<str>2, scope, depth, 0);}
	|modifiers datatype IDENTIFIER '['INTCONST']' { strcpy($<str>$,$<str>3); insert ($<str>3, $<str>2, scope, depth, 0);}
	|modifiers datatype IDENTIFIER '['']' { strcpy($<str>$,$<str>3); insert ($<str>3, $<str>2, scope, depth, 0);}
	|modifiers datatype '*' IDENTIFIER { strcpy($<str>$,$<str>3); char temp[1000];strcpy(temp,$<str>2);strcat(temp,"*"); insert ($<str>4,temp, scope, depth, 0);}
	;
id_assign_dec
	:modifiers datatype IDENTIFIER '=' expression { insert ($<str>3, $<str>2, scope, depth, 0);}
	|modifiers datatype IDENTIFIER'['']' '=' '{'const_list'}' {char temp[1000];strcpy(temp,$<str>2);strcat(temp,"*"); insert ($<str>3,temp, scope, depth, 0);}	
	|modifiers datatype IDENTIFIER'['INTCONST']' '=' '{'const_list'}' {char temp[1000];strcpy(temp,$<str>2);strcat(temp,"*"); insert ($<str>3,temp, scope, depth, 0);}
	|modifiers datatype '*' IDENTIFIER '=' expression {char temp[1000]; strcpy(temp,$<str>2); strcat(temp,"*"); insert ($<str>4,temp, scope, depth, 0);}
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
				strcpy(temp,$<str>2);
				strcat(temp,"*"); 
				pnt[varpt] = 0;
				insert (vars[varpt--], $<str>2, scope, depth, 0);
			}
			else
				insert (vars[varpt--], $<str>2, scope, depth, 0);
		}		
	} 
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
	:id_dec {change_scope($<str>1, level);}
	|id_dec ',' params_list
	;
	
brackets
	:'('expression')'
	;
expression
	:constant
	|IDENTIFIER bin_op expression {check_scope($<str>1, scope, depth);}
	|constant bin_op expression
	|IDENTIFIER {check_scope($<str>1, scope, depth);}
	|un_op IDENTIFIER {check_scope($<str>1, scope, depth);}
	|un_op constant
	|IDENTIFIER INCREMENT {check_scope($<str>1, scope, depth);}
	|IDENTIFIER DECREMENT {check_scope($<str>1, scope, depth);}
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
	:INTCONST { insert ($<str>$, "int", scope, depth, 1);}
	|STRCONST { insert ($<str>$, "string", scope, depth, 1);}
	|FLTCONST { insert ($<str>$, "float", scope, depth, 1);}
	|CHARCONST { insert ($<str>$, "char", scope, depth, 1);}
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
	:IDENTIFIER '('expression_list')' {check_scope($<str>1, scope, depth);}
	|IDENTIFIER '('')' {check_scope($<str>1, scope, depth);}
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
	|func_def
	|IDENTIFIER INCREMENT ';' {check_scope($<str>1, scope, depth);}
	|IDENTIFIER DECREMENT ';' {check_scope($<str>1, scope, depth);}
	|'{'statement_list'}'
	|';'
	;
id_chain
	:IDENTIFIER { strcpy(vars[varpt++],$<str>1); }
	|IDENTIFIER '=' expression { strcpy(vars[varpt++],$<str>1); }
	|'*'IDENTIFIER { strcpy(vars[varpt],$<str>1); pnt[varpt] = 1; varpt++;}
	|'*'IDENTIFIER ',' id_chain { strcpy(vars[varpt],$<str>1); pnt[varpt] = 1; varpt++;}
	|'*'IDENTIFIER '=' expression { strcpy(vars[varpt],$<str>1); pnt[varpt] = 1; varpt++;}
	|'*'IDENTIFIER '=' expression ',' id_chain { strcpy(vars[varpt],$<str>1); pnt[varpt] = 1; varpt++;}
	|IDENTIFIER '=' expression ',' id_chain { strcpy(vars[varpt++],$<str>1); }
	|IDENTIFIER ',' id_chain { strcpy(vars[varpt++],$<str>1); }
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
	:IDENTIFIER '=' expression ';'{check_scope($<str>1, scope, depth);}
	|'*'IDENTIFIER '=' expression';' {check_scope($<str>1, scope, depth);}
	|IDENTIFIER'['INTCONST']' '=' expression';' {check_scope($<str>1, scope, depth);}
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
