#include "./headers/MenuScene.hpp"

MenuScene::MenuScene()
	:_width(WINDOW_WIDTH_PIXELS),_height(WINDOW_HEIGHT_PIXELS)
	{
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	_image = image_init(0, 0);

    glGenTextures(2, _names);

    /* Kreira se prva tekstura. */
    image_read(_image, FILENAME0);

    glBindTexture(GL_TEXTURE_2D, _names[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 _image->width, _image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, _image->pixels);

    /* Kreira se druga tekstura. */
    image_read(_image, FILENAME1);

    glBindTexture(GL_TEXTURE_2D, _names[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 _image->width, _image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, _image->pixels);

    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Unistava se objekat za citanje tekstura iz fajla. */
    image_done(_image);


}

void MenuScene::draw(){

	
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 7, 0, 0, 0, 0, 1, 0);

    glPushMatrix();
   		glTranslatef(-12, -8, -4.5);

    	glBindTexture(GL_TEXTURE_2D, _names[1]);
    	glBegin(GL_QUADS);
	    	    glNormal3f(0, 0, 1);
	
	    	    glTexCoord2f(0, 0);
	    	    glVertex3f(0, 0, 0);
	
	    	    glTexCoord2f(24, 0);
	 			glVertex3f(24, 0, 0);
	
	    	    glTexCoord2f(24, 16);
	   			glVertex3f(24,16, 0);
	
	    	    glTexCoord2f(0, 16);
				glVertex3f(0, 16, 0);
	    	glEnd();
	
    	/* Iskljucujemo aktivnu teksturu */
    	glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
    
    glBindTexture(GL_TEXTURE_2D,_names[0]);

    float x = 1.8;
    float y = 0.4;


    glTranslatef(0,0.3,-0.1);
    glColor3f(0.1,1,0);
    glBegin(GL_QUADS);
    	glNormal3f(0,0,1);

    	glTexCoord2f(-x, -y);
	   	glVertex3f(-x, -y, 0);    	  
	   	
	   	glTexCoord2f(-x, y); 	
	   	glVertex3f(-x, y, 0);    	  
	   	
	   	glTexCoord2f(x, y);   	
	   	glVertex3f(x, y, 0);
	    
	    glTexCoord2f(x, -y);
		glVertex3f(x, -y, 0);
	glEnd();
	
	glTranslatef(0,-1.3,0);
    
    glBegin(GL_QUADS);
    	glNormal3f(0,0,1);

    	glTexCoord2f(-x, -y);
	   	glVertex3f(-x, -y, 0);    	  
	   	
	   	glTexCoord2f(-x, y); 	
	   	glVertex3f(-x, y, 0);    	  
	   	
	   	glTexCoord2f(x, y);   	
	   	glVertex3f(x, y, 0);
	    
	    glTexCoord2f(x, -y);
		glVertex3f(x, -y, 0);
	glEnd();

	glTranslatef(0,-1.3,0);

    glBegin(GL_QUADS);
    	glNormal3f(0,0,1);

    	glTexCoord2f(-x, -y);
	   	glVertex3f(-x, -y, 0);    	  
	   	
	   	glTexCoord2f(-x, y); 	
	   	glVertex3f(-x, y, 0);    	  
	   	
	   	glTexCoord2f(x, y);   	
	   	glVertex3f(x, y, 0);
	    
	    glTexCoord2f(x, -y);
		glVertex3f(x, -y, 0);
	glEnd();	

	glBindTexture(GL_TEXTURE_2D, 0);

}
void MenuScene::drawOptionScreen(){

}
void MenuScene::draw_text(char* text,float x,float y){

	glColor3f(1.0, 1.0, 1.0);
   	glRasterPos3f(x, y, -3);
   	glutBitmapString((void*) GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) text);

}

void MenuScene::on_mouse(int button, int state, int x, int y){
cout << " X: " << x << " | y: " << y <<endl;
}
