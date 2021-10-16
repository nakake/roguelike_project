#include "ImageMapObject.h"

ImageMapObject::~ImageMapObject() {
	for (int i = 0; i < this->imageNums.imageNum;i++) {
		DeleteGraph(this->GHandle[i]);
	}
}

void ImageMapObject::initImage() {
	this->GHandle.resize(this->imageNums.imageNum);

	LoadDivGraph(this->imageNums.fileName.c_str(), this->imageNums.imageNum,
		this->imageNums.splitX, this->imageNums.splitY,
		this->imageNums.sizeX, this->imageNums.sizeY,
		&*this->GHandle.begin());
	
	
	for (int i = 0; i < this->imageNums.imageNum; i++) {
		this->imageSizeX.push_back(this->imageNums.sizeX);
		this->imageSizeY.push_back(this->imageNums.sizeY);
	}
}
