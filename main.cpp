 #include <GL/glut.h>
#include "./headers/GameScene.hpp"
#include "./headers/Ball.hpp"

#define MENU_SCREEN_NUM 0
#define GAME_SCREEN_NUM 1
#define OPTIONS_SCREEN_NUM 2


Ball* userBall;
GameScene* gameScene;
unsigned int width,height;
unsigned char gameState = 1; /* podrazumevano je da smo u menu screen-u */
static void on_display();
static void on_reshape(int x, int y);
static void on_mouse();
static void on_keyboard(unsigned char key, int x, int y);
static void on_timer(int value);

int timer = 0;

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

    /* Obavlja se OpenGL inicijalizacija. */
	glClearColor(0,0,0,0);
	glEnable(GL_DEPTH_TEST);

	gameScene = new GameScene();
	userBall = new Ball();

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
    gluPerspective(30, (float) width / height, 1, 500);
}
static void on_keyboard(unsigned char key,int x, int y){
	/* U zavisnosti u kom je stanju igrica imamo razlicite komanda
	npr strelice ce biti aktivne dok u meniju nece */
	switch(key){
		case 27:
			exit(0); 
			break;
		case 'i':
			gameScene->increaseSpeed();
			break;
		case 'd':
			gameScene->decreaseSpeed();
			break;
		case 'r':
			gameScene->restartSpeed();
			break;
		case 's':
			if(!timer){
				glutTimerFunc(50,on_timer,0);
				timer = 1;
			}
			break;
		case 'p':
			timer = 0;
			break;

	}
	std::cout << "key is " << key << std::endl;

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
