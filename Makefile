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
	$(MAKE) a5
	$(MAKE) a6
	$(MAKE) a7

a1: a1.c derive.c
	$(GCC) $(CFLAGS) a1.c derive.c -o a1 $(LFLAGS)

a2: a2.c bisection.c
	$(GCC) $(CFLAGS) a2.c bisection.c -o a2 $(LFLAGS) 

a3: a3.c derive.c bisection.c newtonraphson.c falseposition.c
	$(GCC) $(CFLAGS) a3.c derive.c bisection.c newtonraphson.c falseposition.c -o a3 $(LFLAGS)

a4: a4.c newtonraphson.c derive.c
	$(GCC) $(CFLAGS) a4.c newtonraphson.c derive.c -o a4 $(LFLAGS)

a5: a5.c integrations.c
	$(GCC) $(CFLAGS) a5.c integrations.c -o a5 $(LFLAGS)

a6: a6.c integrations.c
	$(GCC) $(CFLAGS) a6.c integrations.c -o a6 $(LFLAGS)

a7: a7.c
	$(GCC) $(CFLAGS) a7.c -o a7 $(LFLAGS)

clean:
	$(RM) a1 a2 a3 a4 a5 a6 a7 *~
	$(CD) report && $(RM)  *~ *backup *log *aux && $(CD) ..

tarball:
	$(MAKE) clean
	$(CD) .. && $(TAR) ass2.tar.gz ass2

default:
	all
