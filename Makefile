# Makefile
CC=g++ -std=gnu++0x
SRC=src
DEBUG=debug
RELEASE=release
DFLAGS=-g 
INC=-I /opt/include  
CFLAGS=${INC} -D_GLIBCXX_USE_NANOSLEEP -DDEBUG ${DFLAGS}
#POCOLIB=-L /usr/local/lib -lPocoFoundation

LIBS=-lpthread -L /usr/local/lib -lxerces-c ${POCOLIB}

all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

%.out: %.cpp Makefile
	${CC} $< -o $@ ${CFLAGS} ${LIBS}

clean:
	rm -f *.out *.class core*

.PHONY: clean all

