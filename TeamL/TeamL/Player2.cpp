#include "Player2.h";
#include "DxLib.h";
#include "PadInput.h"

#define PLAYER2_SIZE_X   (30.0f)

Player2::Player2()
{
	x = 1200.0f;
	y = 350.0f;
	move_y = 1.0f;
	radius = 10.0f;
}

Player2::Player2(float mx, float my)
{
	x = mx;
	y = my;
	move_y = 5.0f;
	radius = 10.0f;
}

void Player2::Update()
{
	y += move_y;

	if (y > (480 - radius) || y < (0 + radius))
	{
		move_y *= -1.0f;
	}
}

void Player2::Draw()
{
	DrawCircleAA(x , y, radius, 100, GetColor(255, 255, 255),TRUE);
}

void Player2::Move()
{
	//�L�[���g���ē�����
	if (CheckHitKey(KEY_INPUT_UP) != FALSE) // ��L�[�������Ə�ɍs��
	{
		y -= 5.0f;
	}
	else if (CheckHitKeyAll() == 0)//�L�[�𗣂��Ǝ~�܂�
	{
		y += 0.0f;
	}

	if (CheckHitKey(KEY_INPUT_DOWN) != FALSE) //���L�[�������Ɖ��ɍs��
	{
		y += 5.0f;
	}
	else if (CheckHitKeyAll() == 0)//�L�[�𗣂��Ǝ~�܂�
	{
		y += 0.0f;
	}

	//�����ɏ㉺�{�^�������Ǝ~�܂�
	if (CheckHitKey(KEY_INPUT_UP) != FALSE && CheckHitKey(KEY_INPUT_DOWN) != FALSE)
	{
		y += 0.0f;
	}

	
}