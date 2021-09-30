#include "ImageMapObject.h"

//ImageMapObject::ImageMapObject() {
//	char pathName[] = "image/";
//	char extension[] = ".png";
//	char fileFrontname[100][100] = { "floor","wall","stair" };
//	char fileName[100]; 
//
//	for (int i = 0; i < MAX_IMAGE_MAP_OBJECT; i++) {
//		sprintf_s(fileName,sizeof(fileName),"%s%s%s",pathName,fileFrontname[i], extension);
//		this->GHandle[i] = LoadGraph(fileName);
//		GetGraphSize(this->GHandle[i], &this->imageSizeX[i], &this->imageSizeY[i]);
//	}
//}

ImageMapObject::~ImageMapObject() {
	for (int i = 0; i < MAX_IMAGE_MAP_OBJECT;i++) {
		DeleteGraph(this->GHandle[i]);
	}
}

void ImageMapObject::initImage() {
	char pathName[] = "image/";
	char extension[] = ".png";
	char fileFrontname[100][100] = { "floor","wall","stair" };
	char fileName[100];
	int tmpX, tmpY;

	for (int i = 0; i < MAX_IMAGE_MAP_OBJECT; i++) {
		sprintf_s(fileName, sizeof(fileName), "%s%s%s", pathName, fileFrontname[i], extension);
		this->GHandle.push_back(LoadGraph(fileName));
		GetGraphSize(this->GHandle[i], &tmpX, &tmpY);
		this->imageSizeX.push_back(tmpX);
		this->imageSizeY.push_back(tmpY);
	}
}
