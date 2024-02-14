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

GameMain::GameMain()
{

	//�Q�[����ʔw�i�Ǎ�

	stageimg = LoadGraph("../imege/GameMain.png");

	FILE* fp;

	int block = 0;
	rendering_coodinates_x = 0;

	camerawork = new CameraWork();

	player2 = new Player2();

	//�Ǎ��t�@�C�����J��
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

	// ���s���������Z����(���̃X�s�[�h)
	gMileage += 5;

	player2->Update();

	return this;


}



void GameMain::Draw()const
{
	void BackScrool();



	// �X�e�[�W�摜�\��
// �`��\�G���A��ݒ�
	
	// �㕔�̓��H�W��
	DrawGraph( gMileage % 480 - 480,0, stageimg, FALSE);
	// �����̓��H�W��
	DrawGraph, (gMileage % 480,0, stageimg, FALSE);
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

	player2->Draw();

}
