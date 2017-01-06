#ifndef __GAMESCENE_HPP__
#define __GAMESCENE_HPP__
#include <GL/glut.h>
#include "Ball.hpp"
#include "Road.hpp"
#include "GameSettings.hpp"



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
