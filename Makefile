PROGRAM   = main
CC        = g++
CFLAGS    = -std=c++11
LDFLAGS   = -lGL -lGLU -lglut

$(PROGRAM): main.o GameScene.o 
	$(CC) -o $@ $^ $(LDFLAGS)
GameScene.o : GameScene.cpp ./headers/GameScene.hpp
	$(CC) $(CFLAGS) -c -o $@ $<


.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)


