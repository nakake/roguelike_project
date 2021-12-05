#include "Player.h"

void Player::createPlayer(int x, int y){
	this->setxy(x, y);
	this->image.initImage();
	this->setObjectID(OBJECT_PLAYER);
	this->setDirection(7);
}

void Player::view() {
	int sizeX, sizeY, dummy;
	GetScreenState(&sizeX, &sizeY, &dummy);
	sizeX *= 0.5;
	sizeY *= 0.5;
	DrawGraph((sizeX * this->image.getImageSizeX(this->getDirection())), 
		(sizeY * this->image.getImageSizeY(this->getDirection())),
		this->image.getImageHandle(this->getDirection()), true);
}

PlayerImage Player::getImage() {
	return this->image;
}

void Player::command() {
	if ((CheckHitKey(KEY_INPUT_UP) == 1)) {
		this->setDirection(1);
		this->move(DIRECTION_TOP);
	}
	else if ((CheckHitKey(KEY_INPUT_DOWN) == 1)) {
		this->setDirection(7);
		this->move(DIRECTION_LOWER);
	}
	else if ((CheckHitKey(KEY_INPUT_LEFT) == 1)) {
		this->setDirection(10);
		this->move(DIRECTION_LEFT);
	}
	else if ((CheckHitKey(KEY_INPUT_RIGHT) == 1)) {
		this->setDirection(4);
		this->move(DIRECTION_RIGHT);
	}
}
