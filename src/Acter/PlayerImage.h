#ifndef DEF_PLAYERIMAGE_H

#define DEF_PLAYERIMAGE_H

#include "Option/Image.h"
#include "Option/constant.h"
#include "DxLib.h"

class PlayerImage : public Image
{
	~PlayerImage();
public:
	void initImage();
private:
	PLAYER_IMAGE_NUMS playerImageNums;
};


#endif // !DEF_PLAYERIMAGE_H



