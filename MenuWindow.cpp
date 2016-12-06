#include "./headers/MenuWindow.hpp"
#define MENU_OPTION_NUM 3
#define MENU_OPTION_WIDTH 0.5
#define MENU_OPTION_HEIGHT 0.17
#define MENU_OPTION_SPACING 0.1

int window_height = 600;
int window_width = 900;

void draw_rectangular(double x, double y){
	glBegin(GL_POLYGON);
		glVertex2f(x  					, y 					);
		glVertex2f(x+MENU_OPTION_WIDTH	, y 					);
		glVertex2f(x+MENU_OPTION_WIDTH	, y+MENU_OPTION_HEIGHT	);
		glVertex2f(x  					, y+MENU_OPTION_HEIGHT	);
	glEnd();
}

void on_display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.2,0.2,0.2);
	int i;
	double xPos = -0.25;
	double yPos = 0.1;
	for(i=0;i<MENU_OPTION_NUM; i++){
		draw_rectangular(xPos,yPos);
		yPos -= MENU_OPTION_HEIGHT + MENU_OPTION_SPACING;
	}

	glutSwapBuffers();
}
void on_reshape(int w, int h){
	window_width = w;
	window_height = h;
	glViewport(0,0,window_width,window_height);
}
void on_keyboard(unsigned char key,int x, int y){
	switch(key){
		case 27:
			exit(0);
			break;
	}
}
void MenuWindow::show(){
	glutCreateWindow("Rolling ball");

	/* registruju se callback funkcije */
	glutKeyboardFunc(on_keyboard);
	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);
	glutIdleFunc(on_display);

	// obavlja se openGl inicijalizacija
	glClearColor(0.9,0.9,0.9,0);
	glEnable(GL_DEPTH_TEST);
	glLineWidth(2);

	glutMainLoop();
}
MenuWindow::MenuWindow(int* argc,char** argv){
	glutInit(argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(window_width,window_height);
	glutInitWindowPosition(200,100);
}


