#include "Bullet.h"
#include "DxLib.h"



Bullet::Bullet()   //������
{
	location.x = 320.0f;   //x�̏������W
	location.y = 240.0f;   //x�̏������W
	area.height = 20; //�c��
	area.width = 20; //����
	move_x = 1.0f;   //�����𓮂���
	move_y = 0.0f;   //�����𓮂���
	radius = 10.0f;  //���a
	color = GetColor(255, 0, 0); //�F
	Bulletimage = LoadGraph("../imege/beam.png");
}

Bullet::Bullet(float mx, float my)
{
	location.x = mx-200;  //�󂯎�������W�𔽉f������
	location.y = my;  //�󂯎�������W�𔽉f������
	move_x = -20.0f;   //�����𓮂���
	move_y = 0.0f;   //�����𓮂���
	radius = 10.0f;  //���a
	color = GetColor(255, 0, 0); //�F
	area.height = 20; //�c��
	area.width = 20; //����
	Bulletimage = LoadGraph("../imege/beam.png");

	LoadDivGraph("../imege/tktk_Laser_3.png", 40, 5, 8, 192, 192, image);
	animation_time = 0;
	animation = 0;
}

Bullet::~Bullet()
{
}

void Bullet::Update()//�X�V����
{
	
	if (++animation_time % 3 == 0)
	{
		animation++;
		if (animation > 28)
		{
			animation=20;
		}

	}

	if (animation >= 13)
	{
		location.x += move_x;
	}
}

void Bullet::Draw()//�`�揈��
{
	//DrawRotaGraph(location.x, location.y, 1.0, 0, Bulletimage, TRUE);
	DrawRotaGraph(location.x, location.y, 2.0f, 0, image[animation], TRUE,TRUE);
}


void Bullet::Move()//�ړ�����
{
	
}

