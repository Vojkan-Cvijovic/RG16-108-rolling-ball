#ifndef __GAMESCENE_HPP__
#define __GAMESCENE_HPP__
#include <GL/glut.h>
#include "Ball.hpp"
#include "Road.hpp"
#include "GameSettings.hpp"

#define SPEED_LIMIT 5.0
#define SPEED_DECREASE 0.02
#define ACCELERATION 0.05
#define GAME_OVER_FALL_LEVEL -10

class GameScene
{
public:
	GameScene(){
		speed = ROAD_BASE_SPEED;
	} 
	~GameScene();
	void run();
	void increaseSpeed();
	void decreaseSpeed();
	void restartSpeed();
	void moveLeft();
	void moveRight();
private:
	float speed;


};

#endif 
