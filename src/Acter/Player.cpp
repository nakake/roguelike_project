#include "Player.h"

void Player::createPlayer(int x, int y){
	this->setxy(x, y);
	this->image.initImage();
	this->setObjectID(OBJECT_PLAYER);
}

void Player::view() {
	for (int i = 0; i < 12; i++) {
		DrawGraph(this->getX()+ (i*this->image.getImageSizeX(i)), this->getY()+ (i*this->image.getImageSizeY(i)), this->image.getImageHandle(i), true);
	}
}
