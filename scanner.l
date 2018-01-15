%{
	#include <stdio.h>
	#include <string.h>
	
	#define AUTO 1
	#define BREAK 2
	#define CASE 3 
	#define CHAR 4
	#define CONST 5
	#define CONTINUE 6
	#define DEFAULT 7
	#define DO 8
	#define DOUBLE 9
	#define ELSE 10
	#define NUM 11
	#define EXTERN 12
	#define FLOAT 13
	#define FOR 14
	#define GOTO 15
	#define IF 16
	#define INT 17
	#define LONG 18 
	#define REGISTER 19
	#define RETURN 20
	#define SHORT 21
	#define SIGNED 22
	#define SIZEOF 23
	#define STATIC 24
	#define STRUCT 25
	#define SWITCH 26
	#define TYPEDEF 27
	#define UNION 28 
	#define UNSIGNED 29 
	#define VOID 30
	#define VOLATILE 31
	#define WHILE 32	
	
	typedef struct node
	{
		char* name;		
		int type;
				
		struct node* next;
	}node;

	node* sym_tbl[100];
	
	int hash(char* x, int M) 
	{
	   int i, sum;
	   for (sum=0, i=0; i < strlen(x); i++)
	     sum += x[i];
	   return sum % M;
 	}
 	
 	void insert(char* x, int type)
 	{
 		int idx = hash(x, 100);
 		
 		node* cell = (node*)malloc(sizeof(node));
 		cell->name = (char*)malloc(strlen(x));
 		strcpy(cell->name, x);
 		cell->type = type;
 		cell->next = NULL;		
 		
 		if(sym_tbl[idx]==NULL)
 		{
 			sym_tbl[idx] = cell;
 			return;
 		}
 		
 		node* t = sym_tbl[idx];
 		
 		while(t->next!=NULL);
 		
 		t->next = cell; 		
 	}
 	
 	void display()
 	{
 		int i;	
 	
 		for(i=0; i<100; i++)
 		{
 			if(sym_tbl[i]==NULL)
 				continue;
 			
 			node* t = sym_tbl[i];
 			
 			while(t!=NULL)	
 			{
 				printf("%s - %d\n", t->name, t->type);
 				t = t->next;
 			}
 				
 		}
 	}
 	
%}



identifier [a-zA-Z_][a-zA-Z0-9]*

intconst -?[0-9]*
fltconst -?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)
chrconst [a-zA-Z]
strconst \"(\\.|[^"\\])*\"

arithoperator "+"|"-"|"*"|"%"|"++"|"--"
logicaloperator "&&"|"||"|"!"
bitwiseoperator "&"|"|"|"^"
relationaloperator "=="|"<"|">"|">="|"<="|"!="
assignmentoperator "="

sqopen [ 
sqclose ] 
paopen (
paclose ) 
cuopen {
cuclose } 
pointer * , : = ; ... #

whitespace [ \t] 

endline \n



sincomment "//".*\n

mulcomment "/*"([^*]|\*+[^*/])*"*/"


%%

"auto"      { printf("Keyword: %s\n", yytext); return AUTO; }
"break"     { printf("Keyword: %s\n", yytext); return BREAK; }
"case"      { printf("Keyword: %s\n", yytext); return CASE; }
"char"      { printf("Keyword: %s\n", yytext); return CHAR; }
"const"     { printf("Keyword: %s\n", yytext); return CONST; }
"continue"  { printf("Keyword: %s\n", yytext); return CONTINUE; }
"default"   { printf("Keyword: %s\n", yytext); return DEFAULT; }
"do"        { printf("Keyword: %s\n", yytext); return DO; }
"double"    { printf("Keyword: %s\n", yytext); return DOUBLE; }
"else"      { printf("Keyword: %s\n", yytext); return ELSE; }
"num"       { printf("Keyword: %s\n", yytext); return NUM; }
"extern"    { printf("Keyword: %s\n", yytext); return EXTERN; }
"float"     { printf("Keyword: %s\n", yytext); return FLOAT; }
"for"       { printf("Keyword: %s\n", yytext); return FOR; }
"goto"      { printf("Keyword: %s\n", yytext); return GOTO; }
"if"        { printf("Keyword: %s\n", yytext); return IF; }
"int"       { printf("Keyword: %s\n", yytext); insert(yytext, INT); return INT; }
"long"      { printf("Keyword: %s\n", yytext); return LONG; }
"register"  { printf("Keyword: %s\n", yytext); return REGISTER; }
"return"    { printf("Keyword: %s\n", yytext); return RETURN; }
"short"     { printf("Keyword: %s\n", yytext); return SHORT; }
"signed"    { printf("Keyword: %s\n", yytext); return SIGNED; }
"sizeof"    { printf("Keyword: %s\n", yytext); return SIZEOF; }
"static"    { printf("Keyword: %s\n", yytext); return STATIC; }
"struct"    { printf("Keyword: %s\n", yytext); return STRUCT; }
"switch"    { printf("Keyword: %s\n", yytext); return SWITCH; }
"typedef"   { printf("Keyword: %s\n", yytext); return TYPEDEF; }
"union"     { printf("Keyword: %s\n", yytext); return UNION; }
"unsigned"  { printf("Keyword: %s\n", yytext); return UNSIGNED; }
"void"      { printf("Keyword: %s\n", yytext); return VOID; }
"volatile"  { printf("Keyword: %s\n", yytext); return VOLATILE; }
"while"     { printf("Keyword: %s\n", yytext); return WHILE; }


{strconst} printf("String constant: %s\n", yytext);

{sincomment} printf("This is a Single line comment\n");

{mulcomment} printf("This is a multi line comment\n");



{identifier} printf("Identifier: %s\n", yytext);

{intconst} printf("Integer constant");



%%

int yywrap()
{
	return 1;
}

int main()
{


	yyin = fopen("test_cases/1.c", "r");
	
	while(yylex());
	
	display();
	
	return 0;
}


