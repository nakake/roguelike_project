#ifndef DEF_PLAYERIMAGE_H

#define DEF_PLAYERIMAGE_H

#include "Image.h"
#include "constant.h"
#include "DxLib.h"

class PlayerImage : public Image
{
	~PlayerImage();
public:
	void initImage();
private:
	PLAYERIMAGENUMS playerImageNums;
};


#endif // !DEF_PLAYERIMAGE_H



