#include "./headers/Ball.hpp"


void Ball::jump(){
	if(isJumping == false){
		yVel =  10;
		isJumping = true;
	}
}

void Ball::draw(){
	float rotationSpeed = 1;

	glColor3f(1,0,0);
    glPushMatrix();
    	glTranslatef(x, y,-10);
    	glRotatef(rotationAngle,-1,0,0);
    	//
		/* Kreira se objekat. */
    	glColor3f(1, 0, 0);
    	glutWireSphere(size,10,10);
    glPopMatrix();
    rotationAngle += rotationSpeed;
    if(rotationAngle >= 360)
    	rotationAngle = 0;
}



