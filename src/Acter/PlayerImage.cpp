#include "PlayerImage.h"

PlayerImage::~PlayerImage() {
	for (int i = 0; i < PLAYER_IMAGE_NUM ; i++) {
		DeleteGraph(this->GHandle[i]);
	}
}

void PlayerImage::initImage() {
	LoadDivGraph(this->playerImageNums.fileName.c_str(), PLAYER_IMAGE_NUM,
		this->playerImageNums.splitX, this->playerImageNums.splitY, 
		this->playerImageNums.sizeX, this->playerImageNums.sizeY,
		this->GHandle.data());
	for (int i = 0; i < PLAYER_IMAGE_NUM; i ++) {
		this->imageSizeX.push_back(this->playerImageNums.sizeX);
		this->imageSizeY.push_back(this->playerImageNums.sizeY);
	}
}