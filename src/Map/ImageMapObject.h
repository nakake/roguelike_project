#ifndef DEF_IMAGEMAPOBJECT_H

#define DEF_IMAGEMAPOBJECT_H

#include "Option\\constant.h"
#include <stdio.h>
#include "DxLib.h"
#include "Option\\Image.h"

class ImageMapObject : public Image
{
public:
//	ImageMapObject();
	~ImageMapObject();
	void initImage();
	//int getImageHandle(int handleNum);
	//int getImageSizeX(int handleNum);
	//int getImageSizeY(int handleNum);
private:
	//int GHandle[MAX_IMAGE_MAP_OBJECT];
	//int imageSizeX[MAX_IMAGE_MAP_OBJECT], imageSizeY[MAX_IMAGE_MAP_OBJECT];
};

#endif // !DEF_IMAGEMAPOBJECT





