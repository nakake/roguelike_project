#include "Object.h"

//�I�u�W�F�N�g�� x,y ���W�̃Z�b�g
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

//�I�u�W�F�N�gID���Z�b�g����
void Object::setObjectID(int id) {
	this->objectID = id;
}

//�I�u�W�F�N�gID�̎擾
int Object::getObjectID() {
	return this->objectID;
}

