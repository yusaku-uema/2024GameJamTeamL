#include "Bom.h"
#include "DxLib.h"



Bom::Bom()   //������
{
	location.X = 320.0f;   //x�̏������W
	location.Y = 240.0f;   //x�̏������W
	move_x = 1.0f;   //�����𓮂���
	move_y = 0.0f;   //�����𓮂���
	radius = 30.0f;  //���a
	color = GetColor(255, 0, 0); //�F
}

Bom::Bom(float mx, float my)
{
	location.X = mx;  //�󂯎�������W�𔽉f������
	location.Y = my;  //�󂯎�������W�𔽉f������
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
	location.X += move_x;
}

void Bom::Draw()//�`�揈��
{

	DrawCircleAA(location.X, location.Y, radius, 100, color, TRUE);
}


void Bom::Move()//�ړ�����
{

}

float Bom::GetBomX()
{
	return location.X;
}

float Bom::GetBomY()
{
	return location.Y;
}