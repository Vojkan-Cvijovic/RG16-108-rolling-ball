PROGRAM   = main
CC        = g++
CFLAGS    = -std=c++11
LDFLAGS   = -lGL -lGLU -lglut
DEST 	  = ./headers
$(PROGRAM): main.o GameScene.o Ball.o Road.o Plate.o
	$(CC) -o $@ $^ $(LDFLAGS)
main.o : main.cpp $(DEST)/GameScene.hpp $(DEST)/Ball.hpp $(DEST)/GameSettings.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
GameScene.o : GameScene.cpp $(DEST)/GameScene.hpp $(DEST)/Ball.hpp $(DEST)/Road.hpp $(DEST)/GameSettings.hpp 
	$(CC) $(CFLAGS) -c -o $@ $<
Ball.o: Ball.cpp $(DEST)/Ball.hpp $(DEST)/GameSettings.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
Road.o: Road.cpp $(DEST)/Road.hpp $(DEST)/Plate.hpp $(DEST)/GameSettings.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
Plate.o: Plate.cpp $(DEST)/Plate.hpp $(DEST)/GameSettings.hpp
	$(CC) $(CFLAGS) -c -o $@ $<


.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)


