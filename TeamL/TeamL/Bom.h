#pragma once
#include "Collinder.h"

class Bom : public Collinder //�N���X��
{
public: //�A�N�Z�X�w��q
	float x;           //X���W���
	float y;           //Y���W���
	float radius;		// ���a
	float color;        //�F���
	float move_x;		// �i�s�����x�N�g�����X
	float move_y;		// �i�s�����x�N�g�����Y

	Bom();
	Bom(float mx, float my);   //������
	~Bom();

	void Draw();      //�`�悷�鏈��
	void Update();    //�X�V����
	void Move();      //�ړ�����
	float GetBomX();
	float GetBomY();
};