#ifndef __BALL_HPP__
#define __BALL_HPP__
#include <GL/glut.h>
#include "GameSettings.hpp"
#include <iostream>
#include <cmath>

using namespace std;

class Ball
{
public:
	Ball(){}
	~Ball();
	void move(float m);
	void jump();
	void draw(float speed,float surfaceLevel);
	bool isMoving();
	void run(float speed,float surfaceLevel);
	float getPositionX(){ return x;}
	float getPositionY(){ return y;}
	void speedUp();
	void slowDown();
	void drop(){fall = 1;}
private:
	float size = 0.75;
	float weight = 1; // affects jump
	float x = 0,y = -2,z=-2.5;
	float rotationAngleX = 0;
	float rotationAngleZ = 0;
	bool isJumping = false;
	float gravity = 7;
	float yVel = 0; // uses for jump
	float xVel = 0; // uses for move
	float jumpVel(float surfaceLevel);
	void falling();
	int fall = 0;
};


#endif