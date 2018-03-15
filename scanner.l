%{
	#include "y.tab.h"
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern int level; 
	extern int depth ;
	extern int scope[1000];
	extern int yylineno;
%}



%%

"//".*\n                  { /*printf("Single line comment\n");*/ yylineno++;}
"/*"([^*]|\*+[^*/])*"*/"  { /*printf("Multi line comment\n");*/ }

\"(\\.|[^"\n\\])*\"                                  {/*printf("String const:\t\t%s\n", yytext); insert(yytext, 1, CONST_TBL);*/ strcpy(yylval.str,yytext); return STRCONST; }
0[xX][0-9a-fA-F]+                                    {/*printf("Int const:\t\t%s\n", yytext); insert(yytext, 2, CONST_TBL);*/ strcpy(yylval.str,yytext); return INTCONST; }
[0-9]+                                               {/*printf("Int const:\t\t%s\n", yytext); insert(yytext, 2, CONST_TBL);*/ strcpy(yylval.str,yytext); return INTCONST; }
(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)        {/*printf("Float const:\t\t%s\n", yytext); insert(yytext, 3, CONST_TBL);*/  strcpy(yylval.str,yytext); return FLTCONST; }

'([^'\\\n]|\\.)'                                     {/*printf("Char const:\t\t%s\n", yytext); insert(yytext, 4, CONST_TBL);*/  strcpy(yylval.str,yytext); return CHARCONST; }
'                                                    {/*printf("\n Error: Unterminated Character constant\n\n");*/ }
''                                                   {/*printf("Char const:\t\t%s\n", yytext); insert(yytext, 1, CONST_TBL);*/ }
'([^'\\\n]|\\.)+'                                    {/*printf("\n Error: Character constant too long\n\n");*/ }

"auto"                  { /*printf("Keyword:\t\t%s\n", yytext);*/ return AUTO; }
"break"                 { /*printf("Keyword:\t\t%s\n", yytext);*/ return BREAK; }
"case"                  { /*printf("Keyword:\t\t%s\n", yytext);*/ return CASE; }
"char"                  { /*printf("Keyword:\t\t%s\n", yytext);*/ strcpy(yylval.str,yytext); return CHAR; }
"const"                 { /*printf("Keyword:\t\t%s\n", yytext);*/ return CONST; }
"continue"              { /*printf("Keyword:\t\t%s\n", yytext);*/ return CONTINUE; }
"default"               { /*printf("Keyword:\t\t%s\n", yytext);*/ return DEFAULT; }
"do"                    { /*printf("Keyword:\t\t%s\n", yytext);*/ return DO; }
"double"                { /*printf("Keyword:\t\t%s\n", yytext);*/ strcpy(yylval.str,yytext); return DOUBLE; }
"else"                  { /*printf("Keyword:\t\t%s\n", yytext);*/ return ELSE; }
"enum"                  { /*printf("Keyword:\t\t%s\n", yytext);*/ return ENUM; }
"extern"                { /*printf("Keyword:\t\t%s\n", yytext);*/ return EXTERN; }
"float"                 { /*printf("Keyword:\t\t%s\n", yytext);*/ strcpy(yylval.str,yytext); return FLOAT; }
"for"                   { /*printf("Keyword:\t\t%s\n", yytext);*/ return FOR; }
"if"                    { /*printf("Keyword:\t\t%s\n", yytext);*/ return IF; }
"int"                   { /*printf("Keyword:\t\t%s\n", yytext);*/ strcpy(yylval.str,yytext); return INT; }
"long"                  { /*printf("Keyword:\t\t%s\n", yytext);*/ strcpy(yylval.str,yytext); return LONG; }
"register"              { /*printf("Keyword:\t\t%s\n", yytext);*/ return REGISTER; }
"return"                { /*printf("Keyword:\t\t%s\n", yytext);*/ return RETURN; }
"short"                 { /*printf("Keyword:\t\t%s\n", yytext);*/ strcpy(yylval.str,yytext); return SHORT; }
"signed"                { /*printf("Keyword:\t\t%s\n", yytext);*/ return SIGNED; }
"sizeof"                { /*printf("Keyword:\t\t%s\n", yytext);*/ return SIZEOF; }
"static"                { /*printf("Keyword:\t\t%s\n", yytext);*/ return STATIC; }
"struct"                { /*printf("Keyword:\t\t%s\n", yytext);*/ return STRUCT; }
"switch"                { /*printf("Keyword:\t\t%s\n", yytext);*/ return SWITCH; }
"typedef"               { /*printf("Keyword:\t\t%s\n", yytext);*/ return TYPEDEF; }
"union"                 { /*printf("Keyword:\t\t%s\n", yytext);*/ return UNION; }
"unsigned"              { /*printf("Keyword:\t\t%s\n", yytext);*/ return UNSIGNED; }
"void"                  { /*printf("Keyword:\t\t%s\n", yytext);*/ strcpy(yylval.str,yytext); return VOID; }
"volatile"              { /*printf("Keyword:\t\t%s\n", yytext);*/ return VOLATILE; }
"while"                 { /*printf("Keyword:\t\t%s\n", yytext);*/ return WHILE; }


[a-zA-Z_][a-zA-Z0-9_]*   { /*printf("Identifier:\t\t%s\n", yytext);*/  /*insert(yytext, 0, SYM_TBL);*/ strcpy(yylval.str,yytext); return IDENTIFIER; }

"*/"                    { /*printf("\n Error: Unexpected end of comment\n\n");*/ }
"/*"                    { /*printf("\n Error: Unterminated Multi line comment\n\n");*/ }

"++"                    { /*printf("Operator:\t\t%s\n", yytext);*/ return INCREMENT; }
"--"                    { /*printf("Operator:\t\t%s\n", yytext);*/ return DECREMENT; }
"&&"                    { /*printf("Operator:\t\t%s\n", yytext);*/ return AND; }
"||"                    { /*printf("Operator:\t\t%s\n", yytext);*/ return OR; }
"=="                    { /*printf("Operator:\t\t%s\n", yytext);*/ return EQUAL; }
">="                    { /*printf("Operator:\t\t%s\n", yytext);*/ return GREATER; }
"<="                    { /*printf("Operator:\t\t%s\n", yytext);*/ return LESSER; }
"!="                    { /*printf("Operator:\t\t%s\n", yytext);*/ return NOTEQUAL; }

"!"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '!'; }
"%"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '%'; }
"^"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '^'; }
"&"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '&'; }
"*"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '*'; }
"("                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '('; }
")"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return ')'; }
"-"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '-'; }
"+"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '+'; }
"="                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '='; }
"{"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ depth++; level++;scope[depth-1]=level;return '{'; }
"}"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ scope[depth]=0; depth--; return '}'; }
"|"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '|'; }
"~"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '~'; }
"["                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '['; }
"]"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return ']'; }
";"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return ';'; }

":"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return ':'; }
"<"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '<'; }
">"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '>'; }
"?"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '?'; }
","                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return ','; }
"."                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '.'; }
"/"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '/'; }
"#"                     { /*printf("Punctuator:\t\t%s\n", yytext);*/ return '#'; }

"\n"                    { /*printf("\n");*/ yylineno++; }
" "                     { /*printf(" ");*/ }
"\t"                    { /*printf("\t");*/ }

"\""                    { /*printf("\n Error: Unmatched quotation\n\n");*/ }
.                       { /*printf("\n Error: Invalid token \n\n");*/ }

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


