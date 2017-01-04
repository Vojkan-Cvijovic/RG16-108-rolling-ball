#ifndef __BALL_HPP__
#define __BALL_HPP__s
#include <GL/glut.h>
#include <iostream>

class Ball
{
public:
	Ball(){}
	~Ball();
	void moveLeft(int k) {x -= k;}
	void moveRight(int k){x += k;}
	void jump();
	void draw();

private:
	float size = 0.75;
	float weight = 1; // utice na skok
	float x = 0,y = -2;
	float rotationAngle = 0;
	bool isJumping = false;
	float gravity = 1.2;
	float yVel = 0;
};


#endif