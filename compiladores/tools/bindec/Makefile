calc: bindec.y bindec.l
	bison -d bindec.y
	flex  -o bindec.lex.c bindec.l
	gcc -Wall -o bindec bindec.lex.c bindec.tab.c -lfl -lm 

clean:
	rm -rf bindec
