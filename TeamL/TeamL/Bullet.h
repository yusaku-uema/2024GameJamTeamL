#pragma once
#include "Collinder.h"

class Bullet : public Collinder //�N���X��
{
public: //�A�N�Z�X�w��q
	float radius;		// ���a
	float color;        //�F���
	float move_x;		// �i�s�����x�N�g�����X
	float move_y;		// �i�s�����x�N�g�����Y
	int Bulletimage;
	int image[40]; //���[�U�[�G�t�F�N�g
	long long int animation_time; //�A�j���[�V��������
	int animation; //�摜�؂�ւ�
	int ChargeSE;
	int FiringSE;

	Bullet();
	Bullet(float mx, float my);   //������
	~Bullet();

	void Draw();      //�`�悷�鏈��
	void Update();    //�X�V����
	void Move();      //�ړ�����
};
