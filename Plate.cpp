#include "./headers/Plate.hpp"

void Plate::draw(int level){
	if(_exists){		
		float single_strip_width = PLATE_DEFAULT_WIDTH / _density;
		for(int i=0;i<_density;i++){
			// we draw stripes
			glColor3f(_r+i/40,_g+i/10,_b+i/15);
			//cout << _r << " " << _g << " " << _b << endl;
			glPushMatrix();

				glBegin(GL_POLYGON);
					float x0 = _x + i*single_strip_width, z0 =  level * _length;
					float x1 = _x + (i+1)*single_strip_width, z1 = (level+1) * _length;
					float y0 = _y,y1 = _y; // incline ??

					glVertex3f(x0, y0, -z0);
					glVertex3f(x0, y0, -z1);
					glVertex3f(x1, y1, -z1);
					glVertex3f(x1, y1, -z0);

				glEnd();
			glPopMatrix();
		}
	}
}


