#include "Road.h"

void Road::setXandYandDirection(int x, int y, int direction) {
	this->setX(x);
	this->setY(y);
	this->setDirection(direction);
}

void Road::setX(int x) {
	this->x = x;
}
void Road::setY(int y) {
	this->y = y;
}
void Road::setDirection(int direction) {
	this->direction = direction;
}
int Road::getX() {
	return this->x;
}
int Road::getY() {
	return this->y;
}
int Road::getDirection() {
	return this->direction;
}

void Road::setCreateFlag(bool flag) {
	this->createFlag = flag;
}
bool Road::getCreateFlag() {
	return this->createFlag;
}

void Road::setConnectFlag(bool flag) {
	this->connectFlag = flag;
}

bool Road::getConnectFlag() {
	return this->connectFlag;
}