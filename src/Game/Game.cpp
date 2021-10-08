#include "Game.h"
#include "Acter\PlayerActer.h"

void Game::gameStart() {
	this->map.genarateMap();
	//this->map.viewMap();
	//ScreenFlip();
	//WaitKey();
	//this->player.setxy(10,10);
	this->gameMain();
	
}

void Game::gameMain() {
	int x = MAX_WIDTH / 2, y = MAX_HIGHT / 2;

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
		this->map.viewRange(x, y);
		//this->map.viewMap();
		ScreenFlip();	//裏の画面を表に描写
		ClearDrawScreen(); //画面のリセット
		
	}

}

