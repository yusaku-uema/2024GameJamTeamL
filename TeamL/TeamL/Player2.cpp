#include "Player2.h";
#include "DxLib.h";
#include "PadInput.h"
#include "Bullet.h"
#include"VBullet.h"

#define PLAYER2_SIZE_X   (30.0f)

Player2::Player2()
{
	
	location.X = 1200.0f;
	location.Y = 350.0f;
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
	location.X = mx;
	location.Y = my;
	move_y = 5.0f;
	radius = 10.0f;
}

void Player2::Update()
{
	location.Y += move_y;

	if (location.Y > (480 - radius) || location.Y < (0 + radius))
	{
		move_y *= -1.0f;
	}

	Move();


	if (PadInput::OnButton(XINPUT_BUTTON_B)==1)
	{
		if (p_bullet == nullptr)
		{
			p_bullet=new Bullet(location.X, location.Y);
		}
	}
	if (p_bullet != nullptr)
	{
		p_bullet->Update();
		if (p_bullet->GetBulletX() <= 0.0f)
		{
			delete p_bullet;
			p_bullet = nullptr;
		}
	}

	if (PadInput::OnButton(XINPUT_BUTTON_A) == 1)
	{
		if (p_bom == nullptr)
		{
			p_bom = new Bom(location.X, location.Y);
		}
	}
	if (p_bom != nullptr)
	{
		p_bom->Update();
		if (p_bom->GetBomX() <= 0.0f)
		{
			delete p_bom;
			p_bom = nullptr;
		}
	}

	if (PadInput::OnButton(XINPUT_BUTTON_Y) == 1)
	{
		if (p_vbullet == nullptr)
		{
			p_vbullet = new VBullet(location.X, location.Y,-20.0f,-20.0f);
		}
	}
	if (p_vbullet != nullptr)
	{
		p_vbullet->Update();
		if (p_vbullet->GetVBulletX() <= 0.0f)
		{
			delete p_vbullet;
			p_vbullet = nullptr;
		}
	}

	if (PadInput::OnButton(XINPUT_BUTTON_X) == 1)
	{
		if (p_vbullet == nullptr)
		{
			p_vbullet = new VBullet(location.X, location.Y, -20.0f, 20.0f);
		}
	}
	if (p_vbullet != nullptr)
	{
		p_vbullet->Update();
		if (p_vbullet->GetVBulletX() <= 0.0f)
		{
			delete p_vbullet;
			p_vbullet = nullptr;
		}
	}
}

void Player2::Draw()
{
	Player2image = LoadGraph("../imege/Player2.png");
	DrawRotaGraph(location.X, location.Y, 0.5 ,0,Player2image,TRUE);

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
		location.Y -= 5.0f;
	}
	else if (CheckHitKeyAll() == 0)//キーを離すと止まる
	{
		location.Y += 0.0f;
	}

	if (stick_y < -2000) //下キーを押すと下に行く
	{
		location.Y += 5.0f;
	}
	else if (CheckHitKeyAll() == 0)//キーを離すと止まる
	{
		location.Y += 0.0f;
	}
	
	//同時に上下ボタン押すと止まる
	if (CheckHitKey(KEY_INPUT_UP) != FALSE && CheckHitKey(KEY_INPUT_DOWN) != FALSE)
	{
		location.Y += 0.0f;
	}

	
}