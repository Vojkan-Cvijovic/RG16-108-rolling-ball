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
	int _difficulty = 1;
	int _daytime = 0;
	float speed;
	void light();
	void gameOver();
	void speedModify();
	void addFog();
	void print_score_value();
	void print_speed_value();
};

#endif 
