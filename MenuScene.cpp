#include "./headers/MenuScene.hpp"

MenuScene::MenuScene()
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
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
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

	int window_width = glutGet(GLUT_WINDOW_WIDTH);
	int window_height = glutGet(GLUT_WINDOW_HEIGHT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluLookAt(0, 0, 7, 0, 0, 0, 0, 1, 0);
    gluOrtho2D(0,window_width,0,window_height);

    
    int width = window_width/4;
    int height = window_height/11;

    int y=window_height/2;
    int x=window_width/2;

	glBindTexture(GL_TEXTURE_2D,_names[0]);
    glPushMatrix();

    	for (int i = 0; i < 3; ++i)
    	{
    		int p = 20,q=7;

			switch(i){
				case 0:
					draw_text("Play",x-p,y-q);
					break;
				case 1:
					draw_text("Options",x-2*p,y-q);
					break;
				case 2:
					draw_text("Quit",x-p,y-q);
					break;
			}


			glBegin(GL_QUADS);
    			glNormal3f(0,0,1);
		
		    		glTexCoord2f(0, 0);
				   	glVertex3f(x-width/2, y-height/2, 0);    	  
				   	
				   	glTexCoord2f(0, 1); 	
				   	glVertex3f(x-width/2, y+height/2, 0);    	  
				   	
				   	glTexCoord2f(1, 1);   	
				   	glVertex3f(x+width/2, y+height/2, 0);
				    
				    glTexCoord2f(1, 0);
					glVertex3f(x+width/2, y-height/2, 0);
			glEnd();


			y -= height;
			glTranslatef(0,-height/2,0);
		}
	
	glPopMatrix();
    
	glBindTexture(GL_TEXTURE_2D, 0);


    glPushMatrix();
   		
    	glBindTexture(GL_TEXTURE_2D, _names[1]);
    	glBegin(GL_QUADS);
	    	    glNormal3f(0, 0, 1);
	
	    	    glTexCoord2f(0, 1);
	    	    glVertex3f(0, window_height,0);
	
	    	    glTexCoord2f(1, 1);
	 			glVertex3f(window_width, window_height, 0);
	
	    	    glTexCoord2f(1, 0);
	   			glVertex3f(window_width, 0, 0);
	
	    	    glTexCoord2f(0, 0);
				glVertex3f(0, 0, 0);
	    	glEnd();
	
    	/* Iskljucujemo aktivnu teksturu */
    	glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
    


}
void MenuScene::drawOptionScreen(){

}
void MenuScene::draw_text(char* text,float x,float y){

	glColor3f(1.0, 1.0, 1.0);
   	glRasterPos3f(x, y, 0);
   	glutBitmapString((void*) GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) text);

}

void MenuScene::on_mouse(int button, int state, int x, int y){
cout << " X: " << x << " | y: " << y <<endl;
}
