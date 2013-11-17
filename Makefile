.PHONY:	clean default all

MAKE	:= make
GCC 	:= gcc
CFLAGS	:= -pedantic -Wall -Werror -std=c99
LFLAGS 	:= -lm 
TAR	:= tar -zcvf
RM	:= rm -rf
CD	:= cd
MV	:= mv

all:
	$(MAKE) a1
	$(MAKE) a2
	$(MAKE) a3
	$(MAKE) a4

a1: a1.c derive.c
	$(GCC) $(CFLAGS) a1.c derive.c -o a1 $(LFLAGS)

a2: a2.c derive.c bisection.c newtonraphson.c falseposition.c
	$(GCC) $(CFLAGS) a2.c derive.c bisection.c newtonraphson.c falseposition.c -o a2 $(LFLAGS)

a3: a3.c newtonraphson.c derive.c
	$(GCC) $(CFLAGS) a3.c newtonraphson.c derive.c -o a3 $(LFLAGS)

a4: a4.c integrations.c
	$(GCC) $(CFLAGS) a4.c integrations.c -o a4 $(LFLAGS)

clean:
	$(RM) a1 a2 a3 a4 *~
	$(CD) report && $(RM)  *~ *backup *log *aux && $(CD) ..

tarball:
	$(MAKE) clean
	$(CD) .. && $(TAR) ass2.tar.gz ass2

default:
	all
