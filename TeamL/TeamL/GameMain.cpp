/****************************************************************/
/*	�v���W�F�N�g��:		Gamejam �@�@�`�[��L						*/
/*	�t�@�C�����F�@�@�@�@���C��CPP									*/
/*	���e�F			�Q�[���̃��C��								*/
/*	���t�F					2024/02/14							*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF				���Ð^�@���l						*/
/****************************************************************/
#include"DxLib.h"
#include"GameMain.h"
#define _CRT_SECURE_MD_WARNING
#include<stdio.h>
#include"PadInput.h"

GameMain::GameMain()
{
	
	

	BGM = LoadSoundMem("../BGM/Stage.mp3");

	//�Q�[����ʔw�i�Ǎ�

	stageimg = LoadGraph("../imege/GameMain.png");

	FILE* fp;

	int block = 0;

	rendering_coodinates_x = 0;

	camerawork = new CameraWork();
	player1 = new Player1();

	player2 = new Player2();

	//�Ǎ��t�@�C�����J��
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


	//�J����
	camerawork->Update(player1->GetLocation().x);

	//�O�̍��W
	Location oldlocation = player1->GetLocation();


	player1->Update(camerawork->GetViewCharX());


	if (player1->GetLocation().x > oldlocation.x)
	{
		rendering_coodinates_x++;
	}




	if (CheckSoundMem(BGM) != 1)
	{   //BGM������Ă��Ȃ�������Đ�
		PlaySoundMem(BGM, DX_PLAYTYPE_LOOP, TRUE); //BGM�Đ�
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

	// ���s���������Z����(���̃X�s�[�h)
	gMileage -= 5;

	player2->Update();

	return this;

	//BGM���~�߂�
	StopSoundMem(BGM);

}



void GameMain::Draw()const
{
	void BackScrool();

		
	// �X�e�[�W�摜�\��
// �`��\�G���A��ݒ�
	
	// �ꖇ�ڂ̓��H�W��
	DrawGraph( gMileage % 1200 ,0, stageimg, FALSE);
	// �񖇖ڂ̓��H�W��
	DrawGraph, (gMileage%1200+1200,0, stageimg, FALSE);
	//�G���A��߂�


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
	DrawFormatString(0, 0, GetColor(255, 255, 255), "fuel�F%f", player1->fuel);

	player2->Draw();

}
