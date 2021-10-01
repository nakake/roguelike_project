#ifndef DEF_GAME_H

#define DEF_GAME_H

#include "Option\\constant.h"
#include "Map\\Map.h"
#include "Camera.h"
#include "Option\\Random.h"

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



