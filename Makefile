PROGRAM   = main
CC        = g++
CFLAGS    = -std=c++11
LDFLAGS   = -lGL -lGLU -lglut

$(PROGRAM): main.o GameScene.o Ball.o
	$(CC) -o $@ $^ $(LDFLAGS)
main.o : main.cpp ./headers/GameScene.hpp ./headers/Ball.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
GameScene.o : GameScene.cpp ./headers/GameScene.hpp ./headers/Ball.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
Ball.o: Ball.cpp ./headers/Ball.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)


