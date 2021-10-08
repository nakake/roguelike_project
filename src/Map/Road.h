#ifndef DEF_ROAD_H

#define DEF_ROAD_H

#include "Option/constant.h"

class Road
{
public:
	void setXandYandDirection(int x, int y, int direction);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	int getDirection();
	void setDirection(int direction);
	void setCreateFlag(bool flag);
	bool getCreateFlag();
	void setConnectFlag(bool flag);
	bool getConnectFlag();
private:
	int x, y, direction;
	bool createFlag;
	bool connectFlag;
};

#endif // !DEF_ROAD_H



