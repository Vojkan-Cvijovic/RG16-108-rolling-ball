#include "./headers/Lamppost.hpp"

Lamppost::Lamppost(int lampostNumber){

	/* lampostNumber is number of this lamp post which is given by userRoad
		so that each lampost would know if it is left side 
		or right side lamp post
		*/

	if(lampostNumber%2 == 0)
		_side = RIGHT_SIDE;
	else
		_side = LEFT_SIDE;

	// distance
	_d = (lampostNumber + 1) * LAMPPOST_FREQUENCY * PLATE_BASE_LENGTH;
	
	// light bolb
	_bolb = new Light(-_d,lampostNumber);
}
void Lamppost::paint(int pole){

	/* adding color of material to curtain part of lamp post
		if pole is 0 than it should be yellow */ 

	if(pole){
		glMaterialfv(GL_FRONT, GL_AMBIENT, _ambient_coeffs);
    	glMaterialfv(GL_FRONT, GL_DIFFUSE, _diffuse_coeffs);
  	}else{
  		glMaterialfv(GL_FRONT, GL_AMBIENT, _ambient_coeffs_bolb);
    	glMaterialfv(GL_FRONT, GL_DIFFUSE, _diffuse_coeffs_bolb);
  	}

  	glMaterialfv(GL_FRONT, GL_SPECULAR, _specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, _shininess);
}
void Lamppost::draw(float distance){

	if(_daytime == 1){
		_bolb->draw(distance);
	}
	glPushMatrix();
		//glColor3f(0.8,0.8,0.8);
		glTranslatef(0,0,distance);
		glTranslatef((ROAD_BASE_WIDTH + 1)*_side,0,0);		
		glTranslatef(-ROAD_BASE_WIDTH/2 - 0.5,-1.0,-_d);
		glRotatef(_side*180,0,1,0);
		
		// drawing pole
		glPushMatrix();
			paint(1);
			glTranslatef(0,1,0);
			glScalef(1,30,1);
			glutSolidCube(0.2);
		glPopMatrix();
		
		// drawing neck
		glPushMatrix();
			paint(1);
			glTranslatef(0.4,4,0);
			glScalef(5,1,1);
			glutSolidCube(0.2);
		glPopMatrix();
		
		// drawing base
		glPushMatrix();
			paint(1);
			glTranslatef(0,-2,0);
			glScalef(4,1,4);
			glutSolidCube(0.2);
		glPopMatrix();
		// drawing head
		glPushMatrix();
			paint(0);
			glColor3f(1,1,0.3);
			glTranslatef(1.3,4,0);
			glScalef(4,1,3);
	
			glutSolidCube(0.2);
		glPopMatrix();
	
	glPopMatrix();
}