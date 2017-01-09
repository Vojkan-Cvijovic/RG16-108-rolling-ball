#include <GL/glut.h>
#include "./headers/GameScene.hpp"
#include "./headers/GameSettings.hpp"
#include "./headers/MenuScene.hpp"
#include <time.h>



Road* userRoad;
Ball* userBall;
GameScene* gameScene;
MenuScene* menuScene;

unsigned int width = WINDOW_WIDTH_PIXELS;
unsigned int height = WINDOW_HEIGHT_PIXELS;
unsigned char gameState = 0; /* podrazumevano je da smo u menu screen-u */

static void on_display();
static void on_reshape(int x, int y);
static void on_mouse();
static void on_keyboard(unsigned char key, int x, int y);
static void on_timer(int value);
static void SpecialInput(int key, int x, int y);
static void on_mouse(int button, int state, int x, int y);
static void on_motion(int x, int y);
static void initialize();

int timer = 0;
float delta_t = 1.0/60;


int main(int argc, char** argv){

	/* Inicijalizuje se GLUT. */
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    /* Kreira se prozor. */
	glutInitWindowSize(width,height);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Rolling ball");

    /* Registruju se callback funkcije. */
	glutKeyboardFunc(on_keyboard);
	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);
	glutMotionFunc(on_motion);
	glutMouseFunc(on_mouse);
	glutSpecialFunc(SpecialInput);

	
	initialize();

    /* Program ulazi u glavnu petlju. */
	glutMainLoop();

    return 0;
}

static void initialize(void)
{
   	glClearColor(0, 0, 0, 0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gameScene = new GameScene();
	userBall = new Ball();
	userRoad = new Road(-MAX_ROAD_WIDTH/2, 0, TRACK_LENGTH, DETAILS_LEVEL);
	menuScene = new MenuScene();
}



static void on_reshape(int x,int y){

	width = x;
	height = y;
	menuScene->setWidthAndHeight(x,y);

	glViewport(0, 0, width, height);

	/* Podesava se projekcija */
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(VIEW_ANGLE, (float) width / height, FUSTRUM_NEAR, FUSTRUM_FAR);
}
static void on_keyboard(unsigned char key,int x, int y){
	/* U zavisnosti u kom je stanju igrica imamo razlicite komanda
	npr strelice ce biti aktivne dok u meniju nece */
	switch(key){
		case 27:
			exit(0); 
			break;
		case 's':
			if(!timer){
				glutTimerFunc(50,on_timer,0);
				timer = 1;
			}
			break;
		case 'q':
			userBall->drop();

			break;
		case 'p':
			timer = 0;
			break;
		case 32:
			userBall->jump();
			break;
		default:
			std::cout << "Unknown key " << key << std::endl;
	}
}
static void SpecialInput(int key, int x, int y){

	switch(key){
		case GLUT_KEY_LEFT:
			gameScene->moveLeft();
			break;
		case GLUT_KEY_RIGHT:
			gameScene->moveRight();
			break;
		case GLUT_KEY_UP:
			gameScene->increaseSpeed();
			break;
		case GLUT_KEY_DOWN:
			gameScene->decreaseSpeed();
			break;
		}
}

static void on_timer(int value)
{
	if(value!=0)
		return;

	glutPostRedisplay();

	if(timer)
		glutTimerFunc(50,on_timer,0);
}
static void on_display(){
	/* Moramo da znamo u kom smo prozoru da bi znali sta da prikazemo*/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	switch(gameState){
		case MENU_SCREEN_NUM:
			menuScene->draw();
			break;
		case GAME_SCREEN_NUM:
			gameScene->run();
			break;
		case OPTIONS_SCREEN_NUM:
			menuScene->drawOptionScreen();
			break;
	}

    /* Nova slika se salje na ekran. */
    glutSwapBuffers();

}
static void on_motion(int x, int y){}

static void on_mouse(int button, int state, int x, int y){
	menuScene->on_mouse(button,state,x,y);
}