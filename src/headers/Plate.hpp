#ifndef __PLATE_HPP__ 
#define __PLATE_HPP__
#include <GL/glut.h>
#include "GameSettings.hpp"


#include <cmath>
#include <iostream>

using namespace std;

class Plate
{
public:
	Plate(float x, float y, float length, float density)
	: _x(x),_y(y),_length(length),_density(density)
	, _r(1),_g(0),_b(0)
	{}
	void paint(float r, float g, float b)
	{
		if(!_exists){
			cout << _exists << endl;
			return;
		}
		_r = r;
		_g = g;
		_b = b;
	}
	~Plate(){}
	void draw(int level);
	bool ifExists(){return _exists;}
	void generate(){_exists = true;}
	bool toDraw(){return drawFlag;}
private:
	bool drawFlag;
	bool _exists;
	float _x,_y;
	float _length;
	float _density; // number of stripes	
	float _r,_g,_b; // RGB
	float _angle = -1;
    GLfloat _ambient_coeffs[4] = { 0.1, 0.1, 0.1, 1 };
    GLfloat _diffuse_coeffs[4] = { 0.7, 0.7, 0.7, 1 };
    GLfloat _specular_coeffs[4] = { 0.9, 0.9, 0.9, 1 };
    GLfloat _shininess = 60;

};


#endif