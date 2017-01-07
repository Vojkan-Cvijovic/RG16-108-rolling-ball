#include "./headers/Ball.hpp"

extern float delta_t;

void Ball::jump(){
	if(isJumping == false){
		yVel =  2;
		isJumping = true;
	}
	
}
void Ball::move(float speed){
	if(isJumping)
		xVel = 3*speed;
	else
		xVel = 7*speed;

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
		
		if(new_y < surfaceLevel){
			isJumping = false;
			return surfaceLevel;
		}
		return new_y;
	}
	return y;
}
void Ball::falling(){
	y -= pow(-y,abs(y)/(gravity))/gravity;
}
void Ball::draw(float speed,float surfaceLevel){
	if(!isMoving()) // steering
		rotationAngleZ += xVel*1.2;
	
	x += xVel/120;

	y = jumpVel(surfaceLevel);

	float rotationSpeed = 5*speed;

	glMaterialfv(GL_FRONT, GL_AMBIENT, _ambient_coeffs);
 	glMaterialfv(GL_FRONT, GL_DIFFUSE, _diffuse_coeffs);
   	glMaterialfv(GL_FRONT, GL_SPECULAR, _specular_coeffs);
   	glMaterialf(GL_FRONT, GL_SHININESS, _shininess);


    glPushMatrix();
    	if(fall)
    		falling();
    	glTranslatef(x, y, z);
    	glRotatef(rotationAngleX,-1,0,0);
    	glRotatef(rotationAngleZ,0,0,1);
		/* Kreira se objekat. */
    	
    	glutSolidSphere(size,40,40);
    glPopMatrix();
    rotationAngleX += 5*rotationSpeed;
    if(rotationAngleX >= 360)
    	rotationAngleX = 0;

    xVel = xVel/1.1;

}
void Ball::run(float speed,float surfaceLevel){

	draw(speed,surfaceLevel);

}


