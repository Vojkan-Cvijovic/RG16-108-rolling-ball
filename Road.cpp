#include "./headers/Road.hpp"

Road::Road(float x, float y,int length,int density)
	:_x(x),_y(y),_length(length),distance(-3),level(0)
	{
		int width = PLATE_COUNT * PLATE_DEFAULT_WIDTH;
		_surface = (Plate***) malloc(_length * sizeof(Plate *));
		if(_surface == NULL){
			cout << "Error while allocating road" << endl;
			exit(0);
		}
		for(int i = 0;i<_length ; i++){
			_surface[i] = (Plate**) malloc(PLATE_COUNT* sizeof(Plate *));
			if(_surface[i] == NULL){
				cout << "Error while allocating road width" << endl;
				exit(0);
			}
			for(int j=0;j<PLATE_COUNT;j++){
				_surface[i][j] = new Plate(x + j*PLATE_DEFAULT_WIDTH,y,PLATE_BASE_LENGTH,density,true);
				if(_surface[i][j] == NULL){
					cout << "Error while allocating plate" << endl;
				}
			}
		}
	}
Road::~Road(){
	for (int i = 0; i < _length; ++i)
	{
		for (int j = 0; j < PLATE_COUNT; ++j)
		{
			delete _surface[i][j];
		}
		free (_surface[i]);
	}
	free (_surface);
}

void Road::draw(){
	for (int i = 0; i < _length; ++i)
	{
		for (int j = 0; j < PLATE_COUNT; ++j)
		{
			if(_surface[i][j] != NULL){

				float red = pow(sin(i/87.0),2)+j/20.0 + 0.1;
				float green = pow(sin(i/64.0),2)+j/10.0 + 0.1;
				float blue = pow(sin(i/49.0),2)+j/30.0 + 0.1;

				//cout << "RGB  " << red << " | " << green << " | " << blue << " Za i="<<i<< " & j =" << j << endl;

				glPushMatrix();
					glTranslatef(0,-3,distance);
					_surface[i][j]->paint(red,green,blue);
					_surface[i][j]->draw(i);
				glPopMatrix();
			}
		}
	}
}
void Road::run(float speed){
	draw();
	distance = distance + 1/30.0 * speed;

	
}
void Road::generate(){

}