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
	int varpt = -1; 	

	char multidec_type[1000];
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
%right IF
%right ELSE


%token STRCONST INTCONST FLTCONST CHARCONST
%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR IF INT LONG REGISTER RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE
%token IDENTIFIER
%token INCREMENT DECREMENT AND OR EQUAL GREATER LESSER NOTEQUAL


%%
S
	:func_def S
	|multidec';' S
	|	
	;

func_def
	:modifiers datatype IDENTIFIER '(' params_list')' '{'statement_list'}' 
	{ 
		insert_fun ($<name>3, $<name>2, scope, depth, $<params>5); 
		//printf("dw%s",$<type>8);
		if((!strcmp($<type>2, "void") && strlen($<type>8)!=0) && (strcmp($<type>2, $<type>8)) )
			yyerror("Return type not matching");

		node* t = lookup($<name>3, FUN_TBL); 
		t->func_def = 1;
	}
	|modifiers datatype IDENTIFIER '('')' '{'statement_list'}' 
	{ 
		insert_fun ($<name>3, $<name>2, scope, depth, NULL); 
		//printf("dw%s",$<type>7);
		if((!strcmp($<type>2, "void") && strlen($<type>7)!=0) && (strcmp($<type>2, $<type>7)) )
			yyerror("Return type not matching");

		node* t = lookup($<name>3, FUN_TBL); 
		t->func_def = 1;
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

		node* t = lookup($<name>3, FUN_TBL); 
		t->func_def = 1;
	}	
	|modifiers datatype'*' IDENTIFIER '('')' '{'statement_list'}' 
	{
		char temp[1000];
		strcpy(temp,$<name>2);
		strcat(temp,"*"); 
		insert_fun ($<name>3, $<name>2, scope, depth, NULL); 
		if(strcmp(temp, "void") && strcmp(temp, $<type>8)) 
			yyerror("Return type not matching");

		node* t = lookup($<name>3, FUN_TBL); 
		t->func_def = 1;
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


multidec
	:modifiers datatype id_chain 
	{
		if(!strcmp($<type>2 ,"void"))
			yyerror("Variable of type void");
		//printf("HIHI");
		//varpt--;
		while(varpt>=0)
		{
			//printf("%d - %s\n", varpt, vars[varpt]);
			if(pnt[varpt])
			{
				char temp[1000];
				strcpy(temp,$<name>2);
				strcat(temp,"*"); 
				pnt[varpt] = 0;

				node* t = lookup(vars[varpt--], SYM_TBL); 
				strcpy(t->type, temp);
			}
			else
			{
				node* t = lookup(vars[varpt--], SYM_TBL); 
				strcpy(t->type, $<name>2);
			}

		}		
	} 
;
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

params_dec
	:modifiers datatype IDENTIFIER 
	{ 
		if(!strcmp($<type>2 ,"void"))
			yyerror("Parameter of type void");
		//printf("\n SDA %s",$<name>3);
		strcpy($<name>$,$<name>3); 
		insert ($<name>3, $<name>2, scope, depth, 0); 
		strcpy($<type>$,$<type>2); 
		strcpy($<name>$,$<name>3); 
	}
	|modifiers datatype IDENTIFIER '['INTCONST']' 
	{ 
		if(!strcmp($<type>2 ,"void"))
			yyerror("Parameter of type void");
		strcpy($<name>$,$<name>3); 
		char temp[1000];
		strcpy(temp,$<name>2);
		strcat(temp,"*"); 
		insert ($<name>3, temp, scope, depth, 0); 
		strcpy($<type>$,temp);

		int t_array = atoi($<name>5);
		node* t = lookup($<name>3, SYM_TBL);
		t->array_bound = t_array; 
		strcpy($<name>$,$<name>3); 


	}
	|modifiers datatype IDENTIFIER '['']' 
	{
		if(!strcmp($<type>2 ,"void"))
			yyerror("Parameter of type void"); 
		strcpy($<name>$,$<name>3); 
		char temp[1000];strcpy(temp,$<name>2);
		strcat(temp,"*"); 
		insert ($<name>3, temp, scope, depth, 0); 
		strcpy($<type>$,temp);
		strcpy($<name>$,$<name>3);  
	}
	|modifiers datatype '*' IDENTIFIER 
	{ 
		strcpy($<name>$,$<name>3); 
		char temp[1000];
		strcpy(temp,multidec_type);
		strcat(temp,"*"); 
		insert ($<name>4, temp, scope, depth, 0); 
		strcpy($<type>$,temp);
		strcpy($<name>$,$<name>4); 
	}
	;
	
params_list
	:params_dec 
	{
		printf("\n Name %s ",$<type>1);
		change_scope($<name>1, level); 
		strcpy($<params>$, $<type>1);
	}
	|params_dec ',' params_list 
	{
		//printf("\n Name %s ",$<name>1);
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
		node* t = lookup($<name>1, SYM_TBL); 

		if(strcmp(t->type, $<type>3))
			yyerror("Type mismatch");

		strcpy($<type>$, t->type);
	}
	|constant bin_op expression 
	{
		printf("entered");
		strcpy($<type>$, $<type>1);
		node* t = lookup($<name>1, CONST_TBL);

		if(strcmp(t->type, $<type>3))
			yyerror("Type mismatch");

		strcpy($<type>$, t->type);
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

		if(strcmp(t->type, "int"))
			yyerror("Increment not possible");

		strcpy($<type>$, t->type);
	}
	|IDENTIFIER DECREMENT 
	{
		check_scope($<name>1, scope, depth, SYM_TBL); 
		node* t = lookup($<name>1, SYM_TBL); 

		if(strcmp(t->type, "int"))
			yyerror("Increment not possible");

		strcpy($<type>$, t->type);
	}
	|func_call bin_op expression 
	{
		check_scope($<name>1, scope, depth, FUN_TBL); 
		node* t = lookup($<name>1, FUN_TBL); 

		if(strcmp(t->type, $<type>3))
			yyerror("Type mismatch");

		strcpy($<type>$, t->type);
	}
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
	{
		if(strcmp($<type>1, $<type>3))
			yyerror("Type mismatch");

		strcpy($<type>$, $<type>3);
	}
	|IDENTIFIER'['expression']'
	{
		check_scope($<name>1, scope, depth, SYM_TBL); 	

		node* t = lookup($<name>1, SYM_TBL);


		if(strcmp($<type>3, "int"))
			yyerror("Array index not integer");
		char temp[1000];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		strcpy($<type>$, temp);
	}	
	|IDENTIFIER'['expression']' bin_op expression
	{
		check_scope($<name>1, scope, depth, SYM_TBL);

		if(strcmp($<type>3, "int"))
			yyerror("Array index not integer"); 

		node* t = lookup($<name>1, SYM_TBL);
		char temp[100];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		if(strcmp($<type>3, temp))
			yyerror("Type mismatch");

		strcpy($<type>$,temp);
	}
	|un_op IDENTIFIER'['expression']'
	{
		check_scope($<name>3, scope, depth, SYM_TBL);

		if(strcmp($<type>4, "int"))
			yyerror("Array index not integer");	

		node* t = lookup($<name>1, SYM_TBL);

		strcpy($<type>$, t->type);
	}
	|IDENTIFIER '['expression']' INCREMENT
	{
		check_scope($<name>1, scope, depth, SYM_TBL); 

		if(strcmp($<type>3, "int"))
			yyerror("Array index not integer");	

		node* t = lookup($<name>1, SYM_TBL);
		char temp[100];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		if(strcmp($<type>1, "int*"))
			yyerror("Type mismatch");

		strcpy($<type>$, temp);
	}
	|IDENTIFIER '['expression']' DECREMENT
	{
		check_scope($<name>1, scope, depth, SYM_TBL); 	

		if(strcmp($<type>3, "int"))
			yyerror("Array index not integer");		

		node* t = lookup($<name>1, SYM_TBL);
		char temp[100];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		if(strcmp($<type>1, "int*"))
			yyerror("Type mismatch");

		strcpy($<type>$, temp);
	}
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
	{ 
		strcpy($<type>$, $<type>2);

		if(strlen($<type>1)>0 && strlen($<type>2)>0 && strcmp($<type>1, $<type>2))
			yyerror("Return type not matching");

		if(strlen($<type>1)>0)
			strcpy($<type>$, $<type>1);


	}
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

		if(t->func_def!=1)
			yyerror("Function not defined"); 

		if(strcmp($<params>3, t->params)) 
			yyerror("Parameters type mismatch"); 
		strcpy($<name>$, $<name>1);


	}
	|IDENTIFIER '('')' 
	{
		check_scope($<name>1, scope, depth, FUN_TBL); 
		node* t = lookup($<name>1, FUN_TBL); 

		if(t->func_def!=1)
			yyerror("Function not defined"); 

		if(t->params!=NULL) 
			yyerror("Parameters type mismatch"); 
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
	:multidec ';'
	{ strcpy($<type>$, ""); }
	|conditional
	{ strcpy($<type>$, ""); }
	|iterative
	{ strcpy($<type>$, ""); }
	|assignment
	{ strcpy($<type>$, ""); }
	|RETURN expression';' 
	{ strcpy($<type>$, $<type>2); }
	|func_call';'
	{ strcpy($<type>$, ""); }
	|func_def
	{ strcpy($<type>$, ""); }
	|IDENTIFIER INCREMENT ';' 
	{
		strcpy($<type>$, "");
		check_scope($<name>1, scope, depth, SYM_TBL);
	}
	|IDENTIFIER DECREMENT ';' 
	{
		strcpy($<type>$, "");
		check_scope($<name>1, scope, depth, SYM_TBL);
	}
	|'{'statement_list'}'
	{ strcpy($<type>$, $<type>2); }
	|';'
	{ strcpy($<type>$, ""); }
	|BREAK';'
	{ strcpy($<type>$, ""); }
	;




id_chain
	:IDENTIFIER 
	{ 
		varpt++;strcpy(vars[varpt],$<name>1);

		insert ($<name>1, multidec_type, scope, depth, 0); 
	}
	|IDENTIFIER '=' expression 
	{ 
		varpt++;strcpy(vars[varpt],$<name>1);

		insert ($<name>1, multidec_type, scope, depth, 0); 
	}
	|'*'IDENTIFIER 
	{ 
		varpt++; strcpy(vars[varpt],$<name>2); 
		pnt[varpt] = 1;

		insert ($<name>2, multidec_type, scope, depth, 0); 
	}
	|id_chain ',' '*'IDENTIFIER 
	{ 
		varpt++; strcpy(vars[varpt],$<name>4); 
		pnt[varpt] = 1;

		insert ($<name>4, multidec_type, scope, depth, 0);
	}
	|'*'IDENTIFIER '=' expression 
	{ 
		varpt++; strcpy(vars[varpt],$<name>2); 
		pnt[varpt] = 1;

		insert ($<name>2, multidec_type, scope, depth, 0);
	}
	|id_chain ',' '*'IDENTIFIER '=' expression 
	{ 
		varpt++; strcpy(vars[varpt],$<name>4); 
		pnt[varpt] = 1;
		insert ($<name>4, multidec_type, scope, depth, 0);
	}
	|id_chain ',' IDENTIFIER '=' expression 
	{ 
		varpt++;strcpy(vars[varpt],$<name>3);

		insert ($<name>3, multidec_type, scope, depth, 0); 
	}
	|id_chain ',' IDENTIFIER 
	{ 
		varpt++;strcpy(vars[varpt],$<name>3);

		insert ($<name>3, multidec_type, scope, depth, 0); 
	}
	|IDENTIFIER '['INTCONST']'
	{ 
		varpt++; strcpy(vars[varpt],$<name>1); 
		pnt[varpt] = 1;

		insert ($<name>1, multidec_type, scope, depth, 0); 
		
		int t_array = atoi($<name>3);

		if(t_array<=0)
			yyerror("Invalid array size");

		node* t = lookup($<name>1, SYM_TBL);
		t->array_bound = t_array; 

	}
	|IDENTIFIER'['']' '=' '{'const_list'}'
	{
		varpt++; strcpy(vars[varpt],$<name>1); 
		pnt[varpt] = 1;

		insert ($<name>1,multidec_type, scope, depth, 0);

		node* t = lookup($<name>1, SYM_TBL);
		t->array_bound = $<size>6;
	}
	|IDENTIFIER '['INTCONST']' '=' '{'const_list'}'
	{
		varpt++; strcpy(vars[varpt],$<name>1); 
		pnt[varpt] = 1;

		insert ($<name>1,multidec_type, scope, depth, 0);

		int t_array = atoi($<name>3);

		if(t_array < $<size>7)
			yyerror("Array index out of bound");
		node* t = lookup($<name>1, SYM_TBL);
		t->array_bound = t_array;
	}
	|id_chain ',' IDENTIFIER'['INTCONST']'
	{ 
		varpt++; strcpy(vars[varpt],$<name>3); 
		pnt[varpt] = 1;
		
		insert ($<name>3, multidec_type, scope, depth, 0); 
		
		int t_array = atoi($<name>5);

		if(t_array<=0)
			yyerror("Invalid array size");

		node* t = lookup($<name>3, SYM_TBL);
		t->array_bound = t_array; 

	}
	|id_chain ',' IDENTIFIER '['']' '=' '{'const_list'}'
	{
		varpt++; strcpy(vars[varpt],$<name>3); 
		pnt[varpt] = 1;

		insert ($<name>3,multidec_type, scope, depth, 0);

		node* t = lookup($<name>3, SYM_TBL);
		t->array_bound = $<size>8;
	}
	|id_chain ',' IDENTIFIER '['INTCONST']' '=' '{'const_list'}'
	{
		varpt++; strcpy(vars[varpt],$<name>3); 
		pnt[varpt] = 1; 

		insert ($<name>3,multidec_type, scope, depth, 0);

		int t_array = atoi($<name>5);

		if(t_array < $<size>9)
			yyerror("Array index out of bound");
		node* t = lookup($<name>3, SYM_TBL);
		t->array_bound = t_array;
	}
	;

conditional
	:IF '('expression')' statement %prec IF
	{
		if(strcmp($<type>3,"int"))
			yyerror("Invalid expression");	
	}
	|IF '('expression')' statement  ELSE statement	
	{
		if(strcmp($<type>3,"int"))
			yyerror("Invalid expression");	
	}
	;
iterative
	:WHILE'('expression')' statement
	{
		if(strcmp($<type>3,"int"))
			yyerror("Invalid expression");	
	}
	;
assignment
	:IDENTIFIER '=' expression ';'
	{check_scope($<name>1, scope, depth, SYM_TBL);}
	|'*'IDENTIFIER '=' expression';' 
	{check_scope($<name>1, scope, depth, SYM_TBL);}
	|IDENTIFIER'['expression']' '=' expression';'
	{
		if(strcmp($<type>3,"int"))
			yyerror("Invalid array index");	
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
