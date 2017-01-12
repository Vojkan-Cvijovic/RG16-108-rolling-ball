#ifndef _MENUSCENE_HPP
#define _MENUSCENE_HPP 
#include "GameSettings.hpp"
#include "Image.h"
#include <GL/glut.h>
#include <iostream>
#include <GL/freeglut.h>

using namespace std;

extern unsigned int screenState;

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
private:
	MenuScene(const MenuScene&);
	MenuScene& operator=(const MenuScene&);
	Image* _image;
	GLuint _names[SCREEN_TEXTURE_NUM_COUNT];
	int _selected_button_id = -1;
	bool _selected = false;
	int _button_width,_button_height;
	int _window_width,_window_height;
	void draw_text(char* text,float x,float y);
	void release_button(int button_id);
	void push_button(int button_id);
	int resolve_button_id(int mouse_x, int mouse_y);
	void draw_button_text(int x, int y, int button_id);
	void change_game_state(int button_id);
};



#endif