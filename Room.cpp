#include "Room.h"

void Room::createRoom(int x, int y, int width, int hight) {
	int addRandNum = 1;//���������p 
	int innerSpace = 2;//�G���A���牽�}�X�����ɕ�������邩�����߂�

	/*
	* (�ŏ��l) + (�ő�l�̏�]) + 1 �ŗ������擾
	*   x   : �G���A�̍��[����2�}�X�����`�G���A�̉E�[���� MIN_ROOM_SIZE + 2�}�X�����܂ł��͈�
	*   y   : �G���A�̏�i����2�}�X�����`�G���A�̉��i���� MIN_ROOM_SIZE + 2�}�X�����܂ł��͈�
	* width : MIN_ROOM_SIZE �` �G���A�̉E���W(x+width)���畔����x���W�A�C���i�[�X�y�[�X�AMIN_ROOM_SIZE �����������l���͈�
	* hight : MIN_ROOM_SIZE �` �G���A�̉����W(y+hight)���畔����y���W�A�C���i�[�X�y�[�X�AMIN_ROOM_SIZE �����������l���͈�
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
