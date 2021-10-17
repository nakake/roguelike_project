#include "PlayerImage.h"

PlayerImage::~PlayerImage() {
	for (int i = 0; i < GHandle.size(); i++) {
		DeleteGraph(this->GHandle[i]);
	}
}

void PlayerImage::initImage() {
	this->GHandle.resize(this->playerImageNums.imageNum);

	LoadDivGraph(this->playerImageNums.fileName.c_str(), this->playerImageNums.imageNum,
		this->playerImageNums.splitX, this->playerImageNums.splitY, 
		this->playerImageNums.sizeX, this->playerImageNums.sizeY,
		&*this->GHandle.begin());
	for (int i = 0; i < this->playerImageNums.imageNum; i ++) {
		this->imageSizeX.push_back(this->playerImageNums.sizeX);
		this->imageSizeY.push_back(this->playerImageNums.sizeY);
	}
}