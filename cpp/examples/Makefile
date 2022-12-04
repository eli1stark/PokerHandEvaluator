CC=gcc
CXX=g++
TOPDIR=..
INCLUDE=${TOPDIR}/include
SRC=${TOPDIR}/src
CFLAGS+=-std=c99
CXXFLAG+=-std=c++11

all: c_example

c_example: c_example.c ../libpheval.a
	${CC} ${CFLAGS} -I${INCLUDE} $^ -o $@

../libpheval.a:
	$(MAKE) -C ../;

%.o: %.c
	${CC} -c ${CFLAGS} -I${INCLUDE} $< -o $@

clean:
	rm -f *.o c_example
