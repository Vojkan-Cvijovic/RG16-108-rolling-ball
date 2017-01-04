#include "./headers/Ball.hpp"


void Ball::jump(){
	if(isJumping == false){
		yVel =  10;
		isJumping = true;
	}
}
void Ball::move(float m){
	if(m>0)
		xVel = -15;
	else
		xVel = 15;
}
bool Ball::isMoving(){
	if(abs(xVel) < 0.005)
		return false;
	return true;
}
void Ball::draw(){
	if(!isMoving())
		xVel = 0;
	else
		rotationAngleZ += xVel*1.2;
	x += xVel/120;
	float rotationSpeed = 4;

	glColor3f(1,0,0);
    glPushMatrix();
    	glTranslatef(x, y, z);
    	glRotatef(rotationAngleX,-1,0,0);
    	glRotatef(rotationAngleZ,0,0,1);
    	//
		/* Kreira se objekat. */
    	glColor3f(1, 0, 0);
    	glutWireSphere(size,10,10);
    glPopMatrix();
    rotationAngleX += rotationSpeed;
    if(rotationAngleX >= 360)
    	rotationAngleX = 0;

    xVel = xVel/1.1;
}



