#ifndef _LIGHT_HPP_
#define _LIGHT_HPP_
#include "GameSettings.hpp"
#include <string>
#include <GL/glut.h>
#include <iostream>

using namespace std;

class Light
{
public:
	Light(float z,int i)
	:_z(z)
	{
		_light_position[0] = _x;
		_light_position[1] = _y;
		int position = i%7 + 1;
		_lightId = GL_LIGHT0 + position;
		// we choose side base on position of the lamppost on the road
		if(i%2 == 0)
			// right side
			_side = 1;
		else
			// left side
			_side = -1;
		_light_position[0] *= _side;
		_light_direction[0] *= _side;
	}	
	~Light();
	void draw(float distance);
private:
	bool _enabled = false;
	int _lightId = 0;
	int _side = 1;
	GLfloat _x = ROAD_BASE_WIDTH/2 -1,_y = 2.5,_z;
    GLfloat _light_position[4] = { 0, 0, 0, 1 };
    GLfloat _light_ambient[4] = { 0.1, 0.1, 0.1, 1 };
    GLfloat _light_diffuse[4] = { 0.7, 0.7, 0.7, 1 };
    GLfloat _light_specular[4] = { 0.7, 0.7, 0.7, 1 };
    /*GL_SPOT_DIRECTION,GL_SPOT_EXPONENT, GL_SPOT_CUTOFF*/
    GLfloat _light_direction[4] = {-0.2,-1,0};
    GLfloat _light_exponent = 3;
    GLfloat _light_cutoff = 90;


};


#endif