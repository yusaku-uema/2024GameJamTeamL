#include "VBullet.h"
#include "DxLib.h"



VBullet::VBullet()   //������
{
	location.x = 320.0f;   //x�̏������W
	location.y = 240.0f;   //x�̏������W
	area.height = 20; //�c��
	area.width = 20; //����
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
	area.height = 20; //�c��
	area.width = 20; //����

	LoadDivGraph("../imege/tktk_Laser_1.png", 15, 5, 3, 192, 192, image);
	animation_time = 0;
	animation = 0;
	angle = 0;
}

VBullet::~VBullet()
{
}

void VBullet::Update()//�X�V����
{
	
	if (++animation_time % 1 == 0)
	{
		animation++;
		if (animation > 8)
		{
			animation = 4;
		}

	}

	if (animation >= 3)
	{
		location.x += move_x;
		location.y += move_y;

		if (location.y <= 0)
		{
			move_y *= -1;
			angle = -45;
		}
		if (location.y >= 720)
		{
			move_y *= -1;
			angle = 45;
		}
	}

}

void VBullet::Draw()//�`�揈��
{
	//DrawRotaGraph(location.x, location.y, 1.0, 0, VBulletimage, TRUE);
	DrawRotaGraph(location.x, location.y, 2.0f, angle, image[animation], TRUE);

}


void VBullet::Move()//�ړ�����
{

}
