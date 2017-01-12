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

		/* since we have only 8 lights avaliable and
			if street lights are turned on than GL_LIGHT0is taken by headlight
			so we need to choose from 
				GL_LIGHT1 ... GL_LIGHT7

		 since we have only curtain number of visible lamp posts
		 we dont need unique id form all lights in game
		 we just need for visible ones
		 since number of visible lights, controlled by LAMPPOST_FREQUENCY
		 is lower than 8 per visible area than we are able to
		 give unique id to all visible lamp posts bolbs
		*/
		// calculating bolbs position 
		int position = i%7 + 1;
		// calculating GL_LIGHT1 up to GL_LIGHT7
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
    GLfloat _light_direction[4] = {-0.2,-1,0};
    GLfloat _light_exponent = 3;
    GLfloat _light_cutoff = 90;
};

#endif