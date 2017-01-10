#include "./headers/OptionsScene.hpp"

OptionsScene::OptionsScene(){

	_difficulty_option = DIFFICULTY_OPTION_NUM_0;
	_day_time = DAYTIME_OPTION_DAY;

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	_image = image_init(0, 0);
	_window_width = glutGet(GLUT_WINDOW_WIDTH);
	_window_height = glutGet(GLUT_WINDOW_HEIGHT);

    glGenTextures(3, _names);


    image_read(_image, FILENAME0);

    glBindTexture(GL_TEXTURE_2D, _names[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 _image->width, _image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, _image->pixels);


    image_read(_image, FILENAME1);

    glBindTexture(GL_TEXTURE_2D, _names[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 _image->width, _image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, _image->pixels);


    image_read(_image, FILENAME3);

    glBindTexture(GL_TEXTURE_2D, _names[2]);
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


void OptionsScene::draw(){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);

	_window_width = glutGet(GLUT_WINDOW_WIDTH);
	_window_height = glutGet(GLUT_WINDOW_HEIGHT);
    
    glLoadIdentity();
    gluOrtho2D(0,_window_width,0,_window_height);

    
    _button_width = _window_width/4;
    _button_height = _window_height/11;

    int y=_window_height/2;
    int x=_window_width/2;    
	glBindTexture(GL_TEXTURE_2D, _names[2]);
	cout << "Drawing 3 buttons " << endl;
    glPushMatrix();
    	for (int i = 0; i < 3; ++i)
    	{
    		glBindTexture(GL_TEXTURE_2D,0);

    		draw_button_text(x,y,i);

    		if(_difficulty_option == i){
    			glBindTexture(GL_TEXTURE_2D,_names[1]);
    		}else{
    			glBindTexture(GL_TEXTURE_2D,_names[0]);	
    		}
    	
			glBegin(GL_QUADS);
    			glNormal3f(0,0,1);
		
		    		glTexCoord2f(0, 0);
				   	glVertex3f(x-_button_width/2, y-_button_height/2, 0);    	  
				   	
				   	glTexCoord2f(0, 1); 	
				   	glVertex3f(x-_button_width/2, y+_button_height/2, 0);    	  
				   	
				   	glTexCoord2f(1, 1);   	
				   	glVertex3f(x+_button_width/2, y+_button_height/2, 0);
				    
				    glTexCoord2f(1, 0);
					glVertex3f(x+_button_width/2, y-_button_height/2, 0);
			glEnd();


			y -= _button_height;
			glTranslatef(0,-_button_height/2,0);
		}
		glBindTexture(GL_TEXTURE_2D,0);
	glPopMatrix();
	cout << "Rendering background " << endl;
   	glBindTexture(GL_TEXTURE_2D,_names[2]);	

    	glBegin(GL_QUADS);
	    	glNormal3f(0, 0, 1);
	
	    	glTexCoord2f(0, 1);
	    	glVertex3f(0, _window_height,0);
	
	    	glTexCoord2f(1, 1);
	 		glVertex3f(_window_width, _window_height, 0);
	
	    	glTexCoord2f(1, 0);
	   		glVertex3f(_window_width, 0, 0);
	
	    	glTexCoord2f(0, 0);
			glVertex3f(0, 0, 0);
	    glEnd();
	
	    glBindTexture(GL_TEXTURE_2D,0);

	    glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void OptionsScene::draw_text(char* text,float x,float y){

	glColor3f(1.0, 1.0, 1.0);
   	glRasterPos3f(x, y, 0);
   	glutBitmapString((void*) GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) text);

}

void OptionsScene::on_mouse(int button, int state, int x, int y){

	if ((button == GLUT_LEFT_BUTTON ) && (state == GLUT_DOWN))
		push_button( resolve_button_id(x,y));

	if ((button == GLUT_LEFT_BUTTON ) && (state == GLUT_UP))
		release_button( resolve_button_id(x,y));
}

void OptionsScene::push_button(int button_id){
	
}
void OptionsScene::release_button(int button_id){

}

int OptionsScene::resolve_button_id(int mouse_x, int mouse_y){

	int y=_window_height/2;
    int x=_window_width/2;
    int space_between = 0;

	 return -1;

}
void OptionsScene::draw_button_text(int x,int y,int button_id){
    int p = 20,q=7;

    switch(button_id){
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
}

