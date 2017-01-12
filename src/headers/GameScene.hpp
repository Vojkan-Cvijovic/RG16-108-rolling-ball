#ifndef __GAMESCENE_HPP__
#define __GAMESCENE_HPP__
#include <GL/glut.h>
#include "Ball.hpp"
#include "Road.hpp"
#include "GameSettings.hpp"
#include <GL/freeglut.h>

extern Ball* userBall;
extern Road* userRoad;

class GameScene
{
public:
	GameScene(){
		speed = ROAD_BASE_SPEED;
	} 
	~GameScene(){}
	void run();
	void increaseSpeed();
	void decreaseSpeed();
	void restartSpeed();
	void moveLeft();
	void moveRight();
	void setDifficulty(int d){
		_difficulty = d;
	}
	void dayTime(int d){
		_daytime = d;
	}
private:
	int _difficulty = 1; // difficulty level, effects generation of holes
	int _daytime = 0;	//day or night
	float speed;	// speed of ball
	GLfloat light_position[4] = {0,0,0,1}; 	// position of Sun or headlight
	void light();
	void gameOver();
	void speedModify();
	void addFog();
	void print_score_value();
	void print_speed_value();
};

#endif 
