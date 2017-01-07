#ifndef _LAMPPOST_HPP_
#include <GL/glut.h>

#define _LAMPPOST_HPP_ 
#define RIGHT_SIDE 1
#define LEFT_SIDE 0

#include "GameSettings.hpp"

class Lamppost
{
public:
	Lamppost(int i);
	~Lamppost();
	void draw(float distance);
private:
	float _d;
	int _side;
	
};




#endif