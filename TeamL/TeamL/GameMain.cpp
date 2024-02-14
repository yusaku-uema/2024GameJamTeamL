/****************************************************************/
/*	プロジェクト名:		Gamejam 　　チームL						*/
/*	ファイル名：　　　　メインCPP									*/
/*	内容：			ゲームのメイン								*/
/*	日付：					2024/02/14							*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：				名嘉真　愛斗						*/
/****************************************************************/
#include"DxLib.h"
#include"GameMain.h"
#define _CRT_SECURE_MD_WARNING
#include<stdio.h>

GameMain::GameMain()
{

	//ゲーム画面背景読込

	stageimg = LoadGraph("../imege/GameMain.png");

	FILE* fp;

	int block = 0;
	rendering_coodinates_x = 0;

	camerawork = new CameraWork();

	player2 = new Player2();

	//読込ファイルを開く
	fopen_s(&fp, "stage.txt", "r");

	for (int j = 0; j < 25; j++)
	{
		for (int i = 0; i < 111; i++)
		{
			fscanf_s(fp, "%d", &block);

			if (block > 0)
			{
				stage[j][i] = new Stage(i, j, 32, 32 );
			}
			else
			{
				stage[j][i] = nullptr;
			}
		}
	}
	fclose(fp);




}
GameMain::~GameMain()
{
	for (int j = 0; j < 25; j++)
	{

		for (int i = 0; i < 111; i++)
		{
			if (stage[j][i] != nullptr)
			{
				delete stage[j][i];
			}
		}
	}

	delete player2;

}


AbstractScene* GameMain::Update()
{
	for (int j = 0; j < 25; j++)
	{

		for (int i = 0; i < 111; i++)
		{
			if (stage[j][i]!= nullptr)
			{
				stage[j][i]->Update(camerawork->GetCameraX());
			}
		}
	}

	// 走行距離を加算する(仮のスピード)
	gMileage += 5;

	player2->Update();

	return this;


}



void GameMain::Draw()const
{
	void BackScrool();



	// ステージ画像表示
// 描画可能エリアを設定
	
	// 上部の道路標示
	DrawGraph( gMileage % 480 - 480,0, stageimg, FALSE);
	// 下部の道路標示
	DrawGraph, (gMileage % 480,0, stageimg, FALSE);
	//エリアを戻す


	for (int j = 0; j < 25; j++)
	{
		for (int i = 0; i < 111; i++)
		{
			if (stage[j][i] != nullptr)
			{
				stage[j][i]->Draw();
			}
		}
	}

	player2->Draw();

}
