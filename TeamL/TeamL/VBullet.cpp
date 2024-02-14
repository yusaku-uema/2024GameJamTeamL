#include "VBullet.h"
#include "DxLib.h"



VBullet::VBullet()   //������
{
	location.X = 320.0f;   //x�̏������W
	location.Y = 240.0f;   //x�̏������W
	move_x = 1.0f;   //�����𓮂���
	move_y = 0.0f;   //�����𓮂���
	radius = 10.0f;  //���a
	color = GetColor(255, 0, 0); //�F
}

VBullet::VBullet(float mx, float my,float vx, float vy)
{
	location.X = mx;  //�󂯎�������W�𔽉f������
	location.Y = my;  //�󂯎�������W�𔽉f������
	move_x = vx;   //�����𓮂���
	move_y = vy;   //�����𓮂���
	radius = 10.0f;  //���a
	color = GetColor(255, 0, 0); //�F
}

VBullet::~VBullet()
{
}

void VBullet::Update()//�X�V����
{
	location.X += move_x;
	location.Y += move_y;

	if (location.Y <= 0)
	{
		move_y *= -1;
	}
	if (location.Y >= 720)
	{
		move_y *= -1;
	}
}

void VBullet::Draw()//�`�揈��
{

	DrawCircleAA(location.X, location.Y, radius, 100, color, TRUE);
}


void VBullet::Move()//�ړ�����
{

}

float VBullet::GetVBulletX()
{
	return location.X;
}

float VBullet::GetVBulletY()
{
	return location.Y;
}