all:
	lex basic.l
	cc lex.yy.c 
	./a.out
	
clean:
	rm -rf *.c *.out
