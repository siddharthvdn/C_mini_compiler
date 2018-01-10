all:
	lex basic.l
	cc lex.yy.c 
	./a.out
	
clean:
	rm -rf lex.yy.c *.out
