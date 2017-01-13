#include <GL/glut.h>
#include "./headers/GameScene.hpp"
#include "./headers/GameSettings.hpp"
#include "./headers/MenuScene.hpp"
#include "./headers/OptionsScene.hpp"
#include <time.h>



Road* userRoad = nullptr;
Ball* userBall = nullptr;
GameScene* gameScene = nullptr;
MenuScene* menuScene = nullptr;
OptionsScene* optionsScene = nullptr;

unsigned int width = WINDOW_WIDTH_PIXELS; 
unsigned int height = WINDOW_HEIGHT_PIXELS;

unsigned int screenState = MENU_SCREEN_NUM; 

static void on_display();
static void on_reshape(int x, int y);
static void on_mouse();
static void on_keyboard(unsigned char key, int x, int y);
static void on_timer(int value);
static void SpecialInput(int key, int x, int y);
static void on_mouse(int button, int state, int x, int y);
static void on_motion(int x, int y);
static void initialize();
static void menu_finish(){ exit(0);}

int timer = 0;
float delta_t = 1.0/60;


int main(int argc, char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(width,height);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Rolling ball");

	glutKeyboardFunc(on_keyboard);
	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);
	glutMotionFunc(on_motion);
	glutMouseFunc(on_mouse);
	glutSpecialFunc(SpecialInput);
	//glutTimerFunc(50,on_timer,0);

	initialize();

	glutMainLoop();

    return 0;
}

static void initialize(void)
{
   	glClearColor(0, 0, 0, 0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // userBall = new Ball();
    // userRoad = new Road(-MAX_ROAD_WIDTH/2, 0, TRACK_LENGTH, DETAILS_LEVEL);
    gameScene = new GameScene();	
	menuScene = new MenuScene();
	optionsScene = new OptionsScene();
}



static void on_reshape(int x,int y){

	width = x;
	height = y;

	glViewport(0, 0, width, height);

	/* Podesava se projekcija */
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(VIEW_ANGLE, (float) width / height, FUSTRUM_NEAR, FUSTRUM_FAR);
}
static void on_keyboard(unsigned char key,int x, int y){
	switch(key){
		case 27:
			/*
				we need to know from where did we came
			*/
			if(screenState == MENU_SCREEN_NUM)
				menu_finish();
			if(screenState == OPTIONS_SCREEN_NUM){
				screenState = MENU_SCREEN_NUM;
				break;
			}
			delete userBall;
			delete userRoad;
			screenState = MENU_SCREEN_NUM;
			break;
		case 's':
			timer = 1;
			break;
		case 'p':
			timer = 0;
			break;
		case 32:
			if(screenState == GAME_SCREEN_NUM)
				userBall->jump();
			break;
		default:
			std::cout << "Unknown key " << key << std::endl;
	}
}
static void SpecialInput(int key, int x, int y){
// only active if we are in game, not menu or options
	switch(key){
		case GLUT_KEY_LEFT:
			if(screenState == GAME_SCREEN_NUM)
				gameScene->moveLeft();
			break;
		case GLUT_KEY_RIGHT:
			if(screenState == GAME_SCREEN_NUM)
				gameScene->moveRight();
			break;
		case GLUT_KEY_UP:
			if(screenState == GAME_SCREEN_NUM)
				gameScene->increaseSpeed();
			break;
		case GLUT_KEY_DOWN:
			if(screenState == GAME_SCREEN_NUM)
				gameScene->decreaseSpeed();
			break;
		}
}

static void on_timer(int value)
{

	if(value!=0)
		return;

	glutPostRedisplay();

}
static void on_display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch(screenState){
		case MENU_SCREEN_NUM:
			//cout << "Rendering game menu " << endl ;
			menuScene->draw();
			break;
		case GAME_SCREEN_NUM:
			if(userBall == nullptr){
				cout << "Loading ball" << endl;
				userBall = new Ball();
			}
			if(userRoad == nullptr){
				cout << "Loading road" << endl;
				userRoad = new Road(-MAX_ROAD_WIDTH/2, 0, TRACK_LENGTH, DETAILS_LEVEL,
					optionsScene->get_difficulty_option());
				userRoad->setDifficultyAndDaytime(	optionsScene->get_difficulty_option(),
												 	optionsScene->get_daytime_option());
			}
			//cout << "Starting game ... " << endl; 
			gameScene->run();
			break;
		case OPTIONS_SCREEN_NUM:
			//cout << "Rendering options screen" << endl;
			optionsScene->draw();
			break;
		case QUIT_MENU_NUM:
			cout << "Exiting menu " << endl;
			menu_finish();
			break;
	}

	if(!timer)
		glutTimerFunc(30,on_timer,0);

    /* Nova slika se salje na ekran. */
    glutSwapBuffers();
}
static void on_motion(int x, int y){}

static void on_mouse(int button, int state, int x, int y){
	if(screenState == MENU_SCREEN_NUM)
		menuScene->on_mouse(button,state,x,y);
	else if(screenState == OPTIONS_SCREEN_NUM)
		optionsScene->on_mouse(button,state,x,y);
}