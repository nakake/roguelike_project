#include "Room.h"

void Room::createRoom(int x, int y, int width, int hight) {
	int addRandNum = 1;//乱数生成用 
	int innerSpace = 2;//エリアから何マス内側に部屋を作るかを決める

	/*
	* (最小値) + (最大値の剰余) + 1 で乱数を取得
	*   x   : エリアの左端から2マス内側～エリアの右端から MIN_ROOM_SIZE + 2マス内側までが範囲
	*   y   : エリアの上段から2マス内側～エリアの下段から MIN_ROOM_SIZE + 2マス内側までが範囲
	* width : MIN_ROOM_SIZE ～ エリアの右座標(x+width)から部屋のx座標、インナースペース、MIN_ROOM_SIZE を引いた数値が範囲
	* hight : MIN_ROOM_SIZE ～ エリアの下座標(y+hight)から部屋のy座標、インナースペース、MIN_ROOM_SIZE を引いた数値が範囲
	*/
	this->x = randNum.getRandamNum((x + innerSpace), (x + width - MIN_ROOM_SIZE - innerSpace));
	this->y = randNum.getRandamNum((y + innerSpace), (y + hight - MIN_ROOM_SIZE - innerSpace));
	this->width = randNum.getRandamNum(MIN_ROOM_SIZE, (x + width - this->x - innerSpace));
	this->hight = randNum.getRandamNum(MIN_ROOM_SIZE, (y + hight - this->y - innerSpace));
}


int Room::getX() {
	return this->x;
}


int Room::getY() {
	return this->y;
}


int Room::getWidth() {
	return this->width;
}

int Room::getHight() {
	return this->hight;
}


int Room::getYaddHight() {
	return (this->y + this->hight);
}


int Room::getXaddWidth() {
	return (this->x + this->width);
}
