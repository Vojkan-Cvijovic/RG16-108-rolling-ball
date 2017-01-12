PROGRAM   = Rolling_Ball
CC        = g++
CFLAGS    = -std=c++11 -g -I/usr/X11R6/include -I/usr/pkg/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL

DESTINATION 	= ./src/
HEADER_FOLDER 	= $(DESTINATION)headers/

$(PROGRAM): main.o GameScene.o Ball.o Road.o Plate.o Lamppost.o Light.o Image.o MenuScene.o OptionsScene.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

main.o : $(DESTINATION)main.cpp $(HEADER_FOLDER)GameScene.hpp $(HEADER_FOLDER)Ball.hpp $(HEADER_FOLDER)GameSettings.hpp $(HEADER_FOLDER)Image.h
	$(CC) $(CFLAGS) -c -o $@ $<

MenuScene.o : $(DESTINATION)MenuScene.cpp $(HEADER_FOLDER)MenuScene.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

OptionsScene.o : $(DESTINATION)OptionsScene.cpp $(HEADER_FOLDER)OptionsScene.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

GameScene.o : $(DESTINATION)GameScene.cpp $(HEADER_FOLDER)GameScene.hpp $(HEADER_FOLDER)Ball.hpp $(HEADER_FOLDER)Road.hpp $(HEADER_FOLDER)GameSettings.hpp 
	$(CC) $(CFLAGS) -c -o $@ $<

Ball.o: $(DESTINATION)Ball.cpp $(HEADER_FOLDER)Ball.hpp $(HEADER_FOLDER)GameSettings.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Road.o: $(DESTINATION)Road.cpp $(HEADER_FOLDER)Road.hpp $(HEADER_FOLDER)Plate.hpp $(HEADER_FOLDER)GameSettings.hpp $(HEADER_FOLDER)Lamppost.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Plate.o: $(DESTINATION)Plate.cpp $(HEADER_FOLDER)Plate.hpp $(HEADER_FOLDER)GameSettings.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Lamppost.o: $(DESTINATION)Lamppost.cpp $(HEADER_FOLDER)Lamppost.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Light.o: $(DESTINATION)Light.cpp $(HEADER_FOLDER)Light.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Image.o: $(DESTINATION)Image.c $(HEADER_FOLDER)Image.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)


