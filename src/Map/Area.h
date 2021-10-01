#ifndef DEF_AREA_H
#define DEF_AREA_H

#include "Option\\constant.h"
#include "Room.h"
#include "Road.h"

class Area:public Room
{
public:
	void initArea();
	void setWidthHalf();
	void setHightHalf();
	void setWidth(int width);
	void setHight(int hight);
	void setNewAreaState(int x, int y, int width, int hight);
	void setAreaNum(int areaNum);
	int getAreaNum();
	Room room;
	Road roadEnd[ROAD_DIRECTION_NUM];	
private:
	int areaNum;
};

#endif // !DEF_AREA_H



