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
#include "DxLib.h"
class AbstractScene
{
public:
	//�f�X�g���N�^
	virtual ~AbstractScene() {};

	//�`��ȊO�̍X�V�����s
	virtual AbstractScene* Update() = 0;

	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const = 0;

};
