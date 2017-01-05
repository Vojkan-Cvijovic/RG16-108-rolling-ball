#include "./headers/Road.hpp"

Road::Road(float x, float y,int length,int density)
	:_x(x),_y(y),_length(length)
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
				_surface[i][j] = new Plate(x + j*PLATE_DEFAULT_WIDTH,y,4,density,true);
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
			_surface[i][j]->paint(i+10+j*j % 255, 10+i+j % 255 ,j*10+i % 255);
			_surface[i][j]->draw(i);

		}
	}
}