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
#include "Collinder.h"

class Stage:
	public Collinder

{

	int camerax;

	int tukiimage1;
	int tukiimage2;
	int tukiimage3;
	int tukiimage4;


private:

	int type;

public:

	Stage(float locationx,float locationy,int width,int height,int type);

	~Stage();

	//�`��ȊO�̍X�V�����s
	void Update(int camerax);

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const ;
};
