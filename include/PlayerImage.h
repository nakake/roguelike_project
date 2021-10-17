#ifndef DEF_PLAYERIMAGE_H

#define DEF_PLAYERIMAGE_H

#include "Image.h"
#include "constant.h"
#include "DxLib.h"

class PlayerImage : public Image
{
public:
	~PlayerImage();
	void initImage();
private:
	PLAYER_IMAGE_NUMS playerImageNums;
};


#endif // !DEF_PLAYERIMAGE_H



