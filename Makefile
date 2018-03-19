all: symtbl.o symtbl.h
	yacc -d basic.y -v
	lex scanner.l
	cc symtbl.o y.tab.c lex.yy.c -ll
	./a.out

symtbl.o: symtbl.c
	gcc -c symtbl.c

lex:
	lex scanner.l
	cc lex.yy.c 
	./a.out
	
clean:
	rm -rf lex.yy.c *.out y.tab.h y.tab.c symtbl.o
