#ifndef __GAMESCENE_HPP__
#define __GAMESCENE_HPP__
#include <GL/glut.h>

class GameScene
{
public:
	GameScene(){} // ovde dodajemo naziv igraca i tezinu igrice i ...
	~GameScene();
	void run();
	void increaseSpeed(){ speed += 0.1;}
	void decreaseSpeed(){ speed -= 0.1;}
	void restartSpeed(){ speed =2;}
private:
	float speed = 2;	
};

#endif 
