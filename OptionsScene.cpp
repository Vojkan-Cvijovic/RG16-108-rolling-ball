#include "./headers/OptionsScene.hpp"

OptionsScene::OptionsScene(){

	_difficulty_option = DIFFICULTY_OPTION_NUM_1;
	_day_time = 4;

	gameScene->setDifficulty(_difficulty_option);
	gameScene->dayTime(_day_time%2);

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

    int y= _window_height- 2* _button_height;
    int x=_window_width/5;    
    int _button_spacing = 20;

	glBindTexture(GL_TEXTURE_2D, _names[2]);

	draw_text("Difficulty level",_window_width/2 - _button_width/2,y);

	y-=_button_height;
	int j=1;
    glPushMatrix();
    	for (int i = 0; i < 3; ++i,j++)
    	{
    		glBindTexture(GL_TEXTURE_2D,0);

    		draw_button_text(x,y,j-1);

    		if(_difficulty_option == j){
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


			x += _button_width + _button_spacing;
			//glTranslatef(0,-_button_height/2,0);
		}
		glBindTexture(GL_TEXTURE_2D,0);
	glPopMatrix();

	x = _window_width/3;
	y = y - 3*_button_height/2;

	draw_text("Time of day",x + _button_height,y);

	y-=_button_height;

    glPushMatrix();
    	for (int i = 0; i < 2; ++i,j++)
    	{
    		glBindTexture(GL_TEXTURE_2D,0);

    		draw_button_text(x,y,j-1);

    		//cout << _day_time << " _day_time cmp "<< j << endl;
    		if(_day_time == j){
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


			x += _button_width + _button_spacing;
			//glTranslatef(0,-_button_height/2,0);
		}
		
	glPopMatrix();

	x = _window_width/2;
	y = 2.5*_button_height;

	glBindTexture(GL_TEXTURE_2D,0);

    	draw_button_text(x,y,j-1);
   		if(_selected == true){
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


	//cout << "Rendering background " << endl;
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

	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
   		glRasterPos3f(x, y, 0);
   		glutBitmapString((void*) GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) text);
   		glLoadIdentity();
   	glPopMatrix();
}

void OptionsScene::on_mouse(int button, int state, int x, int y){

	if ((button == GLUT_LEFT_BUTTON ) && (state == GLUT_DOWN))
		push_button( resolve_button_id(x,y));

	if ((button == GLUT_LEFT_BUTTON ) && (state == GLUT_UP))
		release_button( resolve_button_id(x,y));
}

void OptionsScene::push_button(int button_id){

	//cout << "Pressed :  "<< button_id << endl; 

	if(button_id >= 1 && button_id <= 3)
		_difficulty_option = button_id;
	else if(button_id == 4 || button_id == 5)
		_day_time = button_id;
	else if(button_id == 6){
		_selected = true;
		_back_option = true;
	}
}
void OptionsScene::release_button(int button_id){
	if(_selected == true && _back_option == true){
		screenState = MENU_SCREEN_NUM;
		_selected = false;
		_back_option = false;
	}
	gameScene->setDifficulty(_difficulty_option);
	gameScene->dayTime(_day_time%2);
}

int OptionsScene::resolve_button_id(int mouse_x, int mouse_y){

	//cout <<"Mouse " << mouse_x << " " << mouse_y << endl;

	int _button_spacing = 20;
 
    int y=  3* _button_height;
    int x=_window_width/5;    
    
    int x_top = x + _button_width/2;
    int x_down = x - _button_width/2;

    int y_top = y+ _button_height/2;
    int y_down = y - _button_height/2;

    //cout << "First " << x_top << " "<<y_top << " "<< x_down << " " << y_down << endl;

    // first_button
    if( mouse_x <= x_top &&  mouse_y<=y_top &&
    	mouse_x >= x_down && mouse_y>= y_down)
    	return 1;


    x_top += _button_width + _button_spacing;
    x_down += _button_width + _button_spacing;
	//cout << "second " << x_top << " "<<y_top << " "<< x_down << " " << y_down << endl;
	// second button
	if( mouse_x <= x_top &&  mouse_y<=y_top &&
    	mouse_x >= x_down && mouse_y>= y_down)
    	return 2;

    x_top += _button_width + _button_spacing;
    x_down += _button_width + _button_spacing;
    // third button
    //cout << "third " << x_top << " "<<y_top << " "<< x_down << " " << y_down << endl;
    if( mouse_x <= x_top &&  mouse_y<=y_top &&
    	mouse_x >= x_down && mouse_y>= y_down)
    	return 3;
    
	x = _window_width/3;
	y = y + 2*_button_height + _button_height/2;
    
    
    x_top = x + _button_width/2;
    x_down = x - _button_width/2;
	y_top = y+ _button_height/2;
    y_down = y - _button_height/2;

    // forth button
    //cout << "forth " << x_top << " "<<y_top << " "<< x_down << " " << y_down << endl;
    if( mouse_x <= x_top &&  mouse_y<=y_top &&
    	mouse_x >= x_down && mouse_y>= y_down)
    	return 4;

    x_top += _button_width + _button_spacing;
    x_down += _button_width + _button_spacing;
    // fifth button
    //cout << "fifth " << x_top << " "<<y_top << " "<< x_down << " " << y_down << endl;
    if( mouse_x <= x_top &&  mouse_y<=y_top &&
    	mouse_x >= x_down && mouse_y>= y_down)
    	return 5;

    x = _window_width/2;
	y = _window_height - 2.5*_button_height;

    x_top = x + _button_width/2;
    x_down = x - _button_width/2;
	y_top = y+ _button_height/2;
    y_down = y - _button_height/2;

    // sixth button
    //cout << "sixth " << x_top << " "<<y_top << " "<< x_down << " " << y_down << endl;
    if( mouse_x <= x_top &&  mouse_y<=y_top &&
    	mouse_x >= x_down && mouse_y>= y_down)
    	return 6;


	return -1;

}
void OptionsScene::draw_button_text(int x,int y,int button_id){
    int p = 20,q=7;

    switch(button_id){
    	case 0:
    		draw_text("Easy",x-p,y-q);
    		break;
    	case 1:
    		draw_text("Medium",x-2*p,y-q);
    		break;
    	case 2:
    		draw_text("Hard",x-p,y-q);
			break;
		case 3:
			draw_text("Day",x-p,y-q);
			break;
		case 4:
			draw_text("Night",x-p-5,y-q);
			break;
		case 5:
			draw_text("Back",x-p,y-q);
			break;
	}
}

