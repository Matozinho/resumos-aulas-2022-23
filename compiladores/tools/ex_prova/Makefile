build:
	bison -d parser.y
	flex  -o lexical.c lexical.l
	gcc -Wall -o analyse lexical.c parser.tab.c -lfl -lm 

clean:
	rm -rf analyse
	rm -rf *tab*
	rm -rf *.c
	find . -maxdepth 1 -type f -executable -delete
