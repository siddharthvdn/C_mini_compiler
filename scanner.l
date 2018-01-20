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

\"(\\.|[^"\n\\])*\"                                  {printf("String constant: %s\n", yytext); insert(yytext, 1, CONST_TBL); }
-?[0-9]*                                           {printf("Integer constant: %s\n", yytext); insert(yytext, 2, CONST_TBL); }
-?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)    {printf("Float constant: %s\n", yytext); insert(yytext, 3, CONST_TBL); }

"auto"                  { printf("Keyword: %s\n", yytext); }
"break"                 { printf("Keyword: %s\n", yytext); }
"case"                  { printf("Keyword: %s\n", yytext); }
"char"                  { printf("Keyword: %s\n", yytext); }
"const"                 { printf("Keyword: %s\n", yytext); }
"continue"              { printf("Keyword: %s\n", yytext); }
"default"               { printf("Keyword: %s\n", yytext); }
"do"                    { printf("Keyword: %s\n", yytext); }
"double"                { printf("Keyword: %s\n", yytext); }
"else"                  { printf("Keyword: %s\n", yytext); }
"num"                   { printf("Keyword: %s\n", yytext); }
"extern"                { printf("Keyword: %s\n", yytext); }
"float"                 { printf("Keyword: %s\n", yytext); }
"for"                   { printf("Keyword: %s\n", yytext); }
"goto"                  { printf("Keyword: %s\n", yytext); }
"if"                    { printf("Keyword: %s\n", yytext); }
"int"                   { printf("Keyword: %s\n", yytext); }
"long"                  { printf("Keyword: %s\n", yytext); }
"register"              { printf("Keyword: %s\n", yytext); }
"return"                { printf("Keyword: %s\n", yytext); }
"short"                 { printf("Keyword: %s\n", yytext); }
"signed"                { printf("Keyword: %s\n", yytext); }
"sizeof"                { printf("Keyword: %s\n", yytext); }
"static"                { printf("Keyword: %s\n", yytext); }
"struct"                { printf("Keyword: %s\n", yytext); }
"switch"                { printf("Keyword: %s\n", yytext); }
"typedef"               { printf("Keyword: %s\n", yytext); }
"union"                 { printf("Keyword: %s\n", yytext); }
"unsigned"              { printf("Keyword: %s\n", yytext); }
"void"                  { printf("Keyword: %s\n", yytext); }
"volatile"              { printf("Keyword: %s\n", yytext); }
"while"                 { printf("Keyword: %s\n", yytext); }


[a-zA-Z_][a-zA-Z0-9_]*   {printf("Identifier: %s\n", yytext);  insert(yytext, 0, SYM_TBL); }

"*/"                    { printf("\n Error: Unexpected end of comment\n "); }
"/*"                    { printf("\n Error: neverending multi line comment\n "); }

"--"                    { printf("Operator: %s\n", yytext); }
"&&"                    { printf("Operator: %s\n", yytext); }
"||"                    { printf("Operator: %s\n", yytext); }
"=="                    { printf("Operator: %s\n", yytext); }
">="                    { printf("Operator: %s\n", yytext); }
"<="                    { printf("Operator: %s\n", yytext); }
"!="                    { printf("Operator: %s\n", yytext); }

"!"	                    { printf("Punctuator: %s\n", yytext); }
"%"	                    { printf("Punctuator: %s\n", yytext); }
"^"	                    { printf("Punctuator: %s\n", yytext); }
"&"	                    { printf("Punctuator: %s\n", yytext); }
"*"	                    { printf("Punctuator: %s\n", yytext); }
"("	                    { printf("Punctuator: %s\n", yytext); }
")"                         { printf("Punctuator: %s\n", yytext); }
"-"	                    { printf("Punctuator: %s\n", yytext); }
"+"	                    { printf("Punctuator: %s\n", yytext); }
"="	                    { printf("Punctuator: %s\n", yytext); }
"{"                         { printf("Punctuator: %s\n", yytext); }
"}"                         { printf("Punctuator: %s\n", yytext); }
"|"	                    { printf("Punctuator: %s\n", yytext); }
"~"	                    { printf("Punctuator: %s\n", yytext); }
"["                         { printf("Punctuator: %s\n", yytext); }
"]"                         { printf("Punctuator: %s\n", yytext); }
";"	                    { printf("Punctuator: %s\n", yytext); }
"'"	                    { printf("Punctuator: %s\n", yytext); }
":"	                    { printf("Punctuator: %s\n", yytext); }
"<"	                    { printf("Punctuator: %s\n", yytext); }
">"                         { printf("Punctuator: %s\n", yytext); }
"?"	                    { printf("Punctuator: %s\n", yytext); }
","	                    { printf("Punctuator: %s\n", yytext); }
"."	                    { printf("Punctuator: %s\n", yytext); }
"/"	                    { printf("Punctuator: %s\n", yytext); }
"#"	                    { printf("Punctuator: %s\n", yytext); }

"\n"                    { printf("\n"); }
" "                     { printf(" "); }
"\t"                    { printf("\t"); }

"\"" {printf("\n Error: unmatched quotation\n");}
.                       { printf("\n Error: Invalid token \n"); }

%%

int yywrap()
{
	return 1;
}

int main()
{

	printf("\n\n");

	yyin = fopen("test_cases/10.c", "r");
	
	int token;
	while(yylex());

	
	display();
	
	return 0;
}


