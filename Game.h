#ifndef DEF_GAME_H

#define DEF_GAME_H

#include "constant.h"
#include "Map.h"
#include "Camera.h"
#include "Random.h"

class Game
{
public:
	void gameStart();
	void gameMain();
private:
	Camera camera;
	Map map;
};


#endif // !DEF_GAME_H



