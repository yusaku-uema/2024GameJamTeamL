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
#include"PadInput.h"

GameMain::GameMain()
{
	
	

	BGM = LoadSoundMem("../BGM/Stage.mp3");

	//ゲーム画面背景読込

	stageimg = LoadGraph("../imege/GameMain.png");

	FILE* fp;

	int block = 0;

	rendering_coodinates_x = 0;

	camerawork = new CameraWork();
	player1 = new Player1();

	player2 = new Player2();

	//読込ファイルを開く
	fopen_s(&fp, "stage.txt", "r");

	for (int j = 0; j < 25; j++)
	{
		for (int i = 0; i < 111; i++)
		{
			fscanf_s(fp, "%d", &block);

			if (block >0)
			{
				stage[j][i] = new Stage(i, j, 32, 32 ,block);
			}
			else
			{
				stage[j][i] = nullptr;
			}
		}
	}
	fclose(fp);


	gMileage = 0;


	
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
	delete player1;

	delete player2;

}


AbstractScene* GameMain::Update()
{


	//カメラ
	camerawork->Update(player1->GetLocation().x);

	//前の座標
	Location oldlocation = player1->GetLocation();


	player1->Update(camerawork->GetViewCharX());


	if (player1->GetLocation().x > oldlocation.x)
	{
		rendering_coodinates_x++;
	}




	if (CheckSoundMem(BGM) != 1)
	{   //BGMが流れていなかったら再生
		PlaySoundMem(BGM, DX_PLAYTYPE_LOOP, TRUE); //BGM再生
	}

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
	gMileage -= 5;

	player2->Update();

	return this;

	//BGMを止める
	StopSoundMem(BGM);

}



void GameMain::Draw()const
{
	void BackScrool();

		
	// ステージ画像表示
// 描画可能エリアを設定
	
	// 一枚目の道路標示
	DrawGraph( gMileage % 1200 ,0, stageimg, FALSE);
	// 二枚目の道路標示
	DrawGraph, (gMileage%1200+1200,0, stageimg, FALSE);
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
	player1->Draw();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "fuel：%f", player1->fuel);

	player2->Draw();

}
