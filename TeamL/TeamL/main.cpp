/****************************************************************/
/*	プロジェクト名:		Gamejam 　　チームL*/
/*	ファイル名：		ゲームメイン							*/
/*	内容：				全ての大元の処理						*/
/*	日付：		２０２４年０２月１２日							*/
/*	コンパイラ:													*/
/*	note:		変なところあるかも報告ください					*/
/*	作成者：	愛斗											*/
/****************************************************************/



#include "DxLib.h"
#include"common.h"
#include"SceneManager.h"
#include"AbstractScene.h"
#include"PadInput.h"
#include"Main_Title.h"

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	double dNextTime = GetNowCount();

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	SetAlwaysRunFlag(true);		//常にアクティブにする

	SetGraphMode(D_SCREEN_WIDTH, D_SCREEN_HEIGHT, 32);	//画面サイズの設定

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする


	AbstractScene* firstScene = new Main_Title();						//FirstSceneの作成

	SceneManager* sceneManager = SceneManager::Create(firstScene);	//シーンマネージャーの起動

	// ゲームループ
	while ((ProcessMessage() == 0) &&
		sceneManager->Update() != nullptr
		)
	{
		PadInput::UpdateKey();

		ClearDrawScreen();		// 画面の初期化

		sceneManager->Draw();


		ScreenFlip();			// 裏画面の内容を表画面に反映

		//フレームレートの設定
		dNextTime += 1.0 / 60.0 * 1000.0;

		if (dNextTime > GetNowCount())
		{
			WaitTimer(static_cast<int>(dNextTime) - GetNowCount());
		}
		else { dNextTime = GetNowCount(); }		//補正
	}
	delete sceneManager;		//シーンマネージャーの削除

	return 0;
}