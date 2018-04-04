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
		while(top!=0)
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
	/* ICG Functions*/
%}

%union
{
    struct Attributes attr;
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
		insert_fun ($<attr.name>3, $<attr.name>2, scope, depth, $<attr.params>5); 
		//printf("dw%s",$<attr.type>8);
		if((!strcmp($<attr.type>2, "void") && strlen($<attr.type>8)!=0) && (strcmp($<attr.type>2, $<attr.type>8)) )
			yyerror("Return type not matching");

		node* t = lookup($<attr.name>3, FUN_TBL); 
		t->func_def = 1;
	}
	|modifiers datatype IDENTIFIER '('')' '{'statement_list'}' 
	{ 
		insert_fun ($<attr.name>3, $<attr.name>2, scope, depth, NULL); 
		//printf("dw%s",$<attr.type>7);
		if((!strcmp($<attr.type>2, "void") && strlen($<attr.type>7)!=0) && (strcmp($<attr.type>2, $<attr.type>7)) )
			yyerror("Return type not matching");

		node* t = lookup($<attr.name>3, FUN_TBL); 
		t->func_def = 1;
	}
	|modifiers datatype IDENTIFIER '(' params_list')' ';' 
	{ 
		insert_fun ($<attr.name>3, $<attr.name>2, scope, depth, $<attr.params>5);
	}
	|modifiers datatype IDENTIFIER '('')' ';' 
	{
		insert_fun ($<attr.name>3, $<attr.name>2, scope, depth, NULL);
	}
	|modifiers datatype'*' IDENTIFIER '(' params_list')' '{'statement_list'}' 
	{
		char temp[1000];
		strcpy(temp,$<attr.name>2);
		strcat(temp,"*"); 
		insert_fun ($<attr.name>3, $<attr.name>2, scope, depth, $<attr.params>6); 
		if(strcmp(temp, "void") && strcmp(temp, $<attr.type>9)) 
			yyerror("Return type not matching");

		node* t = lookup($<attr.name>3, FUN_TBL); 
		t->func_def = 1;
	}	
	|modifiers datatype'*' IDENTIFIER '('')' '{'statement_list'}' 
	{
		char temp[1000];
		strcpy(temp,$<attr.name>2);
		strcat(temp,"*"); 
		insert_fun ($<attr.name>3, $<attr.name>2, scope, depth, NULL); 
		if(strcmp(temp, "void") && strcmp(temp, $<attr.type>8)) 
			yyerror("Return type not matching");

		node* t = lookup($<attr.name>3, FUN_TBL); 
		t->func_def = 1;
	}	
	|modifiers datatype'*' IDENTIFIER '(' params_list')' ';' 
	{
		char temp[1000];
		strcpy(temp,$<attr.name>2);
		strcat(temp,"*"); 
		insert_fun ($<attr.name>3, $<attr.name>2, scope, depth, $<attr.params>6);
	}	
	|modifiers datatype'*' IDENTIFIER '('')' ';' 
	{
		char temp[1000];
		strcpy(temp,$<attr.name>2);
		strcat(temp,"*"); 
		insert_fun ($<attr.name>3, $<attr.name>2, scope, depth, NULL);
	}	
	;


multidec
	:modifiers datatype id_chain 
	{
		if(!strcmp($<attr.type>2 ,"void"))
			yyerror("Variable of type void");
		//printf("HIHI");
		//varpt--;
		while(varpt>=0)
		{
			//printf("%d - %s\n", varpt, vars[varpt]);
			if(pnt[varpt])
			{
				char temp[1000];
				strcpy(temp,$<attr.name>2);
				strcat(temp,"*"); 
				pnt[varpt] = 0;

				node* t = lookup(vars[varpt--], SYM_TBL); 
				strcpy(t->type, temp);
			}
			else
			{
				node* t = lookup(vars[varpt--], SYM_TBL); 
				strcpy(t->type, $<attr.name>2);
			}

		}		
	} 
;
	;

datatype
	:INT 
	{ strcpy($<attr.type>$, "int"); }
	|FLOAT 
	{ strcpy($<attr.type>$, "float"); }
	|CHAR 
	{ strcpy($<attr.type>$, "char"); }
	|DOUBLE 
	{ strcpy($<attr.type>$, "double"); }
	|VOID 
	{ strcpy($<attr.type>$, "void"); }
	|LONG 
	{ strcpy($<attr.type>$, "long"); }
	|SHORT 
	{ strcpy($<attr.type>$, "short"); }
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
		if(!strcmp($<attr.type>2 ,"void"))
			yyerror("Parameter of type void");
		//printf("\n SDA %s",$<attr.name>3);
		strcpy($<attr.name>$,$<attr.name>3); 
		insert ($<attr.name>3, $<attr.name>2, scope, depth, 0); 
		strcpy($<attr.type>$,$<attr.type>2); 
		strcpy($<attr.name>$,$<attr.name>3); 
	}
	|modifiers datatype IDENTIFIER '['INTCONST']' 
	{ 
		if(!strcmp($<attr.type>2 ,"void"))
			yyerror("Parameter of type void");
		strcpy($<attr.name>$,$<attr.name>3); 
		char temp[1000];
		strcpy(temp,$<attr.name>2);
		strcat(temp,"*"); 
		insert ($<attr.name>3, temp, scope, depth, 0); 
		strcpy($<attr.type>$,temp);

		int t_array = atoi($<attr.name>5);
		node* t = lookup($<attr.name>3, SYM_TBL);
		t->array_bound = t_array; 
		strcpy($<attr.name>$,$<attr.name>3); 


	}
	|modifiers datatype IDENTIFIER '['']' 
	{
		if(!strcmp($<attr.type>2 ,"void"))
			yyerror("Parameter of type void"); 
		strcpy($<attr.name>$,$<attr.name>3); 
		char temp[1000];strcpy(temp,$<attr.name>2);
		strcat(temp,"*"); 
		insert ($<attr.name>3, temp, scope, depth, 0); 
		strcpy($<attr.type>$,temp);
		strcpy($<attr.name>$,$<attr.name>3);  
	}
	|modifiers datatype '*' IDENTIFIER 
	{ 
		strcpy($<attr.name>$,$<attr.name>3); 
		char temp[1000];
		strcpy(temp,multidec_type);
		strcat(temp,"*"); 
		insert ($<attr.name>4, temp, scope, depth, 0); 
		strcpy($<attr.type>$,temp);
		strcpy($<attr.name>$,$<attr.name>4); 
	}
	;
	
params_list
	:params_dec 
	{
		printf("\n Name %s ",$<attr.type>1);
		change_scope($<attr.name>1, level); 
		strcpy($<attr.params>$, $<attr.type>1);
	}
	|params_dec ',' params_list 
	{
		//printf("\n Name %s ",$<attr.name>1);
		change_scope($<attr.name>1, level); 
		char temp[1000]; strcpy(temp, $<attr.type>1); 
		strcat(temp, $<attr.params>3); strcpy($<attr.params>$, temp); 
	}
	;
	
brackets
	:'('expression')'{strcpy($<attr.type>$, $<attr.type>2);}
	;

expression
	:constant 
	{
		node* t = lookup($<attr.name>1, CONST_TBL);

		if(t!=NULL)
			strcpy($<attr.type>$, t->type);	

		strcpy(stack[++top],$<attr.name>1);
	
	
	}
	|expression '+' {strcpy(stack[++top],"+");} expression
	{
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp($<attr.type>1, $<attr.type>4))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, $<attr.type>1);

		gencode();
	}
	|expression '*' {strcpy(stack[++top],"*");} expression
	{
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp($<attr.type>1, $<attr.type>4))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, $<attr.type>1);

		gencode();
	}
	|expression '-' {strcpy(stack[++top],"-");} expression
	{
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp($<attr.type>1, $<attr.type>4))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, $<attr.type>1);

		gencode();
	}
	|expression '/' {strcpy(stack[++top],"/");} expression
	{
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp($<attr.type>1, $<attr.type>4))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, $<attr.type>1);

		gencode();
	}
	|expression '>' {strcpy(stack[++top],">");} expression
	{
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp($<attr.type>1, $<attr.type>4))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, $<attr.type>1);

		gencode();
	}
	|expression '<' {strcpy(stack[++top],"<");} expression
	{
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp($<attr.type>1, $<attr.type>4))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, $<attr.type>1);

		gencode();
	}
	|expression AND {strcpy(stack[++top],"&&");} expression
	{
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp($<attr.type>1, $<attr.type>4))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, $<attr.type>1);

		gencode();
	}
	|expression OR {strcpy(stack[++top],"||");} expression
	{
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp($<attr.type>1, $<attr.type>4))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, $<attr.type>1);

		gencode();
	}
	|expression EQUAL {strcpy(stack[++top],"==");} expression
	{
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp($<attr.type>1, $<attr.type>4))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, $<attr.type>1);

		gencode();
	}
	|expression GREATER {strcpy(stack[++top],">=");} expression
	{
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp($<attr.type>1, $<attr.type>4))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, $<attr.type>1);

		gencode();
	}
	|expression LESSER {strcpy(stack[++top],"<=");} expression
	{
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp($<attr.type>1, $<attr.type>4))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, $<attr.type>1);

		gencode();
	}
	|expression NOTEQUAL {strcpy(stack[++top],"!=");} expression
	{
		//check_scope($<attr.name>1, scope, depth, SYM_TBL);
		//node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp($<attr.type>1, $<attr.type>3))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, $<attr.type>1);

		gencode();
	}
	|IDENTIFIER 
	{
		check_scope($<attr.name>1, scope, depth, SYM_TBL); 
		node* t = lookup($<attr.name>1, SYM_TBL); 
		strcpy($<attr.type>$, t->type);

		strcpy(stack[++top],$<attr.name>1);
	}
	|un_op IDENTIFIER 
	{
		check_scope($<attr.name>1, scope, depth, SYM_TBL); 
		node* t = lookup($<attr.name>2, SYM_TBL); 
		strcpy($<attr.type>$, t->type);

	}
	|'-' IDENTIFIER %prec '$'
	{
		check_scope($<attr.name>1, scope, depth, SYM_TBL); 
		node* t = lookup($<attr.name>2, SYM_TBL); 
		strcpy($<attr.type>$, t->type);

		strcpy(stack[++top], $<attr.name>2);
		gencode_umin();
		
	}
	|un_op constant 
	{strcpy($<attr.type>$, $<attr.type>2);}
	|'-' constant %prec '$'
	{
		strcpy($<attr.type>$, $<attr.type>2);

		strcpy(stack[++top], $<attr.name>2);
		gencode_umin();
	}
	|INCREMENT IDENTIFIER  
	{
		check_scope($<attr.name>2, scope, depth, SYM_TBL); 
		node* t = lookup($<attr.name>1, SYM_TBL); 

		printf("\n");	
		if(strcmp(t->type, "int"))
			yyerror("Increment not possible");

		strcpy($<attr.type>$, t->type);

		
		printf("%s = %s + 1\n", $<attr.name>2, $<attr.name>2);
		strcpy(stack[++top], $<attr.name>2);


	}
	|DECREMENT IDENTIFIER  
	{
		check_scope($<attr.name>2, scope, depth, SYM_TBL); 
		node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp(t->type, "int"))
			yyerror("Increment not possible");

		strcpy($<attr.type>$, t->type);

		printf("%s = %s - 1\n", $<attr.name>2, $<attr.name>2);
		strcpy(stack[++top], $<attr.name>2);
	}
	|IDENTIFIER INCREMENT 
	{
		check_scope($<attr.name>1, scope, depth, SYM_TBL); 
		node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp(t->type, "int"))
			yyerror("Increment not possible");

		strcpy($<attr.type>$, t->type);

		int i = 0;

		char tstack[1000][100];

		int ttop = 0;

		
		for(i=top; i>0; i--)
			strcpy(tstack[++ttop],stack[i]);

		top=0;
			strcpy(temp,$<attr.name>1);
		strcat(temp, " = ");
		strcat(temp, $<attr.name>1);
		strcat(temp, " + 1");
		
		strcpy(stack[++top], temp);


		for(i=ttop; i>0; i--)
			strcpy(stack[++top],tstack[i]);




		strcpy(stack[++top], $<attr.name>1);

	
		
	}

	|IDENTIFIER DECREMENT 
	{
		check_scope($<attr.name>1, scope, depth, SYM_TBL); 
		node* t = lookup($<attr.name>1, SYM_TBL); 

		if(strcmp(t->type, "int"))
			yyerror("Increment not possible");

		strcpy($<attr.type>$, t->type);

		int i = 0;

		char tstack[1000][100];

		int ttop = 0;

		
		for(i=top; i>0; i--)
			strcpy(tstack[++ttop],stack[i]);

		top=0;
		strcpy(temp,$<attr.name>1);
		strcat(temp, " = ");
		strcat(temp, $<attr.name>1);
		strcat(temp, " - 1");
		
		strcpy(stack[++top], temp);


		for(i=ttop; i>0; i--)
			strcpy(stack[++top],tstack[i]);



		strcpy(stack[++top], $<attr.name>1);	
	}
	|func_call 
	{
		check_scope($<attr.name>1, scope, depth, FUN_TBL); 
		node* t = lookup($<attr.name>1, FUN_TBL); 

		strcpy($<attr.type>$, t->type);
	}
	|un_op func_call 
	{
		check_scope($<attr.name>1, scope, depth, FUN_TBL); 
		node* t = lookup($<attr.name>2, FUN_TBL);

		strcpy($<attr.type>$, t->type);
	}
	|brackets 
	{ strcpy($<attr.type>$, $<attr.type>1); }
	|un_op brackets 
	{ strcpy($<attr.type>$, $<attr.type>2); }
	|IDENTIFIER'['expression']'
	{
		check_scope($<attr.name>1, scope, depth, SYM_TBL); 	

		node* t = lookup($<attr.name>1, SYM_TBL);


		if(strcmp($<attr.type>3, "int"))
			yyerror("Array index not integer");
		char temp[1000];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		strcpy($<attr.type>$, temp);
	}	
	|un_op IDENTIFIER'['expression']'
	{
		check_scope($<attr.name>3, scope, depth, SYM_TBL);

		if(strcmp($<attr.type>4, "int"))
			yyerror("Array index not integer");	

		node* t = lookup($<attr.name>1, SYM_TBL);

		strcpy($<attr.type>$, t->type);
	}
	|IDENTIFIER '['expression']' INCREMENT
	{
		check_scope($<attr.name>1, scope, depth, SYM_TBL); 

		if(strcmp($<attr.type>3, "int"))
			yyerror("Array index not integer");	

		node* t = lookup($<attr.name>1, SYM_TBL);
		char temp[100];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		if(strcmp($<attr.type>1, "int*"))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, temp);
	}
	|IDENTIFIER '['expression']' DECREMENT
	{
		check_scope($<attr.name>1, scope, depth, SYM_TBL); 	

		if(strcmp($<attr.type>3, "int"))
			yyerror("Array index not integer");		

		node* t = lookup($<attr.name>1, SYM_TBL);
		char temp[100];
		strcpy(temp, t->type);
		temp[strlen(t->type)-1] = 0;
		if(strcmp($<attr.type>1, "int*"))
			yyerror("Type mismatch");

		strcpy($<attr.type>$, temp);
	}
	;

const_list
	:constant 
	{ $<attr.size>$ = 1; }
	|constant ',' const_list 
	{ $<attr.size>$ = $<attr.size>3 + 1; }
	;

statement_list
	:statement 
	{ strcpy($<attr.type>$, $<attr.type>1); }
	|statement statement_list 
	{ 
		strcpy($<attr.type>$, $<attr.type>2);

		if(strlen($<attr.type>1)>0 && strlen($<attr.type>2)>0 && strcmp($<attr.type>1, $<attr.type>2))
			yyerror("Return type not matching");

		if(strlen($<attr.type>1)>0)
			strcpy($<attr.type>$, $<attr.type>1);


	}
	;

constant
	:INTCONST 
	{ 
		insert ($<attr.name>1, "int", scope, depth, 1); 
		
		strcpy($<attr.type>$, "int");

		strcpy($<attr.name>$, $<attr.name>1);
	}
	|STRCONST 
	{ 
		insert ($<attr.name>1, "string", scope, depth, 1); 
		
		strcpy($<attr.type>$, "char*");

		strcpy($<attr.name>$, $<attr.name>1);
	}
	|FLTCONST 
	{ 
		insert ($<attr.name>1, "float", scope, depth, 1); 
		
		strcpy($<attr.type>$, "float");

		strcpy($<attr.name>$, $<attr.name>1);
	}
	|CHARCONST 
	{ 
		insert ($<attr.name>1, "char", scope, depth, 1); 
		
		strcpy($<attr.type>$, "char");

		strcpy($<attr.name>$, $<attr.name>1);
	}
	;

un_op
	:'!' %prec '$'
	|'+' %prec '$'
	|'*' %prec '$'
	|'&' %prec '$'
	;

func_call
	:IDENTIFIER '('expression_list')' 
	{
		check_scope($<attr.name>1, scope, depth, FUN_TBL); 
		node* t = lookup($<attr.name>1, FUN_TBL); 

		if(t->func_def!=1)
			yyerror("Function not defined"); 

		if(strcmp($<attr.params>3, t->params)) 
			yyerror("Parameters type mismatch"); 
		strcpy($<attr.name>$, $<attr.name>1);


	}
	|IDENTIFIER '('')' 
	{
		check_scope($<attr.name>1, scope, depth, FUN_TBL); 
		node* t = lookup($<attr.name>1, FUN_TBL); 

		if(t->func_def!=1)
			yyerror("Function not defined"); 

		if(t->params!=NULL) 
			yyerror("Parameters type mismatch"); 
		strcpy($<attr.name>$, $<attr.name>1);
	}
	;

expression_list
	:expression 
	{ strcpy($<attr.params>$, $<attr.type>1); }
	|expression ',' expression_list 
	{ 
		char temp[1000]; 
		strcpy(temp, $<attr.type>1); 
		strcat(temp, $<attr.params>3); 
		strcpy($<attr.params>$, temp); 
	}
	;

statement
	:multidec ';'
	{ 
		strcpy($<attr.type>$, ""); 
		post_increment();
	}
	|conditional
	{ 
		strcpy($<attr.type>$, ""); 
		post_increment();
	}
	|iterative
	{ 
		strcpy($<attr.type>$, ""); 
		post_increment();
	}
	
	|assignment
	{ 
		strcpy($<attr.type>$, ""); 
		post_increment();
	}
	|RETURN expression';' 
	{ 
		strcpy($<attr.type>$, $<attr.type>2); 
		post_increment();
	}
	|func_call';'
	{ 
		strcpy($<attr.type>$, ""); 
		post_increment();
	}
	|func_def
	{ 
		strcpy($<attr.type>$, ""); 
		post_increment();
	}
	|IDENTIFIER INCREMENT ';' 
	{
		strcpy($<attr.type>$, "");
		check_scope($<attr.name>1, scope, depth, SYM_TBL);
		post_increment();
	}
	|IDENTIFIER DECREMENT ';' 
	{
		strcpy($<attr.type>$, "");
		check_scope($<attr.name>1, scope, depth, SYM_TBL);
		post_increment();
	}
	|INCREMENT IDENTIFIER  ';' 
	{
		strcpy($<attr.type>$, "");
		check_scope($<attr.name>2, scope, depth, SYM_TBL);
		post_increment();
	}
	|DECREMENT IDENTIFIER  ';' 
	{
		strcpy($<attr.type>$, "");
		check_scope($<attr.name>2, scope, depth, SYM_TBL);
		post_increment();
	}
	|'{'statement_list'}'
	{ 
		strcpy($<attr.type>$, $<attr.type>2); 
		post_increment();
	}
	|';'
	{ 
		strcpy($<attr.type>$, ""); 
		post_increment();
	}
	|BREAK';'
	{ 
		//printf("iterative: %d\n", iterative);
		if(iterative<=0)
			yyerror("Invalid use of break statement");
			
		strcpy($<attr.type>$, "");

		printf("goto L%d\n",label[ltop]);
	}
	;




id_chain
	:IDENTIFIER 
	{ 
		varpt++;strcpy(vars[varpt],$<attr.name>1);

		insert ($<attr.name>1, multidec_type, scope, depth, 0); 
	}
	|IDENTIFIER '=' expression 
	{ 
		varpt++;strcpy(vars[varpt],$<attr.name>1);

		insert ($<attr.name>1, multidec_type, scope, depth, 0); 
	}
	|'*'IDENTIFIER 
	{ 
		varpt++; strcpy(vars[varpt],$<attr.name>2); 
		pnt[varpt] = 1;

		insert ($<attr.name>2, multidec_type, scope, depth, 0); 
	}
	|id_chain ',' '*'IDENTIFIER 
	{ 
		varpt++; strcpy(vars[varpt],$<attr.name>4); 
		pnt[varpt] = 1;

		insert ($<attr.name>4, multidec_type, scope, depth, 0);
	}
	|'*'IDENTIFIER '=' expression 
	{ 
		varpt++; strcpy(vars[varpt],$<attr.name>2); 
		pnt[varpt] = 1;

		insert ($<attr.name>2, multidec_type, scope, depth, 0);
	}
	|id_chain ',' '*'IDENTIFIER '=' expression 
	{ 
		varpt++; strcpy(vars[varpt],$<attr.name>4); 
		pnt[varpt] = 1;
		insert ($<attr.name>4, multidec_type, scope, depth, 0);
	}
	|id_chain ',' IDENTIFIER '=' expression 
	{ 
		varpt++;strcpy(vars[varpt],$<attr.name>3);

		insert ($<attr.name>3, multidec_type, scope, depth, 0); 
	}
	|id_chain ',' IDENTIFIER 
	{ 
		varpt++;strcpy(vars[varpt],$<attr.name>3);

		insert ($<attr.name>3, multidec_type, scope, depth, 0); 
	}
	|IDENTIFIER '['INTCONST']'
	{ 
		varpt++; strcpy(vars[varpt],$<attr.name>1); 
		pnt[varpt] = 1;

		insert ($<attr.name>1, multidec_type, scope, depth, 0); 
		
		int t_array = atoi($<attr.name>3);

		if(t_array<=0)
			yyerror("Invalid array size");

		node* t = lookup($<attr.name>1, SYM_TBL);
		t->array_bound = t_array; 

	}
	|IDENTIFIER'['']' '=' '{'const_list'}'
	{
		varpt++; strcpy(vars[varpt],$<attr.name>1); 
		pnt[varpt] = 1;

		insert ($<attr.name>1,multidec_type, scope, depth, 0);

		node* t = lookup($<attr.name>1, SYM_TBL);
		t->array_bound = $<attr.size>6;
	}
	|IDENTIFIER '['INTCONST']' '=' '{'const_list'}'
	{
		varpt++; strcpy(vars[varpt],$<attr.name>1); 
		pnt[varpt] = 1;

		insert ($<attr.name>1,multidec_type, scope, depth, 0);

		int t_array = atoi($<attr.name>3);

		if(t_array < $<attr.size>7)
			yyerror("Array index out of bound");
		node* t = lookup($<attr.name>1, SYM_TBL);
		t->array_bound = t_array;
	}
	|id_chain ',' IDENTIFIER'['INTCONST']'
	{ 
		varpt++; strcpy(vars[varpt],$<attr.name>3); 
		pnt[varpt] = 1;
		
		insert ($<attr.name>3, multidec_type, scope, depth, 0); 
		
		int t_array = atoi($<attr.name>5);

		if(t_array<=0)
			yyerror("Invalid array size");

		node* t = lookup($<attr.name>3, SYM_TBL);
		t->array_bound = t_array; 

	}
	|id_chain ',' IDENTIFIER '['']' '=' '{'const_list'}'
	{
		varpt++; strcpy(vars[varpt],$<attr.name>3); 
		pnt[varpt] = 1;

		insert ($<attr.name>3,multidec_type, scope, depth, 0);

		node* t = lookup($<attr.name>3, SYM_TBL);
		t->array_bound = $<attr.size>8;
	}
	|id_chain ',' IDENTIFIER '['INTCONST']' '=' '{'const_list'}'
	{
		varpt++; strcpy(vars[varpt],$<attr.name>3); 
		pnt[varpt] = 1; 

		insert ($<attr.name>3,multidec_type, scope, depth, 0);

		int t_array = atoi($<attr.name>5);

		if(t_array < $<attr.size>9)
			yyerror("Array index out of bound");
		node* t = lookup($<attr.name>3, SYM_TBL);
		t->array_bound = t_array;
	}
	;


conditional
	:ifblock  %prec IF
	{
		printf("L%d: \n",label[ltop--]);
	}
	|ifblock  ELSE statement {if3();}	
	;

ifblock
	:IF '('expression')'{if1();} statement
	{

		if(strcmp($<attr.type>3,"int"))
			yyerror("Invalid expression");
		if2();
	}
iterative
	:WHILE {w1();} '('expression')' {w2();} statement {w3();}
	{
		iterative--;
		if(strcmp($<attr.type>4,"int"))
			yyerror("Invalid expression");	
	}
	;
	

assignment
	:IDENTIFIER '=' expression ';'
	{
		check_scope($<attr.name>1, scope, depth, SYM_TBL);


		printf("%s = %s\n",$<attr.name>1,stack[top]);
		top--;
	}
	|'*'IDENTIFIER '=' expression';' 
	{check_scope($<attr.name>1, scope, depth, SYM_TBL);}
	|IDENTIFIER'['expression']' '=' expression';'
	{
		if(strcmp($<attr.type>3,"int"))
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
