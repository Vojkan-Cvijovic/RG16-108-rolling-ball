#include "./headers/GameScene.hpp"
#include <iostream>


using namespace std;
#define MAX_ROAD_LEFT -5
#define MAX_ROAD_RIGHT 5
#define MAX_WIDTH 10

extern Ball* userBall;
extern Road* userRoad;

void GameScene::run(){

	/* Podesava se vidna tacka. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    cout << "Speed : " << speed << endl;;
    userRoad->run(speed);

    userBall->run(speed,-2	);
    //cout << "x " << userBall->getPositionX() << " | y " << userBall->getPositionY() << endl;
    if(speed > ROAD_BASE_SPEED)
    	speed = speed - SPEED_DECREASE;
    else
    	speed = speed + SPEED_DECREASE;
}
void GameScene::increaseSpeed(){
	if(speed <= SPEED_LIMIT)
		speed += ACCELERATION;
}
void GameScene::decreaseSpeed(){
	if(speed > 1)
		speed-= ACCELERATION;
}
void GameScene::moveLeft(){
	userBall->move(-speed);
}
void GameScene::moveRight(){
	userBall->move(+speed);
}

