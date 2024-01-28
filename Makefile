CC = gcc
CFLAGS = -Wall

BASICCLASSIFICATION = basicClassification
ADVANCEDCLASSIFICATION = advancedClassification

CLASSLOOPS = classloops
CLASSRECURSIVE = classrec
LIBCLASSLOOPS = lib$(CLASSLOOPS)
LIBCLASSRECURSIVE = lib$(CLASSRECURSIVE)

all: loops loopd recursives recursived	mains maindloop maindrec

clean:
	rm -f *.a *.so *.o main mains maindloop maindrec

loops: $(LIBCLASSLOOPS).a

loopd: $(LIBCLASSLOOPS).so

recursives: $(LIBCLASSRECURSIVE).a

recursived: $(LIBCLASSRECURSIVE).so

mains: $(LIBCLASSRECURSIVE).a main.o
	$(CC) $(CFLAGS) -o $@ main.o -L. -static -l$(CLASSRECURSIVE)

maindloop: $(LIBCLASSLOOPS).so main.o
	$(CC) $(CFLAGS) -o $@ main.o -L. -l$(CLASSLOOPS)

maindrec: $(LIBCLASSRECURSIVE).so main.o
	$(CC) $(CFLAGS) -o $@ main.o -L. -l$(CLASSRECURSIVE)

.PHONY: all clean loops recursives recursived loopd mains maindloop maindrec

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libclassloops.a: $(BASICCLASSIFICATION).o $(ADVANCEDCLASSIFICATION)Loop.o
	ar rcs $@ $^

libclassrec.a: $(BASICCLASSIFICATION).o $(ADVANCEDCLASSIFICATION)Recursion.o
	ar rcs $@ $^

libclassrec.so: $(BASICCLASSIFICATION).o $(ADVANCEDCLASSIFICATION)Recursion.o
	$(CC) $(CFLAGS) -shared -o $@ $^

libclassloops.so: $(BASICCLASSIFICATION).o $(ADVANCEDCLASSIFICATION)Loop.o
	$(CC) $(CFLAGS) -shared -o $@ $^
