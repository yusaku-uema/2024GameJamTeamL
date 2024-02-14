#include "Bullet.h"
#include "DxLib.h"



Bullet::Bullet()   //������
{
	location.X = 320.0f;   //x�̏������W
	location.Y = 240.0f;   //x�̏������W
	move_x = 1.0f;   //�����𓮂���
	move_y = 0.0f;   //�����𓮂���
	radius = 10.0f;  //���a
	color = GetColor(255, 0, 0); //�F
}

Bullet::Bullet(float mx, float my)
{
	location.X = mx;  //�󂯎�������W�𔽉f������
	location.Y = my;  //�󂯎�������W�𔽉f������
	move_x = -20.0f;   //�����𓮂���
	move_y = 0.0f;   //�����𓮂���
	radius = 10.0f;  //���a
	color = GetColor(255, 0, 0); //�F
}

Bullet::~Bullet()
{
}

void Bullet::Update()//�X�V����
{
	location.X += move_x;
	
}

void Bullet::Draw()//�`�揈��
{
	Bulletimage = LoadGraph("../imege/beam.png");
	DrawRotaGraph(location.X, location.Y, 1.0, 0, Bulletimage, TRUE);
}


void Bullet::Move()//�ړ�����
{
	
}

float Bullet::GetBulletX()
{
	return location.X;
}

float Bullet::GetBulletY()
{
	return location.Y;
}