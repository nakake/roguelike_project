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

typedef struct PlayerImageNums
{
	const std::string fileName = "image/player.png";
	const int imageNum = 12;
	const int splitX = 3;
	const int splitY = 4;
	const int sizeX = 24;
	const int sizeY = 32;
}PLAYER_IMAGE_NUMS;

typedef struct ObjectImageNums
{
	const std::string fileName = "image/objects.png";
	const int imageNum = 3;
	const int splitX = 2;
	const int splitY = 2;
	const int sizeX = 32;
	const int sizeY = 32;
}OBJECT_IMAGE_NUMS;

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


