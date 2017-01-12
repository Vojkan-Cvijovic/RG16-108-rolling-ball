#ifndef _LAMPPOST_HPP_
#define _LAMPPOST_HPP_ 
#include <GL/glut.h>

#define RIGHT_SIDE 1
#define LEFT_SIDE 0
#include "Light.hpp"
#include "GameSettings.hpp"

class Lamppost
{
public:
	Lamppost(int i);
	~Lamppost();
	void draw(float distance);
	void setDaytime(int daytime){
		_daytime = daytime;
	}
private:
	float _d;
	int _side; 	// left or right side of road
	int _daytime = 0; 	// should light be turned on
	void paint(int pole);
	Light* _bolb;

	GLfloat _ambient_coeffs[4] = { 0.3, 0.3, 0.3, 1 };
    GLfloat _ambient_coeffs_bolb[4] = {0.3,0.0,0.0,1};
    GLfloat _diffuse_coeffs[4] = { 0.70, 0.70, 0.70, 1 };
    GLfloat _diffuse_coeffs_bolb[4] = {0.85,0.85,0,1};
    GLfloat _specular_coeffs[4] = { 1, 1, 1, 1 };
    GLfloat _shininess = 60;
	
};




#endif
