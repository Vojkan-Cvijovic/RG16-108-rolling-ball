#include "./headers/Light.hpp"

void Light::draw(float distance){

	// we have base _z, from when we created object, each time we calculate new z position
	// by adding distance to _z
	_light_position[2] = _z + distance;
	// if _light_position is grater then -fustrum_far or lower then -fustrum_near + 10
	// light is enabled
	if(_light_position[2] >= -FUSTRUM_FAR && _light_position[2] <= -FUSTRUM_NEAR +10){	
		
		glEnable(_lightId);
		_enabled = true;

		glLightfv(_lightId,GL_POSITION,_light_position);
		glLightfv(_lightId,GL_AMBIENT, _light_ambient);
		glLightfv(_lightId,GL_DIFFUSE, _light_diffuse);
		glLightfv(_lightId,GL_SPECULAR, _light_specular);
		glLightfv(_lightId, GL_SPOT_DIRECTION, _light_direction);
		glLightf(_lightId, GL_SPOT_CUTOFF, _light_cutoff);
		glLightf(_lightId,GL_SPOT_EXPONENT, _light_exponent);

		// glPushMatrix();
		// 	glColor3f(1,0,0);
		// 	glBegin(GL_LINES);
		// 		glVertex3f(_light_position[0],_light_position[1],_light_position[2]);
		// 		glVertex3f( _light_position[0]+_light_direction[0]*10,
		// 					_light_position[1]+_light_direction[1]*10,
		// 					_light_position[2]+_light_direction[2]*10);
		// 	glEnd();
		// glPopMatrix();

	}else if ( _light_position[2] > -FUSTRUM_NEAR +25 && _enabled == true){
		/*
			if light passes behind our back + 10 then we need to turn it off
			but only one time
		*/
		_enabled = false;
		glDisable(_lightId);
	}
}


