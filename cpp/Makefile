CC=gcc
CXX=g++
INCLUDE=./include
CFLAGS+=-O2 -std=c99
CXXFLAGS+=-O2 -std=c++14

all: libpheval.a

libpheval.a: src/evaluator5.c.o src/hashtable5.c.o \
             src/evaluator6.c.o src/hashtable6.c.o \
             src/evaluator7.c.o src/hashtable7.c.o \
             src/hash.c.o src/hashtable.c.o src/dptables.c.o \
             src/7462.c.o
	ar rcs $@ $^

%.c.o: %.c
	${CC} -c ${CFLAGS} -I${INCLUDE} $< -o $@

clean:
	rm -f src/*.o libpheval.a
