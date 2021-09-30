#ifndef DEF_CONSTANT_H

#define DEF_CONSTANT_H

#include <string>

#define MAX_WIDTH 64
#define MAX_HIGHT 64

#define MAX_AREA 64
#define MIN_AREA_SIZE 16

#define MIN_ROOM_SIZE 7

#define MAX_IMAGE_MAP_OBJECT 3

#define ROAD_DIRECTION_NUM 4

#define SCREEN_RENGE 8

#define CREATE_STAIR_RANGE 2

#define PLAYER_IMAGE_NUM 12

typedef struct PlayerImageNums
{
	std::string fileName = "image/Character.png";
	int splitX = 3;
	int splitY = 4;
	int sizeX = 24;
	int sizeY = 32;
}PLAYERIMAGENUMS;

enum OBJECT_TYPE {
	OBJECT_FLOOR,
	OBJECT_WALL,
	OBJECT_STAIR
};

enum DIRECTION {
	DIRECTION_TOP,
	DIRECTION_LOWER,
	DIRECTION_LEFT,
	DIRECTION_RIGHT
};

#endif // !DEF_CONSTANT\H


