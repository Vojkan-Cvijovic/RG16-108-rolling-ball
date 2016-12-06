PROGRAM   = main
CC        = g++
CFLAGS    = -g -Wall -std=c++11
LDFLAGS   = -lGL -lGLU -lglut

$(PROGRAM): main.o
	$(CC) -o $@ $^ $(LDFLAGS)



.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)


