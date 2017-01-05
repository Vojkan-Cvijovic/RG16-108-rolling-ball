#include "./headers/GameScene.hpp"
#include <iostream>


using namespace std;
#define MAX_ROAD_LEFT -5
#define MAX_ROAD_RIGHT 5
#define MAX_WIDTH 10

extern Ball* userBall;
extern Road* userRoad;

int k =1;
float road_speed = 0.1;
float angle = 0;
// /* n je koliko polja vidimo u daljinu a m je koliko je detaljan put */ 
// void draw_road(int n,int m){
// 	int i,j;
// 	int length = 4;
// 	float width = (float)MAX_WIDTH/m; 
// 	float x0 = -5, x1 = x0 + width;
// 	float z0 = 5,z1 = z0-length;
// 	float color=1;
	

// 	for(i=1;i<=n;i++){
// 		for (j = 0; j <= m; j++){
// 			if(color > 1)
// 				color = 0.1;
// 			glColor3f(color,color,color);
// 			glPushMatrix();
//     			glTranslatef(0,-3,-1*(10));
//     			glBegin(GL_POLYGON);
//     				glVertex3f(x0,0,z0 - road_speed);
//     				glVertex3f(x0,0,z1 - road_speed);
//     				glVertex3f(x1,0,z1 - road_speed);
//     				glVertex3f(x1,0,z0 - road_speed);
//     			glEnd();
//     		glPopMatrix();
//     		color += 0.4;

//     		x0 = x1;
//     		x1 = x0+width;
// 	    }
// 	    x0 = -5;
// 	    x1 = x0+width;
// 	    z0 = z1;
// 	    z1 = z0-length;

// 	}
// }	

void GameScene::run(){

	/* Podesava se vidna tacka. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    angle = angle + speed ;
    if(angle >= 360)
    	angle = 0;
    //draw_road(100,10);
		glPushMatrix();
    		glTranslatef(0,-3,-2);
    		userRoad->draw();
    	glPopMatrix();
    
    userBall->draw(-2);

    k+=1;
    road_speed-=0.1;

}

