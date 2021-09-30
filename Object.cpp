#include "Object.h"

//オブジェクトの x,y 座標のセット
void Object::setxy(int x, int y) {
	this->x = x;
	this->y = y;
}

int Object::getX() {
	return this->x;
}

int Object::getY() {
	return this->y;
}

//オブジェクトIDをセットする
void Object::setObjectID(int id) {
	this->objectID = id;
}

//オブジェクトIDの取得
int Object::getObjectID() {
	return this->objectID;
}

