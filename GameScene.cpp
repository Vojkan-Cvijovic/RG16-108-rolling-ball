#include "./headers/GameScene.hpp"
#include <iostream>

using namespace std;


extern Ball* userBall;
extern Road* userRoad;


void drawSquare(){

	glPushMatrix();
		glColor3f(1,0,0);
		glTranslatef(ROAD_BASE_WIDTH/2-0.8,2.7,-4);
		glutSolidCube(0.2);
	glPopMatrix();


}

void light(){
	
    GLfloat light_position[] = { 0, 0, -1, 1 };

    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1 };

    GLfloat light_diffuse[] = { 0.7, 0.7, 0.7, 1 };

    GLfloat light_specular[] = { 0.9, 0.9, 0.9, 1 };

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

}
void GameScene::addFog(){
	glEnable(GL_FOG);
	GLfloat fogColor[] = {0,0,0,1};
	glFogi(GL_FOG_MODE,GL_EXP2);
	glFogf(GL_FOG_DENSITY,0.02f);
}
void GameScene::run(){

	
	/* Podesava se vidna tacka. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    glShadeModel (GL_SMOOTH);
    addFog();
    light();
     if(speed >= SPEED_LIMIT)
     	speed = SPEED_LIMIT;

     userRoad->run(speed);


     userBall->run(speed, ROAD_BASE_LEVEL);
    
     speedModify();
     gameOver();
     //print_score_value();
    //print_speed_value();         
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
void GameScene::speedModify(){
	if(speed > ROAD_BASE_SPEED && userBall->onGround())
    	speed = speed - SPEED_DECREASE;
    if(speed < ROAD_BASE_SPEED && userBall->onGround())
    	speed = speed + SPEED_DECREASE;
}
void GameScene::gameOver(){

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
   
}
void GameScene::print_score_value(){
    
   /* Rezultat prebacujemo u bafer koji cemo ispisivati. */
   char buff[15];
   snprintf(buff, 10, "Score:%d",(int) userRoad->getDistance()-1);
   glColor3f(1, 1.0, 0.0);
   glRasterPos3f(-6, 4, -5);
   glutBitmapString((void*) GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) buff);

}
void GameScene::print_speed_value(){
    
   /* Rezultat prebacujemo u bafer koji cemo ispisivati. */
   char buff[20];
   snprintf(buff, 10, "Speed: %d", (int) speed);
   glColor3f(1, 1.0, 0);
   glRasterPos3f(4, 4, -5);
   glutBitmapString((void*) GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) buff);

}

