#ifndef DEF_ROOM_H

#define DEF_ROOM_H

#include "Option\\constant.h"
#include "Option\\Random.h"
#include <stdlib.h>

class Room
{
public:
	void createRoom(int x, int y, int width, int hight);// �����Ŏ󂯎�����G���A�̍��W���ɕ������쐬����
	int getX(); //x���W�̎擾
	int getY(); //y���W�̎擾
	int getWidth(); //�����̎擾
	int getHight(); //�c���̎擾
	int getXaddWidth(); //�E�[��x���W(x+width)���擾
	int getYaddHight(); //���i��y���W(y+hight)�̎擾
protected:
	Random randNum;
	int x, y, width, hight;
};

#endif // !DEF_ROOM_H




