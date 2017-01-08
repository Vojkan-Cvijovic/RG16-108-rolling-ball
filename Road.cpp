#include "./headers/Road.hpp"


// Random seed
random_device rd;

// Initialize Mersenne Twister pseudo-random number generator
mt19937 gen(rd());

// Generate pseudo-random numbers
// uniformly distributed in range (1, 100)
uniform_int_distribution<> dis(0, 100);

Road::Road(float x, float y,int length,int density)
	:_x(x),_y(y),_length(length),distance(-3),level(0)
	{

		_lamppostCount = _length/LAMPPOST_FREQUENCY;
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
				_surface[i][j] = new Plate(x + j*PLATE_DEFAULT_WIDTH,y,PLATE_BASE_LENGTH,density);
				if(_surface[i][j] == NULL){
					cout << "Error while allocating plate" << endl;
				}

			}
		}
		generate(0,0);

		_streetLights = (Lamppost**) malloc( _lamppostCount * sizeof(Lamppost*));
		if(_streetLights == NULL){
			cout << "Error while allocating streetLights" << endl;
			exit(0);
		}
		for (int i = 0; i < _lamppostCount; ++i)
		{
			_streetLights[i] = new Lamppost(i);
			if(_streetLights[i] == NULL){
				cout << "Error while allocating single street light" << endl;
				exit(0);
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
	int d = distance;
	int limit = FUSTRUM_FAR + d/4 + 4;
	if(limit>_length)
		limit = _length;

	for (int i = 0; i < limit; ++i)
	{ 

		for (int j = 0; j < PLATE_COUNT; ++j)
		{
			bool exists = _surface[i][j]->ifExists();
			//cout << exists << endl;
			if(!exists){}
			else{
			if(_surface[i][j] != NULL ){

				float red = pow(sin(i/87.0),2)+j/20.0 + 0.1;
				float green = pow(sin(i/64.0),2)+j/10.0 + 0.1;
				float blue = pow(sin(i/49.0),2)+j/30.0 + 0.1;

				glPushMatrix();
					glTranslatef(0,-3,distance);
					if(i <= _length - 5 || i >= _length - 2)
						_surface[i][j]->paint(red,green,blue);
					_surface[i][j]->draw(i);
				glPopMatrix();
			}
			}
		}	
	}
	for (int i = 0; i < _lamppostCount; ++i)
	{
		_streetLights[i]->draw(distance);
	}
}
void Road::run(float speed){
	draw();
	distance = distance + 1/5.0* speed;

	level = ceil(distance + 1);
}
void Road::generate(int i,int j){

	/*
		
			|0,0,0,0,0|  left and right = 2*10%, left-back and right-back = 2*9%, behind = 60%
	i=k+2	|0,0,0,0,0|
	i=k+1	|e,f,_,h,i|
	i=k		|a,b,c,d,e|
	
	we generate _ by adding probability, 
		if f is generated than increase odds by 10%
		if h is generated do the same
		
		if b is generated then increase by 9%
		if d is generated do the same
		
		if c is generated then increase odds by 60%

	*/
	int hendicap = (i%70)/10;

	if(i>=_length-1)
		return;

	if(j >= PLATE_COUNT){
		j=0;
		i++;
	}
	if(i<5 || i > _length-7){
		_surface[i][j]->generate();
	}else{
		float odds = 0;
		if(_surface[i-1][j]->ifExists())
			odds += 50;
		if( j>0 && _surface[i-1][j-1]->ifExists())
			odds += 6;
		if( j<PLATE_COUNT-1 && _surface[i-1][j+1]->ifExists())
			odds += 6;
		if( j<PLATE_COUNT-1 && _surface[i][j+1]->ifExists())
			odds += 7;
		if( j>0 && _surface[i][j-1]->ifExists())
			odds += 7;
		if(i>= 50)
			odds += 20;
		
		int randomNum =0;
		//int randomNum = dis(gen);
		if(randomNum <= odds - hendicap)
			_surface[i][j]->generate();
	}

	// finish line

	if(i > _length - 5 && i < _length - 2){
		if(i%2 == 0){
			if(j%2 == 0)
				_surface[i][j]->paint(-30,-30,-30);
			else
				_surface[i][j]->paint(30,30,30);
		}else{
			if(j%2 == 0)
				_surface[i][j]->paint(30,30,30);
			else
				_surface[i][j]->paint(-30,-30,-30);
		}
	}

	generate(i,j+1);
}
bool Road::fallThrough(float x,int y){
	int j;
	int center = 2;
	float correction = 1.8;
	x = x+ center;
	
	// we need to determine line
	if(x>4.8)
		j=4;
	else if(x>3)
		j=3;
	else if(x>1)
		j=2;
	else if(x>-0.8)
		j=1;
	else 
		j=0;

	
	int d= round((distance + 1)/ PLATE_BASE_LENGTH);

	if(y != ROAD_BASE_LEVEL)
		return false;

	if(d >= 0 &&
		!_surface[d][j]->ifExists()){
		return true;
	}
	return false;

}