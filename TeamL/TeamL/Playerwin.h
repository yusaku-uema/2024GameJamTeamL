/****************************************************************/
/*	�v���W�F�N�g��:												*/
/*	�t�@�C�����F												*/
/*	���e�F														*/
/*	���t�F														*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF													*/
/****************************************************************/
#pragma once
#include "AbstractScene.h"
#include"PadInput.h"

class PlayerWin :public AbstractScene
{
	//�w���v�̔w�i�摜
	int PlayerWin_image;
	int PlayerWIN_BGM;

public:
	//�R���X�g���N�^ 
	PlayerWin();
	~PlayerWin();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
};

