%{
	#include <stdio.h>
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

\"(\\.|[^"\n\\])*\"                                  {printf("String const:\t\t%s\n", yytext); insert(yytext, 1, CONST_TBL); }
0[xX][0-9a-fA-F]+                                    {printf("Int const:\t\t%s\n", yytext); insert(yytext, 2, CONST_TBL); }
[0-9]+                                               {printf("Int const:\t\t%s\n", yytext); insert(yytext, 2, CONST_TBL); }
(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)        {printf("Float const:\t\t%s\n", yytext); insert(yytext, 3, CONST_TBL); }

'([^'\\\n]|\\.)'                                     {printf("Char const:\t\t%s\n", yytext); insert(yytext, 4, CONST_TBL); }
'                                                    {printf("\n Error: Unterminated Character constant\n\n"); }
''                                                   {printf("Char const:\t\t%s\n", yytext); insert(yytext, 1, CONST_TBL); }
'([^'\\\n]|\\.)+'                                    {printf("\n Error: Character constant too long\n\n"); }

"auto"                  { printf("Keyword:\t\t%s\n", yytext); }
"break"                 { printf("Keyword:\t\t%s\n", yytext); }
"case"                  { printf("Keyword:\t\t%s\n", yytext); }
"char"                  { printf("Keyword:\t\t%s\n", yytext); }
"const"                 { printf("Keyword:\t\t%s\n", yytext); }
"continue"              { printf("Keyword:\t\t%s\n", yytext); }
"default"               { printf("Keyword:\t\t%s\n", yytext); }
"do"                    { printf("Keyword:\t\t%s\n", yytext); }
"double"                { printf("Keyword:\t\t%s\n", yytext); }
"else"                  { printf("Keyword:\t\t%s\n", yytext); }
"num"                   { printf("Keyword:\t\t%s\n", yytext); }
"extern"                { printf("Keyword:\t\t%s\n", yytext); }
"float"                 { printf("Keyword:\t\t%s\n", yytext); }
"for"                   { printf("Keyword:\t\t%s\n", yytext); }
"goto"                  { printf("Keyword:\t\t%s\n", yytext); }
"if"                    { printf("Keyword:\t\t%s\n", yytext); }
"int"                   { printf("Keyword:\t\t%s\n", yytext); }
"long"                  { printf("Keyword:\t\t%s\n", yytext); }
"register"              { printf("Keyword:\t\t%s\n", yytext); }
"return"                { printf("Keyword:\t\t%s\n", yytext); }
"short"                 { printf("Keyword:\t\t%s\n", yytext); }
"signed"                { printf("Keyword:\t\t%s\n", yytext); }
"sizeof"                { printf("Keyword:\t\t%s\n", yytext); }
"static"                { printf("Keyword:\t\t%s\n", yytext); }
"struct"                { printf("Keyword:\t\t%s\n", yytext); }
"switch"                { printf("Keyword:\t\t%s\n", yytext); }
"typedef"               { printf("Keyword:\t\t%s\n", yytext); }
"union"                 { printf("Keyword:\t\t%s\n", yytext); }
"unsigned"              { printf("Keyword:\t\t%s\n", yytext); }
"void"                  { printf("Keyword:\t\t%s\n", yytext); }
"volatile"              { printf("Keyword:\t\t%s\n", yytext); }
"while"                 { printf("Keyword:\t\t%s\n", yytext); }


[a-zA-Z_][a-zA-Z0-9_]*   {printf("Identifier:\t\t%s\n", yytext);  insert(yytext, 0, SYM_TBL); }

"*/"                    { printf("\n Error: Unexpected end of comment\n\n"); }
"/*"                    { printf("\n Error: Unterminated Multi line comment\n\n"); }

"--"                    { printf("Operator:\t\t%s\n", yytext); }
"&&"                    { printf("Operator:\t\t%s\n", yytext); }
"||"                    { printf("Operator:\t\t%s\n", yytext); }
"=="                    { printf("Operator:\t\t%s\n", yytext); }
">="                    { printf("Operator:\t\t%s\n", yytext); }
"<="                    { printf("Operator:\t\t%s\n", yytext); }
"!="                    { printf("Operator:\t\t%s\n", yytext); }

"!"                     { printf("Punctuator:\t\t%s\n", yytext); }
"%"                     { printf("Punctuator:\t\t%s\n", yytext); }
"^"                     { printf("Punctuator:\t\t%s\n", yytext); }
"&"                     { printf("Punctuator:\t\t%s\n", yytext); }
"*"                     { printf("Punctuator:\t\t%s\n", yytext); }
"("                     { printf("Punctuator:\t\t%s\n", yytext); }
")"                     { printf("Punctuator:\t\t%s\n", yytext); }
"-"                     { printf("Punctuator:\t\t%s\n", yytext); }
"+"                     { printf("Punctuator:\t\t%s\n", yytext); }
"="                     { printf("Punctuator:\t\t%s\n", yytext); }
"{"                     { printf("Punctuator:\t\t%s\n", yytext); }
"}"                     { printf("Punctuator:\t\t%s\n", yytext); }
"|"                     { printf("Punctuator:\t\t%s\n", yytext); }
"~"                     { printf("Punctuator:\t\t%s\n", yytext); }
"["                     { printf("Punctuator:\t\t%s\n", yytext); }
"]"                     { printf("Punctuator:\t\t%s\n", yytext); }
";"                     { printf("Punctuator:\t\t%s\n", yytext); }

":"                     { printf("Punctuator:\t\t%s\n", yytext); }
"<"                     { printf("Punctuator:\t\t%s\n", yytext); }
">"                     { printf("Punctuator:\t\t%s\n", yytext); }
"?"                     { printf("Punctuator:\t\t%s\n", yytext); }
","                     { printf("Punctuator:\t\t%s\n", yytext); }
"."                     { printf("Punctuator:\t\t%s\n", yytext); }
"/"                     { printf("Punctuator:\t\t%s\n", yytext); }
"#"                     { printf("Punctuator:\t\t%s\n", yytext); }

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

int main()
{

	printf("\n\n");

	yyin = fopen("test_cases/8.c", "r");
	
	int token;
	while(yylex());

	
	display();
	
	printf("\n\n");
	
	return 0;
}


