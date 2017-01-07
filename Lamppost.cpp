#include "./headers/Lamppost.hpp"

Lamppost::Lamppost(int i){
	if(i%2 == 0)
		_side = RIGHT_SIDE;
	else
		_side = LEFT_SIDE;
	_d = (i + 1) * LAMPPOST_FREQUENCY * PLATE_BASE_LENGTH;
}

void Lamppost::draw(float distance){
	
	glPushMatrix();
		glColor3f(0.8,0.8,0.8);
		glTranslatef(0,0,distance);
		glTranslatef((ROAD_BASE_WIDTH-0.2)*_side,0,0);		
		glTranslatef(-ROAD_BASE_WIDTH/2 + 0.5,-1.0,-_d);
		glRotatef(_side*180,0,1,0);
		// pole
		glPushMatrix();
			glTranslatef(0,1,0);
			glScalef(1,30,1);
			
			glutSolidCube(0.2);
		glPopMatrix();
		// neck
		glPushMatrix();
			glTranslatef(0.4,4,0);
			glScalef(5,1,1);
	
			glutSolidCube(0.2);
		glPopMatrix();
		
		// base
		glPushMatrix();
			glTranslatef(0,-2,0);
			glScalef(4,1,4);
		
			glutSolidCube(0.2);
		glPopMatrix();
		// head
		glPushMatrix();
			glColor3f(1,1,0.3);
			glTranslatef(1.3,4,0);
			glScalef(4,1,3);
	
			glutSolidCube(0.2);
		glPopMatrix();
	
	glPopMatrix();
}