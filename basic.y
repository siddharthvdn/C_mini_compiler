%{
	#include <stdio.h>
	
	
	
	void yyerror(char*);
%}

%token STRCONST INTCONST FLTCONST CHARCONST
%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO IF INT LONG REGISTER RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE
%token ID
%token DECREMENT AND OR EQUAL GREATER LESSER NOTEQUAL

%%
program: primary_expression|expression|arg|decalation {printf("SUCCESS!")};

primary_expression: ID | STRCONST| INTCONST| FLTCONST | CHARCONST| '(' expression ')';


expression: ID'='arg;
arg: ID | INTCONST;
	
decalation: INT ID'='INTCONST';' ;

%%


void yyerror(char* s)
{
	printf("ERROR: %s\n", s);
}

int main()
{

	yyparse();
	return 0;
}
