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
	p_bom;
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

	if (PadInput::OnButton(XINPUT_BUTTON_A) == 1)
	{
		if (p_bom == nullptr)
		{
			p_bom = new Bom(x,y);
		}
	}
	if (p_bom != nullptr)
	{
		p_bom->Update();
		if (p_bom->x <= 0.0f)
		{
			delete p_bom;
			p_bom = nullptr;
		}
	}

	if (PadInput::OnButton(XINPUT_BUTTON_Y) == 1)
	{
		if (p_vbullet == nullptr)
		{
			p_vbullet = new VBullet(x, y,-20.0f,-20.0f);
		}
	}
	if (p_vbullet != nullptr)
	{
		p_vbullet->Update();
		if (p_vbullet->x <= 0.0f)
		{
			delete p_vbullet;
			p_vbullet = nullptr;
		}
	}

	if (PadInput::OnButton(XINPUT_BUTTON_X) == 1)
	{
		if (p_vbullet == nullptr)
		{
			p_vbullet = new VBullet(x, y, -20.0f, 20.0f);
		}
	}
	if (p_vbullet != nullptr)
	{
		p_vbullet->Update();
		if (p_vbullet->x <= 0.0f)
		{
			delete p_vbullet;
			p_vbullet = nullptr;
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
	if (p_vbullet != nullptr)
	{
		p_vbullet->Draw();
	}
	if (p_bom != nullptr)
	{
		p_bom->Draw();
	}
}

void Player2::Move()
{
	int stick_y = PadInput::GetLStick().y;


	//キーを使って動かす
	if (stick_y > 2000) // 上キーを押すと上に行く
	{
		y -= 5.0f;
	}
	else if (CheckHitKeyAll() == 0)//キーを離すと止まる
	{
		y += 0.0f;
	}

	if (stick_y < -2000) //下キーを押すと下に行く
	{
		y += 5.0f;
	}
	else if (CheckHitKeyAll() == 0)//キーを離すと止まる
	{
		y += 0.0f;
	}
	
	//同時に上下ボタン押すと止まる
	if (CheckHitKey(KEY_INPUT_UP) != FALSE && CheckHitKey(KEY_INPUT_DOWN) != FALSE)
	{
		y += 0.0f;
	}

	
}