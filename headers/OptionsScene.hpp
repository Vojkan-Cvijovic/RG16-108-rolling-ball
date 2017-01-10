#ifndef _OPTIONS_SCENE_HPP
#define _OPTIONS_SCENE_HPP
#include "GameSettings.hpp"
#include "GameScene.hpp"
#include <iostream>
#include <GL/glut.h>
#include "Image.h"
using namespace std;


class OptionsScene
{
public:
	OptionsScene();
	~OptionsScene(){
		free(_image);
	}
	void draw();
	void on_mouse(int button, int state, int x, int y);	
private:
	OptionsScene(const OptionsScene&);
	OptionsScene& operator=(const OptionsScene&);
	int _difficulty_option;
	int _day_time;
	Image* _image;
	GLuint _names[SCREEN_TEXTURE_NUM_COUNT];
	int _window_width,_window_height;
	int _button_width,_button_height;
	void draw_text(char* text,float x,float y);
	void release_button(int button_id);
	void push_button(int button_id);
	int resolve_button_id(int mouse_x, int mouse_y);
	void draw_button_text(int x, int y, int button_id);
};



#endif