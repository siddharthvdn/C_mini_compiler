%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "symtbl.h"

	#include <stdio.h>
	extern FILE *yyin;
	
	int yylineno;
	
	char* yytext;
	
	void yyerror(char*);
%}

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
	|multidec
	|
	;
func_def
	:modifiers datatype IDENTIFIER '(' params_list')' '{'statement_list'}'
	|modifiers datatype IDENTIFIER '('')' '{'statement_list'}'
	|modifiers datatype IDENTIFIER '(' params_list')' ';'
	|modifiers datatype IDENTIFIER '('')' ';'
	;
id_dec
	:modifiers datatype IDENTIFIER 
	|modifiers datatype IDENTIFIER '['INTCONST']'
	|modifiers datatype '*' IDENTIFIER 
	;
id_assign_dec
	:modifiers datatype IDENTIFIER '=' expression 
	|modifiers datatype IDENTIFIER'['']' '=' '{'const_list'}'	
	|modifiers datatype IDENTIFIER'['INTCONST']' '=' '{'const_list'}'
	;
multidec
	:modifiers datatype id_chain
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
	:INTCONST
	|STRCONST
	|FLTCONST
	|CHARCONST
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
	:IDENTIFIER
	|IDENTIFIER '=' constant
	|IDENTIFIER '=' constant ',' id_chain
	|IDENTIFIER ',' id_chain
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
