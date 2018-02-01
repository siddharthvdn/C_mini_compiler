%{
	#include "y.tab.h"
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>	
	
	#define SYM_TBL 0
	#define CONST_TBL 1
	
	
	typedef struct node
	{
		char* name;		
		int type;
				
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
 	
 	
 	void insert(char* x, int type, int table)
 	{
 		if(lookup(x, table))
 			return;
 	
 		int idx = hash(x, 100);
 		
 		node* cell = (node*)malloc(sizeof(node));
 		cell->name = (char*)malloc(strlen(x));
 		strcpy(cell->name, x);
 		cell->type = type;
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
 				printf("%s\t\t-\t%d\n", t->name, t->type);
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
 				printf("%s\t\t-\t%d\n", t->name, t->type);
 				t = t->next;
 			}
 				
 		}
 	}
 	
%}



%%

"//".*\n                  {printf("Single line comment\n");}
"/*"([^*]|\*+[^*/])*"*/"  {printf("Multi line comment\n");}

\"(\\.|[^"\n\\])*\"                                  {printf("String const:\t\t%s\n", yytext); insert(yytext, 1, CONST_TBL); return STRCONST; }
0[xX][0-9a-fA-F]+                                    {printf("Int const:\t\t%s\n", yytext); insert(yytext, 2, CONST_TBL); return INTCONST; }
[0-9]+                                               {printf("Int const:\t\t%s\n", yytext); insert(yytext, 2, CONST_TBL); return INTCONST; }
(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)        {printf("Float const:\t\t%s\n", yytext); insert(yytext, 3, CONST_TBL);  return FLTCONST; }

'([^'\\\n]|\\.)'                                     {printf("Char const:\t\t%s\n", yytext); insert(yytext, 4, CONST_TBL);  return CHARCONST; }
'                                                    {printf("\n Error: Unterminated Character constant\n\n"); }
''                                                   {printf("Char const:\t\t%s\n", yytext); insert(yytext, 1, CONST_TBL); }
'([^'\\\n]|\\.)+'                                    {printf("\n Error: Character constant too long\n\n"); }

"auto"                  { printf("Keyword:\t\t%s\n", yytext); return AUTO; }
"break"                 { printf("Keyword:\t\t%s\n", yytext); return BREAK; }
"case"                  { printf("Keyword:\t\t%s\n", yytext); return CASE; }
"char"                  { printf("Keyword:\t\t%s\n", yytext); return CHAR; }
"const"                 { printf("Keyword:\t\t%s\n", yytext); return CONST; }
"continue"              { printf("Keyword:\t\t%s\n", yytext); return CONTINUE; }
"default"               { printf("Keyword:\t\t%s\n", yytext); return DEFAULT; }
"do"                    { printf("Keyword:\t\t%s\n", yytext); return DO; }
"double"                { printf("Keyword:\t\t%s\n", yytext); return DOUBLE; }
"else"                  { printf("Keyword:\t\t%s\n", yytext); return ELSE; }
"enum"                  { printf("Keyword:\t\t%s\n", yytext); return ENUM; }
"extern"                { printf("Keyword:\t\t%s\n", yytext); return EXTERN; }
"float"                 { printf("Keyword:\t\t%s\n", yytext); return FLOAT; }
"for"                   { printf("Keyword:\t\t%s\n", yytext); return FOR; }
"goto"                  { printf("Keyword:\t\t%s\n", yytext); return GOTO; }
"if"                    { printf("Keyword:\t\t%s\n", yytext); return IF; }
"int"                   { printf("Keyword:\t\t%s\n", yytext); return INT; }
"long"                  { printf("Keyword:\t\t%s\n", yytext); return LONG; }
"register"              { printf("Keyword:\t\t%s\n", yytext); return REGISTER; }
"return"                { printf("Keyword:\t\t%s\n", yytext); return RETURN; }
"short"                 { printf("Keyword:\t\t%s\n", yytext); return SHORT; }
"signed"                { printf("Keyword:\t\t%s\n", yytext); return SIGNED; }
"sizeof"                { printf("Keyword:\t\t%s\n", yytext); return SIZEOF; }
"static"                { printf("Keyword:\t\t%s\n", yytext); return STATIC; }
"struct"                { printf("Keyword:\t\t%s\n", yytext); return STRUCT; }
"switch"                { printf("Keyword:\t\t%s\n", yytext); return SWITCH; }
"typedef"               { printf("Keyword:\t\t%s\n", yytext); return TYPEDEF; }
"union"                 { printf("Keyword:\t\t%s\n", yytext); return UNION; }
"unsigned"              { printf("Keyword:\t\t%s\n", yytext); return UNSIGNED; }
"void"                  { printf("Keyword:\t\t%s\n", yytext); return VOID; }
"volatile"              { printf("Keyword:\t\t%s\n", yytext); return VOLATILE; }
"while"                 { printf("Keyword:\t\t%s\n", yytext); return WHILE; }


[a-zA-Z_][a-zA-Z0-9_]*   {printf("Identifier:\t\t%s\n", yytext);  insert(yytext, 0, SYM_TBL); return ID; }

"*/"                    { printf("\n Error: Unexpected end of comment\n\n"); }
"/*"                    { printf("\n Error: Unterminated Multi line comment\n\n"); }

"--"                    { printf("Operator:\t\t%s\n", yytext); return DECREMENT; }
"&&"                    { printf("Operator:\t\t%s\n", yytext); return AND; }
"||"                    { printf("Operator:\t\t%s\n", yytext); return OR; }
"=="                    { printf("Operator:\t\t%s\n", yytext); return EQUAL; }
">="                    { printf("Operator:\t\t%s\n", yytext); return GREATER; }
"<="                    { printf("Operator:\t\t%s\n", yytext); return LESSER; }
"!="                    { printf("Operator:\t\t%s\n", yytext); return NOTEQUAL; }

"!"                     { printf("Punctuator:\t\t%s\n", yytext); return '!'; }
"%"                     { printf("Punctuator:\t\t%s\n", yytext); return '%'; }
"^"                     { printf("Punctuator:\t\t%s\n", yytext); return '^'; }
"&"                     { printf("Punctuator:\t\t%s\n", yytext); return '&'; }
"*"                     { printf("Punctuator:\t\t%s\n", yytext); return '*'; }
"("                     { printf("Punctuator:\t\t%s\n", yytext); return '('; }
")"                     { printf("Punctuator:\t\t%s\n", yytext); return ')'; }
"-"                     { printf("Punctuator:\t\t%s\n", yytext); return '-'; }
"+"                     { printf("Punctuator:\t\t%s\n", yytext); return '+'; }
"="                     { printf("Punctuator:\t\t%s\n", yytext); return '='; }
"{"                     { printf("Punctuator:\t\t%s\n", yytext); return '{'; }
"}"                     { printf("Punctuator:\t\t%s\n", yytext); return '}'; }
"|"                     { printf("Punctuator:\t\t%s\n", yytext); return '|'; }
"~"                     { printf("Punctuator:\t\t%s\n", yytext); return '~'; }
"["                     { printf("Punctuator:\t\t%s\n", yytext); return '['; }
"]"                     { printf("Punctuator:\t\t%s\n", yytext); return ']'; }
";"                     { printf("Punctuator:\t\t%s\n", yytext); return ';'; }

":"                     { printf("Punctuator:\t\t%s\n", yytext); return ':'; }
"<"                     { printf("Punctuator:\t\t%s\n", yytext); return '<'; }
">"                     { printf("Punctuator:\t\t%s\n", yytext); return '>'; }
"?"                     { printf("Punctuator:\t\t%s\n", yytext); return '?'; }
","                     { printf("Punctuator:\t\t%s\n", yytext); return ','; }
"."                     { printf("Punctuator:\t\t%s\n", yytext); return '.'; }
"/"                     { printf("Punctuator:\t\t%s\n", yytext); return '/'; }
"#"                     { printf("Punctuator:\t\t%s\n", yytext); return '#'; }

"\n"                    { /*printf("\n");*/ }
" "                     { /*printf(" ");*/ }
"\t"                    { /*printf("\t");*/ }

"\""                    {printf("\n Error: Unmatched quotation\n\n");}
.                       { printf("\n Error: Invalid token \n\n"); }

%%

int yywrap()
{
	return 1;
}

/*int main()
{

	printf("\n\n");

	yyin = fopen("test_cases/program.c", "r");
	
	int token;
	while(yylex());

	
	display();
	
	printf("\n\n");
	
	return 0;
}*/


