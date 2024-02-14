#include "VBullet.h"
#include "DxLib.h"



VBullet::VBullet()   //������
{
	location.x = 320.0f;   //x�̏������W
	location.y = 240.0f;   //x�̏������W
	area.height = 60; //�c��
	area.width = 200; //����
	move_x = 1.0f;   //�����𓮂���
	move_y = 0.0f;   //�����𓮂���
	radius = 10.0f;  //���a
	color = GetColor(255, 0, 0); //�F
}

VBullet::VBullet(float mx, float my,float vx, float vy)
{
	location.x = mx;  //�󂯎�������W�𔽉f������
	location.y = my;  //�󂯎�������W�𔽉f������
	move_x = vx;   //�����𓮂���
	move_y = vy;   //�����𓮂���
	radius = 10.0f;  //���a
	color = GetColor(255, 0, 0); //�F

	VBulletimage = LoadGraph("../imege/beam.png");
	area.height = 60; //�c��
	area.width = 200; //����
}

VBullet::~VBullet()
{
}

void VBullet::Update()//�X�V����
{
	location.x += move_x;
	location.y += move_y;

	if (location.y <= 0)
	{
		move_y *= -1;
	}
	if (location.y >= 720)
	{
		move_y *= -1;
	}
}

void VBullet::Draw()//�`�揈��
{
	DrawRotaGraph(location.x, location.y, 1.0, 0, VBulletimage, TRUE);

}


void VBullet::Move()//�ړ�����
{

}
