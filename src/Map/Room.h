#ifndef DEF_ROOM_H

#define DEF_ROOM_H

#include "Option\\constant.h"
#include "Option\\Random.h"
#include <stdlib.h>

class Room
{
public:
	void createRoom(int x, int y, int width, int hight);// 引数で受け取ったエリアの座標内に部屋を作成する
	int getX(); //x座標の取得
	int getY(); //y座標の取得
	int getWidth(); //横幅の取得
	int getHight(); //縦幅の取得
	int getXaddWidth(); //右端のx座標(x+width)を取得
	int getYaddHight(); //下段のy座標(y+hight)の取得
protected:
	Random randNum;
	int x, y, width, hight;
};

#endif // !DEF_ROOM_H




