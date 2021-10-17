#include "Image.h"

Image::~Image() {

}

int Image::getImageHandle(int handleNum) {
	return this->GHandle[handleNum];
}

int Image::getImageSizeX(int handleNum) {
	return this->imageSizeX[handleNum];
}
int Image::getImageSizeY(int handleNum) {
	return this->imageSizeY[handleNum];
}
