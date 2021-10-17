#include "DxLib.h"
#include "Game.h"
#include <time.h>
#include "Player.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Game game;
	Player p;
	
	ChangeWindowMode(TRUE); //ウィンドウモードに変更
	SetWindowSizeChangeEnableFlag(TRUE); //画面サイズの変更を許可
	//SetGraphMode(320, 320, 32);
	SetGraphMode(640, 640, 32); //画面サイズ(解像度？)とフレームレートを変更
	//SetGraphMode(2560, 2560, 32);
	SetWindowSize(640, 640); //ウィンドウサイズを変更
	SetAlwaysRunFlag(TRUE); //非アクティブでも動作するように変更
	//SetFontThickness(0.1);
	//SetFontSize(255);
	srand((unsigned int)time(NULL));
	SetBackgroundColor(155,155,155); //背景色の設定、だいたい灰色
	
	SetWindowText("RogueLike"); //タイトルの設定

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);	//裏画面に描画するように設定

	//game.gameStart();
	p.createPlayer(0, 0);
	p.view();
	ScreenFlip();
	WaitKey();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 

}