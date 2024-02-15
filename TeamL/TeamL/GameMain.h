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
#include"Player2.h"
#include"stage.h"
#include"Player1.h"
#include"UI.h"
#include"explosion.h"

#include "Bullet.h"
#include"VBullet.h"
#include"Bom.h"


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
	Player2* player2;
	UI* ui; 
	Explosion* explosion;


	//Player2�̒e�یv
	Bullet* p_bullet;
	VBullet* p_vbullet;
	Bom* p_bom;


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
