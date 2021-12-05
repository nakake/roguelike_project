#include "Game.h"

void Game::gameStart() {
	this->map.genarateMap();
	//this->map.viewMap();
	//ScreenFlip();
	//WaitKey();
	this->createActers();
	this->camera.setxy(this->player.getX(), this->player.getY());
	this->gameMain();
	
}

void Game::createActers() {
	this->createPlayer();
}


void Game::createPlayer() {
	int randAreaNum = randNum.getRandamNum(0, (this->map.getAreaCount() - 1));
	int x = randNum.getRandamNum(this->map.getArea(randAreaNum).getRoom().getX(), 
		this->map.getArea(randAreaNum).getRoom().getXaddWidth() - 1);
	int y = randNum.getRandamNum(this->map.getArea(randAreaNum).getRoom().getY(),
		this->map.getArea(randAreaNum).getRoom().getYaddHight() - 1);
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
		else if ((CheckHitKey(KEY_INPUT_Q) == 1)) {
			this->map.genarateMap();
			this->createActers();
		}
		
		this->map.viewMap();
		//this->map.viewRange(this->camera.getX(), this->camera.getY());
		this->player.view();
		
		//this->player.view(0);
		//this->viewAllObject();

		
		ScreenFlip();	//裏の画面を表に描写
		

		this->player.command();
		this->camera.setxy(this->player.getX(), this->player.getY());
		ClearDrawScreen(); //画面のリセット
		WaitTimer(100);
	}
}

void Game::viewObjects(int centerX, int centerY) {
	int x, y, tmpX, tmpY, imageSizeX, imageSizeY;

	imageSizeX = this->map.getMapImage().getImageSizeX(OBJECT_WALL);
	imageSizeY = this->map.getMapImage().getImageSizeY(OBJECT_WALL);

	GetDrawScreenSize(&x, &y);
	
	tmpX = ((x * 0.5) - (SCREEN_RENGE * imageSizeX));
	tmpY = ((y * 0.5) - (SCREEN_RENGE * imageSizeY));
	
	DrawFormatString(0,0,GetColor(0,0,0),"%d%d",tmpX, tmpY);
	
	for (int i = centerY - SCREEN_RENGE, y = tmpY; i < centerY + SCREEN_RENGE; i++, y++) {
		for (int j = centerX - SCREEN_RENGE, x = tmpX; j < centerX + SCREEN_RENGE; j++, x++) {
			if ((i < 0) || (i >= MAX_HIGHT) || (j < 0) || (j >= MAX_WIDTH)) {
				DrawGraph(x,y, this->map.getMapImage().getImageHandle(OBJECT_WALL), FALSE);
				continue;
			}
			if (this->map.getObject(i,j).getObjectID() == OBJECT_FLOOR) {
				DrawGraph((x),
					(y),
					this->map.getMapImage().getImageHandle(OBJECT_FLOOR), FALSE);
				continue;
			}
			if (this->map.getObject(i, j).getObjectID() == OBJECT_WALL) {
				DrawGraph((x),
					(y),
					this->map.getMapImage().getImageHandle(OBJECT_WALL), FALSE);
				continue;
			}
			if (this->map.getObject(i, j).getObjectID() == OBJECT_STAIR) {
				DrawGraph((x),
					(y),
					this->map.getMapImage().getImageHandle(OBJECT_STAIR), FALSE);
				continue;
			}
		}
	}
}

void Game::viewAllObject() {
	for (int i = 0; i < MAX_HIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			if (this->map.getObject(j, i).getObjectID() == OBJECT_FLOOR) {
				DrawGraph(j*32,i*32,this->map.getMapImage().getImageHandle(OBJECT_FLOOR), FALSE);
				continue;
			}
			if (this->map.getObject(j, i).getObjectID() == OBJECT_WALL) {
				DrawGraph(j*32,i*32,this->map.getMapImage().getImageHandle(OBJECT_WALL), FALSE);
				continue;
			}
			if (this->map.getObject(j, i).getObjectID() == OBJECT_STAIR) {
				DrawGraph(j*32,i*32,this->map.getMapImage().getImageHandle(OBJECT_STAIR), FALSE);
				continue;
			}
		}
	}
}
