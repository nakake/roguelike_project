#ifndef DEF_GAME_H

#define DEF_GAME_H

#include "constant.h"
#include "Map.h"
#include "Camera.h"
#include "Random.h"
#include "Player.h"
#include "Player.h"

class Game
{
public:
	void gameStart();
	void gameMain();
private:
	void createActers();
	void createPlayer();
	void viewObjects(int centerX, int centerY);

	Camera camera;
	Map map;
	Player player;
	Random randNum;
};


#endif // !DEF_GAME_H



