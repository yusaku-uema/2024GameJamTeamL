#include "DxLib.h"



#define FRAMERATE 60 //フレームレート

#define SCREEN_WIDTH 640 //画面サイズ（横）

#define SCREEN_HEIGHT 480 //画面サイズ（縦）

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	double dNextTime = GetNowCount();

	SetMainWindowText("Super Mario Bros");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	SetAlwaysRunFlag(TRUE);		//ウィンドウが非アクティブでなくても処理を継続するか設定

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//画面サイズの設定

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	

	return 0;
}