#ifndef _MENUSCENE_HPP
#define _MENUSCENE_HPP 
#include "GameSettings.hpp"
#include "Image.h"
#include <GL/glut.h>
#include <iostream>
#include <GL/freeglut.h>

using namespace std;

class MenuScene
{
public:
	MenuScene();
	~MenuScene(){
		free(_image);
	}
	void draw();
	void drawOptionScreen();
	void on_mouse(int button, int state, int x, int y);
	void setWidthAndHeight(int x,int y){
		_width = x;
		_height = y;
	}	
private:
	MenuScene(const MenuScene&);
	MenuScene& operator=(const MenuScene&);
	Image* _image;
	GLuint _names[2];
	void draw_text(char* text,float x,float y);
	int _width,_height;

};



#endif