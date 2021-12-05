#include "Area.h"

//エリアの初期化
//x,y座標は0
//hight,widthはそれぞれの最大値
void Area :: initArea() {
	this->x = 0;
	this->y = 0;
	this->hight = MAX_HIGHT;
	this->width = MAX_WIDTH;
}

//縦幅を半分にする
void Area::setHightHalf() {
	this->setHight((this->getHight() * 0.5));
}

//横幅を半分にする
void Area::setWidthHalf() {
	this->setWidth((this->getWidth() * 0.5));
}

//縦幅をセットする
void Area::setHight(int hight) {
	this->hight = hight;
}

//横幅をセットする
void Area::setWidth(int width) {
	this->width = width;
}

//x,y,width,hightをセットする
void Area::setNewAreaState(int x, int y, int width, int hight) {
	this->x = x;
	this->y = y;
	this->setHight(hight);
	this->setWidth(width);
}

void Area::setAreaNum(int areaNum) {
	this->areaNum = areaNum;
}
int Area::getAreaNum() {
	return areaNum;
}

Room Area::getRoom() {
	return this->room;
}