#include <GL/glut.h>
#include "./headers/MenuWindow.hpp"

MenuWindow* menuWindow;

int main(int argc, char **argv){
 
	menuWindow = new MenuWindow(&argc,argv);

	menuWindow->show();

}