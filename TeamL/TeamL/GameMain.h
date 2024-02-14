/****************************************************************/
/*	�v���W�F�N�g��:		Gamejam �@�@�`�[��L						*/
/*	�t�@�C�����F���C���w�b�_�[									*/
/*	���e�F			�Q�[���̃��C��								*/
/*	���t�F					2024/02/14							*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF				���Ð^�@���l						*/
/****************************************************************/
#pragma once
#include "AbstractScene.h"
#include"camerawork.h"
#include"stage.h"
#include"Player1.h"

class GameMain :
	public AbstractScene

{
	int BGM;


private:
	//�`����W
	int rendering_coodinates_x;

	CameraWork* camerawork;//�J�������[�N
	Stage* stage[25][111];//�X�e�[�W��[�c][��]
	Player1* player1;

public:
	int gMileage ;//�v���C���[�̑��s����
	int stageimg;

	GameMain();
	~GameMain();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;

};
