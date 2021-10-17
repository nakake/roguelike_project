#include "DxLib.h"
#include "Game.h"
#include <time.h>
#include "Player.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Game game;
	Player p;
	
	ChangeWindowMode(TRUE); //�E�B���h�E���[�h�ɕύX
	SetWindowSizeChangeEnableFlag(TRUE); //��ʃT�C�Y�̕ύX������
	//SetGraphMode(320, 320, 32);
	SetGraphMode(640, 640, 32); //��ʃT�C�Y(�𑜓x�H)�ƃt���[�����[�g��ύX
	//SetGraphMode(2560, 2560, 32);
	SetWindowSize(640, 640); //�E�B���h�E�T�C�Y��ύX
	SetAlwaysRunFlag(TRUE); //��A�N�e�B�u�ł����삷��悤�ɕύX
	//SetFontThickness(0.1);
	//SetFontSize(255);
	srand((unsigned int)time(NULL));
	SetBackgroundColor(155,155,155); //�w�i�F�̐ݒ�A���������D�F
	
	SetWindowText("RogueLike"); //�^�C�g���̐ݒ�

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);	//����ʂɕ`�悷��悤�ɐݒ�

	//game.gameStart();
	p.createPlayer(0, 0);
	p.view();
	ScreenFlip();
	WaitKey();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 

}