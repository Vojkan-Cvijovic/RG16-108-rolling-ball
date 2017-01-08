 #include <GL/glut.h>
#include "./headers/GameScene.hpp"
#include "./headers/GameSettings.hpp"



Road* userRoad;
Ball* userBall;
GameScene* gameScene;
unsigned int width,height;
unsigned char gameState = 1; /* podrazumevano je da smo u menu screen-u */

static void on_display();
static void on_reshape(int x, int y);
static void on_mouse();
static void on_keyboard(unsigned char key, int x, int y);
static void on_timer(int value);
static void SpecialInput(int key, int x, int y);
int timer = 0;
float delta_t = 1.0/60;


int main(int argc, char** argv){

	/* Inicijalizuje se GLUT. */
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    /* Kreira se prozor. */
	glutInitWindowSize(720,540);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Rolling ball");

    /* Registruju se callback funkcije. */
	glutKeyboardFunc(on_keyboard);
	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);
	glutSpecialFunc(SpecialInput);

    /* Obavlja se OpenGL inicijalizacija. */
	glClearColor(0,0,0,0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);

	gameScene = new GameScene();
	userBall = new Ball();
	userRoad = new Road(-MAX_ROAD_WIDTH/2, 0, TRACK_LENGTH, DETAILS_LEVEL);
    /* Program ulazi u glavnu petlju. */
	glutMainLoop();

    return 0;
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
			break;
		case GAME_SCREEN_NUM:
			gameScene->run();
			break;
		case OPTIONS_SCREEN_NUM:
			break;
	}

    /* Nova slika se salje na ekran. */
    glutSwapBuffers();

}