#include "Bom.h"
#include "DxLib.h"



Bom::Bom()   //������
{
	location.x = 320.0f;   //x�̏������W
	location.y = 240.0f;   //x�̏������W
	area.height = 20; //�c��
	area.width = 20; //����
	move_x = 1.0f;   //�����𓮂���
	move_y = 0.0f;   //�����𓮂���
	radius = 30.0f;  //���a
	color = GetColor(255, 0, 0); //�F
	Bomimage = LoadGraph("../imege/bom.png");
}

Bom::Bom(float mx, float my)
{
	location.x = mx;  //�󂯎�������W�𔽉f������
	location.y = my;  //�󂯎�������W�𔽉f������
	move_x = -5.0f;   //�����𓮂���
	move_y = 0.0f;   //�����𓮂���
	radius = 30.0f;  //���a
	color = GetColor(255, 0, 0); //�F
	area.height = 100; //�c��
	area.width = 100; //����
	Bomimage = LoadGraph("../imege/bom.png");
	descent = false;
}

Bom::~Bom()
{
}

void Bom::Update()//�X�V����
{

	if (descent == false)
	{
		location.y++;
	}
	else
	{
		location.x += move_x;
	}
	
	
}

void Bom::Draw()//�`�揈��
{
	DrawRotaGraph(location.x, location.y, 1.0, 0, Bomimage, TRUE);

}


void Bom::Move()//�ړ�����
{

}

void Bom::Setdescent()
{
	descent = true;
}
