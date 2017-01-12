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
	~Ball(){}
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
	bool onGround(){return !isJumping;}
private:
	float size = 0.75;		// balls size
	float weight = 1; 	// balls weight
	float x = 0,y = -2,z= GENERATION_BASE;	// balls position 
	float rotationAngleX = 0;	// rotation around x-axes
	float rotationAngleZ = 0;	// rotation around z-axes
	bool isJumping = false;
	float gravity = 7;
	float yVel = 0; // uses for jump
	float xVel = 0; // uses for move
	float jumpVel(float surfaceLevel);
	void falling();
	int fall = 0; // falling indicator

    GLfloat _ambient_coeffs[4] = { 0.1, 0.1, 0.1, 1 };
	GLfloat _diffuse_coeffs[4] = { 0.9, 0.1, 0.1, 1 };
    GLfloat _specular_coeffs[4] = { 0.9, 0.9, 0.9, 1 };
    GLfloat _shininess = 60;
};


#endif