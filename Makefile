all:
	yacc -d basic.y -Wother
	lex scanner.l
	cc y.tab.c lex.yy.c -ll
	./a.out

lex:
	lex scanner.l
	cc lex.yy.c 
	./a.out
	
clean:
	rm -rf lex.yy.c *.out *.h
