#include "Player.h"

void Player::createPlayer(int x, int y){
	this->setxy(x, y);
	this->image.initImage();
	this->setObjectID(OBJECT_PLAYER);
}

void Player::view(int imageNum) {
	DrawGraph(this->getX()+ (imageNum*this->image.getImageSizeX(imageNum)), 
		this->getY()+ (imageNum*this->image.getImageSizeY(imageNum)), 
		this->image.getImageHandle(imageNum), true);
}
