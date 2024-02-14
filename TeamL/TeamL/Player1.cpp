#include"Player1.h"
#include"PadInput.h"
#include"DxLib.h"

#define FUEL (100.0f)

//コンストラクタ
Player1::Player1()
{
	location.X = 300.0f;
	location.Y = 300.0f;
	area.height = 30.0f;
	area.width = 30.0f;
	R = 30;
	speed = 5.0f;
	count = 0;
	g = 0.0f;
	ground = 690.0f;
	fuel = 100.0f;
	is_jump = false;
	is_fly = false;
}

//デストラクタ
Player1::~Player1()
{

}

//更新処理
void Player1::Update()
{
	Move();
	Flg();
	Jump(type);
	Fly();
}

//描画処理
void Player1::Draw()
{
	DrawCircle(location.X, location.Y, R, 0xffffff, TRUE);
}

//移動処理
void Player1::Move()
{
	//左移動処理
	if (PadInput::OnPressed(0,XINPUT_BUTTON_DPAD_LEFT) == 1)
	{
		if (location.X > 0.0f + area.width)
		{
			location.X -= speed;
		}
	}

	//右移動処理
	if (PadInput::OnPressed(0,XINPUT_BUTTON_DPAD_RIGHT) == 1)
	{
		if (location.X < 1280.0f - area.width)
		{
			location.X += speed;
		}
	}
}

//判定処理
void Player1::Flg()
{
	//地面についたらフラグをtrueにする
	if (location.Y >= ground)
	{
		location.Y = ground;
		g = 0.0f;
		SetJump(false);
		//SetFly(true);
	}
	if (location.Y <= area.height)
	{
		location.Y = area.height;
	}

	//Aボタンを押したら小ジャンプ
	if (PadInput::OnPressed(0,XINPUT_BUTTON_A) == 1 && is_jump == false)
	{
		SetJump(true);
		low = -20;
		type = low;
		abs = -type;
	}

	//Bボタンを押して大ジャンプ
	if (PadInput::OnPressed(0,XINPUT_BUTTON_B) == 1 && is_jump == false)
	{
		SetJump(true);
		high = -30;
		type = high;
		abs = -type;
	}

	//Rトリガーを長押しして上昇
	if (PadInput::GetRTrigger(0) > 0)
	{
		SetFly(true);
		if (location.Y > area.width)
		{
			location.Y -= PadInput::GetRTrigger(0) * 5;
		}
		//ジャンプ中断
		if (is_jump == true)
		{
			SetJump(false);
		}
		Fuel();
	}

	//Lトリガーを長押しして下降
	if (PadInput::GetLTrigger(0) != 0)
	{
		if (location.Y < ground)
		{
			location.Y += PadInput::GetLTrigger(0) * 5;
		}
	}

	//浮遊解除
	if (PadInput::OnPressed(0,XINPUT_BUTTON_DPAD_DOWN) == 1)
	{
		SetFly(false);
	}
}

//ジャンプ処理
void Player1::Jump(int jump)
{
	if (is_jump == true)
	{
		if (jump < 0)
		{
			location.Y += jump / 2;
			type++;
		}
		else
		{
			if (ground - location.Y > 0)
			{
				location.Y += g / 2;
				g++;
			}
		}
	}
}

//落下処理
void Player1::Fly()
{
	if (is_fly == false)
	{
		if (ground - location.Y > 0)
		{
			location.Y += g / 2;
			g++;
		}
	}
}

//ジャンプフラグ設定処理(ジャンプ中＝true、着地＝false)
void Player1::SetJump(bool flg)
{
	is_jump = flg;
}

//浮遊フラグ設定処理(浮遊可能＝true、浮遊不可＝false)
void Player1::SetFly(bool flg)
{
	is_fly = flg;
}

//燃料ゲージ処理
void Player1::Fuel()
{
	if (is_jump == false)
	{
		if (fuel>0.0f)
		{
			SetFly(true);
			fuel-=1.0f;
		}
		else
		{
			SetFly(false);
			fuel++;
		}
	}
}

float Player1::GetPlayer1X()
{
	return location.X;
}

float Player1::GetPlayer1Y()
{
	return location.Y;
}