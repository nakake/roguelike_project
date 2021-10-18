#include "Game.h"
#include "Player.h"

void Game::gameStart() {
	this->map.genarateMap();
	//this->map.viewMap();
	//ScreenFlip();
	//WaitKey();
	this->createActers();
	this->gameMain();
	
}

void Game::createActers() {
	this->createPlayer();
}


void Game::createPlayer() {
	int randAreaNum = randNum.getRandamNum(0, (this->map.getAreaCount() - 1));
	int x = randNum.getRandamNum(this->map.getArea(randAreaNum).getX(), 
		this->map.getArea(randAreaNum).getXaddWidth());
	int y = randNum.getRandamNum(this->map.getArea(randAreaNum).getY(),
		this->map.getArea(randAreaNum).getYaddHight());
	this->player.createPlayer(x,y);
}

void Game::gameMain() {
	int x = MAX_WIDTH / 2, y = MAX_HIGHT / 2;
	/*int x = this->player.getX();
	int y = this->player.getY();*/

	while (TRUE) {
		if ((ProcessMessage() == -1) || (CheckHitKey(KEY_INPUT_ESCAPE) != 0)) {
			break;
		}
		if ((CheckHitKey(KEY_INPUT_UP) == 1)) {
			DrawFormatString(32,32,GetColor(255,255,255),"↑");
			y--;
		}
		else if ((CheckHitKey(KEY_INPUT_DOWN) == 1)){ 
			DrawFormatString(32, 32, GetColor(255, 255, 255), "↓");
			y++;
		}
		else if ((CheckHitKey(KEY_INPUT_LEFT) == 1)) {
			DrawFormatString(32, 32, GetColor(255, 255, 255), "←");
			x--;
		}
		else if ((CheckHitKey(KEY_INPUT_RIGHT) == 1)) {
			DrawFormatString(32, 32, GetColor(255, 255, 255), "→");
			x++;
		}
		else if ((CheckHitKey(KEY_INPUT_Q) == 1)) {
			this->map.genarateMap();			
		}
		//this->map.viewRange(x, y);
		//this->player.view(0);
		this->viewObjects(x, y);
		ScreenFlip();	//裏の画面を表に描写
		ClearDrawScreen(); //画面のリセット
		
	}
}

void Game::viewObjects(int centerX, int centerY) {
	int x, y, tmpX, tmpY, tmp = 0;

	GetDrawScreenSize(&x, &y);
	tmpX = ((x * 0.5) / this->map.getMapImage().getImageSizeX(OBJECT_WALL)) - SCREEN_RENGE;
	tmpY = ((y * 0.5) / this->map.getMapImage().getImageSizeY(OBJECT_WALL)) - SCREEN_RENGE;

	for (int i = centerY - SCREEN_RENGE, y = tmpY; i < centerY + SCREEN_RENGE; i++, y++) {
		for (int j = centerX - SCREEN_RENGE, x = tmpX; j < centerX + SCREEN_RENGE; j++, x++) {
			if ((i < 0) || (i >= MAX_HIGHT) || (j < 0) || (j >= MAX_WIDTH)) {
				tmp = DrawGraph((x * this->map.getMapImage().getImageSizeX(OBJECT_WALL)),
					(y * this->map.getMapImage().getImageSizeY(OBJECT_WALL)), 
					this->map.getMapImage().getImageHandle(OBJECT_WALL), FALSE);
				continue;
			}
			if (this->map.getObject(i,j).getObjectID() == OBJECT_FLOOR) {
				tmp= DrawGraph((x * this->map.getMapImage().getImageSizeX(OBJECT_FLOOR)),
					(y * this->map.getMapImage().getImageSizeY(OBJECT_FLOOR)),
					this->map.getMapImage().getImageHandle(OBJECT_FLOOR), FALSE);
				continue;
			}
			if (this->map.getObject(i, j).getObjectID() == OBJECT_WALL) {
				tmp = DrawGraph((x * this->map.getMapImage().getImageSizeX(OBJECT_WALL)),
					(y * this->map.getMapImage().getImageSizeY(OBJECT_WALL)),
					this->map.getMapImage().getImageHandle(OBJECT_WALL), FALSE);
				continue;
			}
			if (this->map.getObject(i, j).getObjectID() == OBJECT_STAIR) {
				tmp = DrawGraph((x * this->map.getMapImage().getImageSizeX(OBJECT_STAIR)),
					(y * this->map.getMapImage().getImageSizeY(OBJECT_STAIR)),
					this->map.getMapImage().getImageHandle(OBJECT_STAIR), FALSE);
				continue;
			}
			if (tmp == -1) {
				DrawFormatString(0,0,GetColor(0,0,0),"%d",tmp);
			}
		}
	}

}

