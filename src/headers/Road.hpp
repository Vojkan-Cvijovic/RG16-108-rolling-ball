#ifndef __ROAD_HPP__
#define __ROAD_HPP__
#include <iostream>
#include <vector>
#include "Plate.hpp"
#include "GameSettings.hpp"
#include "Lamppost.hpp"

#include <cmath>
#include <random>

using namespace std;

class Road
{
public:
	Road(float x, float y,int length,int density,int difficulty);
	~Road();
	void draw();
	float getDistance(){return distance + 4;}
	void run(float speed);
	void generate(int i, int j);
	bool fallThrough(float x,int y);
	void setDifficultyAndDaytime(int difficulty,int daytime){
		_difficulty = difficulty;
		_daytime = daytime;
	}
private:
	Road(const Road& r);
	Road& operator=(const Road& z);
	Plate*** _surface;
	Lamppost** _streetLights;
	int _length;
	float _x,_y;
	int level; // how much of area is generated
	float distance; 
	int reachedLevel;
	float flyAwayDistance;
	int capatacy;
	int _lamppostCount;
	int _currentLevel;
	int _n;	// number of generated road plates
	int _difficulty = 1;
	int _daytime;
};


#endif

