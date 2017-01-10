PROGRAM   = main
CC        = g++
CFLAGS    = -std=c++11 -g -I/usr/X11R6/include -I/usr/pkg/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL
DEST 	  = ./headers
$(PROGRAM): main.o GameScene.o Ball.o Road.o Plate.o Lamppost.o Light.o Image.o MenuScene.o OptionsScene.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
main.o : main.cpp $(DEST)/GameScene.hpp $(DEST)/Ball.hpp $(DEST)/GameSettings.hpp $(DEST)/Image.h
	$(CC) $(CFLAGS) -c -o $@ $<
MenuScene.o : MenuScene.cpp $(DEST)/MenuScene.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
OptionsScene.o : OptionsScene.cpp $(DEST)/OptionsScene.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
GameScene.o : GameScene.cpp $(DEST)/GameScene.hpp $(DEST)/Ball.hpp $(DEST)/Road.hpp $(DEST)/GameSettings.hpp 
	$(CC) $(CFLAGS) -c -o $@ $<
Ball.o: Ball.cpp $(DEST)/Ball.hpp $(DEST)/GameSettings.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
Road.o: Road.cpp $(DEST)/Road.hpp $(DEST)/Plate.hpp $(DEST)/GameSettings.hpp $(DEST)/Lamppost.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
Plate.o: Plate.cpp $(DEST)/Plate.hpp $(DEST)/GameSettings.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
Lamppost.o: Lamppost.cpp $(DEST)/Lamppost.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
Light.o: Light.cpp $(DEST)/Light.hpp
	$(CC) $(CFLAGS) -c -o $@ $<


.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)


