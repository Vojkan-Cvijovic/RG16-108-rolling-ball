#ifndef __ROAD_HPP__
#define __ROAD_HPP__
#include <iostream>
#include <vector>
#include "Plate.hpp"

#define PLATE_COUNT 5
using namespace std;


class Road
{
public:
	Road(float x, float y,int length,int density);
	~Road();
	void draw();
private:
Road(const Road& r);
Road& operator=(const Road& z);
Plate*** _surface; 
int _length;
float _x,_y;
int level; // how much of area is generated
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
