#include"DxLib.h"
#include"GameMain.h"
#define _CRT_SECURE_MD_WARNING
#include<stdio.h>

GameMain::GameMain()
{

	FILE* fp;

	int block = 0;

	rendering_coodinates_x = 0;

	camerawork = new CameraWork();

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





	return this;


}

void GameMain::Draw()const
{


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



}