#pragma once
#include "Collinder.h"

class VBullet : public Collinder //�N���X��
{
public: //�A�N�Z�X�w��q
	float radius;		// ���a
	float color;        //�F���
	float move_x;		// �i�s�����x�N�g�����X
	float move_y;		// �i�s�����x�N�g�����Y
	int VBulletimage;


	int angle; 
	int image[15];
	long long int animation_time; //�A�j���[�V��������
	int animation; //�摜�؂�ւ�

	VBullet();
	VBullet(float mx, float my,float vx, float vy);   //������
	~VBullet();

	void Draw();      //�`�悷�鏈��
	void Update();    //�X�V����
	void Move();      //�ړ�����

};