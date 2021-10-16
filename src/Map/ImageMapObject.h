#ifndef DEF_IMAGEMAPOBJECT_H

#define DEF_IMAGEMAPOBJECT_H

#include "Option/constant.h"
#include <stdio.h>
#include "DxLib.h"
#include "Option/Image.h"

class ImageMapObject : public Image
{
public:
	~ImageMapObject();
	void initImage();
private:
	OBJECT_IMAGE_NUMS imageNums;
};

#endif // !DEF_IMAGEMAPOBJECT





