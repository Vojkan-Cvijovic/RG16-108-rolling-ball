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

void GameScene::run(){

	/* Podesava se vidna tacka. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);


    glShadeModel (GL_SMOOTH);

    light();
    if(speed >= SPEED_LIMIT)
    	speed = SPEED_LIMIT;

    cout << "Speed : " << speed << endl;;
    userRoad->run(speed);

    userBall->run(speed, ROAD_BASE_LEVEL);
    
    //cout << "x " << userBall->getPositionX() << " | y " << userBall->getPositionY() << endl;
    if(speed > ROAD_BASE_SPEED && userBall->onGround())
    	speed = speed - SPEED_DECREASE;
    if(speed < ROAD_BASE_SPEED && userBall->onGround())
    	speed = speed + SPEED_DECREASE;

    // if(userRoad->fallThrough(userBall->getPositionX(),userBall->getPositionY()) ||
   	// 		(userBall->getPositionY() == ROAD_BASE_LEVEL && 
   	// 			abs(userBall->getPositionX()) > ROAD_BASE_WIDTH/2)){
    // 	userBall->drop();
    // 	speed = ROAD_BASE_SPEED;
    // }

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

