#ifndef __PLATE_HPP__ 
#define __PLATE_HPP__
#include <GL/glut.h>
#define PLATE_DEFAULT_WIDTH 2
#define PLATE_BASE_LENGTH 3
#include <cmath>
#include <iostream>

using namespace std;

class Plate
{
public:
	Plate(float x, float y, float length, float density, bool exists)
	: _x(x),_y(y),_length(length),_density(density),_exists(exists)
	, _r(1),_g(1),_b(1)
	{}
	void paint(float r, float g, float b)
	{
		_r = r;
		_g = g;
		_b = b;
	}
	~Plate(){}
	void draw(int level);
	bool ifExists(){return _exists;}
private:
	bool _exists;
	float _x,_y;
	float _length;
	float _density; // number of stripes	
	float _r,_g,_b; // RGB
};


#endif