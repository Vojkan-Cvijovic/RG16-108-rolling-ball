#include "./headers/GameScene.hpp"
#include <iostream>

using namespace std;

void GameScene::light(){

  /* if day option is turned on, light() simulates Sun 
     if night options is turned on, light() simulates headlight */ 
	  
    if(_daytime == 0){
      light_position[0] = 1;
      light_position[1] = 1;
      light_position[2] = 1;
      light_position[3] = 0;
    }
    else{
      light_position[0] = 0;
      light_position[1] = 0;
      light_position[2] = -1;
      light_position[3] = 1;  
    }
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1 };

    GLfloat light_diffuse[] = { 0.7, 0.7, 0.7, 1 };

    GLfloat light_specular[] = { 0.9, 0.9, 0.9, 1 };

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

}
void GameScene::addFog(){
	glEnable(GL_FOG);
	GLfloat fogColor[] = {0,0,0,1};
	glFogi(GL_FOG_MODE,GL_EXP2);
	glFogf(GL_FOG_DENSITY,0.02f);
}
void GameScene::run(){
    
    glPushMatrix();
    
    glEnable(GL_LIGHTING);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    glShadeModel (GL_SMOOTH);
    addFog();
    light();
     if(speed >= SPEED_LIMIT)
     	speed = SPEED_LIMIT;

     // draw road with street lights
     userRoad->run(speed);
     // draw ball
     userBall->run(speed, ROAD_BASE_LEVEL);
    
     speedModify();
     gameOver();

     // currently disable, printing text while rendering road and ball have huge impact on performance
     //print_score_value();
    //print_speed_value();  
    cout << "Distance : "<< userRoad->getDistance() << endl;
    cout << "Speed: " << speed << endl;
    glPopMatrix();       
}

void GameScene::increaseSpeed(){
	if(speed <= SPEED_LIMIT && userBall->onGround())
		speed += ACCELERATION;
}
void GameScene::decreaseSpeed(){
	if(speed > 1 && userBall->onGround())
		speed-= ACCELERATION;
}
void GameScene::moveLeft(){
	userBall->move(-speed);
}
void GameScene::moveRight(){
	userBall->move(+speed);
}
void GameScene::speedModify(){

  /* in order to speed up or slow down 
      ball needs to be in contact with surrface 

      You can break which will cause speed modification up to -1
      but as sonn as you release slow down button ball will speed up */


	if(speed > ROAD_BASE_SPEED && userBall->onGround())
    	speed = speed - SPEED_DECREASE;
    if(speed < ROAD_BASE_SPEED && userBall->onGround())
    	speed = speed + SPEED_DECREASE;
}
void GameScene::gameOver(){

  /* check for condtions for game to be over */


	if(userRoad->fallThrough(userBall->getPositionX(),userBall->getPositionY()) ||
   			(userBall->getPositionY() == ROAD_BASE_LEVEL && 
   				abs(userBall->getPositionX()) > ROAD_BASE_WIDTH/2)){
    	userBall->drop();
    	speed = ROAD_BASE_SPEED;
    }

    // we are not ending game as soon as ball start falling
    // but as it reaches curtain level

    if(userBall->getPositionY() < GAME_OVER_FALL_LEVEL ){
    	
    	cout << "-------------------" <<endl;
    	cout << "GAME OVER" << endl;
    	cout << "Your distance is : " << userRoad->getDistance() << endl;
    	cout << "-------------------" <<endl;
    	exit(0);
    }

    // if we have reached end of track
    
    if(userRoad->getDistance() >= (TRACK_LENGTH * 4)-1){
    	cout << "-------------------" <<endl;
    	cout << "VICTORY " << endl;
    	cout << "Your distance is : " << userRoad->getDistance() << endl;
    	cout << "-------------------" <<endl;
    	exit(0);
    }
   
}
void GameScene::print_score_value(){
    
   char buff[15];
   snprintf(buff, 10, "Score:%d",(int) userRoad->getDistance()-1);
   //glColor3f(1, 1.0, 0.0);
   glRasterPos3f(-6, 4, -5);
   glutBitmapString((void*) GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) buff);

}
void GameScene::print_speed_value(){
    
   char buff[20];
   snprintf(buff, 10, "Speed: %d", (int) speed);
   //glColor3f(1, 1.0, 0);
   glRasterPos3f(4, 4, -5);
   glutBitmapString((void*) GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) buff);

}

