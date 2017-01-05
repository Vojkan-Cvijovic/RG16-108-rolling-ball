#include "./headers/Ball.hpp"

extern float delta_t;

void Ball::jump(){
	if(isJumping == false){
		yVel =  2;
		isJumping = true;
		jumpTime = 0;
	}
	
}
void Ball::move(float m){
	if(isJumping)
		return;
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
float Ball::jumpVel(float surfaceLevel){
	if(isJumping){
		float new_y = y + 9*delta_t*yVel;
		yVel = yVel - delta_t*gravity;
		std::cout << new_y << std::endl;
		if(new_y < surfaceLevel){
			isJumping = false;
			return surfaceLevel;
		}
		return new_y;
	}
	return y;
}
void Ball::draw(float surfaceLevel){
	if(!isMoving())
		xVel = 0;
	else
		rotationAngleZ += xVel*1.2;
	x += xVel/120;

	if(isJumping)
		jumpTime += 1.0/60;

	y = jumpVel(surfaceLevel);

	float rotationSpeed = 4;

	glColor3f(1,0,0);
    glPushMatrix();
    	glTranslatef(x, y, z);
    	glRotatef(rotationAngleX,-1,0,0);
    	glRotatef(rotationAngleZ,0,0,1);
		/* Kreira se objekat. */
    	glColor3f(1, 0, 0);
    	glutWireSphere(size,10,10);
    glPopMatrix();
    rotationAngleX += rotationSpeed;
    if(rotationAngleX >= 360)
    	rotationAngleX = 0;

    xVel = xVel/1.1;



}



