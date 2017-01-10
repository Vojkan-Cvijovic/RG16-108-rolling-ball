#ifndef __GAMESETTINGS_HPP_
#define __GAMESETTINGS_HPP_

#define WINDOW_WIDTH_PIXELS 720
#define WINDOW_HEIGHT_PIXELS 540

#define DIFFICULTY 1	
#define ROAD_BASE_SPEED 2.0
#define ROAD_BASE_LEVEL -2
#define ROAD_BASE_WIDTH 10
#define ROAD_BASE_LENGTH 100

#define PLATE_DEFAULT_WIDTH 2
#define PLATE_BASE_LENGTH 4
#define PLATE_COUNT 5

#define SPEED_LIMIT 5.0
#define SPEED_DECREASE 0.02
#define ACCELERATION 0.05
#define GAME_OVER_FALL_LEVEL -4

#define MENU_SCREEN_NUM 0
#define GAME_SCREEN_NUM 1
#define OPTIONS_SCREEN_NUM 2

#define VIEW_ANGLE 60
#define FUSTRUM_NEAR 1
#define FUSTRUM_FAR 100
#define FUSTRUM_LENGTH (FUSTRUM_FAR-FUSTRUM_NEAR)

#define MAX_ROAD_LEFT -5
#define MAX_ROAD_RIGHT 5
#define MAX_ROAD_WIDTH 10
#define DETAILS_LEVEL 10

#define TRACK_LENGTH (ROAD_BASE_LENGTH + FUSTRUM_LENGTH * DIFFICULTY)

#define LAMPPOST_FREQUENCY 5
#define FILENAME0 "./resources/road.bmp"
#define FILENAME1 "./resources/background.bmp"

#endif
