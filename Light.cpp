#include "./headers/Light.hpp"

void Light::draw(float distance){

	// we have base _z, from when we created object, each time we calculate new z position
	// by adding distance to _z
	_light_position[2] = _z + distance;
	// if _light_position is grater then -fustrum_far or lower then -fustrum_near + 10
	// light is enabled

	// cout << " _light_position " << _light_position[2] << endl;

	// glPushMatrix();
	// 	glColor3f(1,0,0);
	// 	glTranslatef(_side * (ROAD_BASE_WIDTH/2-0.8),2.7,_light_position[2]);
	// 	glutSolidCube(1);
	// glPopMatrix();


	if(_light_position[2] >= -FUSTRUM_FAR && _light_position[2] <= -FUSTRUM_NEAR +10){	
		cout << "Light " << _lightId-GL_LIGHT0 << " on position "<<_light_position[0] << " "
		<<  _light_position[1] << " " <<  _light_position[2] << endl; 

		glEnable(_lightId);
		_enabled = true;

		glLightfv(_lightId,GL_POSITION,_light_position);
		glLightfv(_lightId,GL_AMBIENT, _light_ambient);
		glLightfv(_lightId,GL_DIFFUSE, _light_diffuse);
		glLightfv(_lightId,GL_SPECULAR, _light_specular);
	}else if ( _light_position[2] > -FUSTRUM_NEAR +10 && _enabled == true){
		/*
			if light passes behind our back + 10 then we need to turn it off
			but only one time
		*/
		_enabled = false;
		glDisable(_lightId);
	}
}


