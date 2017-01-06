#ifndef __ROAD_HPP__
#define __ROAD_HPP__
#include <iostream>
#include <vector>
#include "Plate.hpp"
#include <cmath>
#define ROAD_BASE_SPEED 2.0
#define ROAD_BASE_LEVEL -2
#define ROAD_BASE_WIDTH 10

#define PLATE_COUNT 5
using namespace std;


class Road
{
public:
	Road(float x, float y,int length,int density);
	~Road();
	void draw();
	float getDistance(){return distance + 4;}
	void run(float speed);
	void generate();
private:
	Road(const Road& r);
	Road& operator=(const Road& z);
	Plate*** _surface;
	int _length;
	float _x,_y;
	int level; // how much of area is generated
	float distance;
	int reachedLevel;
	float flyAwayDistance;
	int capatacy;

};


#endif



/*
110011	.
000000	.	
101011	z=6 * length
001010	z=5	* length
001100	z=4 * length
010010	z=3 * length
010101	z=2	* length
010111	z=1	* length
------
 BALL	z=BALL.z
*/
