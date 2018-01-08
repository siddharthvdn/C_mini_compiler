
keyword auto|break|case|char|const|continue|default|do|double|else|num|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while

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

whitespace [ \t] 

endline \n


%%

%%

int yywrap()
{
	return 1;
}

int main()
{
	yylex();
	
	return 0;
}


