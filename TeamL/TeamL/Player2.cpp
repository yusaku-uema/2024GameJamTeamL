#include "Player2.h";
#include "DxLib.h";
#include "PadInput.h"
#include "Bullet.h"

#define PLAYER2_SIZE_X   (30.0f)

Player2::Player2()
{
	x = 1200.0f;
	y = 350.0f;
	move_y = 0.0f;
	radius = 10.0f;
}

Player2::~Player2()
{
	p_bullet;
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

	Move();


	if (PadInput::OnButton(XINPUT_BUTTON_B)==1)
	{
		if (p_bullet == nullptr)
		{
			p_bullet=new Bullet(x, y);
		}
	}
	if (p_bullet != nullptr)
	{
		p_bullet->Update();
		if (p_bullet->x <= 0.0f)
		{
			delete p_bullet;
			p_bullet = nullptr;
		}
	}
}

void Player2::Draw()
{
	DrawCircleAA(x , y, radius, 100, GetColor(255, 255, 255),TRUE);

	if (p_bullet != nullptr)
	{
		p_bullet->Draw();
	}
}

void Player2::Move()
{
	int stick_y = PadInput::GetLStick().y;


	//�L�[���g���ē�����
	if (stick_y > 2000) // ��L�[�������Ə�ɍs��
	{
		y -= 5.0f;
	}
	else if (CheckHitKeyAll() == 0)//�L�[�𗣂��Ǝ~�܂�
	{
		y += 0.0f;
	}

	if (stick_y < -2000) //���L�[�������Ɖ��ɍs��
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