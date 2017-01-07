#include "./headers/GameScene.hpp"
#include <iostream>

using namespace std;


extern Ball* userBall;
extern Road* userRoad;


void light(){
		/* Pozicija svetla (u pitanju je direkcionalno svetlo). */
    GLfloat light_position[] = { 0, 1, -1, 1 };

    /* Ambijentalna boja svetla. */
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1 };

    /* Difuzna boja svetla. */
    GLfloat light_diffuse[] = { 0.7, 0.7, 0.7, 1 };

    /* Spekularna boja svetla. */
    GLfloat light_specular[] = { 0.9, 0.9, 0.9, 1 };

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

}
/*


    glPushMatrix();
    	glTranslatef(0,3,2);

    glPushMatrix();

    	glColor3f(1, .5, .5); 
    	glTranslatef(1, -3, -3);
    	glScalef(1, 10, 1);
    	glutSolidCube(0.2);

    glPopMatrix();

    glPushMatrix();

    	glColor3f(1,.5,.5);
    	glTranslatef(0.4,-2,-3);
    	glScalef(7,1,1);
    	glRotatef(90,0,0,1);
    	glutSolidCube(0.2);

    glPopMatrix();
    glPopMatrix();




*/
float d = -15;
float angle = 0;
void GameScene::run(){

	/* Podesava se vidna tacka. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

glPushMatrix();
	glColor3f(0.8,0.8,0.8);
	//glRotatef(angle,0,1,0);
	glTranslatef(-ROAD_BASE_WIDTH/2 + 0.5,-0.3,d);
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

	d += 0.2;
	angle += 0.6;

glPopMatrix();

/*
    glShadeModel (GL_SMOOTH);

    light();
    if(speed >= SPEED_LIMIT)
    	speed = SPEED_LIMIT;

    */cout << "Speed : " << speed << endl;;
    userRoad->run(speed);

   // userBall->run(speed, ROAD_BASE_LEVEL);
  /*  
    //cout << "x " << userBall->getPositionX() << " | y " << userBall->getPositionY() << endl;
    if(speed > ROAD_BASE_SPEED && userBall->onGround())
    	speed = speed - SPEED_DECREASE;
    if(speed < ROAD_BASE_SPEED && userBall->onGround())
    	speed = speed + SPEED_DECREASE;

    if(userRoad->fallThrough(userBall->getPositionX(),userBall->getPositionY()) ||
   			(userBall->getPositionY() == ROAD_BASE_LEVEL && 
   				abs(userBall->getPositionX()) > ROAD_BASE_WIDTH/2)){
    	userBall->drop();
    	speed = ROAD_BASE_SPEED;
    }

    if(userBall->getPositionY() < GAME_OVER_FALL_LEVEL ){
    	
    	cout << "-------------------" <<endl;
    	cout << "GAME OVER" << endl;
    	cout << "Your distance is : " << userRoad->getDistance() << endl;
    	cout << "-------------------" <<endl;
    	exit(0);
    }
    
    if(userRoad->getDistance() >= (TRACK_LENGTH * 4)-1){
    	cout << "-------------------" <<endl;
    	cout << "VICTORY " << endl;
    	cout << "Your distance is : " << userRoad->getDistance() << endl;
    	cout << "-------------------" <<endl;
    	exit(0);
    }
*/    
}

void GameScene::increaseSpeed(){
	if(speed <= SPEED_LIMIT && userBall->onGround())
		speed += ACCELERATION;
}
void GameScene::decreaseSpeed(){
	if(speed > 1 && userBall->onGround())
		speed-= ACCELERATION;
}
void GameScene::moveLeft(){
	userBall->move(-speed);
}
void GameScene::moveRight(){
	userBall->move(+speed);
}

