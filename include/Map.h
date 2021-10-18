#ifndef DEF_MAP_H

#define DEF_MAP_H

#include "constant.h"
#include "Object.h"
#include "Area.h"
#include "Random.h"
#include "DxLib.h"
#include "ImageMapObject.h"

class Map
{
public:
	void genarateMap();
	void viewMap();
	void viewRange(int centerX, int centerY);
	int getAreaCount();
	Area getArea(int areaNum);
	ImageMapObject getMapImage();
	Object getObject(int x, int y);
	void viewImage(int imageNum, int x, int y);
private:
	void initMap();
	void spritArea(int areaIdx);
	void initRoad();
	void createAreasRoom();
	void createAreasRoad();
	void createTopRoad(int areaNum);
	void createLowerRoad(int areaNum);
	void createLeftRoad(int areaNum);
	void createRightRoad(int areaNum);
	void connectRoad();
	void fillNotConectRoad();
	void createStair();
	void debugViewAreaBox();
	void debugViewSpriteArea();
	int getAreaNum(int x, int y);
	Object mapObject[MAX_HIGHT][MAX_WIDTH];
	Area area[MAX_AREA];
	int areaCount;
	Random randNum;
	ImageMapObject image;
};

#endif // !DEF_MAP_H





