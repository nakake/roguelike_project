#include "Area.h"

//�G���A�̏�����
//x,y���W��0
//hight,width�͂��ꂼ��̍ő�l
void Area :: initArea() {
	this->x = 0;
	this->y = 0;
	this->hight = MAX_HIGHT;
	this->width = MAX_WIDTH;
}

//�c���𔼕��ɂ���
void Area::setHightHalf() {
	this->setHight((this->getHight() * 0.5));
}

//�����𔼕��ɂ���
void Area::setWidthHalf() {
	this->setWidth((this->getWidth() * 0.5));
}

//�c�����Z�b�g����
void Area::setHight(int hight) {
	this->hight = hight;
}

//�������Z�b�g����
void Area::setWidth(int width) {
	this->width = width;
}

//x,y,width,hight���Z�b�g����
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