#ifndef __BALL_HPP__
#define __BALL_HPP__
#include <GL/glut.h>
#include <iostream>
#include <cmath>
class Ball
{
public:
	Ball(){}
	~Ball();
	void move(float m);
	void jump();
	void draw(float surfaceLevel);
	bool isMoving();
private:
	float size = 0.75;
	float weight = 1; // affects jump
	float x = 0,y = -2,z=-4;
	float rotationAngleX = 0;
	float rotationAngleZ = 0;
	bool isJumping = false;
	float gravity = 7;
	float yVel = 0; // uses for jump
	float xVel = 0; // uses for move
	float jumpVel(float surfaceLevel);
	float jumpTime = 0;
};


#endif