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

class PlayerLose :public AbstractScene
{
	//�w���v�̔w�i�摜
	int PlayerLose_image;


public:
	//�R���X�g���N�^ 
	PlayerLose();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
};

