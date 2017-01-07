#include "./headers/Plate.hpp"

void Plate::draw(int level){
	if(_exists){		
		float single_strip_width = PLATE_DEFAULT_WIDTH / _density;
		for(int i=0;i<_density;i++){

			_diffuse_coeffs[0] = _r;
			_diffuse_coeffs[1] = _g;
			_diffuse_coeffs[2] = _b;

			glMaterialfv(GL_FRONT, GL_AMBIENT, _ambient_coeffs);
    		glMaterialfv(GL_FRONT, GL_DIFFUSE, _diffuse_coeffs);
    		glMaterialfv(GL_FRONT, GL_SPECULAR, _specular_coeffs);
    		glMaterialf(GL_FRONT, GL_SHININESS, _shininess);

			//cout << _r << " " << _g << " " << _b << endl;
			glPushMatrix();

				glBegin(GL_POLYGON);
					float x0 = _x + i*single_strip_width, z0 =  level * _length;
					float x1 = _x + (i+1)*single_strip_width, z1 = (level+1) * _length;
					float y0 = _y,y1 = _y; // incline ??
					glNormal3d(0,1,0);
					glVertex3f(x0, y0, -z0);
					glVertex3f(x0, y0, -z1);
					glVertex3f(x1, y1, -z1);
					glVertex3f(x1, y1, -z0);

				glEnd();
			glPopMatrix();
		}
	}
}


