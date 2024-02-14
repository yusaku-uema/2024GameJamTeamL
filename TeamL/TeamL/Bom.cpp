#include "Bom.h"
#include "DxLib.h"



Bom::Bom()   //������
{
	x = 320.0f;   //x�̏������W
	y = 240.0f;   //x�̏������W
	move_x = 1.0f;   //�����𓮂���
	move_y = 0.0f;   //�����𓮂���
	radius = 30.0f;  //���a
	color = GetColor(255, 0, 0); //�F
}

Bom::Bom(float mx, float my)
{
	x = mx;  //�󂯎�������W�𔽉f������
	y = my;  //�󂯎�������W�𔽉f������
	move_x = -5.0f;   //�����𓮂���
	move_y = 0.0f;   //�����𓮂���
	radius = 30.0f;  //���a
	color = GetColor(255, 0, 0); //�F
}

Bom::~Bom()
{
}

void Bom::Update()//�X�V����
{
	x += move_x;
}

void Bom::Draw()//�`�揈��
{

	DrawCircleAA(x, y, radius, 100, color, TRUE);
}


void Bom::Move()//�ړ�����
{

}