#YACC	= bison
#LEX	= flex
YACC	= yacc
LEX	= lex
CC	= gcc
#LFLAGS	= -ly -lfl
#LFLAGS	= -ly -ll
LFLAGS	= 

cmm	: y.tab.c code.o env.o
	$(CC) y.tab.c code.o env.o $(LFLAGS) -o cmm

y.tab.c	: cmm.y lex.yy.c
	$(YACC) cmm.y

code.o	: code.c code.h
	$(CC) -c code.c

env.o	: env.c env.h
	$(CC) -c env.c

lex.yy.c	: cmm.l
	$(LEX) cmm.l

clean	:
	rm -f *~ *.tab.* *.o lex.yy.c

cleanall	: clean
	rm -f cmm code.output
