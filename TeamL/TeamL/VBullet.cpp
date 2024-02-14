#include "VBullet.h"
#include "DxLib.h"



VBullet::VBullet()   //������
{
	x = 320.0f;   //x�̏������W
	y = 240.0f;   //x�̏������W
	move_x = 1.0f;   //�����𓮂���
	move_y = 0.0f;   //�����𓮂���
	radius = 10.0f;  //���a
	color = GetColor(255, 0, 0); //�F
}

VBullet::VBullet(float mx, float my,float vx, float vy)
{
	x = mx;  //�󂯎�������W�𔽉f������
	y = my;  //�󂯎�������W�𔽉f������
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
	x += move_x;
	y += move_y;

	if (y <= 0)
	{
		move_y *= -1;
	}
	if (y >= 720)
	{
		move_y *= -1;
	}
}

void VBullet::Draw()//�`�揈��
{

	DrawCircleAA(x, y, radius, 100, color, TRUE);
}


void VBullet::Move()//�ړ�����
{

}